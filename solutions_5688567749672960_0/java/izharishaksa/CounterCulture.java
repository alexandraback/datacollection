
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 *
 * @author izharishaksa
 */
public class CounterCulture {

    static int flip(int n) {
        String s = n + "";
        String ret = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            ret += s.charAt(i);
        }
        return Integer.parseInt(ret);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            int min = N + 1;
            PriorityQueue<State> pq = new PriorityQueue<State>();
            State state = new State(N, 1);
            pq.add(state);

            while (!pq.isEmpty()) {
                state = pq.poll();
                int curN = state.cur;
                int curStep = state.step;
                if (curN == 1) {
                    min = Math.min(min, curStep);
                    break;
                } else if (curStep + 1 < min) {
                    State newState = new State(curN - 1, curStep + 1);
                    pq.add(newState);

                    if (curN % 10 != 0) {
                        int flipped = flip(curN);
                        if (flipped < curN) {
                            State newState2 = new State(flipped, curStep + 1);
                            pq.add(newState2);
                        }
                    }
                }
            }

            System.out.println("Case #" + t + ": " + min);
        }
    }

}

class State implements Comparable<State> {

    int cur, step;

    public State(int cur, int step) {
        this.cur = cur;
        this.step = step;
    }

    @Override
    public int compareTo(State o) {
        if (cur < o.cur) {
            return -1;
        }
        if (cur > o.cur) {
            return 1;
        }
        return step - o.step;
    }

}
