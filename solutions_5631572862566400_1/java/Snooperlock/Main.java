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
//    final String problem = "B";
    final String problem = "C";
//    final String problem = "D";

    // final String filename = problem + "-sample";

//    final String filename = problem + "-small-attempt0";
//    final String filename = problem + "-small-practice";
//    final String filename = problem + "-large-practice";
//     final String filename= problem+"-small-attempt1";
     final String filename= problem+"-large";

    // Output Float format
    // e.g. out.write(df.format(T0));
    DecimalFormat df = new DecimalFormat("0.0000000");

    //////////////////////////////////////////
    // Hard core function
    public void solve() throws Exception {
        int totalline = iread();
        String [] bffSplitted = readLine().split(" ");

        HashMap<Integer, Integer> bffMap = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> ringCountMap = new HashMap<Integer, Integer>();
        for (int i = 1; i <= bffSplitted.length; i++) {
            bffMap.put(i, Integer.valueOf(bffSplitted[i-1]));
        }

//        System.out.println(bffMap);

        // find the inter pointing loop
        for (int i = 1; i <= bffSplitted.length; i++) {
            if (bffMap.get(bffMap.get(i)).equals(i)) {
                ringCountMap.put(i, 0);
                ringCountMap.put(bffMap.get(i), 0);
            }
        }

//        System.out.println(ringCountMap);

        int singleChainMax = 1;

        for (int i = 1; i <= bffSplitted.length; i++) {
            if (ringCountMap.containsKey(i)) {
                continue;
            }

            Integer curInt = i;
            HashSet<Integer> curChainSet = new HashSet<Integer>();
            curChainSet.add(curInt);
            while (!curChainSet.contains(bffMap.get(curInt)) && !ringCountMap.containsKey(bffMap.get(curInt))) {

//                System.out.println(curInt);

                curInt = bffMap.get(curInt);
                curChainSet.add(curInt);
            }

//            System.out.println("Final int is " + curInt);
//            System.out.println(curChainSet);

            if (bffMap.get(curInt).equals(i) && curChainSet.size() > singleChainMax) {
                singleChainMax = curChainSet.size();
            }
            if (ringCountMap.containsKey(bffMap.get(curInt))) {
                if (curChainSet.size() > ringCountMap.get(bffMap.get(curInt))) {
                    ringCountMap.put(bffMap.get(curInt), curChainSet.size());
                }
            }
        }

        // compare single chain and chain plus ring
        int chainRingSize = 0;
        if (ringCountMap.size() > 0) {
            int valueSum = 0;
            Iterator it = ringCountMap.entrySet().iterator();
            while (it.hasNext()) {
                Map.Entry<Integer, Integer> pair = (Map.Entry<Integer, Integer>)it.next();
                valueSum += pair.getValue();
            }
            chainRingSize = valueSum + ringCountMap.size();
        }

        if (singleChainMax > chainRingSize) {
            out.write(String.valueOf(singleChainMax));
        } else {
            out.write(String.valueOf(chainRingSize));
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
//            // Helper in-&-out for local test
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


