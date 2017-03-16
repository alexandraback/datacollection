package qr16;

import java.io.*;
import java.util.Arrays;

/**
 * Created by dzhang on 5/4/16.
 */
public class B {
//    private static final String MODE = "sample";
    private static final String MODE = "small-attempt1";
//    private static final String MODE = "large";

    private int steps;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("in/" + B.class.getPackage().getName() + "/" + B.class.getSimpleName() + "-" + MODE + ".in"));

        File outFile = new File("out/" + B.class.getPackage().getName() + "/" + B.class.getSimpleName() + "-" + MODE + ".out");
        outFile.createNewFile();
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));

        B solution = new B();

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t ++){
            String line = br.readLine();
            boolean[] pancakes = new boolean[line.length()];
            for (int i = 0; i < pancakes.length; i ++){
                pancakes[i] = line.charAt(i) == '+';
            }
            solution.steps = 0;
            solution.solve(pancakes, pancakes.length - 1, true);
            System.out.printf("Case #" + t + ": " + solution.steps + "\n");
            bw.write("Case #" + t + ": " + solution.steps + "\n");
        }
        br.close();
        bw.close();
    }

    private void solve(boolean[] pancakes, int index, boolean result) {
        if(allSettle(pancakes, index, result)){
            return;
        }

        index -= skipLastN(pancakes, index, result);
        getMostOppInFront(pancakes, index, result);
        flip(pancakes, index);
        solve(pancakes, index, result);
    }

    private void getMostOppInFront(boolean[] pancakes, int index, boolean result) {
        if(pancakes[0] == result){
            int count = fistConsistant(pancakes, index);
            flip(pancakes, count);
        }
    }

    private int fistConsistant(boolean[] pancakes, int index) {
        boolean first = pancakes[0];
        int i = 1;
        for (; i <= index; i ++){
            if (pancakes[i] != first){
                return i - 1;
            }
        }
        return i;
    }

    private int skipLastN(boolean[] pancakes, int index, boolean result) {
        int i = 0;
        for (; index >= i; i ++){
            if (pancakes[index - i] != result){
                break;
            }
        }
        return i;
    }

    private void flip(boolean[] pancakes, int last) {
        boolean temp;
        for (int i = last / 2; i >= 0; i --){
            temp = pancakes[i];
            pancakes[i] = pancakes[last - i];
            pancakes[last - i] = temp;
        }
        for(int i = 0; i <= last; i ++){
            pancakes[i] = !pancakes[i];
        }
        steps ++;
    }

    private boolean allSettle(boolean[] pancakes, int index, boolean result) {
        for (int i = 0; i <= index; i ++){
            if(pancakes[i] != result){
                return false;
            }
        }
        return true;
    }


}
