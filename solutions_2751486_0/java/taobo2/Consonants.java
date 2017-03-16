package Round1C;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * User: taobo2
 */
public class Consonants {

    Set<Character> set = new HashSet<Character>();

    {
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
    }

    public long solve(String name, int n) {
        long result = 0;
        long found = 0;
        int last = -1;
        int j = 0;
        Out:
        for (int i = 0, len = name.length() - n; i <= len; ) {
            for (; j < i + n; j++) {
                if (set.contains(name.charAt(j))) {
                    i = j + 1;
                    j = i;
                    continue Out;
                }
            }

//            result += 1 + name.length() - n - found;
            result += (long) (i - last) * (long) (name.length() - i - n + 1L);
            last = i;
            found++;
            i++;

        }

        int r = 0;
        OUt:
        for (int i = 0, len = name.length(); i <= len; i++) {
            for (int k = i + 1; k <= name.length(); k++) {
                int target = 0;
                for (char c : name.substring(i, k).toCharArray())
                    if (set.contains(c))
                        target = 0;
                    else {
                        target++;
                        if (target == n) {
                            r++;
                            break;
                        }
                    }
            }

        }
        if (r != result) System.err.println(name + "   " + n + "  " + r + "  result=" + result);
        return result;
    }


    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new FileReader("/Users/taobo2/Downloads/A-small-attempt1.in.txt"));

        Writer output = new BufferedWriter(new FileWriter("2013Roundc.1.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; ++i) {
            long result = new Consonants().solve(input.next(), input.nextInt());
            output.write("Case #" + i + ": " + result + "\n");
        }

        output.close();
        input.close();

    }
}
