package ondra;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Digits {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        new Digits().run();
    }

    private void run() throws FileNotFoundException, IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt0.in"));
                PrintWriter writer = new PrintWriter(new FileWriter("A-small-attempt0.out"))) {
            String line;
            reader.readLine(); // ignore
            int c = 1;
            while ((line = reader.readLine()) != null) {
                boolean used[] = new boolean[line.length()];
                List<Character> resultList = new ArrayList<>();
                int count = findZeroes(line, used);
                for (int i = 0; i < count; i++) resultList.add('0');
                count = findTwos(line, used);
                for (int i = 0; i < count; i++) resultList.add('2');
                count = findEights(line, used);
                for (int i = 0; i < count; i++) resultList.add('8');
                count = findSixs(line, used);
                for (int i = 0; i < count; i++) resultList.add('6');
                count = findFours(line, used);
                for (int i = 0; i < count; i++) resultList.add('4');
                count = findThrees(line, used);
                for (int i = 0; i < count; i++) resultList.add('3');
                count = findOnes(line, used);
                for (int i = 0; i < count; i++) resultList.add('1');
                count = findFives(line, used);
                for (int i = 0; i < count; i++) resultList.add('5');
                count = findSevens(line, used);
                for (int i = 0; i < count; i++) resultList.add('7');
                count = findNines(line, used);
                for (int i = 0; i < count; i++) resultList.add('9');
//                System.out.println(line);
//                System.out.println(Arrays.toString(used));
                for (int i = 0; i < used.length; i++) if (!used[i]) throw new RuntimeException("Shouldn't happen.");
                Collections.sort(resultList);
                writer.write(String.format("Case #%d: ", c));
                for (int i = 0; i < resultList.size(); i++) writer.write(resultList.get(i));
                writer.println();
                c++;
            }
        }
    }

    private int findZeroes(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'Z') {
                used[i] = true;
                use(line, used, 'E');
                use(line, used, 'R');
                use(line, used, 'O');
                result++;
            }
        }
        return result;
    }

    private int findTwos(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'W') {
                used[i] = true;
                use(line, used, 'T');
                use(line, used, 'O');
                result++;
            }
        }
        return result;
    }

    private int findEights(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'G') {
                used[i] = true;
                use(line, used, 'E');
                use(line, used, 'I');
                use(line, used, 'H');
                use(line, used, 'T');
                result++;
            }
        }
        return result;
    }

    private int findSixs(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'X') {
                used[i] = true;
                use(line, used, 'S');
                use(line, used, 'I');
                result++;
            }
        }
        return result;
    }

    private int findFours(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'U') {
                used[i] = true;
                use(line, used, 'F');
                use(line, used, 'O');
                use(line, used, 'R');
                result++;
            }
        }
        return result;
    }

    private int findThrees(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'R') {
                used[i] = true;
                use(line, used, 'T');
                use(line, used, 'H');
                use(line, used, 'E');
                use(line, used, 'E');
                result++;
            }
        }
        return result;
    }

    private int findOnes(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'O') {
                used[i] = true;
                use(line, used, 'N');
                use(line, used, 'E');
                result++;
            }
        }
        return result;
    }

    private int findFives(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'F') {
                used[i] = true;
                use(line, used, 'I');
                use(line, used, 'E');
                use(line, used, 'V');
                result++;
            }
        }
        return result;
    }

    private int findSevens(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'S') {
                used[i] = true;
                use(line, used, 'E');
                use(line, used, 'V');
                use(line, used, 'E');
                use(line, used, 'N');
                result++;
            }
        }
        return result;
    }

    private int findNines(String line, boolean[] used) {
        int result = 0;
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == 'I') {
                used[i] = true;
                use(line, used, 'N');
                use(line, used, 'N');
                use(line, used, 'E');
                result++;
            }
        }
        return result;
    }

    private void use(String line, boolean[] used, char c) {
        for (int i = 0; i < line.length(); i++) {
            if (!used[i] && line.charAt(i) == c) {
                used[i] = true;
                return;
            }
        }
        throw new RuntimeException("Shouldn't get here.");
    }

}
