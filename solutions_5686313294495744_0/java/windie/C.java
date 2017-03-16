import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by linxy on 4/29/16.
 */
public class C {

    private static int solve(String[][] topics) {
        int len = topics.length;
        int max = 0;
        for (int i = (1 << len) - 1; i >= 0; i--) {
            Set<String> first = new HashSet<>();
            Set<String> second = new HashSet<>();
            int copy = 0;
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) == 0) {
                    first.add(topics[j][0]);
                    second.add(topics[j][1]);
                }
            }
            boolean find = true;
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) != 0) {
                    if (!first.contains(topics[j][0]) || !second.contains(topics[j][1])) {
                        find = false;
                        break;
                    }
                    copy++;
                }
            }
            if (find) {
                if (max < copy) {
                    max = copy;
                    if (max == topics.length - 1) {
                        return max;
                    }
                }
            }
        }
        return max;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("C-small-attempt0.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            int numTopics = in.nextInt();
            System.out.println(numTopics);
            in.nextLine();
            String[][] topics = new String[numTopics][2];
            for (int i = 0; i < numTopics; i++) {
                String line = in.nextLine();
                System.out.println(line);
                topics[i] = line.split(" ");
            }
            int result = solve(topics);
            out.println(result);
        }
        in.close();
        out.close();
    }
}
