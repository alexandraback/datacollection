/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Bc. Vojtech Kral, student of FIT at CTU in Prague
 */
public class Helper {
    
    private static String outputFolder = "C:\\codeJam\\output\\";
    
    public static String inputFolder = "C:\\codeJam\\intput\\";
    
    public static void write(StringBuilder output, String outputFileName) throws IOException{
         
        FileWriter fileWriter = new FileWriter(outputFolder + outputFileName);
        fileWriter.write(output.toString());
        fileWriter.close();
    }
}
