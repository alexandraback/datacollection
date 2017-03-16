import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ProbB {
    
    private static final String FILEPATH = "C:\\Users\\abhineet\\desktop\\codeJam";
    private static final String INFILE_NAME = "b.in";
    private static final String OUTFILE_NAME = "b.out";
    
    
    private static int noOfGooglers = 0;
    private static int noOfSurprises = 0;
    private static int p = 0;
    private static List<Integer> lstScores = null;
    
    public ProbB() {
        super();
    }
    
//    private static void cleanVars(){
//        noOfGooglers = 0;
//        noOfSurprises = 0;
//        p = 0;
//        lstScores = null;
//    }

    public static void main(String[] args) {
        List<String> inList = readFile(FILEPATH +File.separator +INFILE_NAME);
        List<String> outList = new ArrayList<String>();
        int numTestCases = Integer.parseInt(inList.get(0));
        System.out.println("Number of Test Case : " +numTestCases);
        for(int i = 0; i < numTestCases; i++){
            formatInput(inList.get(i+1));
            int pMax = processData();
            outList.add("Case #" +(i+1) +": " +pMax);
        }
        writeToFile(FILEPATH+ File.separator +OUTFILE_NAME, outList);
        for(String str : outList){
            System.out.println(str);
        }
    }
    
    private static int processData(){
        int sMin = 3 * p - 4;
        int sMax = 3 * p - 2;        
        int noOFSurprisesPossible = min(noOfSurprises, getNoofSurprisesPossible(sMin, sMax));
        return noOFSurprisesPossible + getNonSurpriseSurpriseVals(sMax);        
    }
    
    private static int getNonSurpriseSurpriseVals(int sMax){
        int retVal = 0;
        for (int val :lstScores){
            if (val >= sMax && val >= p){
                retVal++;
            }else{
                // do nothing
            }
        }
        return retVal;
    }
    
    private static int getNoofSurprisesPossible(int sMin, int sMax){
        int retVal = 0;
        for(int val : lstScores){
            if (val < sMax && val >= sMin && val >= p ){
                retVal++;
            }else{
                //do nothing
            }
        }
        return retVal;
    }
    
    private static int min(int a ,int b){
        if (a <= b){
            return a;
        }else{
            return b;
        }
        
    }
    
    private static void formatInput(String str){
        lstScores = new ArrayList<Integer>();
        String[] arrStr = str.split(" ");
        System.out.println(arrStr);
        noOfGooglers = Integer.parseInt(arrStr[0]);
        noOfSurprises = Integer.parseInt(arrStr[1]);
        p = Integer.parseInt(arrStr[2]);
        for (int i =0; i < noOfGooglers; i++){
            lstScores.add(Integer.parseInt(arrStr[i+3]));
        }
        Collections.sort(lstScores,Collections.reverseOrder());
        System.out.println("Input Formatted...");
        System.out.println("No of Googlers : " +noOfGooglers);
        System.out.println("No of Surprises : " +noOfSurprises);
        System.out.println("P : " +p);
        System.out.println("Sorted Scores: " +lstScores);
    }
    
    private static List<String> readFile(String filePath) {
        List<String> retList = new ArrayList<String>();
        try {
            // Open the file that is the firstS
            // command line parameter
            FileInputStream fstream = new FileInputStream(filePath);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine = null;
            //Read File Line By Line
            while ((strLine = br.readLine()) != null) {
                // Print the content on the console
                retList.add(strLine);
            }
            //Close the input stream
            in.close();
            return retList;
        } catch (Exception e) { //Catch exception if any
            System.err.println("Error: " + e.getMessage());
        }
        return null;
    }

    private static void writeToFile(String filePath, List<String> inputLines) {
        BufferedWriter bufferedWriter = null;
        try {

            //Construct the BufferedWriter object
            bufferedWriter = new BufferedWriter(new FileWriter(filePath));

            //Start writing to the output stream
            for (String str : inputLines) {
                bufferedWriter.write(str);
                bufferedWriter.newLine();
            }

        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            //Close the BufferedWriter
            try {
                if (bufferedWriter != null) {
                    bufferedWriter.flush();
                    bufferedWriter.close();
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
