
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Madi
 */
public class RA2016P1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:/Projects/AdExtractor/src/codejam/A-small-practice.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Projects/AdExtractor/src/codejam/A-small-practice.out"));

        int n = Integer.parseInt(br.readLine());
        for (int x = 0; x < n; x++) {
            String s = br.readLine();
            String res = s.charAt(0) + "";
            for (int i = 1; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c < res.charAt(0)) {
                    res = res + c;
                } else {
                    res = c + res;
                }
            }
            bw.write("Case #" + (x + 1) + ": " + res + "\n");
        }
        bw.flush();

    }
}
