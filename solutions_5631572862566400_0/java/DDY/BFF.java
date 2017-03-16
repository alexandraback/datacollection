package CodeJam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class BFF {


    public int bff(int[] nums) {

        int[] easy = new int[nums.length+1];
        for (int i = 0; i < nums.length; i++) {
            easy[i+1] = nums[i];
        }
        boolean f = false;
        boolean stop = false;
        int max = 0;
        for (int i = 1;i <= nums.length; i++) {
            int cnt = 0;
            int idx = i;
            boolean[] b = new boolean[nums.length+1];
            stop = false;
            int last = 0;
            while (!stop) {
                while (true) {
                    if (!b[idx]) {
                        cnt++;
                    } else {
                        idx = last;
                        break;
                    }
                    b[idx] = true;
                    last = idx;
                    idx = easy[idx];
                }
                stop = true;
                if (cnt == nums.length) {
                    int tmp = easy[idx];
                    if (easy[tmp] != idx && tmp != i) {
                        cnt = 0;
                    }
                }



                for (int j = 1; j <= nums.length; j++) {
                    if (easy[j] == idx && !b[j]) {
                        if (easy[idx] != i) {
                            idx = j;
                            stop = false;
                            break;
                        }
                    }
                }
            }
            max = Math.max(cnt, max);
        }

        return max;
    }


    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("C-small-attempt3.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        BFF test = new BFF();

        int n = in.nextInt();
        for (int i = 0; i < n ;i++) {
            pw.print("Case #" + (i + 1) + ": ");
            int num = in.nextInt();
            int[] nums = new int[num];
            for( int j = 0; j < num; j++) {
                nums[j] = in.nextInt();
            }
            pw.println(test.bff(nums));
        }
        pw.flush();
        pw.close();
        in.close();

    }
}
