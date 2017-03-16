

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
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProbA {

    private static Map<Character, Character> charMapping;
    private static final String FILEPATH = "C:\\Users\\abhineet\\desktop\\codeJam";
    private static final String INFILE_NAME = "a.in";
    private static final String OUTFILE_NAME = "a.out";
    private static String[] codedStrings =
        new String[] { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                       "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                       "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
    private static String[] actualStrings =
        new String[] { "our language is impossible to understand",
                       "there are twenty six factorial possibilities",
                       "so it is okay if you want to just give up" };

    public ProbA() {
        super();
    }

    public static void main(String[] args) {
        System.out.println("INITIALIZING...");
        initialize();
        System.out.println("READING FILE...");
        List<String> inList =  readFile(FILEPATH +File.separator +INFILE_NAME);
        for (String str : inList){
            System.out.println("Read : " +str);
        }
        int numTestCases = Integer.parseInt(inList.get(0));
        List<String> outList = new ArrayList<String>();
        String appString= null;
        for (int i=1; i<=numTestCases; i++){
            appString = "Case #" +i+": " +decode(inList.get(i));            
            outList.add(appString);
        }
        writeToFile(FILEPATH+File.separator+OUTFILE_NAME, outList);
    }
    
    private static String decode(String encodedString){
        int len = encodedString.length();
        StringBuilder strBlder = new StringBuilder();
        for (int i=0; i<len;i++){
            strBlder.append(charMapping.get(encodedString.charAt(i)));
        }
        return strBlder.toString();
    }
    
    private static void initialize(){
        charMapping = new HashMap<Character, Character>();
        charMapping.put('q', 'z');
        charMapping.put('z', 'q');
        for (int i = 0; i < codedStrings.length; i++) {
            processCodedStrings(codedStrings[i], actualStrings[i]);
        }
        for (Character ch : charMapping.keySet()) {
            System.out.println(ch + "-->" + charMapping.get(ch));
        }
    }

    private static void processCodedStrings(String inputStr,
                                            String outputStr) {
        System.out.println("Processing : " + inputStr);
        int len = inputStr.length();
        for (int i = 0; i < len; i++) {
            char codedChar = inputStr.charAt(i);
            char actualChar = outputStr.charAt(i);
            if (charMapping.containsKey(codedChar) &&
                charMapping.get(codedChar) != actualChar) {
                System.out.println("MAYDAY!! MAYDAY!! MAYDAY!!");
                throw new Error("ALGO NOT PROPER...");
            } else {
                //do nothing
            }
            charMapping.put(codedChar, actualChar);
        }
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
