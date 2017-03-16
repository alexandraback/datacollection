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
public class D {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * Output
     * 
     * For each test case, output one line containing
     * "Case #x: C1 C2 ... CN", where x is the case number (starting
     * from 1), and where Ci represents the index (starting from 1) of
     * the ith chest that you should open.
     * 
     * choose the "lexicographically smallest" way. In other words,
     * you should choose to make C1 as small as possible, and if there
     * are multiple ways of making C1 as small as possible, choose the
     * one that makes C2 as small as possible, and so on.
     * 
     * If there is no way to open all the chests, you should instead
     * output one line containing "Case #x: IMPOSSIBLE".
     */
    Map<Integer, List<Integer>> openBy;
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        CountMap<Integer> init = new CountMap<Integer>();
        openBy = new HashMap<Integer, List<Integer>>();
        
        int K = INT();
        int N = INT();
        int[] initKey = new int[K];
        for (int i = 0; i < initKey.length; i++) {
            initKey[i]=INT();
            init.add(initKey[i]);
        }

        Chest[] chest = new Chest[N];
        for (int i = 0; i < chest.length; i++) {
            int lock=INT();
            int num=INT();
            int[] a = new int[num];
            for (int j = 0; j < a.length; j++) {
                a[j]=INT();
            }
            chest[i]=new Chest(lock,a);
            add(openBy,lock,i);
        }
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        leftKeys = new CountMap[1<<chest.length];
        for (int msk = 0; msk < leftKeys.length; msk++) {
            leftKeys[msk]=new CountMap<Integer>(init);
            for (int i = 0; i < chest.length; i++) {
                if (has(msk,i)) {
                    leftKeys[msk].add(chest[i].lock,-1);
                    for (int k : chest[i].keys) {
                        leftKeys[msk].add(k,1);
                    }
                }
            }
        }
        
        if (!ok(0,chest)) {
            out.printf("Case #%d: %s\n", caseNumber, NO);
            return;
        }
        
        int[] a = new int[N];
        int msk=0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < N; j++) {
                if (!has(msk,j) && leftKeys[msk].get(chest[j].lock)>0 && ok(msk|1<<j,chest)) {
                    msk|=1<<j;
                    a[i]=j;
                    break;
                }
            }
        }
        
        out.printf("Case #%d: ", caseNumber);
        for (int i = 0; i < a.length; i++) {
            if (i>0) {
                out.print(" ");
            }
            out.print(a[i]+1);
        }
        out.println();
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    private boolean ok(int initMsk, Chest[] chest) {
        int n = chest.length;
        int ALL=(1<<n)-1;
        Set<Integer> cur = new HashSet<Integer>();
        cur.add(initMsk);
        Set<Integer> done = new HashSet<Integer>(cur);
        while (true) {
            //for (int step = 0; step < n; step++) {
            Set<Integer> nxt = new HashSet<Integer>();
            for (int msk : cur) {
                if (msk==ALL) {
                    return true;
                }
                for (int i = 0; i < n; i++) {
                    if (has(msk,i) || leftKeys[msk].get(chest[i].lock)<=0) {
                        continue; 
                    }
                    
                    int nmsk = msk|(1<<i);
                    if (!done.contains(nmsk)) { //!!! REMOVE THIS if better solution in the same round is possible
                        nxt.add(nmsk);
                        done.add(nmsk);
                    }
                }
            }
            if (nxt.isEmpty()) {
                break;
            }
            cur = nxt;
        }
        return false;
    }

    private void add(Map<Integer, List<Integer>> open, int lock, int chest) {
        if (!open.containsKey(lock)) {
            open.put(lock,new ArrayList<Integer>());
        }
        List<Integer> ls = open.get(lock);
        ls.add(chest);
    }

    class Chest {
        @Override
        public String toString() {
            return "(lock=" + lock + ", keys=" + Arrays.toString(keys) + ")";
        }

        int lock;
        int[] keys;
        
        public Chest(int lock, int[] keys) {
            super();
            this.lock = lock;
            this.keys = keys;
        }
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
    class CountMap<K> implements Iterable<K> {
        Map<K, Integer> m;
        long totalCnt = 0;

        public CountMap() {
            this(new HashMap<K, Integer>());
        }

        public CountMap(Map<K, Integer> m) {
            this.m = m;
        }

        public CountMap(CountMap<K> init) {
            this();
            for (K k : init) {
                set(k,init.get(k));
            }
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
//    static boolean printInput=false; // print input case
    
    static boolean printDoubleCheck=true;
//    static boolean printDoubleCheck=false;
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="D-test.in";
    static String testFilename="D-small-attempt0.in";
//    static String testFilename="D-small-attempt1.in";
//    static String testFilename="D-small.in";
//    static String testFilename="D-small-practice.in";
//    static String testFilename="D-large.in";
//    static String testFilename="D-large-practice.in";
    
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
    private CountMap<Integer>[] leftKeys;
    
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
                new D().run(i);
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
//            System.out.println(i+" : "+new D().small(Rn.i(0,50)));
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
