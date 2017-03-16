package com.tiennt4;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by tiennt4 on 16/04/2016.
 */
public class LastWordGame {

    public static void main(String[] args) throws IOException {

        String fileName = "resources/A-large";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File(fileName + ".out")))) {
            try(BufferedReader br =new BufferedReader(new FileReader(new File(fileName + ".in")))) {
                int numTest = Integer.parseInt(br.readLine());
                for (int i = 1; i <= numTest; i++) {
                    bw.write(String.format("Case #%d: %s\n", i, getLastWord(br.readLine())));
                }
            }
        }
    }

    public static String getLastWord(String word) {
        char[] chars = word.toCharArray();
        StringBuilder result = new StringBuilder();
        for(char c : chars) {
            if(result.length() == 0) {
                result.append(c);
            }else{
                if(c >= result.charAt(0)) {
                    result.insert(0, c);
                }else{
                    result.append(c);
                }
            }
        }
        return result.toString();
    }
}
