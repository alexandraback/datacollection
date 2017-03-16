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
     *
Limits
1 ≤ T ≤ 100.
1 ≤ ai, bi ≤ 1e16.
1 ≤ Ai, Bi ≤ 100.

Small dataset
1 ≤ N ≤ 3.
1 ≤ M ≤ 100.

Large dataset
1 ≤ N, M ≤ 100.
     */
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        int n = INT();
        int m = INT();
        int T=0;
        
        long[] ca = new long[n];
        int[] ta = new int[n];
        Set<Integer> type = new HashSet<Integer>();
        for (int i = 0; i < ca.length; i++) {
            ca[i] = LONG();
            ta[i] = INT();
            T = Math.max(T, ta[i]);
            type.add(ta[i]);
        }
        long[] cb = new long[m];
        int[] tb = new int[m];
        
        int nm=0;
        for (int i = 0; i < cb.length; i++) {
            cb[i] = LONG();
            tb[i] = INT();
            if (type.contains(tb[i])) {
                nm++;
            }
//            T = Math.max(T, tb[i]);
        }
        m=nm;
        long[] ncb = new long[m];
        int[] ntb = new int[m];
        nm=0;
        for (int i = 0; i < tb.length; i++) {
            if(type.contains(tb[i])) {
                ncb[nm]=cb[i];
                ntb[nm]=tb[i];
                nm++;
            }
        }
        cb=ncb;
        tb=ntb;
        
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        // b[i,j,t]
        T++;
        long[][][] b = new long[m][m][T];
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                for (int j2 = i; j2 <= j; j2++) {
                    b[i][j][tb[j2]]+=cb[j2];
                }
            }
        }
//        Map<State,Long> done = new HashMap<State,Long>();
        Map<State,Long> cur = new HashMap<State,Long>();
//        Set<State> cur = new HashSet<State>();
        State init=new State(-1, 0, 0);
//        cur.add(init);
//        done.put( init, new Long(0));
        cur.put( init, new Long(0));
        for (int i = 0; i < n; i++) {            
//        while(true) {
//            Set<State> next = new HashSet<State>();
//            Map<State,Long> next = new HashMap<State,Long>();
            Map<State,Long> next = new TreeMap<State,Long>();
//            for (State st : cur) {
            for (State st : cur.keySet()) {
//                long got=done.get(st);
                long got=cur.get(st);
                for (int j = st.i; j < m; j++) {
                    long has=ca[i];
                    long prevCnt = st.cnt;
                    long match=0;
                    if (st.t==ta[i]) {
                        long take = min(has, prevCnt);
                        match += take;
                        has -= take;
                        prevCnt -= take;
                    }
                    long[] tCnt = st.i==j?new long[T]:b[st.i+1][j].clone();
                    tCnt[st.t] += prevCnt;
                    for (int t = 0; t < tCnt.length; t++) {
                        if (t!=0 && tCnt[t]==0) continue;
                        
                        long nv=got+match;
                        if(ta[i]==t) {
                            long take = min(has, tCnt[t]);
                            nv += take;
                            has -= take;
                            tCnt[t] -= take;
                        }
                        State nst=new State(j, t, tCnt[t]);
//                        nst.t = t;
//                        nst.cnt = tCnt[t];
//                        if(!done.containsKey(nst) || done.get(nst)<nv) { // want max, if not done OR new solution is better
//                        if(!next.contains(nst) || (done.containsKey(nst) && done.get(nst)<nv)) { // want max, if not done OR new solution is better
                        if(!next.containsKey(nst) || next.get(nst)<nv) { // want max, if not done OR new solution is better
//                          if(!done.containsKey(nst)||done.get(nst)>nv)) { // want min, if not done OR new solution is better
//                              next.add(nst);
//                              done.put(nst,nv);
                              next.put(nst,nv);
                        } 
                    }
//                    for (int k = st.i+1; k <= j; k++) {
//                        if (tb[k]==ta[i]) {
//                            nst.cnt += tb[k];
//                            long take = min(has, cb[k]);
//                            match += take;
//                            has -= take;
//                            nst.cnt -= take;
//                        }
//                    }
//                    State nst=new State(j, , );
                    //if(!next.contains(nst)) { //!!! REMOVE THIS if use dp to check better position
                }
            }
            if(next.isEmpty()){
                break;
            }
            cur=next;
//            System.out.println("  next=" + next);
//            System.out.println("  next.size()=" + next.size());
        }
//        System.out.println("  done=" + done);
        long ret = 0;
//        for (long v : done.values()) {
        for (long v : cur.values()) {
            ret = Math.max(ret, v);
        }
        
        out.printf("Case #%d: %s\n", caseNumber, ret);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    static class State implements Comparable<State> {
        int i;
        int t;
        long cnt;

        public State(int x, int y, long z) {
            this.i = x;
            this.t = y;
            this.cnt = z;
        }

        public String toString() {
            return "(" + i + "," + t + "," + cnt + ")";
        }

        public int hashCode() {
            final int M = 31;
            int r = 1;
            r = (int) (M * r + i);
            r = (int) (M * r + t);
            r = (int) (M * r + cnt);
            return r;
        }

        public boolean equals(Object obj) {
            if (obj == null || getClass() != obj.getClass())
                return false;
            State other = (State) obj;
            return i == other.i && t == other.t && cnt == other.cnt;
        }

        public int compareTo(State o) {
            if (i == o.i) {
                if (t == o.t) {
                    // < : -1 smallest 1st
                    // > : -1 biggest 1st
                    return cnt < o.cnt ? -1 : (cnt == o.cnt ? 0 : 1);
                } else {
                    return t < o.t ? -1 : 1;
                }
            } else {
                return i < o.i ? -1 : 1;
            }
        }
    }
    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="C-test.in";
//    static String testFilename="C-small-attempt0.in";
    static String testFilename="C-small-attempt1.in";
//    static String testFilename="C-small.in";
//    static String testFilename="C-small-practice.in";
//    static String testFilename="C-large.in";
//    static String testFilename="C-large-practice.in";
    
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
                boolean same=sameFileContent(ans,new File(resultFilename));
                if(same) {
                    System.out.println("Answer correct :)");
                } else {
                    System.out.println("ERROR : Answer not matched");
                }
            }            
        }
    }
    
    private static boolean sameFileContent(File ansFile, File resFile) throws IOException {
        System.out.println();
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
                    System.out.println("### result has more lines than answer");
                    do {
                        System.out.println(sRes);
                    } while ((sRes=res.readLine())!=null);
                    System.out.println();
                    ok=false;
                }
                break;
            }
            if(sRes==null) {
                if(sAns!=null && !sAns.isEmpty()) {
                    System.out.println("### answer has more lines than result");
                    do {
                        System.out.println(sAns);
                    } while ((sAns=ans.readLine())!=null);
                    System.out.println();
                    ok=false;
                }
                break;
            }
//            if(!sAns.equals(sRes)) {
            if(!sAns.trim().equals(sRes.trim())) {
                System.out.println("### line "+ln+" not match:");
                System.out.println("ans = "+sAns);
                System.out.println("res = "+sRes);
                System.out.println();
                ok=false;
                wrong.add(ln);
            }
            ln++;
        }
        if(!ok) {
            System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
            System.out.println("total : "+ln+" lines");
        }
        ans.close();
        res.close();
        return ok;
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
