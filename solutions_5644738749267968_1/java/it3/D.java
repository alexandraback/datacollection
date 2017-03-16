import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.*;
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
public class D {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * problem
     * 
     * each player has N identical-looking blocks of wood, 0 < mass< 1 kg  
     * All of the blocks have different weights.


Limits
1 ≤ T ≤ 50.
All the masses given to Ken and Naomi are distinct, and between 0.0 and 1.0 exclusive.

Small dataset
1 ≤ N ≤ 10.

Large dataset
1 ≤ N ≤ 1000.
     */
    /*
     * solution
     * 
     * Ken's strategy: 
     * if can win: use min weight that can win
     * if cannot win: use min weight
     * 
     * tell a larger weight so Ken use its max to win
     * tell a larger weight so Ken use its min to lose
     */
    private void run(int caseNumber) throws Exception {
        int N = INT();
        double[] a1 = new double[N];
        for (int i = 0; i < N; i++) {
            a1[i] = DOUBLE();
        }
        double[] a2 = new double[N];
        for (int i = 0; i < N; i++) {
            a2[i] = DOUBLE();
        }
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
//        System.out.println("  a1[" + a1.length + "]=" + Arrays.toString(a1));
//        System.out.println("  a2[" + a2.length + "]=" + Arrays.toString(a2));
//        int[] r = small(a1, a2);
        int[] r = big(a1, a2);
        out.printf("Case #%d: %d %d\n", caseNumber, r[0], r[1]);
    }
    
    static int[] big(double[] a1, double[] a2) {
        sort(a1);
        sort(a2);
        
        TreeSet<Double> lie2 = toSet(a2);
        TreeSet<Double> war2 = new TreeSet<Double>(lie2);            
            
        Map<TreeSet<Double>, Integer> memo = new HashMap<TreeSet<Double>, Integer>();
        int war=war(a1, war2);
//        int lie=lie(0, a1, lie2, memo);
        int lie=0;
        for (int i = 0; i < a1.length; i++) {
            double min=lie2.first();
            if (a1[i]<min) {
                // lie so player2 choose max to win
                lie2.pollLast();
            } else {
                // lie so player2 choose min to lose
                lie2.pollFirst();
                lie++;
            }
        }
        return new int[] {lie, war};        
    }
    
    /*
        thread = 16
        Time taken: 117.692 sec
        
        = Observation for bestLie, bestWar 
        player1 best sequence: sorted
     */
    static int[] small(double[] a1, double[] a2) {
        sort(a1);
        sort(a2);
        
        int lie = -1;
        int war = -1;
        TreeSet<Double> s2 = toSet(a2);
        double[] bestLie=null;
        double[] bestWar=null;
        // permutation
        do {
            TreeSet<Double> war2 = new TreeSet<Double>(s2);            
            TreeSet<Double> lie2 = new TreeSet<Double>(s2);            
            
            Map<TreeSet<Double>, Integer> memo = new HashMap<TreeSet<Double>, Integer>();
            int vLie=lie(0, a1, lie2, memo);
            int vWar=war(a1, war2);
            if (lie < vLie) {
                lie = vLie;
                bestLie = a1.clone();
            }
            if (war < vWar) {
                war = vWar;
                bestWar = a1.clone();
            }
        } while (nextPermutation(a1));
        
        sort(a1);
        System.out.println("  bestLie[" + bestLie.length + "]=" + Arrays.toString(bestLie));
        System.out.println("  bestWar[" + bestWar.length + "]=" + Arrays.toString(bestWar));
        System.out.println("       a1[" + a1.length + "]=" + Arrays.toString(a1));
        System.out.println("       a2[" + a2.length + "]=" + Arrays.toString(a2));
        System.out.println();        
        if (!Arrays.equals(a1,bestLie)) {
            System.out.println("ERROR: best lie not sort");
            System.exit(1);
        }
        if (!Arrays.equals(a1,bestWar)) {
            System.out.println("ERROR: best war not sort");
            System.exit(1);
        }
        
        return new int[] {lie, war};
    }

