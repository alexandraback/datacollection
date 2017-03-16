
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ZuoZhong
 */
public class Recycled {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file = new File("C-large.in");
        BufferedReader in = new BufferedReader(new FileReader(file));
        BufferedWriter out = new BufferedWriter(new FileWriter("Recycled_big_output.txt"));

        int T = Integer.parseInt(in.readLine());


        for (int x = 1; x <= T; x++) {
            int ans = 0;
            String[] input = in.readLine().split(" ");
            if (Integer.parseInt(input[1]) > 10) {
                int start = Integer.parseInt(input[0]);
                int end = Integer.parseInt(input[1]);
                
                for (int y = end; y >= start; y--) {
                    String value = Integer.toString(y);
                    int[] history = new int[value.length() - 1];
                    int pos = 0;
                    for (int z = 0; z < value.length(); z++) {
                        String temp = value + value;
                        int rotated = Integer.parseInt(temp.substring(z, z + value.length()));
                        if (rotated - y == 0) {
                        } else if (rotated > end) {
                        } else if (rotated < y) {
                        } else {
                            Arrays.sort(history);
                            int found = Arrays.binarySearch(history, rotated);
                            if (found < 0) {
                                ans++;
                                history[pos++] = rotated;
                            }
                        }
                    }
                }
            }
            out.write("Case #" + x + ": " + ans);
            System.out.println("Case #" + x + ": " + ans);
            out.newLine();
        }
        out.close();
    }
}
