import java.util.*;
import java.math.BigInteger;

public class C {

    public static void main(String[] args) {
        C instance = new C(20);
        System.err.println(instance.numbers.size());

        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int cs = 1; cs <= cases; cs++) {
            BigInteger a = new BigInteger(scanner.next());
            BigInteger b = new BigInteger(scanner.next());
            System.out.printf("Case #%d: %d\n", cs, instance.range(a,b));
        }
    }

    final BigInteger limit;
    final List<BigInteger> numbers;

    C(int exp) {
        limit = BigInteger.TEN.pow(exp);
        numbers = new LinkedList<BigInteger>();

        check("1");
        check("2");
        check("3");

        int i = 1;
        while (true) {
            String s = Integer.toBinaryString(i);
            String t = new StringBuilder(s).reverse().toString();

            if (check(s+t))
                break;

            check(s+"0"+t);
            check(s+"1"+t);
            check(s+"2"+t);

            i++;
        }

        String s = "2";
        while (true) {
            String t = new StringBuilder(s).reverse().toString();

            if (check(s+t))
                break;

            check(s+"0"+t);
            check(s+"1"+t);
            check(s+"2"+t);

            s = s + "0";
        }
    }

    boolean check(String p) {
        BigInteger n = new BigInteger(p).pow(2);

        if (n.compareTo(limit) > 0)
            return true;

        if (palindrome(n)) 
            numbers.add(n);

        return false;
    }

    boolean palindrome(BigInteger n) {
        String d = n.toString();
        int s = d.length();
        for (int i = 0; i < s; i++)
            if (d.charAt(i) != d.charAt(s-1-i))
                return false;

        return true;
    }

    int range(BigInteger a, BigInteger b) {
        int res = 0;
        for (BigInteger n : numbers)
            if (a.compareTo(n) <= 0 && b.compareTo(n) >= 0)
                res++;
        return res;
    }
}
