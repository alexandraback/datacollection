import java.util.*;

import static java.util.Arrays.sort;
import static util.FileHandler.*;

public class Digits {

    public static void main(String[] args) {
        start();

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        scanner.nextLine();
        for (int i = 1; i <= N; i++) {
            OUT.println(String.format("Case #%s: %s", i, solve(scanner.nextLine())));
        }

        end();
    }

    private static String solve(String s) {
        List<Number> numbers = init();

        Map<Character, Integer> elements = buildElements(s);

        String result = "";

        for (Number number : numbers) {
            int numOfValues = isOk(number, elements);
            if (numOfValues > 0) {
                for (int i = 0; i < numOfValues; i++) {
                    result += number.getActualValue();
                }

                for (Character character : number.getChars()) {
                    elements.put(character, elements.get(character) - numOfValues);
                }
            }
        }

        return sortResult(result);
    }

    private static int isOk(Number number, Map<Character, Integer> elements) {
        char def = number.getDef();

        if (elements.containsKey(def) && elements.get(def) > 0) {
            int min = Integer.MAX_VALUE;

            for (Character character : number.getChars()) {
                if (!elements.containsKey(character) || elements.get(character) == 0) {
                    return -1;
                } else {
                    if (elements.get(character) < min) {
                        min = elements.get(character);
                    }
                }
            }

            return min;
        } else {
            return -1;
        }
    }

    private static String sortResult(String result) {
        char[] chars = result.toCharArray();
        sort(chars);
        return new String(chars);
    }

    private static Map<Character, Integer> buildElements(String s) {
        Map<Character, Integer> elements = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (elements.containsKey(c)) {
                elements.put(c, elements.get(c) + 1);
            } else {
                elements.put(c, 1);
            }
        }
        return elements;
    }

    private static List<Number> init() {
        List<Number> numbers = new ArrayList<>();

        numbers.add(new Number('Z', 0, 'Z', 'E', 'R', 'O'));
        numbers.add(new Number('W', 2, 'T', 'W', 'O'));
        numbers.add(new Number('G', 8, 'E', 'I', 'G', 'H', 'T'));
        numbers.add(new Number('U', 4, 'F', 'O', 'U', 'R'));
        numbers.add(new Number('F', 5, 'F', 'I', 'V', 'E'));
        numbers.add(new Number('I', 6, 'S', 'I', 'X'));
        numbers.add(new Number('H', 3, 'T', 'H', 'R', 'E', 'E'));
        numbers.add(new Number('V', 7, 'S', 'E', 'V', 'E', 'N'));
        numbers.add(new Number('O', 1, 'O', 'N', 'E'));
        numbers.add(new Number('I', 9, 'N', 'I', 'N', 'E'));

        return numbers;
    }

    public static class Number {
        final Map<Character, Integer> letters = new HashMap<>();
        List<Character> chars = new ArrayList<>();
        final char def;
        final int actualValue;

        public Number(char def, int actualValue, char... characters) {
            for (char character : characters) {
                letters.put(character, 0);
                chars.add(character);
            }

            this.def = def;
            this.actualValue = actualValue;
        }

        public int getActualValue() {
            return actualValue;
        }

        public List<Character> getChars() {
            return chars;
        }

        public char getDef() {
            return def;
        }

        public String toString() {
            return letters.keySet().toString();
        }

    }

}
