import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.highestOneBit;
import static java.lang.Integer.lowestOneBit;
import static java.lang.Integer.numberOfLeadingZeros;
import static java.lang.Integer.numberOfTrailingZeros;
import static java.lang.Integer.bitCount;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;
import java.util.concurrent.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.awt.geom.*;
import java.io.*;

//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class B {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * problem
     * 
     * 
     */
    /*
     * solution
     * 
     * find si!=s[i+1] and reverse so s[0..i] becomes the same as s[i+1]
     * if all the same(all '-'): flip the entire a 
     */
    private void run(int caseNumber) throws Exception {
        String S = STR();
        
        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
//            System.out.println("----- skip case "+caseNumber+" -----");
            return;
        }
        
        /// start solving problem
//        int ret = small(S);
        int ret = big(S);
        
        out.printf("Case #%d: %s\n", caseNumber, ret);
    }
    
    private static int big(String S) {
        String goal = new String(new char[S.length()]).replace('\0', '+');
        String cur = S;
        for (int step = 0; ; step++) {
            if (cur.equals(goal)) {
                return step;
            }
            
            int i = cur.indexOf(flip(cur.charAt(0)))-1;
            if (i < 0) {
                i = cur.length()-1;
            }
            cur = flip(cur, i);            
        }
    }
    
    private static int small(String S) {
        String goal = new String(new char[S.length()]).replace('\0', '+');
        Set<String> cur = new HashSet<>();
        cur.add(new String(S));
        Set<String> done = new HashSet<>(cur);
        for (int step = 0; ; step++) {
            Set<String> nxt = new HashSet<>();
            for (String s : cur) {
                if (s.equals(goal)) {
                    return step;
                }
                
                for (int i = 0; i < s.length(); i++) {
//                for (int i = max(done.get(s)+1,0); i < s.length(); i++) { // ok to only flip later?
                    String ns = flip(s, i);
                    if (!done.contains(ns)) {
                        nxt.add(ns);
                        done.add(ns);
                    }
                }
            }
            if (nxt.isEmpty()) {
                break;
            }
            cur = nxt;
        }
        return -1;
    }
    
    private static int small2(String S) {
        String goal = new String(new char[S.length()]).replace('\0', '+');
        Set<String> cur = new HashSet<>();
        cur.add(new String(S));
//        Set<String> done = new HashSet<>(cur);
        Map<String, Integer> done = new TreeMap<>();
        done.put(S,-1);
//        <String> done = new HashSet<>(cur);
        for (int step = 0; ; step++) {
            Set<String> nxt = new HashSet<>();
            for (String s : cur) {
                if (s.equals(goal)) {
                    // backtrace
//                    System.out.println("\ngoal\t" + goal);
                    System.out.println("\nstep=" + step);
                    String k = goal;
                    int i;
                    while ((i=done.get(k))>=0) {
                        k = flip(k, i);
                        System.out.println(i+"\t" + k);
                    }
                    return step;
                }
                
//                int beg = 0;
//                int beg = max(done.get(s)+1,0); // ok
//                for (int i = beg; i < s.length(); i++) {
                {
                    int i = s.indexOf(flip(s.charAt(0)))-1;
                    if (i < 0) {
                        i = s.length()-1;
                    }
                    String ns = flip(s, i);
//                    if (!done.contains(ns)) {
                    if (!done.containsKey(ns)) {
                        nxt.add(ns);
//                        done.add(ns);
                        done.put(ns,i);
                    }
                }
            }
            if (nxt.isEmpty()) {
                break;
            }
            cur = nxt;
        }
        return -1;
    }

    // flip s[0..i]
    private static String flip(String s, int i) {
        char[] a = s.toCharArray();
        for (int j = 0; j <= i; j++) {
            a[i-j] = flip(s.charAt(j));
        }
        return new String(a);
    }

    static char flip(char c) {
        return c=='+' ? '-' : '+';
    }


    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true; // output result to file
//    static boolean writeToFile=false;

    static String[] testFilenames = new String[] {
        "B-test.in",
        "B-small-attempt0.in",
//        "B-small-practice.in",
        "B-large.in",
//        "B-large-practice.in",
//        null, // for myTest
    };

    static int THREAD=1;
