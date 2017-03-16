import java.io.*;
import java.util.Scanner;


public class B {

    public static void main(String [] args) throws IOException {
            Scanner s = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
            //Scanner s = new Scanner(new BufferedReader(new FileReader("A-large.in")));
           // Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
            int ncase = s.nextInt();
            for (int i = 1; i <= ncase; i++) {
                int N = s.nextInt();
                solve(s, i, N);
            }
            s.close();
    }

    public static void solve(Scanner s, int caseno, int N) {

        int[] Height = new int[2501];
        for (int i = 1; i <= 2*N - 1; i++) {
            for (int j = 1; j <= N; j++) {
                int h = s.nextInt();
                Height[h-1]++;
            }
        }

        System.out.printf("Case #%d:", caseno);
        for (int i = 0; i <= 2500; i++) {
            if( Height[i] % 2 == 1 ) {
                System.out.printf(" %d", i+1);
            }
        }
        System.out.printf("\n");
    }

}
