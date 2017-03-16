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
public class B {
    private static final String NO = "Too Bad";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * when a player completes a level, he or she is given a 1-star
     * rating or a 2-star rating.
     * 
     * For each level, before he can complete it with a 1-star rating,
     * he needs to have earned a certain number of stars; and he will
     * need a larger or equal number of stars to complete that level
     * with a 2-star rating.
     * 
     * return minimum number of times Ryan must complete levels in
     * order to have earned a 2-star rating on every levell. If it is
     * impossible for Ryan to earn a 2-star rating on every level, y
     * should instead be the string "Too Bad"
     * 
     * Limits 1 ≤ T ≤ 100. 0 ≤ ai ≤ bi ≤ 2001.
     * 
     * Small dataset 1 ≤ N ≤ 10.
     * 
     * Large dataset 1 ≤ N ≤ 1000.
     */
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        int n = INT();
        
        int[][] star = new int[n][2];
        for (int i = 0; i < star.length; i++) {
            for (int j = 0; j < star[i].length; j++) {
                star[i][j]=INT();
            }
        }
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        
//        int ret = 0;
        String ret = small(n, star);
        
        out.printf("Case #%d: %s\n", caseNumber, ret);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    private String small(int n, int[][] star) {
        // state: 0..n-1:star rating, n:star
        Set<State> cur = new HashSet<State>();
        cur.add(new State(new int[n+1]));
        Set<State> done = new HashSet<State>(cur);
        for (int step = 0; ; step++) {
            Set<State> nxt = new HashSet<State>();
            for (State st : cur) {
                int s=st.a[n];
                for (int i = 0; i < n; i++) {
                    if (st.a[i]==2) continue;
                    
                    for (int j = 0; j < star[i].length; j++) {
                        if (s>=star[i][j]) {
                            int earn = j+1-st.a[i];
                            int[] na = st.a.clone();
                            na[n]+=earn;
                            na[i]=j+1;
                            State nst = new State(na);
                            if (pass(nst)) {
                                return (step+1)+"";
                            }
                            //if(!nxt.contains(nst)) { //!!! REMOVE THIS if better solution in the same round is possible
                            if (!done.contains(nst)) { //!!! REMOVE THIS if better solution in the same round is possible
                                nxt.add(nst);
                                done.add(nst);
                            }
                        }
                    }
                }
            }
//            System.out.println("  cur=" + cur);
//            System.out.println("  nxt=" + nxt);
            if (nxt.isEmpty()) {
                return NO;
            }
            cur = nxt;
        }
    }

    private boolean pass(State st) {
        for (int i = 0; i < st.a.length-1; i++) {
            if (st.a[i]!=2) {
                return false;
            }
        }
        return true;
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
    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="B-test.in";
    static String testFilename="B-small-attempt0.in";
//    static String testFilename="B-small-attempt1.in";
//    static String testFilename="B-small.in";
//    static String testFilename="B-small-practice.in";
//    static String testFilename="B-large.in";
//    static String testFilename="B-large-practice.in";
    
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
                new B().run(i);
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
//            System.out.println(i+" : "+new B().small(Rn.i(0,50)));
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
