import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Consonants {
    static Scanner sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        out = new PrintWriter(System.out);

        sc = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
        out = new PrintWriter(new FileWriter("A-small-attempt0.out"));

        int testCases = sc.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println(String.format("Case #%s: %s", testCase, solveCase()));
        }
        out.close();
    }
    
    static final String VOWELS = "aeiou";

    public static long solveCase() {
        String text = sc.next();
        int threshold = sc.nextInt();
        
        int n = text.length(), m = 0;
        int[] count = new int[n];
        for(int prev = 0, index = 0; index < n; index++) {
            if(VOWELS.indexOf(text.charAt(index)) < 0) {
                count[index] = ++prev;
            } else {
                count[index] = prev = 0;
            }
            if (count[index] >= threshold)
                m++;
        }
        
        int[] valid = new int[m];
        m = 0;
        for(int index = 0; index < n; index++)
            if(count[index] >= threshold)
                valid[m++] = index - threshold + 1;
        
        long result = 0;
        for(int start = 0, offset = 0; start < n; start++) {
            while(offset < m && valid[offset] < start)
                offset++;
            if (offset >= m)
                break;
            result += (n - (valid[offset] + threshold - 1));
        }
        return result;
    }
}
