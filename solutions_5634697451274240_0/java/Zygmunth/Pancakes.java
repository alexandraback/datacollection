package me;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.text.MessageFormat;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

@SuppressWarnings("Duplicates")
public class Pancakes {
    public static int solve(List<Character> list, int s, int e, int d, char sf) {

        Integer found = null;
        for (int i = s; d*i <= d*e; i += d) {
            if (sf == list.get(i)) {
                found = i;
                break;
            }
        }
        if (found == null) {
            return 0;
        }

        if (found == e) {
            return 1;
        }

        return 1 + solve(list, found+d,e,d,flip(sf));

    }

    public static void main(String[] args) throws IOException {
        File file = new File("/Users/prv/IdeaProjects/CodeJam/in.txt");
        FileWriter out = new FileWriter("/Users/prv/IdeaProjects/CodeJam/out.txt");
        Scanner scanner = new Scanner(file);
        int caseCount = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < caseCount; i++) {
            List<Character> list = scanner.nextLine().chars().mapToObj(e -> (char) e).collect(Collectors.toList());
            char sf = '-';
            int res = solve(list, list.size()-1,0,-1,'-');
//            if (res != null) {
            out.write(MessageFormat.format("Case #{0,number,#}: {1,number,#}\n", i + 1, res));
//            } else {
//                out.write(MessageFormat.format("Case #{0,number,#}: INSOMNIA\n", i+1));
//            }
        }
        out.close();
    }

    public static char flip(char c) {
        return c == '-' ? '+' : '-';
    }
}
