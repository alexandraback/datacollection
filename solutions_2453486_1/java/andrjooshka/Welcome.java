import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Welcome implements Runnable {
   
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
        Welcome self = new Welcome();
        new Thread(self).start();
    }
    
    @Override
    public void run() {
        try {
            fin = new BufferedReader( new FileReader("A-large.in") );
            fout = new PrintWriter( new FileWriter("A-large.out") );

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
        String in;
        char[][] field = new char[4][4];
        char[][] fieldRotated = new char[4][4];
        boolean hasEmptyCells = false;
        char winner = 0;

        for ( int i = 0; i < 4; i++ ) {
            in = nextLine();
            field[i] = in.toCharArray();
            for ( int j = 0; j < 4; j++ ) {
                fieldRotated[j][i] = field[i][j];
                if ( field[i][j] == '.' ) hasEmptyCells = true;
            }
        }
        nextLine();

        for ( int i = 0; i < 4; i++ ) {
            if ( (winner = checkLine(field[i])) != 0 || (winner = checkLine(fieldRotated[i])) != 0 ) {
                break;
            }
        }
        if ( winner == 0 ) {
            winner = checkLine( field[0][0], field[1][1], field[2][2], field[3][3] );
        }
        if ( winner == 0 ) {
            winner = checkLine( field[0][3], field[1][2], field[2][1], field[3][0] );
        }

        if ( winner != 0 ) {
            fout.println( String.valueOf(winner).toUpperCase() + " won" );
        } else if ( !hasEmptyCells ) {
            fout.println( "Draw" );
        } else {
            fout.println( "Game has not completed" );
        }
    }

    private char checkLine(char[] line) {
        int cnt = 0;
        char check = 0;

        for ( int i = 0; i < 4; i++ ) {
            if ( line[i] == 'T' ) {

                cnt++;

            } else if ( line[i] != '.' ) {

                if ( check == 0 ) {
                    check = line[i];
                }
                if ( check == line[i] ) {
                    cnt++;
                }

            }
        }

        return (check != 0 && cnt == 4) ? check : 0;
    }

    private char checkLine( char a, char b, char c, char d ) {
        char[] line = new char[4];
        line[0] = a; line[1] = b; line[2] = c; line[3] = d;
        return checkLine( line );
    }

}
