package com.vahid.contest.codejam.codejam2015.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Dijkstra {

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){

            int L = input.nextInt();
            long X = input.nextLong();
            input.nextLine();
            String lChar = input.nextLine();
            output.write("Case #" + counter + ": " + (isReducable(lChar, X) ? "YES" : "NO"));
            output.newLine();

        }
        input.close();
        output.close();
    }

    private static boolean isReducable(String lChar, long x) {
        int[] searchList =  {Quaternion.qi, Quaternion.qj, Quaternion.qk};
        int searchItem = 0;
        int eval = Quaternion.q1;
        for (long i = 0; i<x; i++){
            for (int j=0; j < lChar.length(); j++){
                eval = Quaternion.mult(eval, Quaternion.valueOf(lChar.charAt(j)));
                if (searchItem < searchList.length-1){
                    if (eval == searchList[searchItem]){
                        searchItem++;
                        eval = Quaternion.q1;
                    }
                }
            }
        }
        return (searchItem == searchList.length - 1) && (eval == searchList[searchItem]);
    }

}

class Quaternion {
    public static final int q1 = 1;
    public static final int qi = 2;
    public static final int qj = 3;
    public static final int qk = 4;

    public static int valueOf(char ch){
        switch (ch){
            case 'i':
                return qi;
            case 'j':
                return qj;
            case 'k':
                return qk;
        }
        throw new IllegalArgumentException("Wrong Char Input: " + ch);
    }

    public static int neg(int x) {
        return 9 - x;
    }

    public static boolean isNegative(int x){
        return x > 4;
    }

    public static int mult(int x, int y){
        if (isNegative(x))
            return neg(mult(neg(x),y));
        if (isNegative(y))
            return neg(mult(x,neg(y)));

        if (x == q1){
            if (y == q1) return q1;
            if (y == qi) return qi;
            if (y == qj) return qj;
            if (y == qk) return qk;
        }

        if (x == qi){
            if (y == q1) return qi;
            if (y == qi) return neg(q1);
            if (y == qj) return qk;
            if (y == qk) return neg(qj);
        }

        if (x == qj){
            if (y == q1) return qj;
            if (y == qi) return neg(qk);
            if (y == qj) return neg(q1);
            if (y == qk) return qi;
        }

        if (x == qk){
            if (y == q1) return qk;
            if (y == qi) return qj;
            if (y == qj) return neg(qi);
            if (y == qk) return neg(q1);
        }

        throw new IllegalArgumentException("Wrong Args: " + x + " ," + y);
    }
}
