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
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ProbC {
    
    private static final String FILEPATH = "C:\\Users\\abhineet\\desktop\\codeJam";
    private static final String INFILE_NAME = "c.in";
    private static final String OUTFILE_NAME = "c.out";
    
    private static int a =0;
    private static int b =0;
    private static int count = 0;
    private static Set<Integer> daddySet = new HashSet<Integer>();
    
    public ProbC() {
        super();
    }

    public static void main(String[] args) {
        
        List<String> inList = readFile(FILEPATH +File.separator +INFILE_NAME);
        List<String> outList = new ArrayList<String>();
        int numTestCases = Integer.parseInt(inList.get(0));
        System.out.println("Number of Test Case : " +numTestCases);
        for(int i =0 ; i< numTestCases; i++){
            processDataForAB(inList.get(i+1));
            for(int j = a; j <=b ; j++){
                if (!daddySet.contains(j)){
                    Set<Integer> retSet = getCyclicCombinations(new Integer(j).toString()); 
                    if (retSet.size() > 1){
                        count += getCombinations(retSet.size());
                    }
                }
            }
            outList.add("Case #" +i +": " +count);
            count = 0;
        }
        writeToFile(FILEPATH+File.separator+OUTFILE_NAME, outList);
    }
    
   
    
    private static int getCombinations(int n){
        return n* (n-1) /2;
    }
    
    private static Set<Integer> getCyclicCombinations(String strNum){
        int len = strNum.length();
        Set<Integer> retSet = new HashSet<Integer>();
        StringBuilder strBuilder = new StringBuilder(strNum);
        retSet.add(Integer.parseInt(strNum));
        for (int i =1; i<len; i++){
            char ch = strBuilder.charAt(0);
            strBuilder = strBuilder.deleteCharAt(0);
            strBuilder = strBuilder.append(ch);
            int cyclicVal = Integer.parseInt(strBuilder.toString());
            if (cyclicVal <= b && cyclicVal >=a ){
                retSet.add(cyclicVal);  
                
            }
            
        }
        if (retSet.size() > 1){
            daddySet.addAll(retSet);
        }
        return retSet;
    }
    
    private static void processDataForAB(String inputLine){
        String[] arrStr = inputLine.split(" ");
        a = Integer.parseInt(arrStr[0]);
        b = Integer.parseInt(arrStr[1]);
        System.out.println("PROCESSING FOR : " +a +" and " +b);
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
