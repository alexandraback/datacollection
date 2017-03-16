package CJ15.round1C;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 5/10/15
 * Time: 5:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class C {

    private int maxValue;
    private boolean[] denomination;
    private int answer;
    private int current;

    public static void main(String... args) {
        C c = new C();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {

            c.answer = Integer.MAX_VALUE;
            c.current = 0;

            int C = scanner.nextInt();
            int D = scanner.nextInt();
            c.maxValue = scanner.nextInt();
            c.denomination = new boolean[c.maxValue + 1];
            for (int j = 0; j < D; j++) {
                int coin = scanner.nextInt();
                if (coin <= c.maxValue) {
                    c.denomination[coin] = true;
                }
            }
            c.solve();

            System.out.println(String.format("Case #%d: %d", i + 1, c.answer));
        }
    }

    private void solve() {
        boolean[] ok = new boolean[maxValue + 1];
        ok[0] = true;
        for (int i = 1; i <= maxValue; i++) {
            if (denomination[i]) {
                ok = useCoin(ok, i);
            }
        }
        search(ok);
    }

    private  void search(boolean[] used) {
        int remains = 0;
        for (int i = 1; i <= maxValue; i++) {
            if (!used[i]) {
                remains = i;
                break;
            }
        }
        if (remains == 0) {
            answer = Math.min(answer, current);
            return;
        }
        for (int i = 0; i < remains; i++) {
            if (!denomination[remains - i]) {
                denomination[remains - i] = true;
                current++;
                search(useCoin(used, remains - i));
                denomination[remains - i] = false;
                current--;
            }
        }
    }

    private  boolean[] useCoin(boolean[] used, int coin) {
        boolean[] ret = new boolean[used.length];
        System.arraycopy(used, 0, ret, 0, used.length);
        for (int i = 0; i < used.length - coin; i++) {
            ret[i + coin] |= used[i];
        }
        return ret;
    }
}
