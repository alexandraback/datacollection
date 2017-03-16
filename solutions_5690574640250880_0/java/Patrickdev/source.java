import java.io.*;
import java.math.BigInteger;

/**
 * Created by Patrick on 12-4-14.
 */
public class MinesweeperMaster {

    final static String INPUTFILE = "D:\\gcj\\2014\\MinesweeperMaster\\C-small-attempt5.in";

    static void docase(int casenumber) throws Exception {


        int rows = in.nextInt(),
                columns = in.nextInt(),
                mines = in.nextInt();

        out.add("Case #" + casenumber + ":");

        int nonmines = rows * columns - mines;

        char[][] grid = null;

        for (int i = columns; i >= 1; i--) {
            //log(String.format("for column %s: %s >= 2 && %s != 1 && (%s > 1 || %s <= %s))", i, nonmines / i, nonmines % i, i, nonmines, rows));

            // exception for 1 nonmine
            if (nonmines == 1) {
                grid = createGrid(rows, columns, nonmines, 1);
                break;
            }

            // exception for 1 width
            if (rows == 1 || columns == 1) {
                grid = createGrid(rows, columns, nonmines, (rows == 1 ? nonmines : 1));
                break;
            }

            // 2 rows and odd number of mines
            if ((rows == 2 || columns == 2) && mines % 2 == 1) {
                continue;
            }

            if (nonmines / i >= 2 && nonmines % i != 1 && (i > 1 || nonmines <= rows)) {
                //if (rows != 2 || mines % 2 == 0)
                if (i != 1 || nonmines == 1) {
                    grid = createGrid(rows, columns, nonmines, i);
                    break;
                }
            }

            else if (nonmines / i >= 3 && nonmines % i == 1 && nonmines >= 9) {
                grid = createGrid(rows, columns, nonmines, i);
                grid[nonmines / i - 1][i - 1] = '*';
                grid[nonmines / i][1] = '.';
                break;
            }
        }

        if (grid != null && nonmines != 0) {
            grid[0][0] = 'c';
            printGrid(grid);
        } else {
            out.add("Impossible");
        }

    }


    static void printGrid(char[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            String line = "";
            for (int j = 0; j < grid[0].length; j++) {
                line += grid[i][j];
            }
            out.add(line);
        }
    }

    static char[][] createGrid(int rows, int columns, int nonmines, int freecolumns) {
        log("On a " + rows + " x " + columns + ", we want " + nonmines + " in " + freecolumns + " columns");
        char[][] grid = new char[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                char chr = '*';
                //log("row=" + i + " column=" + j + " freecolumns=" + freecolumns + " nonmines=" + nonmines);
                if (freecolumns != 0) {
                    if (freecolumns > j && Math.ceil(nonmines / freecolumns) > i) {
                        chr = '.';
                    }
                    if ((nonmines % freecolumns) > j && Math.ceil(nonmines / freecolumns) == i) {
                        chr = '.';
                    }
                }
                grid[i][j] = chr;
            }
        }

        return grid;
    }



    public static void main(String args[]) {
        try {

            int totalcases = in.nextInt();

            caseloop:
            for (int currentcase = 1; currentcase <= totalcases; currentcase++) {

                docase(currentcase);

            }

            out.write();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    static class In {
        BufferedReader br;
        String buffer = "";

        In() throws Exception {
            br = new BufferedReader(new FileReader(INPUTFILE));
        }

        String nextLine() throws Exception {
            buffer = "";
            return br.readLine();
        }

        String nextString() throws Exception {
            if (buffer.equals("")) {
                buffer = nextLine();
            }

            String line = buffer;

            if (line.contains(" ")) {
                int spacePos = line.indexOf(" ");
                buffer = line.substring(spacePos + 1, line.length());
                return line.substring(0, spacePos);
            } else {
                buffer = "";
                return line;
            }

        }

        int nextInt() throws Exception {
            return Integer.parseInt(nextString());
        }

        BigInteger nextBigInteger() throws Exception {
            return new BigInteger(nextString());
        }
    }

    static class Out {
        StringBuilder strBuilder = new StringBuilder();

        void add(Object str) {
            strBuilder.append(str.toString());
            strBuilder.append("\n");
            log(str);
        }

        void write() throws Exception {
            File file = new File(INPUTFILE.replace(".in", ".out"));
            if (file.exists()) {
                file.delete();
                file.createNewFile();
            }

            BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
            bw.write(strBuilder.toString());
            bw.close();
        }
    }

    static In in;
    static Out out;
    static {
        try {
            in = new In();
            out = new Out();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }


    static void log(Object o) {
        System.out.println("" + o);
    }
}
