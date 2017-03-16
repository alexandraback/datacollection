
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Madi
 */
public class CodeJam2_A {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (BufferedReader br = new BufferedReader(new FileReader("C:/Users/Madi/codejam/A-large-practice.in")); 
                BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Users/Madi/codejam/A-large-practice.out"))) {
            
            int t = Integer.parseInt(br.readLine());
            
            for (int i = 0; i < t; i++) {
                String s = br.readLine();
                solve(i + 1, s, bw);
            }
            
        }

    }
    
    private static void solve(int cs, String s, BufferedWriter bw)  throws FileNotFoundException, IOException {
        
        int[] a = new int[26];
        char[] c = s.toCharArray();
        for (int i = 0; i < c.length; i++) {
            a[c[i] - 'A']++;
        }
        
        List<Integer> list = new ArrayList<>();
        while (a[25] > 0) {
            list.add(0);
            a[25]--;
            a[4]--;
            a[17]--;
            a[14]--;
        }
        
        while (a[22] > 0) {
            list.add(2);
            a[22]--;
            a[19]--;
            a[14]--;
        }
        
        while (a[20] > 0) {
            list.add(4);
            a[20]--;
            a[5]--;
            a[14]--;
            a[17]--;
        }
        
        while (a[23] > 0) {
            list.add(6);
            a[23]--;
            a[18]--;
            a[8]--;
        }
        
        while (a[6] > 0) {
            list.add(8);
            a[6]--;
            a[8]--;
            a[4]--;
            a[7]--;
            a[19]--;
        }
        
        while (a[5] > 0) {
            list.add(5);
            a[5]--;
            a[8]--;
            a[21]--;
            a[4]--;
        }
        
        while (a[21] > 0) {
            list.add(7);
            a[21]--;
            a[4] -= 2;
            a[18]--;
            a[13]--;
        }
        
        while (a[14] > 0) {
            list.add(1);
            a[14]--;
            a[13]--;
            a[4]--;
        }
        
        while (a[7] > 0) {
            list.add(3);
            a[7]--;
            a[19]--;
            a[17]--;
            a[4]--;
        }
        
        while (a[13] > 0) {
            list.add(9);
            a[13] -= 2;
            a[8]--;
            a[4]--;
        }
        
        Collections.sort(list);
        bw.write("Case #" + cs + ": ");
        
        for (Integer i : list) {
            bw.write(i + "");
        }
        bw.write("\n");
        bw.flush();
    }
}
