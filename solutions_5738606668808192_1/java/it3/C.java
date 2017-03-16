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
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.awt.geom.*;
import java.io.*;

//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class C {
//    static int[] ps = primes(1<<16);
    static int[] ps = primes(100000000);
    
    /*
     * problem
     * 
     * 
     */
    /*
     * solution
     * 

##### file[2]: C-large.in
Time taken: 137.426 sec 

verify (x:xs) = all ok $ zip [2..] divs
  where divs = map read xs
        ok (b, d) = str2int b x `mod` d == 0

(all verify . map words . tail . lines) <$> readFile "C-large.in-ans.txt"

     */
    private void run(int caseNumber) throws Exception {
        int N = INT();
        int J = INT();
        
        /// reading input done
        if(debugTestCases.length>0 && Arrays.binarySearch(debugTestCases, caseNumber)<0) {
            if(writeToFile) {
                out.printf("Case #%d: skip\n", caseNumber);
            }
//            System.out.println("----- skip case "+caseNumber+" -----");
            return;
        }

        
        /// start solving problem
        out.printf("Case #%d:\n", caseNumber);
//        char[] cur = new char[N];
        int[] cur = new int[N];
        cur[0] = cur[N-1] = 1;
//        String[] r = new String[J];
        List<String> r = new ArrayList<>();
        gen(1, cur, r, J);
        for (String s : r) {
            out.println(s);
        }
//        String ret = "";
//        out.printf("Case #%d: %s\n", caseNumber, ret);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    private static boolean gen(int i, int[] cur, List<String> ls, int num) {
        if (i==cur.length-1) { // cur[N-1] must be 1
            boolean ok = true;
            int[] div = new int[9];
            for (int b = 2; b <= 10; b++) {
//                div[b-2] = div(cur, b);
                div[b-2] = div2(cur, b);
                if (div[b-2] < 0) {
                    ok = false;
                    break;
                }
            }
//            if (ok) {
            if (ok) {
                if (!pass(cur, div)) {
                    System.out.println("bad");
                    System.exit(1);
                }
                String s = IntStream.of(cur).mapToObj(String::valueOf).collect(Collectors.joining(""));
                ls.add(IntStream.of(div).mapToObj(String::valueOf).collect(Collectors.joining(" ", s+" ", "")));
                if (ls.size() == num) {
                    return true;
                }
            }
            return false;
        }
        
//        for (char j = '0'; j <= '1'; j++) {
        for (int j = 0; j <= 1; j++) {
            cur[i] = j;
            if (gen(i+1, cur, ls, num)) {
                return true;
            }
        }
        return false;
    }

    private static boolean pass(int[] cur, int[] div) {
        for (int i = 0; i < div.length; i++) {
            // TODO avoid d==cur
            int d = div[i];
            if (d <= 1) {
                return false;
            }
            int b = i+2;
            int rem = 0;
            for (int x : cur) {
                rem = (rem*b+x)%d;
            }
            if (rem!=0) {
                System.out.println("bad at b="+b+" div="+d);
                System.out.println("  cur[" + cur.length + "]=" + Arrays.toString(cur));
                return false;
            }
        }
        return true;
    }

    static int div(int[] cur, int b) {
        long v = val(cur, b);
//        long bnd = round(sqrt(v));
//        long bnd = Long.MAX_VALUE;
        long bnd = v-1; // p < cur in base b
        for (int p : ps) {
            if (p > bnd) {
                break;
            }
            if (mod(cur, b, p) == 0) {                
//            if (v % p == 0) {                
                return p;
            }
        }
        return -1;
    }

    // return (cur in base b)%d
    static int mod(int[] cur, int b, int d) {
        int rem = 0;
        for (int x : cur) {
            rem = (rem*b+x)%d;
        }
        return rem;
    }
    
    static int div2(int[] cur, int b) {
        BigInteger v = val2(cur, b);
        if (v.isProbablePrime(100)) {
            return -1;
        }
//        long bnd = round(sqrt(v));
        for (int p : ps) {
//            if (p > bnd) {
//                break;
//            }
            if (mod(cur, b, p) == 0) {                
                return p;
            }
        }
        return -1;
    }
    
    private static BigInteger val2(int[] cur, int b) {
        BigInteger r = BigInteger.ZERO;
        BigInteger bb = BigInteger.valueOf(b);
//        for (int i = cur.length-1; i>=0; i--) {
        for (int i = 0; i < cur.length; i++) {
            r = r.multiply(bb).add(BigInteger.valueOf(cur[i]));
        }
        return r;
    }
    private static long val(int[] cur, int b) {
        long r = 0;
//        for (int i = cur.length-1; i>=0; i--) {
        for (int i = 0; i < cur.length; i++) {
            r = r*b+cur[i];
        }
        return r;
    }

    private static int div(long v) {
        long bnd = round(sqrt(v));
        for (int p : ps) {
            if (p > bnd) {
                break;
            }
            if (v % p == 0) {                
                return p;
            }
        }
        return -1;
    }
    static String[] bf(int n, int cnt) {
        String[] res = new String[cnt];
        int idx = 0;
        while (idx < res.length) {
            if (true) {
                idx++;
            }
        }
        for (int i = 0; i < res.length; i++) {
            res[i] = ""+i;
        }
        return res;
    }

    /**
     * 
     * @param n
     * @return array of primes <= n
     */
    public static int[] primes(int n) {
        List<Integer> ls = new ArrayList<Integer>();
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[1] = false;
        int m = (int) Math.sqrt(n);

        for (int i = 2; i <= m; i++) {
            if (isPrime[i]) {
                for (int k = i * i; k <= n; k += i) {
                    isPrime[k] = false;
                }
            }
        }

        for (int i = 2; i < isPrime.length; ++i) {
            if (isPrime[i])
                ls.add(i);
        }

        int[] a = new int[ls.size()];
        int listIdx = 0;
        for (int x : ls) {
            a[listIdx++] = x;
        }
        return a;
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
        "C-test.in",
        "C-small-attempt0.in",
//        "C-small-attempt1.in",
//        "C-small-practice.in",
        "C-large.in",
//        "C-large-practice.in",
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
                new C().run(i);
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
//            System.out.println(i+" : "+new C().small(Rn.i(0,50)));
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
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