    static TreeSet<Double> toSet(double[] a2) {
        TreeSet<Double> war2 = new TreeSet<Double>();
        for (int i = 0; i < a2.length; i++) {
            war2.add(a2[i]);
        }
        return war2;
    }

    private static int war(double[] a1, TreeSet<Double> set2) {
        int score1=0;
        for (int i = 0; i < a1.length; i++) {
            Double p2=set2.higher(a1[i]);
            if (p2==null) {
                set2.pollFirst();
                score1++;
            } else {
                set2.remove(p2);
            }
        }
        return score1;
    }
    private static int lie(int i, double[] a1, TreeSet<Double> set2, Map<TreeSet<Double>, Integer> memo) {
        if (i==a1.length) {
            return 0;
        }
        
        if (memo.containsKey(set2)) {
            return memo.get(set2);
        }
        
        int score1;
        double max=set2.last();
        TreeSet<Double> nset; 
        if (a1[i]>max) {
            nset = new TreeSet<Double>(set2);
            nset.pollFirst();
            score1 = 1+lie(i+1, a1, nset, memo);
        } else {
            // lie so player2 choose max to win
            nset = new TreeSet<Double>(set2);
            nset.pollLast();
            score1 = lie(i+1, a1, nset, memo);
            
            // lie so player2 choose min to lose
            double min=set2.first();
            if (a1[i]>min) {                
                nset = new TreeSet<Double>(set2);
                nset.pollFirst();
                int v = 1+lie(i+1, a1, nset, memo);
                if (v>score1) {
                    score1=v;
                }
            }
        }
        memo.put(set2, score1);
        return score1;
    }
    public static boolean nextPermutation(double[] a) {
        for (int i = a.length - 2; i >= 0; i--) {
            if (a[i + 1] > a[i]) {
                int j;
                for (j = a.length - 1; a[j] <= a[i]; j--)
                    ;
                swap(a, i, j);
                for (j = 1; j <= (a.length - i) / 2; j++)
                    swap(a, i + j, a.length - j);
                return true;
            }
        }
        return false;
    }

