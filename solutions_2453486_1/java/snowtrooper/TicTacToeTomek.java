import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 */
public class TicTacToeTomek {
    private static final String TEST_FILE_NAME = "A-large";
    private static boolean IN_PROGRESS_CHANCE = false;

    private static enum Result {
        X_WON("X won"), O_WON("O won"), DRAW("Draw"), IN_PROGRESS("Game has not completed");
        private String text;

        private Result(String text) {
            this.text = text;
        }

        @Override
        public String toString() {
            return text;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(TEST_FILE_NAME + ".in.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(TEST_FILE_NAME + ".out"));

        Integer index = Integer.valueOf(reader.readLine());
        System.out.println("index = " + index);
        long startTime = System.currentTimeMillis();

        for (int i = 1; i <= index; i++) {
            writer.write("Case #" + i + ": ");
            char[][] aCase = new char[4][4];
            for (int j = 0; j < 4; j++) {
                String row = reader.readLine();
                for (int k = 0; k < 4; k++) {
                    aCase[j][k] = row.charAt(k);
                }
            }
            reader.readLine(); // skip line
            System.out.println("Processing case " + i);
            writer.write(processCase(aCase));
            writer.newLine();
        }

        System.out.println("Total time: " + (System.currentTimeMillis() - startTime));

        reader.close();
        writer.close();
    }

    private static String processCase(char[][] aCase) {
        IN_PROGRESS_CHANCE = false;
        // check linear
        for (int i = 0; i < 4; i++) {
            String xStr = new String(aCase[i]);
            Result result = processString(xStr);
            if (result != Result.DRAW) {
                return result.toString();
            }

            char[] yStrChars = new char[4];
            for (int j = 0; j < 4; j++) {
                yStrChars[j] = aCase[j][i];
            }
            String yStr = new String(yStrChars);

            result = processString(yStr);
            if (result != Result.DRAW) {
                return result.toString();
            }
        }

        // check diagonals
        String diagStrOne = new String(new char[]{aCase[0][0], aCase[1][1], aCase[2][2], aCase[3][3]});
        Result result = processString(diagStrOne);
        if (result != Result.DRAW) {
            return result.toString();
        }

        String diagStrTwo = new String(new char[]{aCase[3][0], aCase[2][1], aCase[1][2], aCase[0][3]});
        result = processString(diagStrTwo);
        if (result != Result.DRAW) {
            return result.toString();
        }

        return IN_PROGRESS_CHANCE ? Result.IN_PROGRESS.toString() : Result.DRAW.toString();
    }

    private static Result processString(String str) {
        if (str.contains(".")) {
            IN_PROGRESS_CHANCE = true;
            return Result.DRAW;
        }
        else if (str.contains("X") && str.contains("O")) {
            return Result.DRAW;
        }
        else if (str.contains("X")) {
            return Result.X_WON;
        }
        else {
            return Result.O_WON;
        }
    }
}