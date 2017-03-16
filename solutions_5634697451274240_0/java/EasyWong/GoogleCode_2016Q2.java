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
public class GoogleCode_2016Q2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {

            String path = "C:\\Users\\ASUS\\Documents\\NetBeansProjects\\GoogleCode\\";
            FileInputStream fstream = new FileInputStream(path + "B-small-attempt0.in");
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

        char[] strArr = String.valueOf(str).toCharArray();
        int count = 0;
        boolean allFaceUp = false;

        while(true) {

//            System.out.print(count + ": ");
//            for(int i=0;i<strArr.length;i++) {
//                System.out.print(strArr[i]);
//            }
//            System.out.println();

            allFaceUp = true;
            for(int i=0;i<strArr.length;i++) {
                if(strArr[i] == '-') {
                    allFaceUp = false;
                    break;
                }
            }
            if(allFaceUp) break;
            count++;

            //flip it
            char firstChar = ' ';
            int position = -1;

            for(int i=0;i<strArr.length;i++) {
                if(firstChar == ' ') firstChar = strArr[i];
                else if(firstChar != strArr[i]) {
                    position = i;
                    break;
                }
            }
            
            if(position == -1) {
                for(int i=0;i<strArr.length;i++) {
                    if(strArr[i] == '-') strArr[i] = '+';
                    else strArr[i] = '-';
                }                
            }
            else {
                for(int i=0;i<position;i++) {
                    if(strArr[i] == '-') strArr[i] = '+';
                    else strArr[i] = '-';
                }
            }
        }


        System.out.println("Case #" + (lineNum + 1) + ": " + count);
    }
}