    public static void swap(double a[], int i, int j) {
        double temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    static boolean printInput=false;
//    static boolean printInput=false; // print input case
    
    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="D-test.in";
//    static String testFilename="D-small-attempt0.in";
//    static String testFilename="D-small-attempt1.in";
//    static String testFilename="D-small.in";
//    static String testFilename="D-small-practice.in";
    static String testFilename="D-large.in";
//    static String testFilename="D-large-practice.in";
    
    static int THREAD=1;
//    static int THREAD=3;
//    static int THREAD=4;
    
    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");

//    static Scanner in;
    static PrintWriter out;

    //control the cases to run : [caseStart..csaeEnd]
    static int caseStart=1;
//    static int caseStart=1;
    static int caseEnd=Integer.MAX_VALUE;
//    static int caseEnd=caseStart+0;
    
    public static void main(String[] args) throws Exception {
        String resultFilename=testFilename+"-res.txt";
        long start = System.currentTimeMillis();

//        myTest();
        
        // $0 inputFile caseStart caseEnd
        if(args.length>0) {
            testFilename = args[0];
        }
        if(args.length>1) {
            caseStart=parseInt(args[0]);
        }
        if(args.length>2) {
            caseEnd=parseInt(args[1]);
        }
        
        // redirect sys out
        if(redirectStdoutToFile) {            
            String filename = "output.txt";
            System.out.println("NOTE: redirect stdout to file "+filename);
            FileOutputStream fos = new FileOutputStream(filename);
            PrintStream ps = new PrintStream(fos,true);
            System.setOut(ps);
        }
        
        if(testFilename==null) {
            myTest();
        } else {
//          in = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new FileReader(testFilename));
            int NN=INT();
//            in = new Scanner(System.in);
//            in = new Scanner(new File(testFilename));
//            int NN=in.nextInt();
            out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true) 
                              : new PrintWriter(System.out, true);
            if (THREAD>1) {                
                parallelSolve(NN);            
            } else {                
                for (int i = 1; i <= NN; i++) {
//                    out.printf("Case #%d: ", i);
                    if (printInput) System.out.println("\n### Case "+i);                
                    new D().run(i);
                }
            }
            in.close();
            
            if(writeToFile) {
                out.close();
            }
        }
        
        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
        
        if(writeToFile) {
            File ans=new File(testFilename+"-ans.txt");
            if(ans.exists()&&ans.length()>0) {
                boolean same=sameFileContent(ans, new File(resultFilename), true);
                if(same) {
                    System.out.println("Answer correct :)");
                    System.out.println("Answer match file "+ans);
                } else {
                    System.out.println("ERROR : Answer not matched");
                    
                    // check other possible answer file
                    for (int i = 1; i < 9; i++) {
                        ans=new File(testFilename+"-ans"+i+".txt");
                        if (ans.exists() && ans.length()>0) {                            
                            same=sameFileContent(ans, new File(resultFilename), false);
                            if (same) {
                                System.out.println("\nAnswer correct :)");
                                System.out.println("Answer match file "+ans);
                                break;
                            }
                        }
                    }
                }
            }            
        }
    }
    static void parallelSolve(int totalCase) throws Exception {
        int th = Math.min(THREAD, Runtime.getRuntime().availableProcessors());
        System.out.println("thread = "+th);
        ExecutorService executor = Executors.newFixedThreadPool(th);
        List<Solver> solvers = new ArrayList<Solver>();
        for (int i = 1; i <= totalCase; i++) {
            if (printInput) System.out.println("\n### Case "+i);

            solvers.add(new Solver());
        }

        List <Future<Object>> results = executor.invokeAll(solvers);
            
        int caseNumber=1;
        for (Future<Object> result : results) {
            out.printf("Case #%d: %s\n", caseNumber, result.get());
            caseNumber++;
        }
        executor.shutdown();
    }
    static class Solver implements Callable<Object> {
        final int N;
        final double[] a1;
        final double[] a2;

        // Do all input reading here!!
        public Solver() throws IOException {
            N = INT();
            a1 = new double[N];
            for (int i = 0; i < N; i++) {
                a1[i] = DOUBLE();
            }
            a2 = new double[N];
            for (int i = 0; i < N; i++) {
                a2[i] = DOUBLE();
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public Object call() throws Exception {
            int[] r=small(a1, a2);
            return r[0]+" "+r[1];
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
                if (matchDouble(tAns,tRes, showInfo && printDoubleCheck)) {
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
//        int num=1000;
//        boolean check=true;
//        int maxLen = 10;
        int num=1000000;
        boolean check=false;
        int maxLen = 1000;
        
//        for (int i = 1; i <= num; ++i) {
//            double[] all=Rn.uniq(Rn.da(Rn.i(3,2*maxLen), 0.00001, 1));
//            int len=all.length/2;
//            if (len==0) continue; 
//            
//            all = Rn.shuffle(all);
//            double[] a1 = new double[len];
//            double[] a2 = new double[len];
//            for (int j = 0; j < a1.length; j++) {
//                a1[j]=all[2*j];
//                a2[j]=all[2*j+1];
//            }
////            System.out.println("  a1[" + a1.length + "]=" + Arrays.toString(a1));
////            System.out.println("  a2[" + a2.length + "]=" + Arrays.toString(a2));
//            int[] r1=big(a1,a2);
//            if (check && len<=10) {
//                int[] r2=small(a1,a2);
//                if (!Arrays.equals(r1,r2)) {
//                    System.out.println("big fail");
//                    System.exit(1);
//                }
//            }
//            System.out.println(i+" : "+r1[0]+" "+r1[1]);
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
