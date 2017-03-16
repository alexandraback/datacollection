import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main
{
    static ArrayList<BigInteger> squaredPalindromes = new ArrayList<BigInteger>();
    static int case_i;
    static int T;
    static BigInteger A, B;


    public static void loadPalindromes() throws IOException{
        FileReader stream = new FileReader("b");
        BufferedReader reader = new BufferedReader(stream);
        String line = null;
        while ((line = reader.readLine()) != null) {
            BigInteger bigint = new BigInteger(line);
            squaredPalindromes.add(bigint);
        }
    }

    static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        BigInteger res = a.subtract(BigInteger.ONE);
        if (res.multiply(res).compareTo(n) != 0) {
            return new BigInteger("24356789");
        }
        return res;
    }

    private static boolean isPalindrome(String s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    static void doCase(){
        int count = 0;
        for (BigInteger i : squaredPalindromes) {
            if (i.compareTo(A) >= 0 && i.compareTo(B) <= 0) {
//                System.out.println(sqrt(i));
                count++;
            }
        }

        System.out.println(String.format("Case #%d: %d", case_i + 1, count));
    }

    public static void main(String[] args) throws IOException{
        loadPalindromes();
//        FileWriter stream = new FileWriter("b");
//        BufferedWriter reader = new BufferedWriter(stream);
//        for (BigInteger i : squaredPalindromes) {
//            BigInteger sq = sqrt(i);
//            if (isPalindrome(sq.toString())) {
//                reader.write(i.toString() + "\n");
//            }
//        }
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        T = Integer.parseInt(br.readLine());

        for (case_i = 0; case_i < T; ++case_i) {
           String line = br.readLine();
           String[] split = line.split(" ");
           A = new BigInteger(split[0]);
           B = new BigInteger(split[1]);

           doCase();
        }
    }
}