import java.io.*;
import java.lang.String;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class C {
    private static List<BigInteger> values;

    private static void testValue(String s) {      
        BigInteger v = new BigInteger(s);
        BigInteger ans = v.multiply(v);
        String ansStr = ans.toString();
        for (int i = 0; i < ansStr.length(); ++i) {
            if (ansStr.charAt(i) != ansStr.charAt(ansStr.length() - 1 - i))
                return;
        }
        values.add(ans);
    }

    private static void initializeValues() {
        values = new ArrayList<BigInteger>();
        for (int i = 1; i <= 10; ++i) {
            int bits = i / 2, maxVal = 1;
            for (int j = 0; j < bits; ++j)
                maxVal *= 10;
            for (int num = 0; num < maxVal; ++num) {
                int[] digits = new int[bits];
                int tmp = num;
                for (int j = 0; j < bits; ++j) {
                    digits[j] = tmp % 10;
                    tmp /= 10;
                }
                if (bits >= 1 && digits[bits - 1] == 0)
                    continue;
                String first = "", second = "";
                for (int j = 0; j < bits; ++j) {
                    first += digits[bits - 1 - j];
                    second += digits[j];
                }
                if (i % 2 == 0)
                    testValue(first + second);
                else {
                    for (int j = 0; j <= 9; ++j)
                        testValue(first + j + second);
                }
            }
        }
    }

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintStream cout = System.out;      

        initializeValues();
        // for (int i = 0; i < values.size(); ++i) {
        //    cout.printf("%s\n", values.get(i).toString());
        // }
        int numOfCases = Integer.parseInt(in.readLine());
		for (int caseNo = 1; caseNo <= numOfCases; ++caseNo) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			BigInteger a = new BigInteger(st.nextToken()), b = new BigInteger(st.nextToken());
            int ans = 0;
            for (int i = 0; i < values.size(); ++i) {
                if (a.compareTo(values.get(i)) != 1 && values.get(i).compareTo(b) != 1) {
                    ++ans;
                }
            }
            cout.printf("Case #%d: %s\n", caseNo, ans);
		}
		cout.flush();
	}
}


