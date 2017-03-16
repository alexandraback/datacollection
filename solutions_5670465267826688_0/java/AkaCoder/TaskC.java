import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by admin on 4/11/2015.
 */
public class TaskC {

    static void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            st = null;
            out.println("Case #" + testCase + ": " + solve());
        }
    }

    static String solve() throws IOException{
        int L = nextInt();
        Long X = nextLong();
        String input = nextToken();
        StringBuilder totalLine = new StringBuilder();

        for (Long i = (long) 0; i < X; i++) {
            totalLine.append(input);
        }

        input = totalLine.toString();


        if (input.length() < 3) {
            return "NO";
        }

        int curPosition = 0;
        Unit privUnit = new Unit(1, '1'),
                iUnit = new Unit(1, 'i'),
                jUnit = new Unit(1, 'j'),
                kUnit = new Unit(1, 'k'),
                oneUnit = new Unit(1, '1');
        Unit curUnit = new Unit();
        boolean iFound = false, jFound = false, kFound = false, oneFound = false;
        for (; curPosition < input.length() ; curPosition++ ) {
            curUnit = multiple(privUnit, new Unit(1, input.charAt(curPosition)));
            privUnit = curUnit;
            if (curUnit.equals(iUnit)) {
                iFound = true;
                curPosition++;

                privUnit = oneUnit;
                break;
            }
        }
        if (iFound == false) {
            return "NO";
        }


        for (; curPosition < input.length() ; curPosition++ ) {
            curUnit = multiple(privUnit, new Unit(1, input.charAt(curPosition)));
            privUnit = curUnit;
            if (curUnit.equals(jUnit)) {
                jFound = true;
                curPosition++;
                privUnit = oneUnit;
                break;
            }
        }
        if (jFound == false) {
            return "NO";
        }


        for (; curPosition < input.length() ; curPosition++ ) {
            curUnit = multiple(privUnit, new Unit(1, input.charAt(curPosition)));
            privUnit = curUnit;
            if (curUnit.equals(kUnit)) {
                kFound = true;
                curPosition++;

                privUnit = oneUnit;
                break;
            }
        }
        if (kFound == false) {
            return "NO";
        }

        if (curPosition == input.length()) {
            return "YES";
        }


        for (; curPosition < input.length() ; curPosition++ ) {
            curUnit = multiple(privUnit, new Unit(1, input.charAt(curPosition)));
            privUnit = curUnit;
        }
        if (curUnit.equals(oneUnit)) {
            return "YES";
        } else {
            return "NO";
        }

    }

    static class Unit {
        int sign;
        Character value;
        public Unit(int sign, Character value) {
            super();
            this.sign = sign;
            this.value = value;
        }

        public boolean equals(Unit anotherUnit) {
            return (this.sign == anotherUnit.sign) && (this.value.equals(anotherUnit.value));
        }

        public Unit() {}
    }



    static Unit multiple(Unit a, Unit b) {

        int iSign = a.sign * b.sign;

        if (a.value.equals('1')) {
            return new Unit(iSign, b.value);
        } else if (b.value.equals('1')) {
            return new Unit(iSign, a.value);
        } else if (a.value.equals(b.value)) {
            return new Unit(iSign * -1, '1');
        } else {
            if (a.value.equals('i') && b.value.equals('j')) {
                // i * j = k
                return new Unit(iSign, 'k');
            } else if (a.value.equals('i') && b.value.equals('k')) {
                // i * k = -j
                return new Unit(iSign * -1, 'j');
            } else if (a.value.equals('j') && b.value.equals('i')) {
                // j * i = -k
                return new Unit(iSign * -1, 'k');
            } else if (a.value.equals('j') && b.value.equals('k')) {
                // j * k = i
                return new Unit(iSign, 'i');
            } else if (a.value.equals('k') && b.value.equals('i')) {
                // k * i = j
                return new Unit(iSign, 'j');
            } else if (a.value.equals('k') && b.value.equals('j')) {
                // k * j = -i
                return new Unit(iSign * -1, 'i');
            }
        }
        return null;
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("gcj/a.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
            output = new PrintStream(new File("a.out"));
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solveMultiTest();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static String nextLine() throws IOException {
        String line=null;
        line = br.readLine();
        System.out.println(line);
        return line;
    }

}
