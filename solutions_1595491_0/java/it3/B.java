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
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;
    
    static int[] best = new int[31];
    static int[] bestSurprise = new int[31];
    static {
        fill(best,-1);
        fill(bestSurprise,-1);
        for (int a1 = 0; a1 <= 10; ++a1) {
            for (int a2 = a1; a2 <= 10 && a2<=a1+2; ++a2) {
                for (int a3 = a2; a3 <= 10 && a3<=a1+2; ++a3) {
                    if (a3-a1==2) {
                        bestSurprise[a1+a2+a3] = Math.max(bestSurprise[a1+a2+a3], a3);
                    } else {
                        best[a1+a2+a3] = Math.max(best[a1+a2+a3], a3);                        
                    }
                }
            }
        }
    }

    /*
     * each dancer is given a triplet of scores by three judges
     * Each triplet of scores consists of three integer scores = [0..10]
     * 
     * C(3,2) max diff<=2, surprising if max diff=2
     * it's surprising if a triplet of scores contains two scores that are 2 apart.  
     * No triplet of scores contains scores that are more than 2 apart. 
     * 
     * The best result is the maximum of the three scores in that Googler's triplet of scores.
     * 
     * Given the total points for each Googler, as well as the number of surprising triplets of scores, 
     * what is the maximum number of Googlers that could have had a best result of at least p?  

N, the number of Googlers, 
S, the number of surprising triplets of scores

Limits
1 ≤ T ≤ 100.
0 ≤ S ≤ N.
0 ≤ p ≤ 10.
0 ≤ ti ≤ 30.
At least S of the ti values will be between 2 and 28, inclusive.

Small dataset
1 ≤ N ≤ 3.

Large dataset
1 ≤ N ≤ 100.
     */
    /*
     * iter 10^3 possibility to record sum -> max best result
     * 
     * greedy : use surprise only when it has benefit (cross >=p boundary)
     */
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        int n = INT();
        int s = INT();
        int p = INT();
        int[] tot = new int[n];
        for (int i = 0; i < tot.length; i++) {
            tot[i] = INT();
        }
        
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        int ret = 0;
        for (int i = 0; i < tot.length; i++) {
            if (best[tot[i]]>=p) {
                ret++;
            } else if(s>0 && bestSurprise[tot[i]]>=p) {
                ret++;
                s--;
            }
        }
        
        out.printf("Case #%d: %s\n", caseNumber, ret);
    }
    
    class XYZ implements Comparable<XYZ> {
        int x;
        int y;
        int z;

        public XYZ(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public String toString() {
            return "(" + x + "," + y + "," + z + ")";
        }

        public int hashCode() {
            final int M = 31;
            int r = 1;
            r = (int) (M * r + x);
            r = (int) (M * r + y);
            r = (int) (M * r + z);
            return r;
        }

        public boolean equals(Object obj) {
            if (obj == null || getClass() != obj.getClass())
                return false;
            XYZ other = (XYZ) obj;
            return x == other.x && y == other.y && z == other.z;
        }

        public int compareTo(XYZ o) {
            if (x == o.x) {
                if (y == o.y) {
                    // < : -1 smallest 1st
                    // > : -1 biggest 1st
                    return z < o.z ? -1 : (z == o.z ? 0 : 1);
                } else {
                    return y < o.y ? -1 : 1;
                }
            } else {
                return x < o.x ? -1 : 1;
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
