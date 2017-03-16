
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class DeceitfulWar {
    
    public static void main(String[] args) throws IOException {
        //Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        Scanner sc = new Scanner(new File("D-small-attempt0.in"));
        sc.useLocale(Locale.US);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int naomi[] = new int[N];
            int ken[] = new int[N];
            
            for (int j = 0; j < N; j++) {
                naomi[j] = (int)(sc.nextDouble()*100000.0f);
            }
            for (int j = 0; j < N; j++) {
                ken[j] = (int)(sc.nextDouble()*100000.0f);
            }
            Arrays.sort(naomi);
            Arrays.sort(ken);
            boolean naomiMarks[] = new boolean[N];
            boolean kenMarks[] = new boolean[N];
            int Z = 0;
            for (int j = 0; j < N; j++) {
                naomiMarks[j] = true;
                int ind = Math.abs(Arrays.binarySearch(ken, naomi[j]))-1;
                while(kenMarks[ind%N])ind++;
                kenMarks[ind%N] = true;
                if(naomi[j] > ken[ind%N])Z++;
            }
            naomiMarks = new boolean[N];
            kenMarks = new boolean[N];
            int Y = 0;
            for (int j = 0; j < N; j++) {
                kenMarks[j] = true;
                int ind = Math.abs(Arrays.binarySearch(naomi, ken[j]))-1;
                while(naomiMarks[ind%N])ind++;
                naomiMarks[ind%N] = true;
                if(naomi[ind%N] > ken[j])Y++;
            }
            bw.write("Case #" + (int)(i+1) + ": " + Y + " " + Z);
            bw.newLine();
        }
        bw.close();
    }
    
}
