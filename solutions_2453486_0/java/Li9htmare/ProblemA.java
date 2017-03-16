
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Li9htmare
 */
public class ProblemA {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("A-small-attempt0.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int caseCount = Integer.parseInt(in.readLine());

        for (int caseI = 1; caseI <= caseCount; caseI++) {
            char[][] board = new char[4][];
            for (int i = 0; i < 4; i++) {
                String line = in.readLine();
                board[i] = line.toCharArray();
            }
            in.readLine();
            ResultType resultType = checkResult(board);
            resultBuilder.append("Case #").append(caseI);
            switch (resultType) {
                case X:
                    resultBuilder.append(": X won\n");
                    break;
                case O:
                    resultBuilder.append(": O won\n");
                    break;
                case DRAW:
                    resultBuilder.append(": Draw\n");
                    break;
                case INCOMPLETE:
                    resultBuilder.append(": Game has not completed\n");
                    break;
            }
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        //System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }

    private static ResultType checkResult(char[][] board) {
        ResultType result = ResultType.DRAW;
        CharCounter counter = new CharCounter();
        for (int i = 0; i < 4 && (result == ResultType.DRAW
                || result == ResultType.INCOMPLETE); i++) {
            for (int j = 0; j < 4; j++) {
                try {
                    counter.count(board[i][j]);
                } catch (Exception e) {
                    System.out.println("");
                }
            }
            result = updateResult(counter, result);
        }
        
        for (int i = 0; i < 4 && (result == ResultType.DRAW
                || result == ResultType.INCOMPLETE); i++) {
            for (int j = 0; j < 4; j++) {
                counter.count(board[j][i]);
            }
            result = updateResult(counter, result);
        }
        
        for (int i = 0; i < 4 && (result == ResultType.DRAW
                || result == ResultType.INCOMPLETE); i++) {
            counter.count(board[i][i]);
        }
        result = updateResult(counter, result);
        for (int i = 0; i < 4 && (result == ResultType.DRAW
                || result == ResultType.INCOMPLETE); i++) {
            counter.count(board[3 - i][i]);
        }
        result = updateResult(counter, result);

        return result;
    }

    private static class CharCounter {

        public int X = 0;
        public int O = 0;
        public int T = 0;
        public int D = 0;

        public void reset() {
            X = O = T = D = 0;
        }

        public void count(char c) {
            switch (c) {
                case 'X':
                    X++;
                    break;
                case 'O':
                    O++;
                    break;
                case 'T':
                    T++;
                    break;
                case '.':
                    D++;
                    break;
            }
        }

        public boolean isIncomplete() {
            return D > 0;
        }

        public boolean isOWon() {
            return (O == 3 && T == 1) || (O == 4);
        }

        public boolean isXWon() {
            return (X == 3 && T == 1) || (X == 4);
        }
    }

    private static ResultType updateResult(CharCounter counter, ResultType currentResult) {
        ResultType result;
        if (counter.isIncomplete()) {
            result = ResultType.INCOMPLETE;
        } else if (counter.isOWon()) {
            result = ResultType.O;
        } else if (counter.isXWon()) {
            result = ResultType.X;
        } else {
            result = currentResult;
        }
        counter.reset();
        return result;
    }

    private enum ResultType {

        X, O, DRAW, INCOMPLETE
    }

    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("result.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
