import java.io.*;
import java.util.*;


public class C { 

    public static void main(String [] args) throws IOException { 
    
            //Scanner s = new Scanner(new BufferedReader(new FileReader("C-small-attempt0.in"))); 
            Scanner s = new Scanner(new BufferedReader(new FileReader("C-large.in")));
            //Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
            int ncase = s.nextInt();
            for (int i = 1; i <= ncase; i++) {
                int N = s.nextInt();
                solve(s, i, N);
            }
            s.close();
    }

    public static void solve(Scanner s, int caseno, int N) {

        int[] pref = new int[N];
        for (int i = 0; i < N; i++) {
            pref[i] = s.nextInt() - 1;
        }

        // count rings

        int[] rid = new int[N]; // ring id
        int[] llen = new int[N]; // link len
        int[] inter = new int[N]; // intersection
        int[] rlen = new int[N];

        for (int i = 0; i < N; i++) {
            boolean[] rr = new boolean[N];
            Arrays.fill(rr, false);
 
            int j = i;
            int len = 0;
            while( !rr[j] ) {
                rr[j] = true;
                j = pref[j];
                len++;
            }
            inter[i] = j;

            int k = pref[j];
            int rrrlen = 1;
            int id = j;
            while ( k != j ) {
                id = Math.min(id, k);
                k = pref[k];
                rrrlen++;
//                System.out.println(k);
            }

            llen[i] = len - rrrlen;
            rid[i] = id;
            rlen[id] = rrrlen;
        }



        int rv = 0;
        int sum = 0;
        for ( int i = 0; i < N; i++) {
            int[] tmp = new int[N];
            for ( int  j = 0 ; j < N; j++ ) {
                if ( rid[j] == i ) {
                    tmp[inter[j]] = Math.max(tmp[inter[j]], llen[j]);
                }
            }

            Arrays.sort(tmp);
            if ( rlen[i] > 2 )
                rv = Math.max(rv, rlen[i]);
            else {
                sum += rlen[i] + tmp[N-1] + tmp[N-2];

            }
        }
        rv = Math.max(rv, sum);

        System.out.printf("Case #%d: %d\n", caseno, rv);
    }

}
