import java.util.*;

/**
 * Created by study on 4/15/16.
 */
public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.print(String.format("Case #%d: ", i));
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        String S = scanner.next();

        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < S.length(); i++) {
            Character key = S.charAt(i);
            if (map.containsKey(key)) {
                map.put(key, map.get(key) + 1);
            } else {
                map.put(key, 1);
            }
        }
        List<Integer> rst = test(map);
        Collections.sort(rst);

        for (int d : rst) {
            System.out.print(d);
        }
        System.out.println();
    }

    public static List<Integer> test(Map<Character, Integer> map) {
        List<Integer> rst = new ArrayList<>();
        if (map.containsKey('Z') && map.get('Z') > 0) { // "ZERO"
            int c = map.get('Z');
            map.put('Z', 0);
            map.put('E', map.get('E') - c);
            map.put('R', map.get('R') - c);
            map.put('O', map.get('O') - c);
            for (int i = 0; i < c; i++) {
                rst.add(0);
            }
        }
        if (map.containsKey('U') && map.get('U') > 0) { //  "FOUR"
            int c = map.get('U');
            map.put('F', map.get('F') - c);
            map.put('O', map.get('O') - c);
            map.put('U', 0);
            map.put('R', map.get('R') - c);
            for (int i = 0; i < c; i++) {
                rst.add(4);
            }
        }
        if (map.containsKey('X') && map.get('X') > 0) { // "SIX"
            int c = map.get('X');
            map.put('S', map.get('S') - c);
            map.put('I', map.get('I') - c);
            map.put('X', 0);
            for (int i = 0; i < c; i++) {
                rst.add(6);
            }
        }
        if (map.containsKey('S') && map.get('S') > 0) { // "SEVEN"
            int c = map.get('S');
            map.put('S', 0);
            map.put('E', map.get('E') - 2 * c);
            map.put('V', map.get('V') - c);
            map.put('N', map.get('N') - c);

            for (int i = 0; i < c; i++) {
                rst.add(7);
            }
        }
        if (map.containsKey('V') && map.get('V') > 0) { // "FIVE"
            int c = map.get('V');
            map.put('F', map.get('F') - c);
            map.put('I', map.get('I') - c);
            map.put('V', 0);
            map.put('E', map.get('E') - c);

            for (int i = 0; i < c; i++) {
                rst.add(5);
            }
        }
        if (map.containsKey('G') && map.get('G') > 0) { // "EIGHT"
            int c = map.get('G');
            map.put('E', map.get('E') - c);
            map.put('I', map.get('I') - c);
            map.put('G', 0);
            map.put('H', map.get('H') - c);
            map.put('T', map.get('T') - c);

            for (int i = 0; i < c; i++) {
                rst.add(8);
            }
        }
        if (map.containsKey('R') && map.get('R') > 0) { // "THREE"
            int c = map.get('R');
            map.put('E', map.get('E') - 2 * c);
            map.put('T', map.get('T') - c);
            map.put('H', map.get('H') - c);
            map.put('R', 0);

            for (int i = 0; i < c; i++) {
                rst.add(3);
            }
        }
        if (map.containsKey('T') && map.get('T') > 0) { // "TWO"
            int c = map.get('T');
            map.put('W', map.get('W') - c);
            map.put('T', 0);
            map.put('O', map.get('O') - c);

            for (int i = 0; i < c; i++) {
                rst.add(2);
            }
        }

        if (map.containsKey('O') && map.get('O') > 0) { // "ONE"
            int c = map.get('O');
            map.put('E', map.get('E') - c);
            map.put('N', map.get('N') - c);
            map.put('O', 0);

            for (int i = 0; i < c; i++) {
                rst.add(1);
            }
        }

        if (map.containsKey('I') && map.get('I') > 0) { // "NINE"
            int c = map.get('I');
            map.put('I', 0);
            map.put('N', map.get('N') - 2 * c);
            map.put('E', map.get('E') - c);

            for (int i = 0; i < c; i++) {
                rst.add(9);
            }
        }

        return rst;
    }
}
