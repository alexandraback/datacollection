
import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class Main {

    static Scanner in;
    static PrintWriter out;
    static int[] a;
    
    public static void solve(int caseNumber) {
        int n = in.nextInt();
        long sum = 0;
        int maxElement=0;
        for (int i=0; i<n; i++) {
            a[i]=in.nextInt();
            sum+=a[i];
            if (i==0 || maxElement<a[i]) {
                maxElement=a[i];
            }
        }
        //out.
        out.format(Locale.ENGLISH,"Case #%d:",caseNumber);
        double forEveryone = (double)sum*2/n;
        int cnt = 0;
        long sum2 = sum*2;
        boolean[] used = new boolean[n];
        for (int i=0; i<n;++i) {
            if (a[i]>forEveryone) {
                used[i]=true;
                cnt++;
                sum2-=a[i];
            }
        }
        forEveryone = (double)sum2/(n-cnt);
        
        
        double result;
        for (int i=0; i<n; i++) {
            result = 0;
            if (!used[i]) {
                result = (forEveryone-a[i])/(double)sum;
            }        
            out.printf(Locale.ENGLISH," %f",Math.max(0, result*100));
        }
        out.println();
        
        
    }
    
    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("file.txt"));
        out = new PrintWriter("out.txt");
        int T = in.nextInt();
        a = new int[201];
        for (int i=0; i<T; i++) {
            solve(i+1);
        }
        
        out.close();
    }
}
