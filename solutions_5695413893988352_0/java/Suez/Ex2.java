import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ex2 {
    private static String input = "B-small-attempt2.in";
    private static String output = "out.txt";
    private PrintWriter out;
    private long m;
    private int n;
    private final int max = 1000;
    private final int maxN = 3;

    private String[][] dict = new String[maxN+1][max];

    public int execute(String s1, String s2) {
        this.n = s1.length();
        int min = Integer.MAX_VALUE;
        int ans1 = 0;
        int ans2 = 0;
        this.m = (long)Math.pow(10, n);
        System.out.println("m=" + m);
        for (int i=0; i<m; i++) if (match(s1, dict[n][i])) {
            for (int j=0; j<m; j++) if (match(s2, dict[n][j])) {
                int dist = Math.abs(i-j);
                if (dist < min || (dist == min && i<ans1) || (dist == min && i==ans1 && j<ans2)) {
                    min = Math.abs(i-j);
                    ans1 = i;
                    ans2 = j;
                }
            }
        }

        out.print(dict[n][ans1] + " " + dict[n][ans2]);
        return 1;
    }

    private String str (int i) {
        return String.format("%"+n+"d", i).replace(' ', '0');
    }

    private boolean match (String s1, String s2) {
        int n = s1.length();
        for (int i=0; i<n; i++) {
            if (s1.charAt(i) == '?' || s2.charAt(i) == '?') continue;
            if (s1.charAt(i) != s2.charAt(i)) return false;
        }
        return true;
    }


    private void initDict() {
        for (int j=1; j<=maxN; j++) {
            for (int i=0; i<max; i++) {
                n=j;
                dict[j][i]=str(i);
            }
        }
    }

    public void runTests(Scanner input) throws FileNotFoundException {
        initDict();
        out = new PrintWriter(output);
        int testsNo = Integer.valueOf(input.nextLine());

        for (int i=1; i<=testsNo; i++) {
            String[] someData = input.nextLine().split(" ");

            out.print("Case #"+i+": ");
            execute(someData[0], someData[1]);
            out.println();

        }
        out.close();
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new FileInputStream(input));
        new Ex2().runTests(file);
        file.close();
    }
}
