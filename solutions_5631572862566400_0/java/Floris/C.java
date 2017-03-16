import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Pattern;

public class C {
    static int[] primes = new int[1<<16];
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/C-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/dev/java/Codejam2016/src/C.out"));
        Scanner sc = new Scanner(in);
        sc.useDelimiter(Pattern.compile("[\n /]"));

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int kids = sc.nextInt();
            int[] bff = new int[kids];

            for (int i = 0; i < kids; i++) bff[i] = sc.nextInt()-1;


            System.out.printf("Case #%d: %d%n", c, find(kids, bff, new boolean[kids], -1));
        }
    }

    private static int find(int kids, int[] bff, boolean[] taken, int head1) {
        int max = 0;
        for (int start = 0; start < kids; start++) {
            if (taken[start]) continue;
//            System.out.println("start " + (start+1) + " head " +(head1+1));
            boolean[] part = Arrays.copyOf(taken, kids);
            int s = start;
            int count = 0;
            while (true) {
                int last = s;
                part[s] = true;
                s = bff[s];
                count++;
                if (bff[s] == last) {
                    part[s] = true;
                    count++;
//                    System.out.println("connect to " + (s+1));
                    count += find(kids, bff, part, s);
                    if (max<count) max= count;
                    break;
                }
                if (part[s]) {
                    if (head1 <0 && s == start) {
                        if (max<count) max= count;
                    }
                    if (head1 >=0 && s == head1) {
                        if (max<count) max= count;
                    }
                    break;
                }
            }
        }
        return max;
    }
}
