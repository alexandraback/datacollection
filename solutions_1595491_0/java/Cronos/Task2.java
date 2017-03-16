package codejam.y2012.r0;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Ilya Lantuh
 */
public class Task2 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int N = input.nextInt();
        int S = input.nextInt();
        int p = input.nextInt();
        List<Integer> scores = getList(N);
        int s = 0;
        int res = 0;
        for (int i = 0; i < N; i++) {
            int num = scores.get(i);
            if (num >= p * 3) res++;
            else if (num == p + p + (p-1)) res++;
            else if (num == p + (p-1) + (p-1)) res++;
            else if ((num == p + (p-1) + (p-2)) || (num == p + (p-2) + (p-2))) {
                if ((s < S) && (p-2 >= 0)) {
                    s++;
                    res++;
                }
            }
        }
        return String.valueOf(res);
    }
    
    public static List<Integer> getList(int size) {
        List<Integer> result = new ArrayList<Integer>(size);
        for (int i = 0; i < size; i++) {
            result.add(input.nextInt());
        }
        return result;
    }

}
