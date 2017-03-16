package codejam2014;

import java.util.*;

/**
 * Created by kong
 * Time: 5/11/2014 12:42 PM
 */
public class Trains {

    public static final long MOD = 1000000007L;

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int tests = s.nextInt();
        for (int t = 1; t <= tests; t++) {
            int cars = s.nextInt();
            s.nextLine();
            String line = s.nextLine();
            String[] carsParts = line.split(" ");
            if (carsParts.length != cars)
                System.out.println("Parse error");

            long rez = solve(carsParts);

            System.out.printf("Case #%d: %d\n", t, rez);
        }
    }

    private static long solve(String[] cars) {
        Map<Character, Set<Integer>> char2cars = new HashMap<Character, Set<Integer>>();
        for (int i = 0; i < cars.length; i++) {
            String car = cars[i];
            for (int j = 0; j < car.length(); j++) {
                char c = car.charAt(j);
                Set<Integer> cars4char = char2cars.get(c);
                if (cars4char == null) {
                    cars4char = new HashSet<Integer>();
                    char2cars.put(c, cars4char);
                }
                cars4char.add(i);
            }
        }

        long rez = 1;
        int connected = 0, cons = 0;
        for (char c :char2cars.keySet()) {
            Set<Integer> cs = char2cars.get(c);
            if (cs.size() > 1) {
                connected += cs.size();
                cons++;
                long modes = modes2connect(cars, c, cs);
                rez *= modes;
                rez %= MOD;
            }
        }

//        Set<Character> lset = char2cars.keySet();
//        List<Character> llist = new ArrayList<Character>(lset);
//        for (int i = 0; i < llist.size(); i++) {
//            Set<Integer> s1 = char2cars.get(llist.get(i));
//            if (s1.size() == 1)
//                continue;
//            for (int j = 0; j < llist.size(); j++) {
//                Set<Integer> s2 = char2cars.get(llist.get(j));
//                if (s2.size() == 1)
//                    continue;
//                s1.retainAll(s2);
//                if (s1.size() > 0)
//                    cons--;
//            }
//        }

        rez *= factMod(cars.length - connected + cons);
        rez %= MOD;

        return rez;
    }

    private static long modes2connect(String[] cars, char c, Set<Integer> cs) {
        for (int carNo : cs) {
            String car = cars[carNo];
            if (car.length() > 2 && car.charAt(0) != c && car.charAt(car.length() - 1) != c)
                return 0;
        }

        int starts = 0, ends = 0;
        for (int carNo : cs) {
            String car = cars[carNo];
            if (car.charAt(0) == c && car.charAt(car.length() - 1) == c) { // connectors
                continue;
            }
            if (car.charAt(0) == c) {
                ends++;
                continue;
            }
            if (car.charAt(car.length() - 1) == c) {
                starts++;
            }
        }

        if (starts > 1 || ends > 1)
            return 0;

        return factMod(cs.size() - starts - ends);
    }

    private static String contract(String[] cars, char c, Set<Integer> cs) {
        for (int carNo : cs) {
            String car = cars[carNo];
            if (car.length() > 2 && car.charAt(0) != c && car.charAt(car.length() - 1) != c)
                return null;
        }

        int starts = 0, ends = 0;
        char start = c, end = c;
        for (int carNo : cs) {
            String car = cars[carNo];
            if (car.charAt(0) == c && car.charAt(car.length() - 1) == c) { // connectors
                continue;
            }
            if (car.charAt(0) == c) {
                ends++;
                end = car.charAt(car.length() - 1);
                continue;
            }
            if (car.charAt(car.length() - 1) == c) {
                starts++;
                start = car.charAt(0);
            }
        }

        if (starts > 1 || ends > 1)
            return null;

        return "" + start + "" + end;
    }

    private static long factMod(int n) {
        long rez = 1;
        for (int i = 2; i <= n; i++) {
            rez *= i;
            rez %= MOD;
        }

        return rez;
    }

}