//    static int THREAD=3;

    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");
    static PrintWriter out;

    /// only run given cases, {} runs all
    static int[] debugTestCases = {};
//    static int[] debugTestCases = {};

    public static void main(String[] args) throws Exception {
        // $0 inputFile caseStart caseEnd
        if (args.length>0) {
            testFilenames = args;
        }

        if (debugTestCases.length > 0) {
            System.out.println("NOTE: only run these cases: "+Arrays.toString(debugTestCases)+"\n");            
        }
        // redirect sys out
        if (redirectStdoutToFile) {
            String filename = "output.txt";
            System.out.println("NOTE: redirect stdout to file "+filename);
            FileOutputStream fos = new FileOutputStream(filename);
            PrintStream ps = new PrintStream(fos,true);
            System.setOut(ps);
        }

//        myTest();

        for (int i = 0; i < testFilenames.length; i++) {
            System.out.println((i>0?"\n\n":"") + "##### file["+i+"]: "+testFilenames[i]);
            solveFile(testFilenames[i]);
        }
    }

    static void solveFile(String testFilename) throws Exception {
        if (testFilename == null) {
            myTest();
            return;
        }

        String resultFilename=testFilename+"-res.txt";
        long start = System.currentTimeMillis();
//        in = new BufferedReader(new InputStreamReader(System.in));
        in = new BufferedReader(new FileReader(testFilename));
        int NN=INT();
        out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true)
                          : new PrintWriter(System.out, true);
        if (THREAD>1) {
            parallelSolve(NN);
        } else {
            for (int i = 1; i <= NN; i++) {
                boolean debug=debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, i)>=0;
                if (debug) {
                    printInput = true;
                }
//                out.printf("Case #%d: ", i);
                if (printInput) System.out.println("\n### Case "+i);
                new B().run(i);
                if (debug) {
                    printInput = false;
                }
            }
        }
        in.close();

        if (writeToFile) {
            out.close();
        }

        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");

        if (writeToFile) {
            boolean first = true;
            String[] suffix = new String[] {
                    "", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                    "-bad", "-bad0", "-bad1", "-bad2", "-bad3", "-bad4", "-bad5", "-bad6", "-bad7", "-bad8", "-bad9", };
            for (int i = 0; i < suffix.length; i++) {
                File ans=new File(testFilename+"-ans"+suffix[i]+".txt");
                if(ans.exists()&&ans.length()>0) {
                    boolean same=sameFileContent(ans, new File(resultFilename), first);
                    first = false;
                    if(same) {
                        System.out.println("All pass :)          Answer == "+ans);
                        break;
                    } else {
                        System.out.println("ERROR: Answer != "+ans);
                    }
                }
            }
        }
    }
    static void parallelSolve(int totalCase) throws Exception {
        int th = Math.min(THREAD, Runtime.getRuntime().availableProcessors());
        System.out.println("thread = "+th);
        ExecutorService executor = Executors.newFixedThreadPool(th);
        List<GcjSolver> solvers = new ArrayList<GcjSolver>();
        for (int i = 1; i <= totalCase; i++) {
            if (printInput) System.out.println("\n### Case "+i);

            solvers.add(new GcjSolver());
        }

        List <Future<Object>> results = executor.invokeAll(solvers);

        int caseNumber=1;
        for (Future<Object> result : results) {
            /// ! print the output
            out.printf("Case #%d: %s\n", caseNumber, result.get());
            caseNumber++;
        }
        executor.shutdown();
    }
    static class GcjSolver implements Callable<Object> {
        final int n;

        /// !! Do all input reading here
        public GcjSolver() throws IOException {
            n = INT();
            throw new RuntimeException("TODO: do reading/solving in "+getClass().getSimpleName());
        }

        /// Do no reading here! This is run async!
        /// !! Solve the actual problem here, return the result to print
        public Object call() throws Exception {
            return n;
        }
    }

    private static boolean sameFileContent(File ansFile, File resFile, boolean showInfo) throws IOException {
        if (showInfo) {
            System.out.println();
        }

        BufferedReader ans = new BufferedReader(new FileReader(ansFile));
        BufferedReader res = new BufferedReader(new FileReader(resFile));
        boolean ok=true;
        List<Integer> wrong = new ArrayList<Integer>();
        int ln=1;
        while(true) {
            String sAns=ans.readLine();
            String sRes=res.readLine();
            if(sAns==null) {
                if(sRes!=null) {
                    if (showInfo) {
                        System.out.println("### result has more lines than answer");
                        do {
                            System.out.println(sRes);
                        } while ((sRes=res.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            if(sRes==null) {
                if(sAns!=null && !sAns.isEmpty()) {
                    if (showInfo) {
                        System.out.println("### answer has more lines than result");
                        do {
                            System.out.println(sAns);
                        } while ((sAns=ans.readLine())!=null);
                        System.out.println();
                    }
                    ok=false;
                }
                break;
            }
            String tAns = sAns.trim();
            String tRes = sRes.trim();
            if(!tAns.equals(tRes)) {
                if (debugTestCases.length > 0 && tRes.endsWith(": skip")) {
                    // no compare for skip lines
                } else if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
                    if (showInfo && printDoubleCheck) {
                        System.out.println("### line "+ln+" pass double check:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }
                } else {
                    if (showInfo) {
                        System.out.println("### line "+ln+" not match:");
                        System.out.println("ans = "+sAns);
                        System.out.println("res = "+sRes);
                        System.out.println();
                    }
                    ok=false;
                    wrong.add(ln);
                }
            }
            ln++;
        }
        if(!ok && showInfo) {
            System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
            System.out.println("total : "+ln+" lines");
        }
        ans.close();
        res.close();
        return ok;
    }
    private static boolean matchDouble(String tAns, String tRes, boolean showInfo) {
        final double tol = 1e-6;

        if (!tAns.matches(".*[0-9]+\\.[0-9]+.*") || !tRes.matches(".*[0-9]+\\.[0-9]+.*")) {
            // no 123.456 pattern
            return false;
        }

        String[] sa= tAns.split(" ");
        String[] sr= tRes.split(" ");
        if (sa.length!=sr.length) {
            return false;
        }
        for (int i = 0; i < sr.length; i++) {
            if (sa[i].equals(sr[i])) continue;

            try {
                double a = Double.parseDouble(sa[i]);
                double r = Double.parseDouble(sr[i]);
                if (abs(a-r)>tol) {
                    if (showInfo) {
                        System.out.println(i+"-th ans!=res: "+sa[i]+" != "+sr[i]);
                    }
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }


    private static void myTest() throws Exception {
//        int num=-1000;
        int num=100000;
        for (int i = 1; i <= num; ++i) {
//            String s = Rn.s(Rn.i(1,100),"-+");
//            System.out.println("run "+i+": "+s+"  "+big(s));
            
////            String s = Rn.s(Rn.i(1,20),"-+");
//            String s = Rn.s(Rn.i(1,18),"-+");
//            int r1 = small(s);
////            int r2 = small2(s);
//            int r2 = big(s);
//            System.out.println("run "+i+": "+s+"  "+r1+" "+r2);
//            if (r1 != r2) {
//                System.out.println("ERROR");
//                System.exit(1);
//            }
        }
    }

    static String LINE() throws IOException {
        String s=in.readLine();
        if (printInput) System.out.println(s);
        return s;
    }
    static String STR() throws IOException {
        while (!inTok.hasMoreTokens()) {
            String line = LINE();
            if (line == null) {
                return null;
            }
            inTok = new StringTokenizer(line);
        }
        return inTok.nextToken();
    }

    static int INT() throws IOException { return Integer.parseInt(STR()); }
    static long LONG() throws IOException { return Long.parseLong(STR()); }
    static double DOUBLE() throws IOException { return Double.parseDouble(STR()); }
    
    static int INT(String s) { return Integer.parseInt(s); }
    static double DOUBLE(String s) { return Double.parseDouble(s); }
    static long LONG(String s) { return Long.parseLong(s); }
}
