import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;

/**
 * User: jlee
 * Date: 11/1/12
 * Time: 11:30 AM
 */
public class R1B2013 extends CodeJam {


    double inf = Double.MAX_VALUE;
    LinkedList<Long> list = new LinkedList<Long>();

    public R1B2013(String fileName) throws IOException {
        super(fileName);

    }

    protected void init() {
        for (long i = 0; i < 40000000; i++) {
            if (isPalindrome(i) && isPalindrome(i*i)) {
                list.add(i * i);
            }
        }
    }


    protected void solve() {
        try {
            String[] row = br.readLine().split("\\s+");

            long start = Long.parseLong(row[0]);
            long end = Long.parseLong(row[1]);

            Iterator<Long> iterator = list.listIterator();

            int count = 0;

            while (iterator.hasNext()) {
                long fair = iterator.next();
                if (fair >= start) {
                   if (fair <= end) {
                       count++;
                       System.out.println(fair);
                   } else {
                       break;
                   }
                }
            }

            printResult(count + "");

        } catch (Exception e) {
            e.printStackTrace();
        }


    }

    protected boolean isPalindrome(long in) {
        String number = in + "";

        for (int i = 0; i < number.length() / 2; i++ ) {
            if (number.charAt(i) == number.charAt(number.length() - i - 1)) {
            } else {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {

        String fileName = "A-";

        if (args[0].compareTo("small") == 0) {
            fileName += "small";
        } else if (args[0].compareTo("large") == 0) {
            fileName += "large";
        } else if (args[0].compareTo("sample") == 0) {
            fileName += "sample";
        } else {
            System.out.println("small or large or sample");
            return;
        }

        if (args[1].compareTo("1") == 0) {
            fileName += "-practice.in.txt";
        } else {
            fileName += ".in.txt";
        }

        try {
            R1B2013 codeJam = new R1B2013(fileName);
            codeJam.run();
        } catch (IOException e) {
            System.err.print(e);
        }
    }
}
