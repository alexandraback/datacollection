package code.jam.y2013.round1c;

import java.io.*;
import java.util.Arrays;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class ProblemA {

    private static String PATH = "F:\\dev\\projects\\code-jam-2012\\src\\code\\jam\\y2013\\round1c";
    File inputFile = new File(PATH, "A-small-attempt0.in");
    File outputFile = new File(PATH, "A-small.out");
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) throws Exception {
        new ProblemA().solve();
    }

    void solve() throws Exception {
        in = new BufferedReader(new FileReader(inputFile));
        out = new PrintWriter(outputFile);

        for (int testCase = 1, testCount = nextInt(); testCase <= testCount; testCase++) {
            print("Case #" + testCase + ": " + solve(testCase));
        }

        out.close();
    }
    private static final Set ALPHABET = new TreeSet(Arrays.asList("a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z".split(",")));
    private static final Set VOWELS = new TreeSet(Arrays.asList("a,e,i,o,u".split(",")));
    private static final Set CONSONANTS = new TreeSet(ALPHABET);
    static {
        CONSONANTS.removeAll(VOWELS);
    }
    String solve(int testCase) throws IOException {
        final String name = nextToken();
        final int n = nextInt();
        long count = 0;
        for (int i = 0, ii=name.length()-n; i <= ii; i++) {
            for (int j = i + n, jj=name.length(); j <= jj; j++) {
                int consecutiveConstants = 0;
                for (int k = i; k < j; k++) {
                    if (CONSONANTS.contains(String.valueOf(name.charAt(k)))) {
                        consecutiveConstants++;
                    } else {
                        consecutiveConstants = 0;
                    }
                    if (consecutiveConstants==n) {
                        count++;
                        break;
                    }
                    
                }
            }
        }
        return Long.toString(count);
    }
    
    private void print(String text) {
        out.println(text);
        System.out.println(text);
    }

    
    /**
     * helpers
     */
    String nextToken() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    
    int nextChar() throws IOException {
        return in.read();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextLine() throws IOException {
        st = new StringTokenizer("");
        return in.readLine();
    }

    boolean EOF() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return true;
            }
            st = new StringTokenizer(s);
        }
        return false;
    }
    
}
