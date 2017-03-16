package round1;

import java.util.*;

/**
 * Created by ninghou on 4/15/16.
 */
public class P3 {

    String nhou(String[] input) {
        int[] bff = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            bff[i] = Integer.parseInt(input[i]);
        }

        // find min, max
        int count = 0;
        int min = bff.length + 1;
        int max = 0;
        for (int x : bff) {
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }

        // look up bff of x: bff[x - 1]
        if (bff[min - 1] == max || bff[max - 1] == min) {
            count++;        // consider first, last
        }

        Arrays.sort(bff);
        int prev = bff[0];
        for (int i = 1; i < bff.length; i++) {
            if (prev + 1 == bff[i]) {
                count++;
            }
            prev = bff[i];
        }

        count++;
        return count > input.length ? Integer.toString(count - 1) : Integer.toString(count);
    }
}
