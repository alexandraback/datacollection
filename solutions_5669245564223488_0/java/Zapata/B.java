import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Max Loewenthal
 */
public class B {
    private class Letter {
        Integer trainStartingWith = null;
        Integer trainEndsWith = null;
        Set<Integer> trainsConsistingOf = new HashSet<Integer>();
        Set<Integer> trainsContaining = new HashSet<Integer>();
        Character ending = null;
    }

    private Map<Character, Letter> letters = new HashMap<Character, Letter>();

    private boolean updateCharacter(char character, Integer start, Integer end, Integer consists, Integer contains, Character ending) {
        Letter letter  = letters.get(character);

        if (letter == null) {
            letter = new Letter();

            letters.put(character, letter);
        }

        if (ending != null) {
            letter.ending = ending;
        }

        if (start != null) {
            if (letter.trainStartingWith != null || !letter.trainsContaining.isEmpty()) {
                return false;
            }

            letter.trainStartingWith = start;
        }

        if (end != null) {
            if (letter.trainEndsWith != null || !letter.trainsContaining.isEmpty()) {
                return false;
            }

            letter.trainEndsWith = end;
        }

        if (consists != null) {
            if (!letter.trainsContaining.isEmpty()) {
                return false;
            }

            letter.trainsConsistingOf.add(consists);
        }

        if (contains != null) {
            if (!letter.trainsContaining.isEmpty() || !letter.trainsConsistingOf.isEmpty() || letter.trainStartingWith != null || letter.trainEndsWith != null) {
                return false;
            }

            letter.trainsContaining.add(consists);
        }

        return true;
    }

    public void solve(Scanner input, StringBuilder buffer) {
        letters = new HashMap<Character, Letter>();
        int count = input.nextInt();

        String[] trains = new String[count];
        for (int i = 0; i < count; i++) {
            trains[i] = input.next();
        }
        boolean possible = true;

        for (int i = 0; i < trains.length && possible; i++) {

            String train = trains[i];

            char start = train.charAt(0);
            int j = 1;
            while (j < train.length() && train.charAt(j) == start) {
                j++;
            }

            if (j >= train.length()) {
                possible = possible && updateCharacter(start, null, null, i, null, null);

                continue;
            }
            possible = possible && updateCharacter(start, i, null, null, null, null);

            char end = train.charAt(train.length() - 1);
            int k = train.length() - 2;
            while (k >= 0  && train.charAt(k) == end) {
                k--;
            }

            possible = possible && updateCharacter(end, null, i, null, null, null);
            possible = possible && updateCharacter(start, null, null, null, null, end);

            Character lastChar = null;

            for (int l = j; l <= k; l++) {
                if (lastChar == null || train.charAt(l) != lastChar) {
                    possible = possible && updateCharacter(train.charAt(l), null, null, null, i, null);
                    lastChar = train.charAt(l);
                }
            }
        }

        List<Integer> factors = new ArrayList<Integer>();

        if (!possible) {
            buffer.append("0");
        }
        else {
            Map<Character, Letter> copy = new HashMap<Character, Letter>(letters);

            int cycles = 0;
            while(true) {
                Character nextStart = null;
                for (Map.Entry<Character, Letter> entry : copy.entrySet()) {
                    if (entry.getValue().trainStartingWith != null &&entry.getValue().trainEndsWith == null) {
                        nextStart = entry.getKey();
                        break;
                    }
                }

                if (nextStart != null) {
                    cycles = cycles + 1;
                    Letter letter = copy.remove(nextStart);
                    while (letter != null && letter.trainStartingWith != null) {
                        factors.add(letter.trainsConsistingOf.size());
                        Character nextEnd = letter.ending;
                        letter = copy.remove(nextEnd);
                    }

                    if (letter != null)  {
                        factors.add(letter.trainsConsistingOf.size());
                    }
                }
                else {
                    for (Map.Entry<Character, Letter> entry : copy.entrySet()) {
                        if (entry.getValue().trainStartingWith != null || entry.getValue().trainEndsWith != null) {
                            buffer.append("0");
                            return;
                        }

                        if (entry.getValue().trainsConsistingOf.size() > 0) {
                            factors.add(entry.getValue().trainsConsistingOf.size());
                            cycles = cycles + 1;
                        }
                    }

                    break;
                }
            }

            factors.add(cycles);

            long result = 1;
            for (Integer factor: factors) {
                result = compute(result, factor);
            }

            buffer.append(Long.toString(result));
        }
    }

    private long compute(long number, long factor) {
        for (long i = 1; i <= factor; i ++) {
            number = (number * i) % 1000000007l;
        }

        return number;
    }

    public static void main(String[] args) {
        try {
            InputStream input = System.in;
            OutputStream output = System.out;

            if (args.length > 0) {
                input = new FileInputStream(new File(args[0]));
            }

            if (args.length > 1) {
                File outputFile = new File(args[1]);

                if (outputFile.exists()) {
                    throw new Exception("Output file already exists");
                }

                output = new FileOutputStream(new File(args[1]));
            }

            Scanner scanner = new Scanner(input);
            PrintWriter writer = new PrintWriter(output);

            B a = new B();

            int count = scanner.nextInt();
            scanner.nextLine();

            for (int i = 0; i < count; i++) {
                StringBuilder result = new StringBuilder();
                a.solve(scanner, result);


                writer.println("Case #" + (i + 1) + ": " + result.toString());
            }

            writer.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
