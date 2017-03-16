import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by admin on 4/11/2015.
 */
public class TaskA {
    static void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            st = null;
            out.println("Case #" + testCase + ": " + solve());
        }
    }

    static String solve() throws IOException{
        Integer sMax, total=0, friends=0;
        sMax = nextInt();
        String tt = nextToken();
        for(int i=0; i<=sMax; i++){
           if(total<i){
              friends += i - total;
               total = i;
           }
            total += Character.getNumericValue(tt.charAt(i));
        }
        return friends.toString();
    }


    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("gcj/a.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
            output = new PrintStream(new File("a.out"));
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solveMultiTest();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static String nextLine() throws IOException {
        String line=null;
        line = br.readLine();
        System.out.println(line);
        return line;
    }

}
