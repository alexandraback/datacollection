import java.lang.Integer;
import java.lang.String;
import java.lang.StringBuffer;
import java.util.*;
import java.util.HashSet;

public class Mine {
    private static Set<StringBuffer> checkedGrids;
    private static StringBuffer toStringRep(int R, int C, Set<Cell> marginCells, Set<Cell> zeroCells) {
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                Cell cell = new Cell(i, j);
                if(marginCells.contains(cell)) {
                    sb.append("+");
                } else if (zeroCells.contains(cell)) {
                    sb.append(".");
                } else {
                    sb.append("*");
                }
            }
            sb.append("\n");
        }
        return sb;
    }

    private static boolean isZero(int R, int C, Set<Cell> marginCells, Set<Cell> zeroCells, Cell cell) {
        for(int i = cell.r - 1; i <= cell.r + 1; ++i) {
            if(i < 0 || i >= R) {
                continue;
            }
            for(int j = cell.c - 1; j <= cell.c + 1; ++j) {
                if(j < 0 || j >= C) {
                    continue;
                }
                Cell mmCell  = new Cell(i, j);
                if(mmCell.equals(cell)) {
                    continue;
                }

                if(!marginCells.contains(mmCell) && !zeroCells.contains(mmCell))
                    return false;
            }
        }

        return true;

    }

    private static String helper(int R, int C, int M, Set<Cell> marginCells, Set<Cell> zeroCells) {
        //System.out.println("margins: " + Arrays.toString(marginCells.toArray()));

        //System.out.println("zeros: " + Arrays.toString(zeroCells.toArray()));

        StringBuffer grid = toStringRep(R, C, marginCells, zeroCells);
        if(checkedGrids.contains(grid)) {
            return "Impossible\n";
        }
        checkedGrids.add(grid);

        if(marginCells.size() + zeroCells.size() == R * C - M) {
            if(zeroCells.size() > 0) {
                int index = grid.indexOf(".");
                grid.setCharAt(index, 'c');
            } else {
                int index = grid.indexOf("+");
                grid.setCharAt(index, 'c');
            }
            for(int i = 0; i < grid.length(); ++i) {
                if(grid.charAt(i) == '+') {
                    grid.setCharAt(i, '.');
                }
            }
            return grid.toString();
        } else if (marginCells.size() + zeroCells.size() > R * C - M) {
            return "Impossible\n";
        } else {
            for(Cell marginCell : marginCells) {
                Set<Cell> copiedMarginCells = new HashSet<Cell>(marginCells);
                Set<Cell> copiedZeroCells = new HashSet<Cell>(zeroCells);
                Set<Cell> candZeros = new HashSet<Cell>();
                candZeros.add(marginCell);
                for(int i = marginCell.r - 1; i <= marginCell.r + 1; ++i) {
                    if(i < 0 || i >= R) {
                        continue;
                    }
                    for(int j = marginCell.c - 1; j <= marginCell.c + 1; ++j) {
                        if(j < 0 || j >= C) {
                            continue;
                        }
                        Cell mmCell  = new Cell(i, j);
                        if(mmCell.equals(marginCell)) {
                            continue;
                        }

                        if(zeroCells.contains(mmCell)) {
                            continue;
                        } else if (marginCells.contains(mmCell)) {

                        } else {
                            copiedMarginCells.add(mmCell);
                        }
                        candZeros.add(mmCell);
                    }
                    for(Cell cand : candZeros) {
                        if(isZero(R, C, copiedMarginCells, copiedZeroCells, cand)) {
                            copiedMarginCells.remove(cand);
                            copiedZeroCells.add(cand);
                        }
                    }

                }

                String answer = helper(R, C, M, copiedMarginCells, copiedZeroCells);
                if(!answer.equals("Impossible\n")) {
                    return answer;
                }
            }

            return "Impossible\n";
        }

    }

    public static String solution(int R, int C, int M) {
        checkedGrids = new HashSet<StringBuffer>();
        for(int j = 0; j < C; ++j) {
            Cell startCell = new Cell(0, j);
            Set<Cell> margins = new HashSet<Cell>();
            margins.add(startCell);
            String answer = helper(R, C, M, margins, new HashSet<Cell>());
            if(!answer.equals("Impossible\n")) {
                return answer;
            }
        }
        return "Impossible\n";
    }

    public static void main(String[] args) {
       System.out.println(solution(Integer.parseInt(args[0]), Integer.parseInt(args[1]), Integer.parseInt(args[2])));
    }

}

class Cell {
    public int r;
    public int c;

    public Cell(int r, int c) {
        this.r = r;
        this.c = c;
    }

    public int hashCode() {
        return new Integer(r).hashCode() + new Integer(c).hashCode();
    }

    public boolean equals(Object o) {
        if(o instanceof Cell) {
            Cell other = (Cell) o;
            return other.r == this.r && other.c == this.c;
        }

        return false;
    }

    public String toString() {
        return "" + this.r + ":" + this.c;
    }
}
