import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class C {

    public static void main(String[] args) throws Throwable {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            System.out.println("Case #" + c + ": " + solveCase(reader.readLine()));
        }
    }

    private static int solveCase(String line) {
        String[] tokens = line.split(" ");
        int a = Integer.parseInt(tokens[0]);
        int b = Integer.parseInt(tokens[1]);
        Set<String> alreadyFound;

        int count = 0;

        if (b > 9) {
            for (int n = a; n <= b; n++) {
                String nstr = String.valueOf(n);
                int nlen = nstr.length();
                alreadyFound = new HashSet<String>();
                for (int index = 1; index < nlen; index++) {
                    String mstr = nstr.substring(index, nlen) + nstr.substring(0, index);
                    int m = Integer.parseInt(mstr);
                    mstr = String.valueOf(m);
                    if (mstr.length() == nlen && alreadyFound.add(mstr)) {
                        if (m > n && m >=a && m <= b) {
                            count++;
                        }
                    }
                }

            }
        }

        return count;
    }
}
