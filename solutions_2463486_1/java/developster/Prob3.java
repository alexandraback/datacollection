package codejam.y2013.q;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Prob3 {
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/C-large-1.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/C-large-1.out.txt"));
        
        Set<Long> fn = new TreeSet<Long>();
        for (long i = 1; i <= 10000000; i++) {
            long x = mkpal(i);
            long sqrt = (long) Math.sqrt(x);
            if (sqrt * sqrt == x && palin(sqrt)) {
                fn.add(x);
            }
            
            x = mkpal2(i);
            sqrt = (long) Math.sqrt(x);
            if (sqrt * sqrt == x && palin(sqrt)) {
                fn.add(x);
            }
        }
        Long[] fnarray = fn.toArray(new Long[0]);
        
        int cn = scanner.nextInt();
        for (int c = 0; c < cn; c++) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            int fnc = 0;
            for (int i = 0; i < fnarray.length; i++) {
                if (fnarray[i] >= a && fnarray[i] <= b) {
                    fnc++;
                }
            }
            writer.write("Case #" + (c+1) + ": " + fnc + "\n");
        }
        writer.close();
        scanner.close();
    }

    private static long mkpal(long i) {
        long r = i;
        while (i != 0) {
            r = (r * 10) + (i % 10);
            i /= 10;
        }
        return r;
    }
    
    private static long mkpal2(long i) {
        long r = i;
        i /= 10;
        while (i != 0) {
            r = (r * 10) + (i % 10);
            i /= 10;
        }
        return r;
    }

    private static boolean palin(long x) {
        char[] cs = Long.toString(x).toCharArray();
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

//[
//1, 
//4, 
//9, 
//121, 
//484, 
//10201, 
//12321, 
//14641, 
//40804, 
//44944, 
//1002001, 
//1234321,
//4008004, 
//100020001, 
//102030201, 
//104060401, 
//121242121, 
//123454321, 
//125686521, 
//400080004, 
//404090404, 
//10000200001, 
//10221412201, 
//12102420121, 
//12345654321, 
//40000800004, 
//1000002000001, 
//1002003002001, 
//1004006004001, 
//1020304030201, 
//1022325232201, 
//1024348434201, 
//1210024200121, 
//1212225222121, 
//1214428244121, 
//1232346432321, 
//1234567654321, 
//4000008000004, 
//4004009004004]
