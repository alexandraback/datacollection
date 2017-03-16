import java.io.*;

public class TicTacToeTomek {

    private static void debug(String msg) {
        System.err.println(msg);
    }

    private static final int NOONE_WON = 0;
    private static final int X_WON = 1 << 0;
    private static final int O_WON = 1 << 1;
    
    private static int whoWon(char[] four) {
        assert(four.length == 4) : "Array size is " + four.length;
        
        int cntX = 0;
        int cntO = 0;
        int cntT = 0;
        for (int i = 0; i < 4; ++i) {
            switch (four[i]) {
                case 'X': ++cntX; break;
                case 'O': ++cntO; break;
                case 'T': ++cntT; break;
                case '.': break;
                default: assert(false) : "Character is " + four[i];
            }
        }
        
        if (cntX + cntT == 4) return X_WON;
        if (cntO + cntT == 4) return O_WON;
        return NOONE_WON;
    }

    public static void main(String[] args) throws Exception {
        String inputfile = args[0];
        String outputfile = args[1];
        
        BufferedReader in = new BufferedReader(new FileReader(inputfile));
        PrintWriter out = new PrintWriter(new FileWriter(outputfile));
        
        int cases = Integer.parseInt(in.readLine());
        debug("Number of test cases: " + cases);
        
        for (int i = 1; i <= cases; ++i) {
            debug("Processing Case #" + i);
            
            char table[][] = new char[4][4];
            for (int r = 0; r < 4; ++r) {
                String row = in.readLine();
                assert(row.length() == 4) : "Case #" + i + " Row " + r + ": length = " + row.length();
                for (int c = 0; c < 4; ++c) {
                    char chr = row.charAt(c);
                    assert((chr == 'X') || (chr == 'O') || (chr == 'T') || (chr == '.')) : "Case #" + i + " Row " + r + " Column " + c + ": length = " + row.length();
                    table[r][c] = chr;
                }
            }
            String emptyline = in.readLine();
            assert(emptyline.length() == 0) : "No empty line ending case #" + i;
            
            String debugmsg = "";
            for (int r = 0; r < 4; ++r) {
                for (int c = 0; c < 4; ++c)
                    debugmsg += table[r][c];
                debugmsg += '\n';
            }
            debug(debugmsg);
            
            char four[] = new char[4];
            int won = NOONE_WON;
            
            for (int r = 0; r < 4; ++r) {
                debug("Checking row " + r);
                won |= whoWon(table[r]);
                debug("  whoWon: " + won);
                if (won != NOONE_WON) 
                    break;
            }
            
            if (won == NOONE_WON) {
                for (int c = 0; c < 4; ++c) {
                    debug("Checking column " + c);
                    for (int r = 0; r < 4; ++r)
                        four[r] = table[r][c];
                    won |= whoWon(four);
                    debug("  whoWon: " + won);
                    if (won != NOONE_WON) 
                        break;
                }
            }
            
            if (won == NOONE_WON) {
                debug("Checking diagonal");
                for (int r = 0; r < 4; ++r)
                    four[r] = table[r][r];
                won |= whoWon(four);
                debug("  whoWon: " + won);
            }

            if (won == NOONE_WON) {
                debug("Checking second diagonal");
                for (int r = 0; r < 4; ++r)
                    four[r] = table[r][3-r];
                won |= whoWon(four);
                debug("  whoWon: " + won);
            }
            
            if (won != NOONE_WON) {
                assert(won != (X_WON | O_WON)) : "Both players won";
                assert((won == X_WON) || (won == O_WON)) : "Who won??? " + won;
                if (won == X_WON) { out.println("Case #" + i + ": X won"); continue; }
                if (won == O_WON) { out.println("Case #" + i + ": O won"); continue; }
            }
            else {
                int cntDot = 0;
                for (int r = 0; r < 4; ++r)
                    for (int c = 0; c < 4; ++c)
                        if (table[r][c] == '.')
                            ++cntDot;
                if (cntDot == 0) out.println("Case #" + i + ": Draw");
                else out.println("Case #" + i + ": Game has not completed");
            }
        }
        
        out.close();
        in.close();
    }
}
