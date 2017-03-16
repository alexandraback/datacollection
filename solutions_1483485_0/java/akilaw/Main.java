/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author akila
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        ArrayList<String> testCases = new ArrayList<String>();
        boolean isCaseNo = true;
        int testCount = 0;
        FileReader fr = new FileReader("A-small-attempt0.in");
        BufferedReader br = new BufferedReader(fr);
        String s;

        while ((s = br.readLine()) != null) {
            if (isCaseNo) {
                testCount = Integer.parseInt(s);
                isCaseNo = false;
            } else {
                System.out.println(s);
                testCases.add(s);
            }
        }
        fr.close();
        Solve(testCount, testCases);
    }

    public static void Solve(int testCount, ArrayList<String> testCases) {
        HashMap<String,String> map = new HashMap<String, String>();

        map.put("y", "a"); map.put("s", "n");
        map.put("n", "b"); map.put("e", "o");
        map.put("f", "c"); map.put("v", "p");
        map.put("i", "d"); map.put("z", "q");
        map.put("c", "e"); map.put("p", "r");
        map.put("w", "f"); map.put("d", "s");
        map.put("l", "g"); map.put("r", "t");
        map.put("b", "h"); map.put("j", "u");
        map.put("k", "i"); map.put("g", "v");
        map.put("u", "j"); map.put("t", "w");
        map.put("o", "k"); map.put("h", "x");
        map.put("m", "l"); map.put("a", "y");
        map.put("x", "m"); map.put("q", "z");
        map.put(" ", " ");


        for (int i = 0; i < testCount; i++) {
            String s = testCases.get(i);
            char[] line  = s.toCharArray();

            for (int j = 0; j < line.length; j++) {
                line[j] = map.get(String.valueOf(line[j])).charAt(0);
            }

            System.out.println("Case #"+(i+1)+": "+String.valueOf(line));
        }
    }

}
