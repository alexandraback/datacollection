

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
import java.util.Arrays;
import java.util.List;

public class ProblemB {

    private static final String PROBLEM_CODE = "B";
//    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-large.in", PROBLEM_CODE);
    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-small-attempt1.in", PROBLEM_CODE);
    private static final String OUTPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-out%s.txt", PROBLEM_CODE, System.currentTimeMillis());


    private String solveProblem(String element) {
        String[] line = element.split(" ");
        String a = line[0];
        String b = line[1];
        int len = a.length();
        List<Long> aList = genelateLong(a, b);
        List<Long> bList = genelateLong(b, a);
        
        long min = Long.MAX_VALUE;
        long minNum = Long.MAX_VALUE;
        long minB = Long.MAX_VALUE;
        for(long aLong : aList) {
            for(long bLong : bList) {
                long now = Math.abs(aLong - bLong);
                if(now < min || (now == min && minNum > aLong)) {
                    min = now;
                    minNum = aLong;
                    minB = bLong;
                }
            }
        }
        
        return String.format("%1$0"+len+"d", minNum) + " " + String.format("%1$0" + len + "d", minB);
    }
    
    private List<Long> genelateLong(String s, String b) {
        List<Long> list = new ArrayList<>();
        dfs(new StringBuilder(s), b, list);
        return list;
    }
    
    private void dfs(StringBuilder s, String b, List<Long> list) {
        char[] ca = s.toString().toCharArray();
        boolean isClear = true;
        for(int i = 0; i < ca.length; i++) {
            char c = ca[i];
            if(c == '?') {
                isClear = false;
                int index = 0;
                if(b.charAt(i) != '?') {
                    index = Character.getNumericValue(b.charAt(i));
                }
                for(int j = -1; j < 9; j++) {
                    char[] copy = Arrays.copyOf(ca, ca.length);
                    copy[i] = Character.forDigit((index + 10 + j) % 10, 10);
                    dfs(new StringBuilder(new String(copy)), b, list);
                }
            }
        }
        if(isClear) {
            list.add(Long.parseLong(s.toString()));
        }
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
        ProblemB app = new ProblemB();
//        System.out.println(app.solveProblem("1? 2?"));
//        System.out.println(app.solveProblem("?2? ??3"));
//        System.out.println(app.solveProblem("? ?"));
//        System.out.println(app.solveProblem("?5 ?0"));
        app.run();
    }
}

