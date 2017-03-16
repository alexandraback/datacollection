package pl.venc.minesweeper;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import org.apache.commons.math3.util.Combinations;

/**
 * Hello world!
 *
 */
public class MineSweeper {

    private static final String MINE = "*";
    private static final String EMPTY = ".";
    private static final String NUMBER = "X";
    private static final String CLICK = "c";

    public static void main(String[] args) {
        try {
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            int numOfCases = Integer.parseInt(stdin.readLine());
            for (int currentCase = 1; currentCase <= numOfCases; currentCase++) {
                String[] input = stdin.readLine().split(" ");
                int rows = Integer.parseInt(input[0]);
                int cols = Integer.parseInt(input[1]);
                int mines = Integer.parseInt(input[2]);

                // prepare play area
                String[][] playArea = new String[cols][rows];
                for (int i = 0; i < cols; i++) {
                    Arrays.fill(playArea[i], EMPTY);
                }

                if (mines + 1 < rows * cols) {
                    // squarify
                    int minesLeft = mines;
                    int effectiveCols = cols;
                    int effectiveRows = rows;
                    while (effectiveCols <= minesLeft || effectiveRows <= minesLeft) {
                        if (effectiveCols <= effectiveRows && effectiveCols <= minesLeft) {
                            for (int i = 0; i < effectiveCols; i++) {
                                playArea[i][effectiveRows - 1] = MINE;
                            }
                            minesLeft -= effectiveCols;
                            effectiveRows--;

                        } else if (effectiveRows < effectiveCols && effectiveRows <= minesLeft) {
                            for (int i = 0; i < effectiveRows; i++) {
                                playArea[effectiveCols - 1][i] = MINE;
                            }
                            minesLeft -= effectiveRows;
                            effectiveCols--;
                        }
                    }

                    tagNumbers(playArea);
//                printPlayArea(playArea, false);

                    boolean solvable = true;
                    if (isSolvable(playArea)) {
                        while (minesLeft > 0) {
                            boolean distroSuccess = distributeMine(playArea);
                            minesLeft--;
                            if (!isSolvable(playArea) || !distroSuccess) {
                                solvable = false;
                                break;
                            }
                        }
                    } else {
                        solvable = false;
                    }

                    System.out.println("Case #" + currentCase + ":");
                    if (!solvable) {
                        String[][] result = tryBruteForce(cols, rows, mines);
                        if (result == null) {
//                            printPlayArea(playArea, false);
                            System.out.println("Impossible");
                        } else {
                            putClick(result);
                            printPlayArea(result, true);
                        }
                    } else {
                        putClick(playArea);
                        printPlayArea(playArea, true);
                    }
                } else {
                    //corner case
                    System.out.println("Case #" + currentCase + ":");
                    boolean first = true;
                    for (int row = 0; row < rows; row++) {
                        for (int col = 0; col < cols; col++) {
                            if (first) {
                                first = false;
                                System.out.print(CLICK);
                            } else {
                                System.out.print(MINE);
                            }
                        }
                        System.out.print("\n");
                    }
                }
            }
        } catch (IOException ex) {
            System.err.println("Ooops: " + ex.getMessage());
        }
    }

    private static void printPlayArea(String[][] playArea, boolean result) {
        int cols = playArea.length;
        int rows = playArea[0].length;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (result && playArea[col][row].equals(NUMBER)) {
                    System.out.print(EMPTY);
                } else {
                    System.out.print(playArea[col][row]);
                }
            }
            System.out.print("\n");
        }
    }

    private static boolean isSolvable(String[][] playArea) {
        int cols = playArea.length;
        int rows = playArea[0].length;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (playArea[col][row].equals(EMPTY)) {
                    String[][] clonedPlayArea = cloneArray(playArea);
                    clonedPlayArea[col][row] = CLICK;
                    if (isSolvablePermutation(clonedPlayArea)) {
                        return true;
                    }
                }

            }
        }

        return false;
    }

    private static boolean isSolvablePermutation(String[][] playArea) {
        int cols = playArea.length;
        int rows = playArea[0].length;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (playArea[col][row].equals(EMPTY) || playArea[col][row].equals(NUMBER)) {
                    if (!hasNeighbourOfType(playArea, col, row, new String[]{EMPTY, CLICK})) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    private static boolean hasNeighbourOfType(String[][] playArea, int col, int row, String[] types) {
        int cols = playArea.length;
        int rows = playArea[0].length;
        int searchColMin = Math.max(col - 1, 0);
        int searchColMax = Math.min(col + 1, cols - 1);
        int searchRowMin = Math.max(row - 1, 0);
        int searchRowMax = Math.min(row + 1, rows - 1);
        List<String> typesList = Arrays.asList(types);
        for (int currCol = searchColMin; currCol <= searchColMax; currCol++) {
            for (int currRow = searchRowMin; currRow <= searchRowMax; currRow++) {
                if (currCol == col && currRow == row) {
                    continue;
                } else {
                    if (typesList.contains(playArea[currCol][currRow])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private static boolean tagNumbers(String[][] playArea) {
        int cols = playArea.length;
        int rows = playArea[0].length;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (playArea[col][row].equals(EMPTY)) {
                    if (hasNeighbourOfType(playArea, col, row, new String[]{MINE})) {
                        playArea[col][row] = NUMBER;
                    }
                }
            }
        }

        return true;
    }

    private static boolean distributeMine(String[][] playArea) {
        int cols = playArea.length;
        int rows = playArea[0].length;
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                if (playArea[col][row].equals(NUMBER) || playArea[col][row].equals(EMPTY)) {
                    String[][] clonedPlayArea = cloneArray(playArea);
                    clonedPlayArea[col][row] = MINE;
                    tagNumbers(clonedPlayArea);
                    if (isSolvable(clonedPlayArea)) {
                        playArea[col][row] = MINE;
                        tagNumbers(playArea);
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public static String[][] cloneArray(String[][] src) {
        int length = src.length;
        String[][] target = new String[length][src[0].length];
        for (int i = 0; i < length; i++) {
            System.arraycopy(src[i], 0, target[i], 0, src[i].length);
        }
        return target;
    }

    private static void putClick(String[][] playArea) {
        int cols = playArea.length;
        int rows = playArea[0].length;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                boolean isEmptyOrNumber = playArea[col][row].equals(EMPTY) || playArea[col][row].equals(NUMBER);
                if (isEmptyOrNumber) {
                    String before = playArea[col][row];
                    playArea[col][row] = CLICK;
                    if (isSolvablePermutation(playArea)) {
                        return;
                    } else {
                        playArea[col][row] = before;
                    }
                }
            }
        }
    }

    private static String[][] tryBruteForce(int cols, int rows, int mines) {
        // apache commons-math3 version 3.3 (compiled source) library used.
        Combinations c = new Combinations(cols * rows, mines);
        Iterator<int[]> it = c.iterator();
        while (it.hasNext()) {
            int[] playAreaCombination = it.next();
            HashSet<Integer> combinationSet = new HashSet<Integer>();
            for (int val : playAreaCombination) {
                combinationSet.add(val);
            }

            String[][] playArea = new String[cols][rows];
            for (int i = 0; i < cols; i++) {
                Arrays.fill(playArea[i], EMPTY);
            }

            // put mines
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    int idx = row * cols + col;
                    if (combinationSet.contains(idx)) {
                        playArea[col][row] = MINE;
                    }
                }
            }

            tagNumbers(playArea);
            if (isSolvable(playArea)) {
                return playArea;
            }

        }

        return null;
    }

}
