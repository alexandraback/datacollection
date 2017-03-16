import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Consonants {
    public static void main(String[] args) throws IOException {
        System.setOut(new PrintStream("out"));
        System.setIn(new FileInputStream("in"));
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        Set<Character> vowels = new HashSet<Character>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('u');
        vowels.add('i');
        vowels.add('o');
        String line = in.nextLine();
        for (int c = 1; c <= t; c++) {
            line = in.nextLine();
            String q = line.split(" ")[0];
            int n = Integer.valueOf(line.split(" ")[1]);
            int[] consecCon = new int[q.length()];
            consecCon[0] = vowels.contains(q.charAt(0)) ? 0 : 1;
            for (int i = 1; i < q.length(); i++) {
                if (vowels.contains(q.charAt(i)))
                    consecCon[i] = 0;
                else
                    consecCon[i] = consecCon[i - 1] + 1;
            }
            long sum = 0;
            int latestStart = -1;
            for (int i = 0; i < q.length(); i++) {
                if (consecCon[i] >= n) {
                    latestStart = i + 1 - n;
                    sum += latestStart + 1;
                } else {
                    if (latestStart != -1) {
                        sum += latestStart + 1;
                    }
                }
            }
            System.out.println(String.format("Case #%d: %d", c, sum));
        }
    }
}
