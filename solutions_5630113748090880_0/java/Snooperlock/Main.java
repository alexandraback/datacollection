import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;
import java.util.*;


public class Main implements Runnable {

    ///////////////////////
    // File name variables
//    final String problem = "A";
    final String problem = "B";
//    final String problem = "C";
//    final String problem = "D";

    // final String filename = problem + "-sample";

    final String filename = problem + "-small-attempt0";
//    final String filename = problem + "-small-practice";
//    final String filename = problem + "-large-practice";
//     final String filename= problem+"-small-attempt1";
//     final String filename= problem+"-large";

    // Output Float format
    // e.g. out.write(df.format(T0));
    DecimalFormat df = new DecimalFormat("0.0000000");

    // Helper object
    static int MAX = (int)Math.pow(2.0, 17.0);
    HashMap<Integer, Boolean> primeMap = new HashMap<Integer, Boolean>();
    int[] primeNums = new int[MAX];

    //////////////////////////////////////////
    // Hard core function
    public void solve() throws Exception {
        int totalline = iread();
        ArrayList<Integer> result = new ArrayList<Integer>();
        HashMap<Integer, Integer> countMap = new HashMap<Integer, Integer>();

        for (int i = 0; i < 2*totalline - 1; i++) {
            String curLine = readLine();
            String [] splitedLine = curLine.split(" ");
            for (String curChar : splitedLine) {
                Integer curCharInInt = Integer.valueOf(curChar);
                if (countMap.containsKey(curCharInInt)) {
                    countMap.put(curCharInInt, countMap.get(curCharInInt) + 1);
                } else {
                    countMap.put(curCharInInt, 1);
                }
            }
        }

        Iterator it = countMap.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, Integer> pair = (Map.Entry<Integer, Integer>)it.next();
            if (pair.getValue() % 2 != 0) {
                result.add(pair.getKey());
            }
        }
        Collections.sort(result);
        for (Integer singleResult : result) {
            out.write(singleResult + " ");
        }
    }

//    private long calPower(int K, int C) {
//        long result = 1;
//        for (int i = 0; i < C; i++) {
//            result *= K;
//        }
//        return result;
//    }

    //////////////////////////////////////////
    /// Helper functions
    public void solve_gcj() throws Exception {

        int tests = iread();
        for (int test = 1; test <= tests; test++) {
            out.write("Case #" + test + ": ");
            solve();
            out.write("\n");
        }
    }

    public void run() {
        try {
            // Helper in-&-out for local test
//            in = new BufferedReader(new InputStreamReader(System.in));
//            out = new BufferedWriter(new OutputStreamWriter(System.out));

            // For real file input and output
            in = new BufferedReader(new FileReader(filename + ".in"));
            out = new BufferedWriter(new FileWriter(filename + ".out"));
            solve_gcj();
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public int iread() throws Exception {
        return Integer.parseInt(readword());
    }

    public double dread() throws Exception {
        return Double.parseDouble(readword());
    }

    public long lread() throws Exception {
        return Long.parseLong(readword());
    }

    BufferedReader in;

    BufferedWriter out;

    public String readword() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c >= 0 && c <= ' ')
            c = in.read();
        if (c < 0)
            return "";
        while (c > ' ') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }

    public String readLine() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c != '\n') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }

    /////////////////////////
    // Main Function
    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception e) {

        }
        new Thread(new Main()).start();
    }
}


