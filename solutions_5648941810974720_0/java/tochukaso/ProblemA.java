

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.List;

public class ProblemA {

    private static final String PROBLEM_CODE = "A";
//    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-large.in", PROBLEM_CODE);
    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-small-attempt1.in", PROBLEM_CODE);
    private static final String OUTPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-out%s.txt", PROBLEM_CODE, System.currentTimeMillis());

//    private string[] s = "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE";
    
    private String solveProblem(String element) {
        int[] count = new int[27];
        for(char c : element.toCharArray()) {
            count[convChar(c)]++;
        }
        int[] nums = new int[10];
        extra(count, nums, "FOUR", count[convChar('U')], 4);
        extra(count, nums, "SIX", count[convChar('X')], 6);
        extra(count, nums, "EIGHT", count[convChar('G')], 8);
        extra(count, nums, "ZERO", count[convChar('Z')], 0);
        extra(count, nums, "TWO", count[convChar('W')], 2);
        extra(count, nums, "ONE", count[convChar('O')], 1);
        extra(count, nums, "THREE", count[convChar('T')], 3);
        extra(count, nums, "FIVE", count[convChar('F')], 5);
        extra(count, nums, "SEVEN", count[convChar('S')], 7);
        extra(count, nums, "NINE", count[convChar('I')], 9);
        
        for(int i : count) {
            if(i > 0) {
                throw new RuntimeException(i + "");
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j < nums[i]; j++) {
                sb.append(i);
            }
        }
        
        
        return sb.toString();
    }


    private void extra(int[] count, int[] nums, String x, int num, int index) {
        for(char c: x.toCharArray()) {
            count[convChar(c)] -= num;
        }
        nums[index]=num;
    }

    
    private int convChar(char c) {
        switch(c) {
            case 'Z' :
            return 0;
            case 'E' :
            return 1;
            case 'R' :
            return 2;
            case 'O' :
            return 3;
            case 'N' :
            return 4;
            case 'H' :
            return 5;
            case 'F' :
            return 6;
            case 'U' :
            return 7;
            case 'I' :
            return 8;
            case 'V' :
            return 9;
            case 'X' :
            return 10;
            case 'S' :
            return 11;
            case 'G' :
            return 12;
            case 'T' :
            return 13;
            case 'W' :
            return 14;
        }
        throw new IllegalArgumentException(String.valueOf(c));
    }
    
    private void run() { 
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(INPUT_PATH))))) {
            List<String> answerList = new ArrayList<String>();
            int testCaseCount = readInt(br);
            for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
                String element = br.readLine();
                String answer = solveProblem(element); 
                answerList.add(answer);
                
                System.out.printf("%s: %s : %s \r\n", testCaseIndex + 1, element, answer);
            }
            writeFile(OUTPUT_PATH, answerList);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
    
    private static final String FORMAT = "Case #{0}: {1}";

    public static void writeFile(String filePath, List<String> solve) {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File (filePath))))){
            for (int i = 0; i < solve.size(); i++) {
                Object[] ans = new Object[2];
                ans[0] = String.valueOf(i + 1);
                ans[1] = solve.get(i);
                String write = MessageFormat.format(FORMAT, ans);
                bufferedWriter.write(write);
                bufferedWriter.newLine();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private int readInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) {
        ProblemA app = new ProblemA();
        app.run();
        System.out.println(app.solveProblem("OZONETOWER"));
        System.out.println(app.solveProblem("WEIGHFOXTOURIST"));
        System.out.println(app.solveProblem("OURNEONFOE"));
        System.out.println(app.solveProblem("ETHER"));
    }
}

