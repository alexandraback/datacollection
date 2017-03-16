package codejam.y2013.q;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob3 {
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/C-small-attempt0.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/C-small-attempt0.out.txt"));
        
        boolean[] fn = new boolean[1001];
        for (int i = 1; i <= 1000; i++) {
            int sqrt = (int) Math.sqrt(i);
            fn[i] = sqrt*sqrt == i && palin(i) && palin(sqrt);
//            if (fn[i]) System.out.println(i + " - " + sqrt);
        }
        
        int cn = scanner.nextInt();
        for (int c = 0; c < cn; c++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int fnc = 0;
            for (int i = a; i <= b; i++) {
                if (fn[i]) fnc++;
            }
            
            writer.write("Case #" + (c+1) + ": " + fnc + "\n");
        }
        writer.close();
        scanner.close();
    }

    private static boolean palin(int x) {
        char[] cs = Integer.toString(x).toCharArray();
        int n = cs.length;
        int n2 = cs.length / 2;
        for (int i = 0; i < n2; i++) {
            if (cs[i] != cs[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
}
