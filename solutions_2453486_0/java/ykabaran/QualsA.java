package codejam2013;

import java.io.*;

public class QualsA extends CodeJam2013 {

    private char[][] board;
    //variables here
    //solution algorithm here

    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "qA" + inputSize + "in.in";
        String outfilename = "qA" + inputSize + "out.in";

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
        for (int i = 1; i <= numCases; i++) {
            //read in variables here
            board = new char[4][4];
            for (int j = 0; j < 4; ++j) {
                line = br.readLine();
                for (int k = 0; k < 4; ++k) {
                    board[j][k] = line.charAt(k);
                }
            }
            if (i != numCases) {
                br.readLine();
            }

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private boolean won(char c) {
        boolean won;

        //check rows
        for (int i = 0; i < 4; ++i) {
            won = true;
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] != c && board[i][j] != 'T') {
                    won = false;
                    break;
                }
            }
            if (won) {
                return true;
            }
        }

        //check columns
        for (int i = 0; i < 4; ++i) {
            won = true;
            for (int j = 0; j < 4; ++j) {
                if (board[j][i] != c && board[j][i] != 'T') {
                    won = false;
                    break;
                }
            }
            if (won) {
                return true;
            }
        }

        //check diagonal top-left to bottom-right
        won = true;
        for (int j = 0; j < 4; ++j) {
            if (board[j][j] != c && board[j][j] != 'T') {
                won = false;
                break;
            }
        }
        if (won) {
            return true;
        }

        //check diagonal top-right to bottom-left
        won = true;
        for (int j = 0; j < 4; ++j) {
            if (board[j][3 - j] != c && board[j][3 - j] != 'T') {
                won = false;
                break;
            }
        }
        if (won) {
            return true;
        }

        return false;
    }

    private boolean isOver() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    private String solve() {
        if (won('X')) {
            return "X won";
        }
        if (won('O')) {
            return "O won";
        }
        if (isOver()) {
            return "Draw";
        }
        return "Game has not completed";
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new QualsA();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
