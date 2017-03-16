import java.io.*;
import java.util.*;


public class TheRepeater {
    public static Scanner sc;

    public static void main(String[] args) throws Exception {
//        sc = new Scanner(System.in);
        sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\B-small-attempt0.in"));
        int c = sc.nextInt();
        String sol = "";
        
        for (int i = 1; i <= c; i++)
            sol += "Case #" + i + ": " + solve() + "\n";
        
        System.out.print(sol);
        PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\B-small-attempt0.out"));
        pw.print(sol);
        pw.close();
    }

    public static String solve() {
        long a = sc.nextInt();
        long b = sc.nextInt();
        long k = sc.nextInt();
        long ans = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
            	long temp = i & j;
//            	System.out.println("i: " + i + ", j: " + j + ", temp: " + temp);
                if (temp < k)
                    ans++;
            }
        }

        return "" + ans;
    }



    // public static void toBinary(int in, int[] out) {
    //     String temp = Integer.toBinaryString();
    //     out = new int[temp.size()];

    //     for (int i = 0; i < temp.size(); i++) {
    //         out[i] = temp.charAt(i) - '0';
    //     }
    // }
}
