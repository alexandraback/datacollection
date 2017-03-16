/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecode;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

/**
 *
 * @author ASUS
 */
public class GoogleCode_2016Q4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {

            String path = "C:\\Users\\ASUS\\Documents\\NetBeansProjects\\GoogleCode\\";
            FileInputStream fstream = new FileInputStream(path + "D-small-attempt1.in");
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));

            String strLine;
            //Read First Line
            strLine = br.readLine();
            for (int i = 0; i < (Integer.parseInt(strLine)); i++) {
                processLine(i, br.readLine());
            }

            in.close();

        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void processLine(int lineNum, String str) {

        Integer K = Integer.parseInt(str.split(" ")[0]);
        Integer C = Integer.parseInt(str.split(" ")[1]);
        Integer S = Integer.parseInt(str.split(" ")[2]);

        //if complexity is 1, need at least K ppl
        if (C == 1) {
            if (S < K) {
                System.out.println("Case #" + (lineNum + 1) + ": " + "IMPOSSIBLE");
            } else {
                //open 1st tile to k-th tile
                System.out.print("Case #" + (lineNum + 1) + ": ");
                
                if(K==1) System.out.print(1);
                else {
                    for (int i = 0; i < K; i++) {
                        System.out.print((i + 1) + ((i < K - 1) ? (" ") : ("")));
                    }
                }
                System.out.println();

            }
        } //else, need K-1 ppl
        else {
            if (S < K - 1) {
                System.out.println("Case #" + (lineNum + 1) + ": " + "IMPOSSIBLE");
            } else {
                //open 2nd tile to k-th tile
                System.out.print("Case #" + (lineNum + 1) + ": ");
                
                if(K==1) System.out.print(1);
                else {
                    for (int i = 1; i < K; i++) {
                        System.out.print((i + 1) + ((i < K - 1) ? (" ") : ("")));
                    }
                }
                System.out.println();

            }
        }

    }
}
