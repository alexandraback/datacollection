package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FairAndSquare {
    static List<Long> fairAndSquare = new ArrayList<Long>();
    static int[] result;
    
    public static void main(String[] args) throws IOException {
        initialize();
        read();
        write();
    }

    static void initialize() {
        for (long i=1; i<=10000000; i++) {
            if (isFair(i) && isFair(i*i)) {
                fairAndSquare.add(i*i);
            }
        }
    }
    
    static boolean isFair(long value) {
        String s = Long.toString(value);
        int length = s.length();
        for (int i=0; i<length/2; i++) {
            if (s.charAt(i) != s.charAt(length-i-1)) {
                return false;
            }
        }
        return true;
    }
    
    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        int T = scanner.nextInt();
        result = new int[T];
        for (int t=0; t<T; t++) {
            long A = scanner.nextLong();
            long B = scanner.nextLong();
            int value = 0;
            for (long number : fairAndSquare) {
                if (A <= number && number <= B) {
                    value++;
                }
            }
            result[t] = value;
        }
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<result.length; t++) {
            pw.println("Case #"+(t+1)+": "+result[t]);
        }

        pw.close();
    }
    
}
