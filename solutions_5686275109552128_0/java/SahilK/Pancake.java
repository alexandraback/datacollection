import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Collections;

public class Pancake {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i=1;i<=T;i++) {
            int d = sc.nextInt();
            PriorityQueue<Integer> que = new PriorityQueue<Integer>(2*d, Collections.reverseOrder());
            for (int k=0; k<d; k++) {
                que.add(sc.nextInt());
            }
            System.out.printf("Case #%d: %d",i,solve(que,d));
            System.out.println("");

        }
    }

    public static int solve(PriorityQueue<Integer> que, int d) {
        int specials = 0;
        int maxPi = que.peek();
        int minima = maxPi;
        while (specials < minima) {
            int a = que.poll();
            if (a <= 3) {
                break;
            } else {
                specials++;
                int x = a/2;
                que.add(x); que.add(a-x);
                int thisTime = specials + que.peek();
                if (thisTime < minima) {
                    minima = thisTime;
                }
            }
        }
        return minima;
    }
}
