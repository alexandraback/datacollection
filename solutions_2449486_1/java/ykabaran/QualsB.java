package codejam2013;

import java.io.*;

public class QualsB extends CodeJam2013 {

    //variables here
    private int rows;
    private int cols;
    private int[][] field;
    //solution algorithm here

    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "qB" + inputSize + "in.in";
        String outfilename = "qB" + inputSize + "out.in";

        //create output file if it does not exist, otherwise overwrite everything in it
        File file = new File("data/" + outfilename);
        if (!file.exists()) {
            file.createNewFile();
        }

        //create reader and writer for the input and output files
        BufferedReader br = new BufferedReader(new FileReader("data/" + infilename));
        BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));

        //get the number of test cases to use throughout solving process
        int numCases = Integer.parseInt(br.readLine());

        //create some temporary variables to use for storing input variabes and output string
        String line;
        String[] splitted;
        for (int i = 1; i <= numCases; i++) {
            //read in variables here
            line = br.readLine();
            splitted = line.split(" ");
            rows = Integer.parseInt(splitted[0]);
            cols = Integer.parseInt(splitted[1]);
            field = new int[rows][cols];
            for (int j = 0; j < rows; ++j) {
                line = br.readLine();
                splitted = line.split(" ");
                for (int k = 0; k < cols; ++k) {
                    field[j][k] = Integer.parseInt(splitted[k]);
                }
            }

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private boolean horizontalGreater(int i, int j) {
        int val = field[i][j];
        for (int k = 0; k < cols; ++k) {
            if (field[i][k] > val) {
                return true;
            }
        }
        return false;
    }

    private boolean verticalGreater(int i, int j) {
        int val = field[i][j];
        for (int k = 0; k < rows; ++k) {
            if (field[k][j] > val) {
                return true;
            }
        }
        return false;
    }

    private String solve() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (horizontalGreater(i, j) && verticalGreater(i, j)) {
                    return "NO";
                }
            }
        }
        return "YES";
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new QualsB();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
