/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 *
 * @author Vale
 */
public class CodeJam_2013_1C_C {
    
    public static void main(String[] args) {
        String inputFile = "/Users/Vale/Desktop/C-small-attempt2.in";
        String outputFile = "/Users/Vale/Desktop/C-small-output2.txt";
        
        String[] lines = readAllLinesOfFile(inputFile);
        int numberOfCases = Integer.parseInt(lines[0]);
        String[] result = new String[numberOfCases];
        int index=0;
        for (int i = 1; i <= numberOfCases; i++) {
            //Work on one case
            int[] wallHeightAtIMinus300=new int[1202];
            int numberOfTribes=Integer.parseInt(lines[++index]);
            int[][] tribes=new int[numberOfTribes][8];
            for(int j=0; j<numberOfTribes; j++){
                tribes[j]=getIntArrayFromSpaceSeperatedString(lines[++index]);
            }
            int succesfulAttacks=0;
            for(int day=0; day<676069; day++){
                int[] oldWallHeights=new int[wallHeightAtIMinus300.length];
                System.arraycopy(wallHeightAtIMinus300, 0, oldWallHeights, 0, wallHeightAtIMinus300.length);
                for(int[] tribe : tribes){
                    if(day==tribe[0]){
                        //attacking wall
                        boolean attackSuccesful=false;
                        for(int location=2*tribe[2]; location<=2*tribe[3]; location++){
                            if(oldWallHeights[location+600]<tribe[4]){
                                attackSuccesful=true;
                                if(wallHeightAtIMinus300[location+600]<tribe[4])
                                    wallHeightAtIMinus300[location+600]=tribe[4];
                            }
                        }
                        if(attackSuccesful)
                            succesfulAttacks++;
                        
                        //Updating Tribe data
                        tribe[1]=tribe[1]-1;
                        if(tribe[1]>0){
                            tribe[0]=tribe[0]+tribe[5];
                            tribe[2]=tribe[2]+tribe[6];
                            tribe[3]=tribe[3]+tribe[6];
                            tribe[4]=tribe[4]+tribe[7];
                        }
                        
                    }
                }
            }
            result[i-1]="Case #"+i+": "+succesfulAttacks;
        }
        writeLinesToFile(outputFile, result);
    }
    
    public static int[] getIntArrayFromSpaceSeperatedString(String numbers) {
        String[] numbersAsString = numbers.split(" ");
        int[] result = new int[numbersAsString.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = Integer.parseInt(numbersAsString[i]);
        }
        return result;
    }
    
    public static int[] getIntArrayFromSpaceSeperatedString(String numbers, int numberOfInts) {
        numbers = numbers.trim();
        int[] result = new int[numberOfInts];
        int start = 0;
        int end = numbers.indexOf(" ");
        for (int i = 0; i < numberOfInts; i++) {
            if (end != -1) {
                result[i] = Integer.parseInt(numbers.substring(start, end));
                start = end + 1;
                end = numbers.indexOf(" ", start);
            } else {
                result[i] = Integer.parseInt(numbers.substring(start));
            }
        }
        return result;
    }
    
    public static String[] readAllLinesOfFile(String file) {
        try {
            // Open the file that is the first 
            // command line parameter
            FileInputStream fstream = new FileInputStream(file);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            //Read File Line By Line
            String[] result = new String[1000000];
            int index = 0;
            while ((strLine = br.readLine()) != null) {
                result[index++] = strLine;
            }
            //Close the input stream
            in.close();
            String[] newResult = java.util.Arrays.copyOf(result, index);
            return newResult;
        } catch (Exception e) {//Catch exception if any
            System.err.println("Error: " + e.getMessage());
            return new String[]{};
        }
    }
    
    public static void writeLinesToFile(String filename, String[] linesToWrite) {
        try {
            PrintWriter pw = new PrintWriter(new FileWriter(filename));
            for (int i = 0; i < linesToWrite.length; i++) {
                pw.println(linesToWrite[i]);
            }
            pw.flush();
            pw.close();
        } catch (Exception e) {
            throw new RuntimeException("Writing File \"" + filename + "\" Failed!");
        }
    }
    
    public static String spaceSeperatedIntegersFromArray(int[] integers){
        String result="";
        for(int i=0; i<integers.length; i++){
            result+=integers[i]+" ";
        }
        return result.trim();
    }
}
