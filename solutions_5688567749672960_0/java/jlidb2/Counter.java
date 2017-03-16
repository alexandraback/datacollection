import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/** algorithms */
class Counter {
    
    static int minCount = 0;
    static int[] arr = new int[1];
    
    // reverse given integer
    static int reverse(int n) {
        int result = 0;
        int rem;
        while (n > 0) {
            rem = n % 10;
            n = n / 10;
            result = result * 10 + rem;
        }
        return result;
     }
    
    static void countN(int n) {
        for (int i = 1; i < n + 1; i++) {
            int rev = reverse(i);
            if (rev <= n && (arr[rev] == 0 || arr[rev] > arr[i])) {
                arr[rev] = arr[i] + 1;
            }
            if (i + 1 <= n && (arr[i + 1] == 0 || arr[i + 1] > arr[i])) {
                arr[i + 1] = arr[i] + 1;
            }
        }
        minCount = arr[n];
    }

    // read the file named after the given String and return its contents
    // as a String
    public static String readFile(String filename) {
        String content = null;
        File file = new File(filename); //for ex foo.txt
        try {
            FileReader reader = new FileReader(file);
            char[] chars = new char[(int) file.length()];
            reader.read(chars);
            content = new String(chars);
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content;
    }

    // input file contents as a string
    public static String s = readFile("A-small-attempt2.in");

    static int t = 0;
    static int n = 0;

    static String output = "";

    public static void main(String [] args) throws IOException {
        Scanner sc = new Scanner(s);
        t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            n = sc.nextInt();
            minCount = 1000000;
            arr = new int[n + 1];
            arr[1] = 1;
            countN(n);
            output = output + "\nCase #" + (i + 1) + ": " + minCount;
        }
        output = output.substring(1, output.length());
        File outFile = new File ("output.txt");
        FileWriter fWriter = new FileWriter (outFile);
        PrintWriter pWriter = new PrintWriter (fWriter);
        pWriter.println(output);
        pWriter.close();
        System.out.println(output);
    }
}