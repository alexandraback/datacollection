package org.active.nerd.sweeper;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

import org.active.nerd.code.jam.InOutProcessor;
import org.active.nerd.code.jam.LineReader;
import org.active.nerd.code.jam.Result;
import org.active.nerd.code.jam.Utility;
import org.active.nerd.sweeper.Sweeper.Minefield;

public class Sweeper extends LineReader<Minefield> {

    private static final String infileName = "C-large.in";

    public static void main(String[] args) {
        InOutProcessor<Sweeper, Minefield> reader = new InOutProcessor<Sweeper, Minefield>(
                infileName, new Sweeper());
        try {
            reader.processFile();
        } catch (NumberFormatException | IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    @Override
    public Collection<Result> parse(BufferedReader reader)
            throws NumberFormatException, IOException {
        int cases = Integer.parseInt(reader.readLine());
        List<Result> results = new LinkedList<Result>();

        for (int i = 0; i < cases; i++) {
            int[] contents = Utility.toIntArray(reader.readLine(), " ");

            results.add(new Minefield(contents[0], contents[1], contents[2]));
        }

        return results;
    }

    public static class Minefield implements Result {

        int rows;
        int columns;
        final int mines;
        int minesLeft;
        int openSpace;
        int openSpaceUsed;
        private int openRows;
        private int openColumnsLastRow;
        private int leastSquare;
        private int leastSquareLeftOver;
        private boolean removeCorner;
        private boolean addonColumn;
        private boolean addonRow;
        private int[] openSpacesPerRow;
        private int openColumns;
        private int openRowsLastColumn;
        private boolean fillRowsFirst;

        public Minefield(int rows, int columns, int mines) {
            this.rows = rows;
            this.columns = columns;
            this.mines = mines;
            openSpacesPerRow = new int[rows];
        }

        @Override
        public String getResult() {
            openSpace = (rows * columns) - mines;
            boolean isPossible = false;
            if (openSpace == 1) {
                isPossible = true;
            } else if (((openSpace > 1 && openSpace < 4) || openSpace == 5 || openSpace == 7)
                    && (rows != 1 && columns != 1)) {
                isPossible = false;
            } else if ((rows == 2 || columns == 2) && openSpace % 2 == 1) {
                isPossible = false;
            } else {
                isPossible = true;
            }

            if (!isPossible) {
                return "\r\nImpossible";
            } else {
                calculateBoard();
                return printBoard();
            }
        }

        private void calculateBoard() {
            this.fillRowsFirst = rows >= columns;

            this.openRows = openSpace / columns;
            this.openColumnsLastRow = openSpace % columns;

            this.openColumns = openSpace / rows;
            this.openRowsLastColumn = openSpace % rows;

            this.leastSquare = (int) Math.sqrt(openSpace);
            this.leastSquareLeftOver = openSpace - (leastSquare * leastSquare);

            this.removeCorner = leastSquareLeftOver % leastSquare == 1;
            this.addonColumn = columns > leastSquare;
            this.addonRow = rows > leastSquare;

            fillOpenSpacesPerRow();
        }

        private void fillOpenSpacesPerRow() {
            if (addonColumn && addonRow) {
                // take up space for square
                for (int i = 0; i < leastSquare; i++) {
                    openSpacesPerRow[i] = leastSquare;
                    openSpaceUsed += leastSquare;
                }

                int spaceLeft = openSpace - openSpaceUsed;
                for (int i = 0; i < spaceLeft && i < leastSquare; i++) {
                    openSpacesPerRow[i] = openSpacesPerRow[i] + 1;
                    openSpaceUsed++;
                }

                if (removeCorner) {
                    openSpacesPerRow[leastSquare - 1] = openSpacesPerRow[leastSquare - 1] - 1;
                    openSpaceUsed--;
                }

                spaceLeft = openSpace - openSpaceUsed;
                if (spaceLeft == 1) {
                    // must go in the 2nd row because this is the one that was
                    // removed from the corner
                    openSpacesPerRow[1] = openSpacesPerRow[1] + spaceLeft;
                } else {
                    openSpacesPerRow[leastSquare] = spaceLeft;
                }
            } else {
                // take up as many dimensions as possible
                if (fillRowsFirst) {
                    for (int i = 0; i < openRows; i++) {
                        openSpacesPerRow[i] = columns;
                        openSpaceUsed += columns;
                    }

                    if ((openSpace - openSpaceUsed) == 1) {
                        // remove bottom right corner
                        openSpacesPerRow[openRows - 1] = openSpacesPerRow[openRows - 1] - 1;
                        openSpaceUsed--;
                    }

                    int lastRowSpace = openSpace - openSpaceUsed;
                    if (lastRowSpace != 0) {
                        openSpacesPerRow[openRows] = lastRowSpace;
                        openSpaceUsed += lastRowSpace;
                    }
                } else {
                    for (int i = 0; i < rows; i++) {
                        openSpacesPerRow[i] = openColumns;
                        openSpaceUsed += openColumns;
                    }

                    if ((openSpace - openSpaceUsed) == 1) {
                        openSpacesPerRow[rows - 1] = openSpacesPerRow[rows - 1] - 1;
                        openSpaceUsed--;
                    }

                    int rowsWithExtraSpace = openSpace - openSpaceUsed;
                    for (int i = 0; i < rowsWithExtraSpace; i++) {
                        openSpacesPerRow[i] = openSpacesPerRow[i] + 1;
                        openSpaceUsed++;
                    }
                }
            }
        }

        private String printBoard() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < rows; i++) {
                sb.append("\r\n");
                int rowBombCount = getRowBombCount(i);

                if (rowBombCount < columns) {
                    if (i == 0) {
                        // need c
                        sb.append("c");
                        for (int j = 0; j < columns - rowBombCount - 1; j++) {
                            sb.append(".");
                        }
                    } else {
                        // fill out with open
                        for (int j = 0; j < columns - rowBombCount; j++) {
                            sb.append(".");
                        }
                    }
                }

                for (int j = 0; j < rowBombCount; j++) {
                    sb.append("*");
                    minesLeft--;
                }
            }

            return sb.toString();
        }

        private int getRowBombCount(int rowNumber) {
            return columns - openSpacesPerRow[rowNumber];
        }
    }

}
