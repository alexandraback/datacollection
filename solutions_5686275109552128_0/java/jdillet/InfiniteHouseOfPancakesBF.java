import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class InfiniteHouseOfPancakesBF {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int D = in.nextInt();
            int[] arr = new int[D];
            for (int i = 0; i < D; i++) {
                arr[i] = in.nextInt();
            }

            solve(testCase, D, arr);
        }

        in.close();
    }

    int res;
    public void solve(int testCase, int D, int[] arr) {
        List<Integer> state = new ArrayList<Integer>();
        for (Integer val : arr) {
            state.add(val);
        }
        Collections.sort(state, Collections.reverseOrder());
        res = state.get(0);
        
        go(1, state);

        System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);
    }

    private void go(int count, List<Integer> state) {
        if (count > res) {
            return;
        }

        List<Integer> eat = new ArrayList<>(state);
        for (int i = 0; i < eat.size(); i++) {
            eat.set(i, eat.get(i) - 1);
        }
        Iterator<Integer> it = eat.iterator();
        while (it.hasNext()) {
            if (it.next() == 0) {
                it.remove();
            }
        }
        if (eat.isEmpty()) {
            res = Math.min(res, count);
        } else {
            Collections.sort(eat, Collections.reverseOrder());
            go(count + 1, eat);
        }
        
        List<Integer> half = new ArrayList<>(state);
        int val = half.get(0);
        half.add(val / 2);
        int diff = val - (val / 2);
        half.set(0, diff);
        Collections.sort(half, Collections.reverseOrder());
        go(count + 1, half);
        
        if (state.get(0) > 3) {
            List<Integer> three = new ArrayList<>(state);
            val = three.get(0);
            three.add(val - 3);
            diff = 3;
            three.set(0, diff);
            Collections.sort(three, Collections.reverseOrder());
            go(count + 1, three);
        }
    }

    public static void main(String[] args) throws Exception {
        InfiniteHouseOfPancakesBF main = new InfiniteHouseOfPancakesBF();
        main.processInput();
    }
}
