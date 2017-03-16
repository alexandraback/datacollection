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
public class A {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * 
     */
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        int n = INT();
        int[] s = new int[n];
        int tot=0;
        for (int i = 0; i < s.length; i++) {
            s[i] = INT();
            tot+=s[i];
        }
        
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
/*
 * 7 0 0 87 0 0 0 0
 * ans = Case #5: 28.571428571428573 28.571428571428573 0.0 28.571428571428573 28.571428571428573 28.571428571428573 28.571428571428573
 * res = Case #5: 28.571428571428573 28.571428571428573 -71.42857142857143 28.571428571428573 28.571428571428573 28.571428571428573 28.571428571428573
 * 
 * 9 1 0 98 99 99 98 0 1 1
 * ans = Case #6: 21.97033305345648 22.22222222222222 0.0 0.0 0.0 0.0 22.22222222222222 21.97033305345648 21.97033305345648
 * res = Case #6: 21.97033305345648 22.22222222222222 -2.4629163168206 -2.714805485586343 -2.714805485586343 -2.4629163168206 22.22222222222222 21.97033305345648 21.97033305345648
 * 
 * 5 46 32 2 69 10
 * ans = Case #11: 11.069182389937108 19.87421383647799 38.742138364779876 0.0 33.71069182389937
 * res = Case #11: 11.069182389937108 19.87421383647799 38.742138364779876 -3.3962264150943398 33.71069182389937
 * 
 * 5 0 0 0 0 62
 * ans = Case #18: 40.0 40.0 40.0 40.0 0.0
 * res = Case #18: 40.0 40.0 40.0 40.0 -60.0        
 */
        double[] m = new double[n];
        boolean[] win = new boolean[n];
        int need=0;
        int left=0;
        for (int i = 0; i < m.length; i++) {
            if (n*s[i]>=2*tot) {
                m[i]=0;
                win[i]=true;
            } else {
                left+=s[i];
                need++;
            }
        }
        for (int i = 0; i < m.length; i++) {
            if (win[i])
                continue; 
            
//            m[i]=(2.0*tot/n-s[i])/tot*100;
//            m[i]=(200.0/n-100.0*s[i]/tot);
            m[i]=(1.0*(left+tot)/need-s[i])/tot*100;
        }
        out.printf("Case #%d:", caseNumber);
        for (int i = 0; i < m.length; i++) {
            out.print(" "+m[i]);
        }
        out.println();
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }

    
    static boolean printInput=false;
//    static boolean printInput=true; // print input case
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="A-test.in";
//    static String testFilename="A-small-attempt0.in";
//    static String testFilename="A-small-attempt1.in";
//    static String testFilename="A-small-attempt2.in";
    static String testFilename="A-small-attempt3.in";
//    static String testFilename="A-small.in";
//    static String testFilename="A-small-practice.in";
//    static String testFilename="A-large.in";
//    static String testFilename="A-large-practice.in";
    
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
                new A().run(i);
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
//            System.out.println(i+" : "+new A().small(Rn.i(0,50)));
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
