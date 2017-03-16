import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 */
public class Lawnmower {
    private static final String TEST_FILE_NAME = "B-small-attempt0";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(TEST_FILE_NAME + ".in.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(TEST_FILE_NAME + ".out"));

        Integer index = Integer.valueOf(reader.readLine());
        System.out.println("index = " + index);
        long startTime = System.currentTimeMillis();

        for (int i = 1; i <= index; i++) {
            String[] lawnDimensionsStrTokens = reader.readLine().split(" ");

            // build lawn array
            int lawnNSize = Integer.valueOf(lawnDimensionsStrTokens[0]);
            int lawnMSize = Integer.valueOf(lawnDimensionsStrTokens[1]);
            byte[][] lawn = new byte[lawnNSize][lawnMSize];
            for (int n = 0; n < lawnNSize; n++) {
                String[] rowTokens = reader.readLine().split(" ");
                for (int m = 0; m < lawnMSize; m++) {
                    lawn[n][m] = Byte.parseByte(rowTokens[m]);
                }
            }
            String caseResult = "Case #" + i + ": " + (canProcessLawn(lawn, (byte) 0) ? "YES" : "NO");
            System.out.println(caseResult);
            writer.write(caseResult);
            writer.newLine();
        }

        System.out.println("Total time: " + (System.currentTimeMillis() - startTime));

        reader.close();
        writer.close();
    }

    private static boolean canProcessLawn(byte[][] lawn, byte prevMinHeight) {
        // determine minimum lawn's square height
        byte minHeight = 100;
        int minHeightSquaresCount = 0;
        for (byte[] lawnRow : lawn) {
            for (byte squareHeight : lawnRow) {
                if (squareHeight < minHeight && squareHeight > prevMinHeight) {
                    minHeight = squareHeight;
                    minHeightSquaresCount = 1;
                }
                else if (squareHeight == minHeight) {
                    minHeightSquaresCount++;
                }
            }
        }

        if (prevMinHeight > 0) {
            // fill previous to match current and update count
            for (int n = 0; n < lawn.length; n++) {
                for (int m = 0; m < lawn[0].length; m++) {
                    if (lawn[n][m] == prevMinHeight) {
                        minHeightSquaresCount++;
                        lawn[n][m] = minHeight;
                    }
                }
            }
        }

        // check if we've cut to the top level w/o any problems
        if (minHeightSquaresCount == lawn.length * lawn[0].length) {
            return true;
        }

        // check if it's possible to cut lawn like that
        // first check rows
        int validRows = getValidLines(lawn, minHeight, true);
        // second check columns
        int validColumns = getValidLines(lawn, minHeight, false);
        // calculate with account for line intersection
        int validSquaresCount = validRows * lawn[0].length + validColumns * lawn.length - validRows * validColumns;
        // decide
        if (validSquaresCount < minHeightSquaresCount) {
            return false;
        }

        // if this layer is valid, move to the next one
        return canProcessLawn(lawn, minHeight);
    }

    private static int getValidLines(byte[][] lawn, byte minHeight, boolean rows) {
        int validLines = 0;
        int nSize = rows ? lawn.length : lawn[0].length;
        int mSize = rows ? lawn[0].length : lawn.length;

        for (int n = 0; n < nSize; n++) {
            boolean validLine = true;
            for (int m = 0; m < mSize; m++) {
                byte squareHeight = rows ? lawn[n][m] : lawn[m][n];
                if (squareHeight != minHeight) {
                    validLine = false;
                    break;
                }
            }
            if (validLine) {
                validLines++;
            }
        }

        return validLines;
    }
}
