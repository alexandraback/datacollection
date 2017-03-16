
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vale
 */
public class PasswordProblem {
    
    public static void main(String[] args){
        String inputFile="/Users/Vale/Desktop/CodeJam/A-small-attempt0.in";
        String outputFile="/Users/Vale/Desktop/CodeJam/A-small-result0.txt";
        
        String[] allLines=readAllLinesOfFile(inputFile);
        int numberOfCases=Integer.parseInt(allLines[0]);
        
        String[] result=new String[numberOfCases];
        
        for (int i = 0; i < numberOfCases; i++) {
            String firstLine=allLines[1+2*i];
            String secondLine=allLines[2+2*i];
            int typedCharacters=Integer.parseInt(firstLine.substring(0, firstLine.indexOf(" ")));
            int lengthOfPassword=Integer.parseInt(firstLine.substring(firstLine.indexOf(" ")+1));
            
            double[] chancesCorrectlyTyped=getDoubleArrayFromSpaceSeperatedString(secondLine, typedCharacters);
            
            double enterRightAway=lengthOfPassword+2;
            
            double chancesAlreadyCorrect=1;
            for (int j = 0; j < typedCharacters; j++) {
                chancesAlreadyCorrect*=chancesCorrectlyTyped[j];
            }
            double keepTyping=chancesAlreadyCorrect*(lengthOfPassword-typedCharacters+1)+
                    (1-chancesAlreadyCorrect)*(2*lengthOfPassword-typedCharacters+2);
            
            double[] pressBackSpacesXTimes=new double[typedCharacters];
            for (int j = 0; j < typedCharacters; j++) {
                double chancesEnoughCorrect=1;
                for (int k = 0; k < typedCharacters-j-1; k++) {
                    chancesEnoughCorrect*=chancesCorrectlyTyped[k];
                }
                pressBackSpacesXTimes[j]=j+1+chancesEnoughCorrect*(lengthOfPassword-typedCharacters+j+2)+
                        (1-chancesEnoughCorrect)*(2*lengthOfPassword-typedCharacters+j+3);
            }
            java.util.Arrays.sort(pressBackSpacesXTimes);
            
            double resultValue=Math.min(enterRightAway, Math.min(keepTyping, pressBackSpacesXTimes[0]));
            result[i]="Case #"+(i+1)+": "+resultValue;
        }
        
        writeLinesToFile(outputFile, result);
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
    
    public static double[] getDoubleArrayFromSpaceSeperatedString(String numbers, int numberOfDoubles){
        numbers=numbers.trim();
        double[] result= new double[numberOfDoubles];
        int start=0;
        int end=numbers.indexOf(" ");
        for(int i=0; i<numberOfDoubles; i++){
            if(end!=-1){
                result[i]=Double.parseDouble(numbers.substring(start, end)); 
                start=end+1;
                end=numbers.indexOf(" ", start);
            } else{
                result[i]=Double.parseDouble(numbers.substring(start));
            }
        }
        return result;
    }
    
    public static String[] readAllLinesOfFile(String file){
        try{
          // Open the file that is the first 
          // command line parameter
          FileInputStream fstream = new FileInputStream(file);
          // Get the object of DataInputStream
          DataInputStream in = new DataInputStream(fstream);
          BufferedReader br = new BufferedReader(new InputStreamReader(in));
          String strLine;
          //Read File Line By Line
          String[] result=new String[1000000];
          int index=0;
          while ((strLine = br.readLine()) != null)   {
              result[index++]=strLine;
          }
          //Close the input stream
          in.close();
          String[] newResult=java.util.Arrays.copyOf(result, index);
          return newResult;
        }catch (Exception e){//Catch exception if any
          System.err.println("Error: " + e.getMessage());
          return new String[] {};
        }
    }
    
    public static void writeLinesToFile(String filename, String[] linesToWrite){
        try {
            PrintWriter pw = new PrintWriter(new FileWriter(filename));
            for (int i = 0; i < linesToWrite.length; i++) {
                pw.println(linesToWrite[i]);
            }
            pw.flush();
            pw.close();
        } catch (Exception e) {
            throw new RuntimeException("Writing File \""+filename+"\" Failed!");
        }
    }
    
}
