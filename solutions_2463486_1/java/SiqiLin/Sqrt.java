import java.io.*;
import java.util.*;

public class Sqrt {
    private static boolean isPalindrome(long n) {
        String str = Long.toString(n);
        int len = str.length();
        int half = len / 2;

        for (int i = 0; i <= half; i++) {
            if (str.charAt(i) != str.charAt(len - i - 1)) {
                return false;
            }
        }

        return true;
    }

    private static int arrayFind(ArrayList<Long> arr, long key) {
        int len = arr.size();

        if (key <= arr.get(0)) {
            return 0;
        }

        for (int i = 0; i < len; i++) {
            if (arr.get(i) > key) {
                return i - 1;
            } 
        }

        return len - 1;
    }

    public static void main(String[] args) {
        ArrayList<Long> palindromes = new ArrayList<>(60);
        long squared;
        for (long i = 1; i <= 10000000; i++) {
            if (isPalindrome(i)) {
                squared = i * i;
                if (isPalindrome(squared)) {
                    System.out.println(i + "  :  " + squared);
                    palindromes.add(squared);
                }
            }
        }
        System.out.println("Size: " + palindromes.size());
        System.out.println("");

        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            File outputFile = new File("./Square_out.txt");
            br = new BufferedReader(new FileReader("./Square_in.txt"));

            if (!outputFile.exists()) {
              outputFile.createNewFile();
            }

            bw = new BufferedWriter(new FileWriter(outputFile));

            String currentLine;

            currentLine = br.readLine();
            int T = Integer.valueOf(currentLine);

            for (int t = 1; t <= T; t++) {
                currentLine = br.readLine();

                String[] split = currentLine.split(" ");
                long A = Long.valueOf(split[0]);
                long B = Long.valueOf(split[1]);

                int a = arrayFind(palindromes, A);
                int b = arrayFind(palindromes, B);

                int count = b - a - 1;

                if (B >= palindromes.get(b)) {
                    count++;
                }

                if (A <= palindromes.get(a)) {
                    count++;
                }

                bw.write("Case #" + t + ": " + count);
                bw.newLine();
                System.out.println("There are " + count + " palindromes in [" + A + ", " + B + "]");
            }
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            } 
        }
    }
}
