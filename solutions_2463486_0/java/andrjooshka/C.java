import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C implements Runnable {
   
    private BufferedReader fin;
    private StringTokenizer tk;
    private PrintWriter fout;

    private String nextLine() throws IOException {
        return fin.readLine();
    }
    private String nextToken() throws IOException {
        while ( tk == null || !tk.hasMoreTokens() ) {
            tk = new StringTokenizer( fin.readLine() );
        }
        return tk.nextToken();
    }
    private int nextInt() throws IOException { return Integer.valueOf( nextToken() ); }
    private long nextLong() throws IOException { return Long.valueOf( nextToken() ); }
    private double nextDouble() throws IOException { return Double.valueOf( nextToken() ); }
    private BigInteger nextBigInt() throws IOException { return new BigInteger( nextToken() ); }
    
    public static void main(String[] args) {
        C self = new C();
        new Thread(self).start();
    }
    
    @Override
    public void run() {
        try {
            fin = new BufferedReader( new FileReader("C-small-attempt0.in") );
            fout = new PrintWriter( new FileWriter("C-small-attempt0.out") );

            int tc = nextInt();
            for ( int i = 1; i <= tc; i++ ) {
                fout.print("Case #" + i + ": ");
                solveSimple();
            }

            fout.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    
    //////////////////////////////////////////////////////////////////

    private void solveSimple() throws IOException {
        long a = nextLong(), b = nextLong();
        int result = 0;

        for ( long i = (long)Math.ceil(Math.sqrt(a)); i <= Math.floor(Math.sqrt(b)); i++ ) {
            if ( isPalindrome( String.valueOf(i) ) && isPalindrome( String.valueOf( i*i )) ) {
                result++;
            }
        }

        fout.println( result );
    }

    private boolean isPalindrome(String s) {
        return new StringBuffer(s).reverse().toString().equals(s);
    }
}
