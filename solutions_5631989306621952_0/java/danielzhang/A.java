package round1A2016;

import utils.FileIO;

import java.io.IOException;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        FileIO io = new FileIO(A.class);
        A solution = new A();
        int T = Integer.parseInt(io.readLine());

        for (int t = 1; t <= T; t++) {
            char[] words = io.readLine().toCharArray();

            String output = solution.solve(words);
            io.writeLineWithHeader(t, output);

        }
        io.close();
    }

    private String solve(char[] words) {
        StringBuilder sb = new StringBuilder();
        sb.append(words[0]);
        for (int i = 1; i < words.length; i ++){
            if(words[i] >= sb.charAt(0)){
                sb.insert(0, words[i]);
            }else {
                sb.append(words[i]);
            }
        }

        return sb.toString();
    }
}