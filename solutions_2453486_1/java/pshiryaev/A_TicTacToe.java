/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 *
 * @author Pavel.Shiryaev
 */
public class A_TicTacToe {

    public void main(String fileName) {

        InputStream fis; OutputStream fos;
        BufferedReader br; BufferedWriter bw;

        try {
            fis = new FileInputStream(fileName);
            fos = new FileOutputStream(fileName.concat(".out"));
            //fis = new FileInputStream("c:\\data\\codejam\\A-large-practice.in");
            //fis = new FileInputStream("c:\\data\\codejam\\test.in");
            br = new BufferedReader(new InputStreamReader(fis)); //, Charset.forName("UTF-8")));
            bw = new BufferedWriter(new OutputStreamWriter(fos)); //, Charset.forName("UTF-8")));

            String line = br.readLine();
            int nc = Integer.parseInt(line); // number of cases
            //int cc = 0;

            // read cases
            String board[] = new String[4];
            for (int cc = 1; cc <= nc; cc++) {

                String output = "Case #" + cc + ": ";
                System.out.print(output);
                bw.write(output);
                
                for (int l = 0; l < 4; l++) {
                    line = br.readLine();
                    board[l] = line;
                    //System.out.println(line);
                }

                // now test
                String test = "";
                boolean gameOver = true;

                // test horizontal
                for (int l = 0; l < 4; l++) {
                    // test horizontal
                    // X won?
                    line = board[l];                    

                    if (line.contains(".")) {
                        gameOver = false;
                    }
                    test += testLine(line);

                    // test vertical
                    line = Character.toString(board[0].charAt(l)) +
                            Character.toString(board[1].charAt(l)) +
                            Character.toString(board[2].charAt(l)) +
                            Character.toString(board[3].charAt(l));
                    
                    if (line.contains(".")) {
                        gameOver = false;
                    }
                    test += testLine(line);

                }

                // main diagonal
                    line = Character.toString(board[0].charAt(0)) +
                            Character.toString(board[1].charAt(1)) +
                            Character.toString(board[2].charAt(2)) +
                            Character.toString(board[3].charAt(3));
                test += testLine(line);

                // second diagonal
                    line = Character.toString(board[0].charAt(3)) +
                            Character.toString(board[1].charAt(2)) +
                            Character.toString(board[2].charAt(1)) +
                            Character.toString(board[3].charAt(0));
                test += testLine(line);


                // display results

                if (test.contains("X")) {
                    output = "X won";
                } else if (test.contains("O")) {
                    output =  "O won";
                } else if (gameOver) {
                    output =  "Draw";
                } else {
                    output =  "Game has not completed";
                }

                
                System.out.println(output);
                bw.write(output);
                bw.newLine();
                
                
                line = br.readLine(); // Each test case is followed by an empty line.
            }


            br.close();
            fis.close();
            bw.close();
            fos.close();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
    }

    private String testLine(String line) {
        String result = "";
        //System.out.println(line);
        if (line.contains("X") && !(line.contains(".") || line.contains("O"))) {
            result += "X";
        }
        if (line.contains("O") && !(line.contains(".") || line.contains("X"))) {
            result += "O";
        }
        return result;
    }
}
