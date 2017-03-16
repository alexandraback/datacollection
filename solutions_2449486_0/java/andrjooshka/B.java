import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B implements Runnable {
   
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
        B self = new B();
        new Thread(self).start();
    }
    
    @Override
    public void run() {
        try {
            fin = new BufferedReader( new FileReader("B-small-attempt0.in") );
            fout = new PrintWriter( new FileWriter("B-small-attempt0.out") );

            int tc = nextInt();
            for ( int i = 1; i <= tc; i++ ) {
                fout.print("Case #" + i + ": ");
                solve();
            }

            fout.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    
    //////////////////////////////////////////////////////////////////

    private void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        int[][] field = new int[n][m];
        int[][] fieldRotated = new int[m][n];
        int[]lineMax = new int[n];
        int[]rotatedMax = new int[m];
        boolean result = true;

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                field[i][j] = nextInt();
                fieldRotated[j][i] = field[i][j];
                if ( field[i][j] > lineMax[i] ) lineMax[i] = field[i][j];
                if ( fieldRotated[j][i] > rotatedMax[j] ) rotatedMax[j] = fieldRotated[j][i];
            }
        }

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( field[i][j] < lineMax[i] && field[i][j] < rotatedMax[j] ) {
                    result = false;
                    break;
                }
            }
        }

        fout.println( result ? "YES" : "NO" );
    }
}
