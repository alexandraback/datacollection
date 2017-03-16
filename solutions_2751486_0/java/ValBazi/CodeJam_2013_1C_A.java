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
public class CodeJam_2013_1C_A {
    
    public static void main(String[] args){
        String inputFile="/Users/Vale/Desktop/A-small-attempt1.in";
        String outputFile="/Users/Vale/Desktop/A-small-output1.txt";
        
        String[] lines=readAllLinesOfFile(inputFile);
        int numberOfCases=Integer.parseInt(lines[0]);
        String[] result=new String[numberOfCases];
        for (int i = 1; i <= numberOfCases; i++) {
            //Work on one case
            String current=lines[i];
            String[] a=current.split(" ");
            long nValue=0;
            String name=a[0];
            long n=Long.parseLong(a[1]);
            for(int k=0; k<name.length(); k++){
                for(int l=k+1; l<=name.length(); l++){
                    String substring=name.substring(k, l);
                    if(numberOfConsecutiveConsonants(substring)>=n){
                        nValue++;
                    }
                }
            }
            result[i-1]="Case #"+i+": "+nValue;
        }
        writeLinesToFile(outputFile, result);
    }
    
    public static long numberOfConsecutiveConsonants(String name){
        long result=0;
        long currentCombo=0;
        char[] nameArray=name.toCharArray();
        for(char c : nameArray){
            if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u'){
                if(result<currentCombo)
                    result=currentCombo;
                currentCombo=0;
            }
            else{
                currentCombo++;
            }
        }
        if(result<currentCombo)
            result=currentCombo;
        return result;
    }
    
    public static int[] getIntArrayFromSpaceSeperatedString(String numbers){
        String[] numbersAsString=numbers.split(" ");
        int[] result= new int[numbersAsString.length];
        for(int i=0; i<result.length; i++){
            result[i]=Integer.parseInt(numbersAsString[i]);
        }
        return result;
    }
    
    public static int[] getIntArrayFromSpaceSeperatedString(String numbers, int numberOfInts){
        numbers=numbers.trim();
        int[] result= new int[numberOfInts];
        int start=0;
        int end=numbers.indexOf(" ");
        for(int i=0; i<numberOfInts; i++){
            if(end!=-1){
                result[i]=Integer.parseInt(numbers.substring(start, end));
                start=end+1;
                end=numbers.indexOf(" ", start);
            } else{
                result[i]=Integer.parseInt(numbers.substring(start));
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
