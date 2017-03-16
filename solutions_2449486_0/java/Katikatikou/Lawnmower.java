import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

/**
 * Date: 13/04/13
 * Time: 01:54
 */
public class Lawnmower {

    /**
     *
     * @param lawn matrix
     * @param rows height
     * @param cols width
     * @return yes if the design can be obtained, no else
     */
    private static String solve(List<List<Integer>> lawn, int rows, int cols) {

        Set<Integer> possibleValues = new TreeSet<Integer>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                possibleValues.add(lawn.get(i).get(j));

            }
        }
        if(rollBackLastMown(lawn, rows, cols, possibleValues)) {
            return "YES";
        }
        return "NO";
    }


    /**
     *
     * @param lawn
     * @param rows
     * @param cols
     * @param possibleValues
     * @return a recursive call ot itself by just trying to remove the last lawnmowing done we stop when all the lawn has the same values, or when the lawn is impossible to obtain
     */
    private static boolean rollBackLastMown(List<List<Integer>> lawn, int rows, int cols, Set<Integer> possibleValues) {
        if(possibleValues.size() == 1) {
            return true;
        }
        // possibleValues contains at least 2 elements, height, and nextheight
        int height = possibleValues.iterator().next();

        Set<Integer> linesToIncrease = new TreeSet<Integer>();
        Set<Integer> colsToIncrease = new TreeSet<Integer>();

        for (int i = 0; i < rows; i++) {
            if(lawn.get(i).get(0) == height) {
                if(checkLinePossible(height,lawn.get(i))) linesToIncrease.add(i);
            }
        }
        for(int j = 0; j < cols; ++j) {
            if(lawn.get(0).get(j) == height) {
                List<Integer> col = new ArrayList<Integer>(rows);
                for (int i = 0; i < rows; i++) {
                    col.add(lawn.get(i).get(j));

                }
                if(checkLinePossible(height, col)) colsToIncrease.add(j);
            }
        }

        possibleValues.remove(height);
        int nextHeight = possibleValues.iterator().next();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(linesToIncrease.contains(i) || colsToIncrease.contains(j)) {
                    lawn.get(i).set(j, nextHeight);
                } else {
                    if(lawn.get(i).get(j) == height) {  // an element that isn't linked to any other one and cannot be obtained alone, so the lawn is impossible
                        return false;
                    }
                }

            }

        }
        return rollBackLastMown(lawn, rows, cols, possibleValues);
    }




    /**
     *
     * @param height
     * @param line
     * @return true if all values in the line have the same value
     */
    private static boolean checkLinePossible(int height, List<Integer> line) {
        for (int i : line) {
            if(i != height) return false;
        }
        return true;
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
                String[] matrixSizeS = br.readLine().split(" ");
                int[] dim = new int[]{Integer.parseInt(matrixSizeS[0]), Integer.parseInt(matrixSizeS[1])};

                List<List<Integer>> lawn = new ArrayList<List<Integer>>(dim[0]);
                for(int j = 0; j < dim[0]; j++) {
                    String[] row = br.readLine().split(" ");
                    List<Integer> lawnLine = new ArrayList<Integer>(dim[1]);
                    for (String s : row) {
                        lawnLine.add(Integer.parseInt(s));
                    }
                    lawn.add(lawnLine);
                }
                res.append("Case #").append(i).append(": ").append(solve(lawn, dim[0], dim[1]));
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

    public static void main(String[] args) {
        runTest("C:\\workarea\\inout\\B-small-attempt0.in", "C:\\workarea\\inout\\output.txt");
    }
}
