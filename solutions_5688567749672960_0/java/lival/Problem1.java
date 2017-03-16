
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pivis
 */
public class Problem1 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ_B\\src\\a.in");
        File out = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ_B\\src\\a.out");
        Scanner in = new Scanner(new FileReader(f));
        BufferedWriter output = new BufferedWriter(new FileWriter(out));
        HashMap<Integer, Integer> map = new HashMap<>();
        fill(map);
        
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int N = in.nextInt();
            String text = "Case #" + (i+1) + ": " + map.get(N) + "\n";
            output.write(text);
            
        }
        output.close();
    }
        
    public static void fill(HashMap<Integer, Integer> map) {
        for (int i = 1; i <= 1000000; i++) {
            if (i <= 20) map.put(i, i);
            else {
                int r1 = map.get(i-1);
                if (i%10 != 0) {
                    int rev = reverse(i);
                    if (rev < i) {
                        int r2 = map.get(rev);
                        map.put(i, Math.min(r1, r2)+1);
                    } else {
                        map.put(i, r1+1);
                    }
                } else {
                    map.put(i, r1+1);
                }
            }
        }
    }
    public static int findMin(int N) {
        HashMap<Integer, Integer> map = new HashMap<>();
        return 1;
        /*
        if (map.containsKey(N)) return map.get(N);
        if (N <= 20) {
            map.put(N, N);
            return N;
        }
        int r1 = findMin(N-1, map);
        int rev = reverse(N);
        if (N%10 !=0 && rev < N) {
            int r2 = findMin(rev, map);
            map.put(N, Math.min(r1, r2)+1);
        } else map.put(N, r1+1);
        return map.get(N);
        * */
    }
    
    public static int reverse(int num) {
        int res = 0;
        while (num > 0) {
            int d = num%10;
            res *= 10;
            res += d;
            num /=10;
        }
        return res;
    }
}
