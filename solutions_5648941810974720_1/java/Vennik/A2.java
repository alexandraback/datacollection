import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class A2 {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("A-large (1).in"));
        FileWriter fw = new FileWriter(new File("a.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new A2().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    List<String> strings = Arrays.asList("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE");


    private String solve(Scanner sc) {

        List<Integer> found = new ArrayList<>();

        int[] counter = new int[26];

        for (char c : sc.next().toCharArray()) {
            counter[c - 'A']++;
        }

        while (counter['Z' - 'A'] > 0) {
            found.add(0);
            counter['Z' - 'A']--;
            counter['E' - 'A']--;
            counter['R' - 'A']--;
            counter['O' - 'A']--;
        }

        while (counter['X' - 'A'] > 0) {
            found.add(6);
            counter['S' - 'A']--;
            counter['I' - 'A']--;
            counter['X' - 'A']--;
        }

        while (counter['W' - 'A'] > 0) {
            found.add(2);
            counter['T' - 'A']--;
            counter['W' - 'A']--;
            counter['O' - 'A']--;
        }

        while (counter['U' - 'A'] > 0) {
            found.add(4);
            counter['F' - 'A']--;
            counter['O' - 'A']--;
            counter['U' - 'A']--;
            counter['R' - 'A']--;
        }

        while (counter['O' - 'A'] > 0) {
            found.add(1);
            counter['O' - 'A']--;
            counter['N' - 'A']--;
            counter['E' - 'A']--;
        }

        while (counter['G' - 'A'] > 0) {
            found.add(8);
            counter['E' - 'A']--;
            counter['I' - 'A']--;
            counter['G' - 'A']--;
            counter['H' - 'A']--;
            counter['T' - 'A']--;
        }

        while (counter['T' - 'A'] > 0) {
            found.add(3);
            counter['T' - 'A']--;
            counter['H' - 'A']--;
            counter['R' - 'A']--;
            counter['E' - 'A']--;
            counter['E' - 'A']--;
        }

        while (counter['F' - 'A'] > 0) {
            found.add(5);
            counter['F' - 'A']--;
            counter['I' - 'A']--;
            counter['V' - 'A']--;
            counter['E' - 'A']--;
        }

        while (counter['I' - 'A'] > 0) {
            found.add(9);
            counter['N' - 'A']--;
            counter['I' - 'A']--;
            counter['N' - 'A']--;
            counter['E' - 'A']--;
        }

        while (counter['S' - 'A'] > 0) {
            found.add(7);
            counter['S' - 'A']--;
            counter['E' - 'A']--;
            counter['V' - 'A']--;
            counter['E' - 'A']--;
            counter['N' - 'A']--;
        }

        Collections.sort(found);

        return found.stream().map(Object::toString).collect(Collectors.joining());

    }

}
