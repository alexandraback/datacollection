
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Madi
 */
public class RA2016P3 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:/Projects/AdExtractor/src/codejam/C-small-practice.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Projects/AdExtractor/src/codejam/C-small-practice.out"));

        int t = Integer.parseInt(br.readLine());
        for (int x = 0; x < t; x++) {
            int n = Integer.parseInt(br.readLine());

            Map<Integer, Integer> map = new HashMap<>();
            boolean[] vis = new boolean[n + 1];

            String[] s = br.readLine().split(" ");
            for (int i = 1; i <= n; i++) {
                map.put(i, Integer.parseInt(s[i - 1]));
            }

            int max = 0;    
            int count;
            for (int i = 1; i <= n; i++) {
                count = 1;
                if (!vis[i]) {
                    vis[i] = true;
                    int j = map.get(i);
                    while (!vis[j]) {
                        vis[j] = true;
                        count++;
                        j = map.get(j);
                    }
                }
                if (count > max) {
                    max = count;
                }
            }

            bw.write("Case #" + (x + 1) + ": " + max + "\n");
            bw.flush();
        }

    }

}
