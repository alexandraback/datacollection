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

import java.awt.geom.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.*;
import java.util.stream.*;

import org.netlib.util.booleanW;

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
     * 
     */
    private void run(int caseNumber) throws Exception {
        String c = STR();
        String j = STR();
        
        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
            return;
        }

        
        /// start solving problem
//        String[] res = small(c, j);
        String[] res = big(c, j);
//        String[] res = greedy(c, j);
        out.printf("Case #%d: %s %s\n", caseNumber, res[0], res[1]);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    static private String[] big(String s0, String s1) {
        int n = s0.length();
        String[] res = new String[2];
//        Set<XY> cur = new HashSet<>();
        XY[] cur = new XY[3];
        XY init = new XY(0,0);
//        cur.add(init);
        cur[0] = init;
        for (int i = 0; i < n; i++) {
            long d0=Long.MAX_VALUE, d1=-Long.MAX_VALUE;
            XY ans0 = null; // v0>v1
            XY ans1 = null; // v0<v1
            XY ans2 = null; // v0=v1
//            Set<XY> nxt = new HashSet<>();
//            XY nxt[] = new HashSet<>();
            for (XY xy : cur) {
                if (xy==null) continue;
                
                int beg0, end0, beg1, end1;
                if (s0.charAt(i)=='?') {
                    beg0 = 0;
                    end0 = 9;
                } else{
                    beg0 = end0 = s0.charAt(i)-'0';
                }
                if (s1.charAt(i)=='?') {
                    beg1 = 0;
                    end1 = 9;
                } else{
                    beg1 = end1 = s1.charAt(i)-'0';
                }
                for (int v0 = beg0; v0 <= end0; v0++) {
                    for (int v1 = beg1; v1 <= end1; v1++) {
                        long nx = xy.x*10+v0;
                        long ny = xy.y*10+v1;
                        XY nxy = new XY(nx, ny);
                        long nd = nx-ny;
                        if (nd > 0) {
                            if (nd < d0) {
                                d0 = nd;
                                ans0 = nxy;
                            } else if (nd==d0) {
                                if (nxy.x < ans0.x) {
                                    ans0 = nxy;
                                } else if (nxy.x == ans0.x && nxy.y < ans0.y) {
                                    ans0 = nxy;                                    
                                }
                            }
                        } else if (nd < 0) {
                            if (nd > d1) {
                                d1 = nd;
                                ans1 = nxy;
                            } else if (nd==d1) {
                                if (nxy.x < ans1.x) {
                                    ans1 = nxy;
                                } else if (nxy.x == ans1.x && nxy.y < ans1.y) {
                                    ans1 = nxy;                                    
                                }
                            }                            
                        } else { // nd==0
                            if (better(nxy, ans2)) {
                                ans2 = nxy;
                            }
                        }
                    }
                }
            }
//            if (ans0!=null) {
//                nxt.add(ans0);
//            }
//            if (ans1!=null) {
//                nxt.add(ans1);
//            }
//            if (nxt.isEmpty()) {
//                break;
//            }
//            cur = nxt;
            cur = new XY[] {ans0, ans1, ans2};
//            System.out.println("  cur=" + cur);
//            System.out.println("  cur[" + cur.length + "]=" + Arrays.toString(cur));
        }
        XY best = null;
        for (int i = 0; i < cur.length; i++) {
            if (better(cur[i], best)) {                
                best = cur[i];
            }
        }
//        if (better(cur[1],best)) {
//            best = cur[1];
//        }
        res[0] = str(best.x, n);
        res[1] = str(best.y, n);
        return res;
    }
    
    private static String str(long x, int n) {
        String r = Long.toString(x);
        while (r.length()<n) {
            r = "0"+r;
        }
        return r;
    }

    private static boolean better(XY xy1, XY xy2) {
        if (xy1 == null) {            
            return false;
        }
        if (xy2 == null) {            
            return true;
        }
        long d1 = abs(xy1.x-xy1.y);
        long d2 = abs(xy2.x-xy2.y);
        if (d1 < d2) {
            return true;
        }
        if (d1 == d2) {
            if (xy1.x < xy2.x) {
                return true;
            }
            if (xy1.x == xy2.x && xy1.y < xy2.y) {
                return true;
            }
        }
        return false;
    }

    static class XY implements Comparable<XY> {
        long x;
        long y;

        public XY(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int hashCode() {
            final long M = 31;
            long r = M * M + M * x + y;
            return (int) r;
        }

        public boolean equals(Object a) {
            if (a == null || getClass() != a.getClass())
                return false;
            XY o = (XY) a;
            return x == o.x && y == o.y;
        }

        public int compareTo(XY o) {
            // < : -1 smallest 1st
            if (x != o.x)
                return x < o.x ? -1 : 1;
            return y < o.y ? -1 : (y == o.y ? 0 : 1);
        }
    }
    
    // xx
    private String[] greedy(String s0, String s1) {
        String[] res = new String[2];
        char[][] a = new char[2][];
        a[0] = s0.toCharArray();
        a[1] = s1.toCharArray();
        long diff = 0;
        for (int i = 0; i < s0.length(); i++) {
            char c0 = s0.charAt(i);
            char c1 = s1.charAt(i);
            if (diff==0) {
                if (c0 == '?' && c1 == '?') {
                    a[0][i] = a[1][i] = '0';
                } else if (c0 == '?') {
                    a[0][i] = c1;
                } else if (c1 == '?') {
                    a[1][i] = c0;                    
                } else {
                    diff = 10*diff+(c0-c1);
                }
            }
        }
        return res;
    }

    static String[] small(String c, String j) {
        List<String> cs = new ArrayList<>();
        gen(0, new char[c.length()], c.toCharArray(), cs);
        List<String> js = new ArrayList<>();
        gen(0, new char[j.length()], j.toCharArray(), js);
        int d = INF, r1=0, r2=0;
        String[] res = new String[2];
        for (String s1 : cs) {
            int v1 = Integer.valueOf(s1); 
            for (String s2 : js) {
                int v2 = Integer.valueOf(s2); 
                int nd = abs(v1-v2);
                if (nd < d) {
                    d = nd;
                    r1 = v1;
                    r2 = v2;
                    res[0] = s1;
                    res[1] = s2;
                } else if (nd==d) {
                    if (v1 < r1) {
                        r1 = v1;
                        r2 = v2;
                        res[0] = s1;
                        res[1] = s2;
                    } else if (v1==r1 && v2 < r2) {
                        r1 = v1;
                        r2 = v2;
                        res[0] = s1;
                        res[1] = s2;
                    }
                }
            }
        }
        return res;
    }
    
    static private void gen(int i, char[] a, char[] str, List<String> ls) {
        if (i==a.length) {
            ls.add(new String(a));
            return;
        }
        if (str[i]=='?') {
            for (char j = '0'; j <= '9'; j++) {
                a[i] = j;
                gen(i+1, a, str, ls);
            }
            a[i] = '?';
        } else {
            a[i] = str[i];
            gen(i+1, a, str, ls);
        }
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
//        "B-small-attempt1.in",
//        "B-small.in",
//        "B-small-practice.in",
        "B-large.in",
//        "B-large-practice.in",
//        null, // for myTest()
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
        int num=10000;
//        for (int i = 1; i <= num; ++i) {
//            int n=Rn.i(1,9);
//            String s1 = Rn.s(n, "?0123456789");
//            String s2 = Rn.s(n, "?0123456789");
//            String[] ans = small(s1,s2);
//            String[] res = big(s1,s2);
//            System.out.println("run " + i + ": " + s1+" "+s2);
//            if (!Arrays.equals(ans,res)) {
//                System.out.println("Wrong");
//                System.out.println("  ans[" + ans.length + "]=" + Arrays.toString(ans));
//                System.out.println("  res[" + res.length + "]=" + Arrays.toString(res));
//                System.exit(1);
//            }
//        }
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
