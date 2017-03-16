package codejam15;

import java.io.*;

public class omino {
    public static void main(String[] args) throws NumberFormatException,
            IOException {

//        int count = 0;
//        for (int i = 1; i <= 4; i++) {
//            for (int j = 1; j <= 4; j++) {
//                for (int k = 1; k <= 4; k++) {
//                    if ((i > j && i > k) || i == 1 || i == 2 || j * k % i != 0 || (j == 1 || k ==1)) {
//                        count++;
//                    } else {
//                        System.out.println(i + " -> " + j + " " + k);
//                    }
//                }
//            }
//        }
//        System.out.println(count);
//
//        if (true) {
//            System.exit(0);
//        }
        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in), 1024 * 1024 * 2);

        int t = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int x = 1; x <= t; x++) {
            int y[] = readArrayLine(br.readLine(), 3);
            int X = y[0];
            int r = y[1];
            int c = y[2];

            sb.append("Case #" + x + ": " + (f(X, r, c) ? "RICHARD" : "GABRIEL") + "\n");
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outCJam.txt"));
        bw.write(sb.toString());
        bw.close();
        System.out.println(sb.toString());
    }

    public static boolean f(int x, int r, int c) {
        if (r > c) {
            int tmp = r;
            r = c;
            c = tmp;
        }

        //can obtain an overlapping omino
        if (x > r && x > c) {
            return true;
        }

        //if the grid cannot be filled by X-ominos
        if (r * c % x != 0) {
            return true;
        }

        //1-omino and 2 will be always filled in this point
        if (x == 1 || x == 2) {
            return false;
        }

        if (r == 1) {
            return true;
        }

        if (r == 2 && c ==4 ) {
            return true;
        }

        return false;
    }

    public static int[] readArrayLine(String line, int n) {
        int[] ret = new int[n];
        int start = 0;
        int end = line.indexOf(' ', start);
        for (int i = 0; i < n; i++) {
            if (end > 0)
                ret[i] = Integer.parseInt(line.substring(start, end));
            else
                ret[i] = Integer.parseInt(line.substring(start));
            start = end + 1;
            end = line.indexOf(' ', start);
        }
        return ret;
    }
}
