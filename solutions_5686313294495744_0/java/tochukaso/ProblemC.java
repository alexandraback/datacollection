

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
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProblemC {

    private static final String PROBLEM_CODE = "C";
//    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-large.in", PROBLEM_CODE);
    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-small-attempt1.in", PROBLEM_CODE);
    private static final String OUTPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-out%s.txt", PROBLEM_CODE, System.currentTimeMillis());


    private String solveProblem(String[][] element) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        
        for(String[] e : element) {
            for(int j = 0; j < 2; j++) {
                String s = e[j]+"__"+j;
                Integer i = map.get(s);
                if(i == null) {
                    i = 0;
                }
                i++;
                map.put(s, i);
            }
        }
        
        int sum = 0;
        for(String[] e : element) {
            boolean isFake = false;
            for(int j = 0; j < 2; j++) {
                String s = e[j]+"__"+j;
                Integer i = map.get(s);
                if(i == 1) {
                    isFake = true;
                    break ;
                }
            }
            if(!isFake) sum++;
        }
        
        return String.valueOf(sum);
    }
    
    private void run() { 
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(INPUT_PATH))))) {
            List<String> answerList = new ArrayList<String>();
            int testCaseCount = readInt(br);
            for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
                String element = br.readLine();
                int n = Integer.parseInt(element);
                String[][] elements = new String[n][2];
                for(int i = 0 ; i < n; i++) {
                    elements[i] = br.readLine().split(" ");
                }
                String answer = solveProblem(elements); 
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
        ProblemC app = new ProblemC();
        app.run();
    }
}

