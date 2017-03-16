import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class T2 {
    private static int num = 2000000;
    private static int res;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("B-small-attempt1.in"));
        int cases = sc.nextInt();
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
        int point[] = new int[2];
        nextCase:
        for (int ks = 0; ks < cases; ks++) {
            if (ks != 0) {
                out.newLine();
            }
            point[0] = sc.nextInt();
            point[1] = sc.nextInt();
            int pointSum = Math.abs(point[0]) + Math.abs(point[1]);
            int step = 1;
            int curr = step;
            int resStep = 0;
            while (true) {
                if (curr >= pointSum &&
                        ((pointSum % 2 == 1 && curr % 2 == 1) || (pointSum % 2 == 0 && curr % 2 == 0))) {
                    resStep = step;
                    break;
                }
                step++;
                curr += step;
            }
            StringBuilder sb = new StringBuilder();
            while (resStep != 0) {
                if (Math.abs(point[0]) > Math.abs(point[1])) {
                    if (point[0] > 0) {
                        point[0] -= resStep;
                        sb.append('E');
                    } else {
                        point[0] += resStep;
                        sb.append('W');
                    }
                } else {
                    if (point[1] > 0) {
                        point[1] -= resStep;
                        sb.append('N');
                    } else {
                        point[1] += resStep;
                        sb.append('S');
                    }
                }
                resStep--;
            }
            out.write("Case #" + (ks + 1) + ": " + sb.reverse());
        }
        out.close();

    }
}
