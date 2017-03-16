import java.io.*;
import java.util.HashSet;
import java.util.Set;

/**
 * Date: 13/04/13
 * Time: 01:08
 */
public class TicTacToeTomek {

    /**
     *
     * @param T
     * @return the expected result per tic tac toe tomek game
     * it's a little matrix so just brute force it
     */
    private static String printResult(char[][] T) {

        Set<State> states = new HashSet<State>();

        for(int i = 0; i < 4; ++i) {
            State state = getSingleResult(T[i]); // rows
            if(state == State.O_WON) return O_WON_OUTPUT;
            if(state == State.X_WON) return X_WON_OUTPUT;

            states.add(state);
        }

        for(int j = 0; j < 4; ++j) {
            State state = getSingleResult(new char[] {T[0][j], T[1][j], T[2][j], T[3][j]}); // columns
            if(state == State.O_WON) return O_WON_OUTPUT;
            if(state == State.X_WON) return X_WON_OUTPUT;
        }

        // diagonals :

        State state = getSingleResult(new char[] {T[0][0], T[1][1], T[2][2], T[3][3]});
        if(state == State.O_WON) return O_WON_OUTPUT;
        if(state == State.X_WON) return X_WON_OUTPUT;

        state = getSingleResult(new char[] {T[0][3], T[1][2], T[2][1], T[3][0]});
        if(state == State.O_WON) return O_WON_OUTPUT;
        if(state == State.X_WON) return X_WON_OUTPUT;

        if(states.size() > 1) {   // Game is pending
            return GAME_NOT_COMPLETED_OUTPUT;
        }
        if(states.iterator().next() == State.PENDING) return GAME_NOT_COMPLETED_OUTPUT;
        return DRAW_OUTPUT;
    }


    /**
     *Checks in a sequence if there's a winner
     */
    private static State getSingleResult(char[] seq) {
        int countO = 0;
        int countX = 0;
        int countT = 0;

        for (char c : seq) {
            if(c == '.') {
                return State.PENDING;
            }
            if(c == 'X') {
                countX++;
            } else if(c == 'T') {
                countT++;
            } else if(c == 'O') {
                countO++;
            }

        }

        if(countO + countT == 4) return State.O_WON;
        if(countX + countT == 4) return State.X_WON;

        return State.DRAW;
    }


    /**
     * run tests from input and print them in output
     * @param inputFile
     * @param outputFile
     */
    public static void runTest(String inputFile, String outputFile) {
        try{
            FileInputStream fstream = new FileInputStream(inputFile);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            int nbTestCases = Integer.parseInt(br.readLine());

            StringBuilder res = new StringBuilder();
            for(int i = 1; i <= nbTestCases; ++i) {
                char[][] T = new char[4][4];
                T[0] = br.readLine().toCharArray();
                T[1] = br.readLine().toCharArray();
                T[2] = br.readLine().toCharArray();
                T[3] = br.readLine().toCharArray();

                br.readLine();
                res.append("Case #").append(i).append(": ").append(printResult(T));
                res.append("\n");

            }
            in.close();

            BufferedWriter writer = new BufferedWriter( new FileWriter( outputFile));
            writer.write( res.toString());

            writer.close();

        }catch (Exception e){
            e.printStackTrace();
        }
    }


    private static final String O_WON_OUTPUT = "O won";
    private static final String X_WON_OUTPUT = "X won";
    private static final String DRAW_OUTPUT = "Draw";
    private static final String GAME_NOT_COMPLETED_OUTPUT = "Game has not completed";

    enum State {
        O_WON,
        X_WON,
        DRAW,
        PENDING
    }

    public static void main(String[] args) {
        runTest("C:\\workarea\\inout\\A-large.in", "C:\\workarea\\inout\\output.txt");
    }
}
