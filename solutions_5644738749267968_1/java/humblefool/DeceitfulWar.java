import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {
    static Scanner input;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);
        
        input = new Scanner(new BufferedReader(new FileReader("D-large.in")));
        out = new PrintWriter(new FileWriter("D-large.out"));

        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #" + testCase + ": ");
            solveCase();
        }
        out.close();
    }
    
    static void solveCase() {
        int n = input.nextInt();
        double[] naomi = readArray(n);
        double[] ken = readArray(n);
        out.println(getScore(naomi, ken) + " " + (n - getScore(ken, naomi)));
    }
    
    static int getScore(double[] second, double[] first) {
        int n = second.length, score = 0;
        Arrays.sort(second);
        boolean[] used = new boolean[n];
        
        for(double value: first) {
            boolean done = false;
            for(int i=0;i<n;i++) {
                if (!used[i] && second[i]>value) {
                    used[i] = done = true;
                    score++;
                    break;
                }
            }
            
            if (!done) {
                for(int i=0;i<n;i++) {
                    if (!used[i]) {
                        used[i] = true;
                        break;
                    }
                }
            }
        }
        return score;
    }
    
    static double[] readArray(int size) {
        double[] array = new double[size];
        for(int i=0;i<size;i++)
            array[i] = input.nextDouble();
        return array;
    }

}
