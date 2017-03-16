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
public class GoogleCode_2016Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {

            String path = "C:\\Users\\ASUS\\Documents\\NetBeansProjects\\GoogleCode\\";
            FileInputStream fstream = new FileInputStream(path + "A-small-attempt0.in");
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
        
        Integer initNum = Integer.parseInt(str);
        
        if(initNum == 0) {
            System.out.println("Case #" + (lineNum + 1) + ": " + "INSOMNIA");
        }
        else {
            Boolean _0 = true; Boolean _1 = true; Boolean _2 = true;
            Boolean _3 = true; Boolean _4 = true; Boolean _5 = true;
            Boolean _6 = true; Boolean _7 = true; Boolean _8 = true;
            Boolean _9 = true; 
            
            int count = 0;
            
            while(_0 || _1  || _2  || _3  || _4  || _5  || _6  || _7  || _8  || _9) {
                
                count++;
                char[] strArr = String.valueOf(initNum*count).toCharArray();
                
                for(int i=0;i<strArr.length;i++) {
                    if(strArr[i] == '0') _0 = false;
                    else if(strArr[i] == '1') _1 = false;
                    else if(strArr[i] == '2') _2 = false;
                    else if(strArr[i] == '3') _3 = false;
                    else if(strArr[i] == '4') _4 = false;
                    else if(strArr[i] == '5') _5 = false;
                    else if(strArr[i] == '6') _6 = false;
                    else if(strArr[i] == '7') _7 = false;
                    else if(strArr[i] == '8') _8 = false;
                    else if(strArr[i] == '9') _9 = false;
                }
                //System.out.println("Check: " + initNum*count);
                //System.out.println("Check: " + _0 + "," + _1 + "," + _2 + "," + _3 + "," + _4);
                //System.out.println("Check: " + _5 + "," + _6 + "," + _7 + "," + _8 + "," + _9);
                
            }
            System.out.println("Case #" + (lineNum + 1) + ": " + initNum*count);
        }
    }
}
