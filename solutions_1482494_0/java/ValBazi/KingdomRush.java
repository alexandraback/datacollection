
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
public class KingdomRush {
    
    public static void main(String[] args){
        
        String inputFile="/Users/Vale/Desktop/CodeJam/B-small-attempt3.in";
        String outputFile="/Users/Vale/Desktop/CodeJam/B-small-result3.txt";
        
        String[] allLines=readAllLinesOfFile(inputFile);
        int numberOfCases=Integer.parseInt(allLines[0]);
        
        String[] result=new String[numberOfCases];
        int linePointer=1;
        
        for (int i = 0; i < numberOfCases; i++) {
            int numberOfLevels=Integer.parseInt(allLines[linePointer++]);
            
            int[][]starsNeededForLevel=new int[numberOfLevels][2];
            for (int j = 0; j < numberOfLevels; j++) {
                starsNeededForLevel[j][0]=Integer.parseInt(allLines[linePointer].substring(0, allLines[linePointer].indexOf(" ")));
                starsNeededForLevel[j][1]=Integer.parseInt(allLines[linePointer].substring(allLines[linePointer].indexOf(" ")+1));
                linePointer++;
            }
            
            int starsEarned=0;
            int resultValue=0;
            int[] levelCompleted=new int[numberOfLevels];
            int[] possibleLevels=new int[numberOfLevels];
            
            boolean impossible=false;
            boolean finished=false;
            
            while(!impossible && !finished){
                for (int j = 0; j < numberOfLevels; j++) {
                    if(starsNeededForLevel[j][1]<=starsEarned && levelCompleted[j]==0){
                        possibleLevels[j]=3;
                    } else if(starsNeededForLevel[j][1]<=starsEarned && levelCompleted[j]==1){
                        possibleLevels[j]=2;
                    } else if(starsNeededForLevel[j][0]<=starsEarned && levelCompleted[j]==0){
                        possibleLevels[j]=1;
                    } else{
                        possibleLevels[j]=0;
                    }
                }
                boolean completedALevel=false;
                for (int j = 0; j < numberOfLevels; j++) {
                    if(possibleLevels[j]==3){
                        starsEarned+=2;
                        levelCompleted[j]=2;
                        completedALevel=true;
                        break;
                    }
                }
                if(completedALevel){
                    resultValue++;
                    continue;
                }
                for (int j = 0; j < numberOfLevels; j++) {
                    if(possibleLevels[j]==2){
                        starsEarned+=1;
                        levelCompleted[j]=2;
                        completedALevel=true;
                        break;
                    }
                }
                if(completedALevel){
                    resultValue++;
                    continue;
                }
                int bestLevelIndex=numberOfLevels;
                int costForTwoStars=0;
                for (int j = 0; j < numberOfLevels; j++) {
                    if(possibleLevels[j]==1 && starsNeededForLevel[j][1]>costForTwoStars){
                        bestLevelIndex=j;
                        costForTwoStars=starsNeededForLevel[j][1];
                    }
                }
                if(bestLevelIndex!=numberOfLevels){
                    starsEarned+=1;
                    levelCompleted[bestLevelIndex]=1;
                    resultValue++;
                    continue;
                }
                if(starsEarned==numberOfLevels*2){
                    finished=true;
                } else{
                    impossible=true;
                }
                
            }
            if(impossible){
                result[i]="Case #"+(i+1)+": Too Bad";
            } else{
                result[i]="Case #"+(i+1)+": "+resultValue;
            }
            
        }
        
        writeLinesToFile(outputFile, result);
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
