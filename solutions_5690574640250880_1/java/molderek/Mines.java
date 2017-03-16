package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Mines {
    
    public static MinesTestCase[] testCases;
    public static String[] results;
    
    public static void main(String[] args) {
        
        if (args.length != 1) {
            System.out.println("usage: java Mines <input.file>");
            return;
        }
        
        readInput(args[0]);
        
        results = new String[testCases.length];
        for (int i = 0; i < testCases.length; i++) {
            results[i] = solveCase(testCases[i]);
        }
        
        writeOutput();
        
        System.out.println("done!");
    }

    private static final String IMPOSSIBLE = "Impossible\n";
    
    private static String solveCase(MinesTestCase testCase) {
        System.out.println("solving " + testCase);
        
        final int r = testCase.rows;
        final int c = testCase.columns;
        final int m = testCase.mines;

        char[][] result = new char [r][c];
        for (int i = 0; i < r; i++) {
            result[i] = new char[c];
        }

        if (r == 1) {
            fillRowWithMines(result[0], m);
            return printResult(result);
        } 

        if (c == 1) {
            fillRowsRestEmpty(result, m);
            return printResult(result);
        }
        
        if (m == 0) {
            fillRowsRestEmpty(result, 0);
            return printResult(result);
        }
        
        final int numberOfEmptyFields = r*c - m;
        if (numberOfEmptyFields == 1) {
             fillRowsRestEmpty(result, r-1);
             fillRowWithMines(result[result.length - 1], m % c);
             return printResult(result);
        } 
        
        if (numberOfEmptyFields == 2 || numberOfEmptyFields == 3 || numberOfEmptyFields == 5 || numberOfEmptyFields == 7) {
            return IMPOSSIBLE;
        }
        
        // two rows or cols - can do if even number of mines
        if (r == 2 || c == 2) {
            if (m % 2 == 1) {
                return IMPOSSIBLE;
            }
            if (r == 2) {
                fillRowWithMines(result[0], m / 2);
                fillRowWithMines(result[1], m / 2);
                return printResult(result);
            }
            fillRowsRestEmpty(result, m / 2);
            return printResult(result);
        }
        
        
        /* three or more rows or cols
         * 
         * lets put mines next to each others in rows
         * first n rows are filled - no worries 
         * last row may be unfilled - if it is the last row it can have only one empty field or not possible
         * if there are at least two rows after unfilled one, than any number of mines is possible (either move one or two to next row(s)
         * else if there is only last row after unfilled one 
         * then possible number of empty fields are 1, 4, 6, >= 8
        */
        
        int fullRows = m / c;
        int remainingMines = m % c;
        int remainingRows = r - fullRows;
        
        fillRowsRestEmpty(result, fullRows);
        if (remainingRows == 1) {
            if (numberOfEmptyFields % 2 == 1) {
                fillRowWithMines(result[fullRows - 2], result[0].length - 3);
                remainingMines += 3;                
            }
            remainingMines += c;
            fillRowWithMines(result[fullRows - 1], remainingMines / 2);
            fillRowWithMines(result[fullRows], remainingMines / 2);
            return printResult(result);
        }
        
        if (remainingRows == 2) {
            if (numberOfEmptyFields % 2 == 1) {
                fillRowWithMines(result[fullRows - 1], result[0].length - 3);
                remainingMines += 3;
            }
            fillRowWithMines(result[fullRows], remainingMines / 2);
            fillRowWithMines(result[fullRows + 1], remainingMines / 2);
            return printResult(result);
        }

        if (remainingMines < c - 1) {
            fillRowWithMines(result[fullRows], remainingMines);
            emptyRowsToTheEnd(result, fullRows + 1);
            return printResult(result);            
        }
        
        // remainingMines == c - 1 at this point
        if (remainingRows == 3) {
            fillRowWithMines(result[fullRows], remainingMines - 2);
            fillRowWithMines(result[fullRows + 1], 1);
            fillRowWithMines(result[fullRows + 2], 1);
            emptyRowsToTheEnd(result, fullRows + 3);
            return printResult(result);
        }

        fillRowWithMines(result[fullRows], remainingMines - 1);
        fillRowWithMines(result[fullRows + 1], 1);
        emptyRowsToTheEnd(result, fullRows + 2);
        return printResult(result);
    }

    private static final char MINE_FIELD  = '*';
    private static final char EMPTY_FIELD  = '.';
    private static final char CLICK_FIELD  = 'c';
    
    private static void fillRowWithMines(char[] row, int numberOfMines) {
        for (int i = 0; i < numberOfMines; i++) {
            row[i] = MINE_FIELD;
        }
        for (int i = numberOfMines; i < row.length; i++) {
            row[i] = EMPTY_FIELD;
        }
    }

    private static String printResult(char[][] result) {
        int rows = result.length;
        int cols = result[0].length;
        
        // last field click
        result[rows - 1][cols - 1] = CLICK_FIELD;
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                sb.append(result[i][j]);
            }
            sb.append('\n');
        }
        
        String printResult = sb.toString();
        //System.out.println("result: \n" + printResult);
        
        return printResult;
    }

    private static void fillRowsRestEmpty(char[][] result, int rowsToFill) {
        for (int i = 0; i < rowsToFill; i++) {
            fillRowWithMines(result[i], result[i].length);
        }
        emptyRowsToTheEnd(result, rowsToFill);
    }
    


    private static void emptyRowsToTheEnd(char[][] result, int rowsToFill) {
        int rows = result.length;
        for (int i = rowsToFill; i < rows; i++) {
            fillRowWithMines(result[i], 0);
        }
    }

    private static void writeOutput() {

        Path file = Paths.get("output.out") ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("writing to path: " + file.toUri());

        try (BufferedWriter writer = Files.newBufferedWriter(file, charset)) {
            
            for (int i = 0; i < results.length; i++) {
                writer.write("Case #" + (i + 1) + ":\n" + results[i]);
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

    private static void readInput(String fileName) {
        
        Path file = Paths.get(fileName) ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("reading from path: " + file.toUri());

        try (BufferedReader reader = Files.newBufferedReader(file, charset)) {
            String line = reader.readLine();
            int testCaseNumber = Integer.valueOf(line);
            testCases = new MinesTestCase[testCaseNumber];
            
            int testCaseCount = 0;
            while ((line = reader.readLine()) != null) {
                MinesTestCase testCase = new MinesTestCase();

                String[] split = line.split(" ");
                testCase.rows = Integer.valueOf(split[0]);
                testCase.columns = Integer.valueOf(split[1]);
                testCase.mines = Integer.valueOf(split[2]);
                
                testCases[testCaseCount++] = testCase;
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

}

class MinesTestCase {
    
    int rows;
    int columns;
    int mines;
    
    @Override
    public String toString() {
        return "rows: " + rows + ", columns: " + columns + ", mines: " + mines;
    }
    
}
