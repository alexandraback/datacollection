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
public class CodeJam_2013_1C_B {
    
    public static void main(String[] args) {
        String inputFile = "/Users/Vale/Desktop/B-small-attempt0.in";
        String outputFile = "/Users/Vale/Desktop/B-small-output0.txt";
        
        String[] lines = readAllLinesOfFile(inputFile);
        int numberOfCases = Integer.parseInt(lines[0]);
        String[] result = new String[numberOfCases];
        for (int i = 1; i <= numberOfCases; i++) {
            //Work on one case
            int[] coordinates=getIntArrayFromSpaceSeperatedString(lines[i]);
            String moves=moveToTarget(coordinates[0], coordinates[1], "");
            result[i-1]="Case #"+i+": "+moves;
        }
        writeLinesToFile(outputFile, result);
    }
    
    
    public static String moveToTarget(int x, int y, String lastMoves){
        if(x==0 && y==0)
            return lastMoves;
        while(x>lastMoves.length()+1){
            lastMoves=lastMoves+"E";
            x-=lastMoves.length();
        }
        while(x<-1-lastMoves.length()){
            lastMoves=lastMoves+"W";
            x+=lastMoves.length();
        }
        while(x>0){
            lastMoves=lastMoves+"WE";
            x--;
        }
        while(x<0){
            lastMoves=lastMoves+"EW";
            x++;
        }
        while(y>lastMoves.length()+1){
            lastMoves=lastMoves+"N";
            y-=lastMoves.length();
        }
        while(y<-1-lastMoves.length()){
            lastMoves=lastMoves+"S";
            y+=lastMoves.length();
        }
        while(y>0){
            lastMoves=lastMoves+"SN";
            y--;
        }
        while(y<0){
            lastMoves=lastMoves+"NS";
            y++;
        }
        if(x==0 && y==0)
            return lastMoves;
        else
            throw new RuntimeException("Schleifen zu Ende ohne am Ziel zu sein!");
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
