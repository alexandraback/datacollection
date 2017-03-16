import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Google Code Jam 2012
 * 
 * @author 7henick
 */
public class ProblemC {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        // A <= n < m <= B
        for (int i = 0; i < T; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            int count = 0;

            for (int n = A; n < B; n++) {
                String nString = String.valueOf(n);
                Set<Integer> intSet = new HashSet<Integer>();

                for (int j = 1; j < nString.length(); j++) {
                    char idx = nString.charAt(j);

                    if (idx != '0') {
                        String mString = nString.substring(j)
                                + nString.substring(0, j);
                        int m = Integer.valueOf(mString);

                        if (n < m && m <= B) {
                            intSet.add(m);
                        }
                    }
                }
                count += intSet.size();
            }

            System.out.println("Case #" + (i + 1) + ": " + count);
            if (sc.hasNextLine()) {
                sc.nextLine();
            }
        }
    }

    public static boolean isValid(int n, int m, int B) {
        return n < m && m <= B;
    }
}
