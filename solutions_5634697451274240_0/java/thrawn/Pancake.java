import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Pancake {

    private static int calculate(boolean[] pencakes) {
        int flipps = 0;
        for (int end = pencakes.length - 1; end >= 0; end--) {
            if (pencakes[end]) {
                continue;
            }

            int happy = -1;
            for (int start = 0; start < end; start++) {
                if (pencakes[start]) {
                    happy++;
                } else {
                    break;
                }
            }

            if (happy >= 0) {
                flipps +=flip(pencakes, happy);
            }
            flipps += flip(pencakes, end);
        }
        return flipps;
    }

    private static int flip(boolean[] pencakes, int last) {
//        toString(pencakes);
        for (int i = 0; i <= last; i++) {
            pencakes[i] = !pencakes[i];
        }
//        toString(pencakes);
        for (int i = 0; i <= (last/2); i++) {
            boolean tmp = pencakes[last-i];
            pencakes[last-i] = pencakes[i];
            pencakes[i] = tmp;
        }
//        toString(pencakes);
        return 1;
    }

    public static void main(String[] args) throws Exception {
//        calculate(new boolean[] {false, false, true, false});
//        if (true) return;
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            boolean[] pencakes = toPencaces(br.readLine());
//            toString(pencakes);
            int flipps = calculate(pencakes);
//            toString(pencakes);
            System.out.println("Case #" + i + ": " + flipps);
        }
    }

    private static boolean[] toPencaces(String line) {
        boolean[] pencaces = new boolean[line.length()];
        int p = 0;
        for (char c : line.toCharArray()) {
            pencaces[p++] = (c == '+');
        }
        return pencaces;
    }

    private static void toString(boolean[] pencakes) {
        for (boolean p : pencakes) {
            System.err.print(p ? '+' : '-');
        }
        System.err.println();
    }
}
