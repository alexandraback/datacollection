package com.gmail.danielcomsa.codejam.y2014.qualification;

import com.gmail.danielcomsa.codejam.Utility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;

/**
 * Created by daniel on 4/12/14.
 */
public class MinesweeperMaster {

    private static final int MINE = -2;
    private static final int EMPTY = -1;
    private int numberOfRows;
    private int numberOfColumns;
    private int numberOfMines;
    private int[][] currentMatrix;

    public MinesweeperMaster(int numberOfRows, int numberOfColumns, int numberOfMines) {
        this.numberOfRows = numberOfRows;
        this.numberOfMines = numberOfMines;
        this.numberOfColumns = numberOfColumns;
        this.currentMatrix = new int[numberOfRows][numberOfColumns];
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                currentMatrix[i][j] = EMPTY;
            }
        }
    }

    public static void main(String[] args) throws IOException {
//        String file = "sample";
//        String file = "C-small-attempt1.in";
        String file = "C-large.in";

        BufferedReader reader = Utility.getReader(MinesweeperMaster.class, file);
        PrintStream out = Utility.getPrintStream(MinesweeperMaster.class, file);
        int testCases = Utility.readInt(reader);
        for (int i = 1; i <= testCases; i++) {
            int[] input = Utility.readInts(reader);
            MinesweeperMaster minesweeperMaster = new MinesweeperMaster(input[0], input[1], input[2]);
            String result = "Case #" + i + ": \n" + minesweeperMaster.solve();
            out.println(result);
            System.out.println(result);
        }
        out.flush();
        out.close();
    }

    private String solve() {
        int remainingMines = numberOfMines;
        int remainingRows = numberOfRows;
        int remainingColumns = numberOfColumns;
        while (remainingMines > 0) {
            if (remainingRows > remainingColumns) {
                for (int x = remainingColumns - 1; x >= 0; x--) {
                    if (remainingMines == 1 && x == 1 && remainingRows > 0) {
                        break;
                    } else if (remainingMines > 0) {
                        currentMatrix[remainingRows - 1][x] = MINE;
                        remainingMines--;
                    }
                }
                remainingRows--;
            } else {
                for (int x = remainingRows - 1; x >= 0; x--) {
                    if (remainingMines == 1 && x == 1 && remainingColumns > 0) {
                        break;
                    } else if (remainingMines > 0) {
                        currentMatrix[x][remainingColumns - 1] = MINE;
                        remainingMines--;
                    }
                }
                remainingColumns--;
            }
        }

        return getResult(currentMatrix);
    }


    private String getResult(int[][] matrix) {
        if (!isValid(matrix)) {
//            System.out.println("Impossible");
            return "Impossible";
        }

        StringBuilder result = new StringBuilder();
        StringBuilder line = new StringBuilder();

        for (int i = 0; i < numberOfRows; i++) {
            line.setLength(0);
            for (int j = 0; j < numberOfColumns; j++) {
                char c = i == 0 && j == 0 ? 'c' : matrix[i][j] == MINE ? '*' : '.';
                line.append(c);
            }
            result.append(line.toString().trim()).append('\n');
        }

        return result.toString().trim();
    }

    private void inc(int[][] matrix, int row, int column, Direction direction) {
        row += direction.xOffset;
        column += direction.yOffset;
        if (0 <= row && row < numberOfRows && 0 <= column && column < numberOfColumns) {
            if (matrix[row][column] == EMPTY) {
                matrix[row][column] = 1;
            } else if (matrix[row][column] != MINE) {
                matrix[row][column]++;
            }
        }
    }

    private boolean isValid(int[][] matrix) {
        if (numberOfMines == numberOfRows * numberOfColumns - 1) {
            return true;
        }
        int[][] localMatrix = new int[numberOfRows][numberOfColumns];
        for (int i = 0; i < numberOfRows; i++) {
            System.arraycopy(currentMatrix[i], 0, localMatrix[i], 0, numberOfColumns);
        }

        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                if (localMatrix[i][j] == MINE) {
                    for (Direction direction : Direction.values()) {
                        inc(localMatrix, i, j, direction);
                    }
                }
            }
        }

        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                if (localMatrix[i][j] > 0) {
                    boolean isOK = false;
                    for (Direction direction : Direction.values()) {
                        isOK = isOK || hasEmptyNeighbour(localMatrix, i, j, direction);

                    }
                    if (!isOK) {
                        return false;
                    }
                }
            }
        }
        boolean result = matrix[0][0] != MINE;

        if (numberOfColumns >= 2 && numberOfRows >= 2) {
            result = result && (matrix[1][1] != MINE || (matrix[1][1] == MINE && matrix[0][1] == MINE && matrix[1][0] == MINE));
        }

        return result;
    }

    private boolean hasEmptyNeighbour(int[][] matrix, int row, int column, Direction direction) {
        row += direction.xOffset;
        column += direction.yOffset;
        if (0 <= row && row < numberOfRows && 0 <= column && column < numberOfColumns) {
            return matrix[row][column] == EMPTY;
        }
        return false;
    }

    private static enum Direction {
        NORTH_WEST(-1, -1),
        NORTH(-1, 0),
        NORTH_EAST(-1, 1),
        EAST(0, 1),
        SOUTH_EAST(1, 1),
        SOUTH(1, 0),
        SOUTH_WEST(1, -1),
        WEST(0, -1);

        int xOffset;
        int yOffset;

        Direction(int xOffset, int yOffset) {
            this.xOffset = xOffset;
            this.yOffset = yOffset;
        }
    }
}
