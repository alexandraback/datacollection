import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

/**
 * Apr 14, 2012 
 * @author parisel
 * GGJ - Qualification Round
 */
public class C {
    private static final int TEST= 0, SMALL= 1, LARGE= 2;
    private static final String[] infile= { "-test.in",  "-small.in",  "-large.in"};
    private static final String[] outfile= {"-test.out", "-small.out", "-large.out"};
    java.io.BufferedReader br;
    java.io.PrintWriter out;
    int N;
    String[] tok;

    private String[] getTok() throws IOException {return br.readLine().split(" ");}
    private int getInt() throws IOException {return Integer.valueOf(br.readLine());}
    private int[] getInt(int N) throws IOException {
        int[] data= new int[N]; tok= br.readLine().split(" ");
        for (int i=0; i<N; i++) data[i]= Integer.valueOf(tok[i]);
        return data;
    }
    private int toInt(String s) { return Integer.valueOf(s); }



    int A, B;
    int cn;
    private long answer() {
        int n, m;
        long count= 0;

        for (n=A; n<=B; n++)
            count+= reclycled(n);
        return count;
    }

    int[] div= {1, 10, 100, 1000, 10000, 100000, 1000000};
    HashSet<Integer> hs= new HashSet<Integer>();
    private int reclycled(int n) {
        int m, count= 0;
        for (int i=1; i<cn; i++) {
            m= (n/div[i]) + (n%div[i])*div[cn-i];
            if (m>n && m<=B && hs.add(m))  {
                ++count;
//                System.out.printf("%d -> %d\n", n, m);
            }
        }
        hs.clear();
        return count;
    }

    public void solve() throws IOException {
        int i,j,k;
        String s;

        int MODE= SMALL;
        br = new BufferedReader (new FileReader("C"+infile[MODE]));
        out = new PrintWriter(new BufferedWriter(new FileWriter("C"+outfile[MODE])));

        int C= Integer.valueOf(br.readLine());
        for (int c=1; c<=C; c++) {
            // read
            tok= getTok();
            A= toInt(tok[0]);
            B= toInt(tok[1]);
            cn= tok[0].length();
            // output
            out.printf("Case #%d: %d\n", c, answer());
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().solve();
    }
}
