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
public class C {
    private static final char MINE = '*';
    private static final char NO_MINE = '.';
    private static final char FIRST = 'c';
    private static final String NO = "Impossible";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * problem
     * 
     * exact M mines 
     * 
     * the revealed cell will contain a digit between 0 and 8, inclusive, 
     * which corresponds to the number of neighboring cells that contain mines
     * 
     * if the revealed cell contains a 0, then all of the neighbors of the revealed cell 
     * are automatically revealed as well, recursively.
     * 
     * When all the cells that don't contain mines have been revealed, 
     * the game ends, and you win.
     * 
     *  Given the size of the board (R x C) and the number of hidden mines M, 
     *  is it possible (however unlikely) to win in one click? You may choose where you click. 
     *  If it is possible, then print any valid mine configuration and the coordinates of your click 
     *  Otherwise, print "Impossible".

Limits
0 ≤ M < R * C.

Small dataset
1 ≤ T ≤ 230.
1 ≤ R, C ≤ 5.

Large dataset
1 ≤ T ≤ 140.
1 ≤ R, C ≤ 50.
     */
    /*
     * solution
     * 
     * only 1 non-mine or click on 0 init & auto spread to connected 0
     */
    private void run(int caseNumber) throws Exception {
        int R = INT();
        int C = INT();
        int M = INT();
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }
        
        /// start solving problem
//        String ret = small(R,C,M);
        String ret = toStr(big(R,C,M));
//        String ret = toStr(checkBig(R,C,M));
        
