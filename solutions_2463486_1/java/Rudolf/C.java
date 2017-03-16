import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;

public class C {
    public static void main(String... args) throws FileNotFoundException {
        String name = "C-large-1";
        Scanner sc = new Scanner(new FileInputStream(name + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(name + ".out")));
        prepare();
        int t = sc.nextInt();
        for (int ti = 0; ti < t; ti++) {
/*/
            long a = sc.nextLong();
            long b = sc.nextLong();
            long result = solveLong(a, b);
/*/
            String a = sc.next();
            String b = sc.next();
            long result = solveStrings(a, b);
/**/
//            long str = solveLong(Long.valueOf(a), Long.valueOf(b));
//            if(str != result) {
//                debug("ERROR");
//            }
            System.out.println("Case #" + (ti + 1) + ": " + result);
        }
    }

    private static void prepare() {
        long count = 0;
        int l = 30;
                /*
        Смысл в том, что сумма x[i]^2 < 10 где x*x искомое число
        Из этого следует что можно использовать числа в такой комбинации
        111111111
        2 11111
        221

         */

        // 1 x 9
        count += go('0', "1", 4, 0, l);
        count += go('1', "1", 4, 0, l);

        count += go(null, "1", 4, 0, l);
        // 1 x 5, 2 x 1
        count += go('0', "1", 2, 0, l);
        count += go('1', "1", 2, 0, l);

        count += go('2', "1", 2, 0, l);

        count += go(null, "1", 2, 0, l);
        // 1 x 1, 2 x 2
        count += go('0', "2", 0, 0, l);
        count += go('1', "2", 0, 0, l);

        count += go(null, "2", 0, 0, l);

    }

    private static TreeSet<String> from = new TreeSet<String>(new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            if(o1.length() != o2.length())
                return o1.length() - o2.length();
            return o1.compareTo(o2);
        }
    }){{
        add("1");
        add("4");
        add("9");
        add("121");
        add("484");
    }};

    private static long solveStrings(String a, String b) {
        NavigableSet<String> strings = from.subSet(a, true, b, true);
        int size = strings.size();
        return size;
    }

    private static boolean add(String s) {
        if(isPolyndrom(s)) {
            BigInteger bigInteger = new BigInteger(s);
            String s1 = bigInteger.pow(2).toString();
            if(isPolyndrom(s1)) {
                from.add(s1);
                return true;
            }
        }
        return false;
    }


    private static long go(Character delimiter, String start, int i1, int i2, int length) {
        long res = 0;
        {
            String r;
            if(delimiter != null)
                r = start + delimiter + (new StringBuilder(start).reverse().toString());
            else
                r = start + (new StringBuilder(start).reverse().toString());

            if(add(r))
                res++;
        }
        if(length == 0) {
            return res;
        }
        if(i1 != 0) {
            res += go(delimiter, start + "1", i1-1, i2, length - 1);
        }
        if(i2 != 0) {
            res += go(delimiter, start + "2", i1, i2, length - 1);
        }
        res += go(delimiter, start + "0", i1, i2, length - 1);
        return res;
    }

    private static long solveLong(long a, long b) {
        Set<String> set = new TreeSet<String>(from.subSet(a+"", true, b+"", true));
        long sqrt = (long) Math.sqrt(a);
        while (sqrt * sqrt < a) sqrt++;
        long res = 0;
        for (long d = sqrt; d * d <= b; d++) {
            if (isPolyndrom(d + "") && isPolyndrom((d * d) + "")) {
                res++;
                debug(d + "*" + d + " = " + d*d);
                if(set.contains(d*d + ""))
                    set.remove(d*d + "");
                else
                    debug("NOT FOUND: " + (d * d));
            }
        }
        for(String left: set){
            debug("LEFT: " + left);
        }
        return res;
    }

    private static boolean isPolyndrom(String s) {
        for(int i = 0; i < (s.length()+1)/2; i++)
            if(s.charAt(i) != s.charAt(s.length() - i - 1))
                return false;
        return true;
    }
    private static void debug(String s) {
//        System.out.println(s);
    }
}
