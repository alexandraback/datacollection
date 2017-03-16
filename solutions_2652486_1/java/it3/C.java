import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.*;
import static java.lang.Long.parseLong;
import java.util.*;
import java.awt.geom.*;
import java.io.*;

//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class C {
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
     * (M-1)^N
     * 7^12 = 13841287201 ~ 1e10
     * 
     * small-1
     *   cnt.size()=10
     *   
     * small-2
     *   cnt.size()=18564  
     */
    int N,M,K;
    private void run(int caseNumber) throws Exception {
        int R = INT();
        N = INT();
        M = INT();
        K = INT();
                
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        /// start solving problem
        out.printf("Case #%d:\n", caseNumber);
        
        int[] a = new int[N];
        int maxP=1;
        for (int i = 0; i < N; i++) {
            maxP+=M;
        }
        prob = new CountMap[maxP+1];
        gen(a,0);
        System.out.println("  cnt.size()=" + cnt.size());
        
        for (int i = 0; i < R; i++) {
            long[] p = new long[K];
            for (int j = 0; j < p.length; j++) {
                p[j] = LONG();
            }
            int[] ret = small(p);
            for (int j = 0; j < ret.length; j++) {
                out.print(ret[j]);
            }
            out.println();
        }
    }

    CountMap<State>[] prob;
    Map<State, CountMap<Long>> cnt = new HashMap<State, CountMap<Long>>();
    private void gen(int[] a, int i) {
        if (i==a.length) {
            CountMap<Long> cm=new CountMap<Long>();
            cnt.put(new State(a.clone()),cm);
            for (int msk = 0; msk < 1<<a.length; msk++) {
                long p=1;
                for (int j = 0; j < a.length; j++) {
                    if (has(msk,j)) {
                        p*=a[j];
                    }
                }
                cm.add(p);
            }
            return;
        }
        for (int j = (i==0)?2:a[i-1]; j <= M; j++) {
            a[i]=j;
            gen(a,i+1);
        }
    }

    double perm(long[] a) {
        double ret=N==4?6:479001600;// 12!
        CountMap<Long> c=new CountMap<Long>();
        for (int i = 0; i < a.length; i++) {
            c.add(a[i]);
        }
        for (long x : c) {
            int num=c.get(x);
            for (int i = 2; i <= num; i++) {
                ret/=i;
            }
        }
        return ret;
    }
    private int[] small(long[] prod) {
        double prob=-1;
        State best=null;
        for (State st : cnt.keySet()) {
            CountMap<Long> cm=cnt.get(st);
            double p=1;
            for (int i = 0; i < prod.length; i++) {
                if (!cm.containsKey(prod[i])) {
                    p=0;
                    break;
                }
                p*=cm.get(prod[i]);
            }
            p*=perm(prod);
            if (p>prob) {
                prob=p;
                best=st;
            }
        }
        return best.a;
    }

    // keep only the lowest bit
    static int lowest(int mask) {
        return (mask & -mask);
    }

    // i-th bit is set
    static boolean has(int mask, int i) {
        return (mask & (1 << i)) != 0;
    }

    // set i-th bit to v
    static int set(int mask, int i, boolean v) {
        return v ? set(mask, i) : unset(mask, i);
    }

    // set i-th bit
    static int set(int mask, int i) {
        return mask | (1 << i);
    }

    // unset i-th bit
    static int unset(int mask, int i) {
        return mask & ~(1 << i);
    }

    // mask set contains subset
    static boolean contain(int set, int subset) {
        return (set & subset) == subset;
    }
    class State implements Comparable<State> {
            int[] a;
            
            public State(int[] a) {
                super();
                this.a = a;
                //Arrays.sort(a); // normalize
            }
            
            public boolean equals(Object obj) {	    
                State o = (State) obj;
                return Arrays.equals(a,o.a);
            }
            
            public int hashCode() {
                return Arrays.hashCode(a);
            }
            
            public String toString() {
                return Arrays.toString(a);
            }
            public int compareTo(State o) {
                return compare(a, o.a); // min first
                //return -compare(a, o.a); // max first
            }
            
            private int compare(int[] a1, int[] a2) {
                int n=Math.min(a1.length,a2.length);
                for (int i = 0; i < n; i++) {
                    if(a1[i]<a2[i]) {
                        return -1;
                    }
                    if(a1[i]>a2[i]) {
                        return 1;
                    }
                }
                return a1.length-a2.length;
            }
        }
    class CountMap<K> implements Iterable<K> {
        Map<K, Integer> m;
        long totalCnt = 0;

        public CountMap() {
            this(new HashMap<K, Integer>());
        }

        public CountMap(Map<K, Integer> m) {
            this.m = m;
        }

        public boolean containsKey(K key) {
            return m.containsKey(key);
        }

        public void add(K key) {
            add(key, 1);
        }

        public void add(K key, int v) {
            set(key, get(key) + v);
        }

        public void set(K key, int v) {
            //v %= MOD;
            if (v == 0) { // remove key if v=0
                remove(key);
                return;
            }

            totalCnt += v - get(key);
            m.put(key, v);
        }

        public int remove(K key) {
            if (!containsKey(key))
                return 0;
            int v = m.remove(key);
            totalCnt -= v;
            return v;
        }

        public int get(K key) {
            return m.containsKey(key) ? m.get(key) : 0;
        }

        public int size() {
            return m.size();
        }

        public Iterator<K> iterator() {
            return m.keySet().iterator();
        }

        public String toString() {
            StringBuffer sb = new StringBuffer();
            // sb.append("## size: "+m.size()+"\n");
            int i = 0;
            for (K e : m.keySet()) {
                // sb.append(e+": "+m.get(e)+"\n");
                sb.append("(" + e + "," + m.get(e) + "), ");
                i++;
                if (i == 10) {
                    sb.append("\n");
                    i = 0;
                }
            }
            return sb.toString();
        }
    }

    static boolean printInput=false;
//    static boolean printInput=true; // print input case

    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="C-test.in";
//    static String testFilename="C-small-1-attempt0.in";
//    static String testFilename="C-small-2-attempt0.in";
//    static String testFilename="C-small-2-attempt1.in";
    static String testFilename="C-small-2-attempt2.in";
//    static String testFilename="C-small.in";
//    static String testFilename="C-small-practice.in";
    
    static String resultFilename=testFilename+"-res.txt";
    
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
            for (int i = 1; i <= NN; i++) {
//                out.printf("Case #%d: ", i);
                if (printInput) System.out.println("\n### Case "+i);                
                new C().run(i);
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
        int num=1000;
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