        out.printf("Case #%d:\n%s", caseNumber, ret);
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }
    
    static List<int[]> noAns = new ArrayList<>();
    static char[][] checkBig(int R, int C, int M) {
        char[][] res = big(R,C,M);
        if (res==null) {
            noAns.add(new int[] {R,C,M,R*C-M});
            if (R*C<=25) {                
                String ans = small(R, C, M);
                if (!ans.equals(toStr(res))) {
                    System.out.println("ERROR: should found solution: \n"+ans);
                    System.exit(1);
                }
            }
            return res;
        }
        
        if (res.length!=R || res[0].length!=C) {
            System.out.println("ERROR: R,C not match");
            System.exit(1);
        }
        int m=0;
        int[][] cnt = new int[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (res[r][c]==MINE) {
                    cnt[r][c] = -1;
                    updateCnt(cnt,r,c);
                    m++;
                } else if (res[r][c]==NO_MINE) {                    
                    if (r==0 && c==0) {
                        System.out.println("ERROR: res[r][c]="+res[r][c]);
                        System.exit(1);
                    }
                } else if (res[r][c]==FIRST && res[r][c]!=NO_MINE) {
                    if (r!=0 || c!=0) {
                        System.out.println("ERROR: res[r][c]="+res[r][c]);
                        System.exit(1);
                    }
                } else {
                    System.out.println("ERROR: res[r][c]="+res[r][c]);
                    System.exit(1);                    
                }
            }
        }
        if (m!=M) {
            System.out.println("ERROR: mine count != "+M);
            System.exit(1);
        }
        if(M+go(cnt, 0, 0)!=R*C) {
            System.out.println("ERROR: not 1 click");
            System.out.println("### a");
            for (int i = 0; i < res.length; i++) {
                System.out.printf("%2d: ", i);
                System.out.println(Arrays.toString(res[i]));
            }
            System.exit(1);
        }
        return res;
    }

    static char[][] big(int R, int C, int M) {
        if (R > C) {
            return trans(big(C, R, M));
        }
        
        int noMine=R*C-M;
        if (R==1 || noMine==1) {
            return rect(R, C, 1, noMine);
        }
        if (M>0 && (noMine==2 || noMine==3 || noMine==5 || noMine==7)) {
            return null;
        }
        if (R==2) {
            if (M%2==0) {
                return rect(R, C, 2, noMine/2);
            } else {
                return null;
            }
        }
        if (noMine%2==0 && noMine/2<=C) {
            return rect(R, C, 2, noMine/2);
        }
        
        // noMine<=7 is done
        
        // ax or ax+b for x>=2, a>=3, b>=2: ok
        char[][] board = getBoard(R, C);
        for (int row = 3; row <= R; row++) {
            int col=noMine/row;
            if (col > C) continue; 
            
            int mod=noMine%row;
            if (mod==0) {
                return setRect(board, row, col);
            } else if (mod>=2 && col<C) {
                setRect(board, row, col);
                for (int i = 0; i < mod; i++) {
                    board[i][col]=NO_MINE;
                }
                return board;
            }
        }        
        for (int col = 3; col <= C; col++) {
            int row=noMine/col;
            if (row > R) continue; 
            
            int mod=noMine%col;
            if (mod==0) {
                return setRect(board, row, col);
            } else if (mod>=2 && row<R) {
                setRect(board, row, col);
                for (int i = 0; i < mod; i++) {
                    board[row][i]=NO_MINE;
                }
                return board;
            }
        }
        
        if (noMine>=2*(R+C-2)) {
            setRect(board, R, 2);
            setRect(board, 2, C);
            int rest = noMine - 2*(R+C-2);
            for (int r = 2; rest>0 && r < R; r++) {
                for (int c = 2; rest>0 && c < C; c++) {
                    board[r][c]=NO_MINE;
                    rest--;
                }
            }
            return board;
        }
        
        return null;
    }
    static char[][] trans(char[][] a) {
        if (a==null) {
            return null;
        }
        
        char[][] ret = new char[a[0].length][a.length];
        for (int i = 0; i < ret.length; i++) {
            for (int j = 0; j < ret[i].length; j++) {
                ret[i][j]=a[j][i];
            }
        }
        return ret;
    }
    
    static String small(int R, int C, int M) {
        if (M==0) {
            return rectStr(R, C, R, C);            
        }
        if (R*C-M==1) {
            return rectStr(R, C, 1, 1);            
        }
        
        if (R*C>60) {
            return R+"*"+C+": cannot handle by small\n";
        }
        
        for (int msk = 0; msk < 1<<(R*C); msk++) {
            if (bitCount(msk)!=M) continue;
            
            char[][] board = new char[R][C];
            int[][] cnt = new int[R][C];
            for (int r = 0; r < board.length; r++) {
                for (int c = 0; c < board[r].length; c++) {
                    boolean mine=has(msk, r*C+c);
                    if (mine) {
                        board[r][c] = MINE;
                        cnt[r][c] = -1;
                        updateCnt(cnt,r,c);
                    } else {
                        board[r][c] = NO_MINE;
                    }
                }
            }
            
            boolean done = false;
            for (int r = 0; !done && r < cnt.length; r++) {
                for (int c = 0; !done && c < cnt[r].length; c++) {
                    if (cnt[r][c] == 0) {
                        done=true;
                        int v=go(cnt, r, c);
                        if (v+M==R*C) {
                            board[r][c] = FIRST;
                            return toStr(board);
                        }
                    }
                }
            }
        }
        return toStr(null);
    }
    static String toStr(char[][] board) {
        if (board==null) {
            return NO+"\n";
        }
        
        String ret="";
        for (int i = 0; i < board.length; i++) {
            ret+=new String(board[i])+"\n";
        }
        return ret;
    }
    private static int go(int[][] cnt, int r, int c) {
        int v=cnt[r][c];
        if (v<0)
            return 0;
        int ret=1;
        cnt[r][c]=-1;
        if (v==0) {
            for (int i = -1; i <= 1; i++) {
                int nr=r+i;
                if (nr<0 || nr>=cnt.length) continue; 
                
                for (int j = -1; j <= 1; j++) {
                    if (i==0 && j==0) continue; 
                    int nc=c+j;
                    if (nc<0 || nc>=cnt[nr].length) continue; 
                    
                    ret += go(cnt, nr, nc);
                }
            }            
        }
        return ret;
    }
    static char[][] getBoard(int R, int C) {
        char[][] board = new char[R][C];
        for (int i = 0; i < board.length; i++) {
            fill(board[i],MINE);
        }
        board[0][0] = FIRST;
        return board;
    }
    static char[][] rect(int R, int C, int row, int col) {
        return setRect(getBoard(R,C), row, col);
    }
    static char[][] setRect(char[][] board, int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != FIRST) {                    
                    board[i][j] = NO_MINE;
                }
            }
        }
        return board;
    }
    static String rectStr(int R, int C, int row, int col) {
        return toStr(rect(R,C,row,col));
    }
    
    private static void updateCnt(int[][] cnt, int r, int c) {
        for (int i = -1; i <= 1; i++) {
            int nr=r+i;
            if (nr<0 || nr>=cnt.length) continue; 
            
            for (int j = -1; j <= 1; j++) {
                if (i==0 && j==0) continue; 
                int nc=c+j;
                if (nc<0 || nc>=cnt[nr].length) continue; 
                
                if (cnt[nr][nc]>=0) {
                    cnt[nr][nc]++;
                }
            }
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
//    static String testFilename="C-small-attempt0.in";
//    static String testFilename="C-small-attempt1.in";
//    static String testFilename="C-small.in";
//    static String testFilename="C-small-practice.in";
    static String testFilename="C-large.in";
//    static String testFilename="C-large-practice.in";
    
    static int THREAD=1;
//    static int THREAD=3;
    
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
//        myTest();
        
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
                    new C().run(i);
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
        final int n;

        // Do all input reading here!!
        public Solver() throws IOException {
            n = INT();
            throw new RuntimeException("TODO: do reading/solving in Solver()");
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
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
        int max=50;
        for (int r = 1; r <= max; r++) {
            for (int c = 1; c <= max; c++) {
//                if (r*c>max) continue; 
                for (int m = 1; m < r*c; m++) {
                    checkBig(r,c,m);
                }
            }
        }
        System.out.println("  noAns.size()=" + noAns.size());
        for (int[] a : noAns) {
            System.out.println("(R,C,M) = " + Arrays.toString(a));
        }
//        int num=-1000;
//        int num=1000;
//        for (int i = 1; i <= num; ++i) {
//            System.out.println(i+" : "+new C().small(Rn.i(0,50)));
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
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
