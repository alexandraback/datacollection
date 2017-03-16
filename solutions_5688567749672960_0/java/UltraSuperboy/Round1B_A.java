package CodeJam2015;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Round1B_A {
	
	static int MAX = 1000000; //1000000;
	
	static int dist[] = new int[MAX+1];
	
	static int reverse(int n) {
		int ans = 0;
		while (n > 0) {
			ans = ans*10 + (n % 10);
			n /= 10;
		}
		return ans;
	}

	public static void main(String[] args) {
		Queue<Integer> l = new LinkedList<Integer>();
		Queue<Integer> l2 = new LinkedList<Integer>();
		Queue<Integer> t;
		l.add(1);
		int distance = 1;
		while (!l.isEmpty()) {
			while (!l.isEmpty()) {
				int num = l.poll();
				dist[num] = distance;
				int rev = reverse(num);
				if (rev <= MAX && dist[rev] == 0) {
					l2.add(rev);
					dist[rev] = distance+1;
				}
				if (num+1 <= MAX && dist[num+1] == 0) {
					l2.add(num+1);
					dist[num+1] = distance+1;
				}
			}
			distance++;
			t = l;
			l = l2;
			l2 = t;
		}
		/*for (int i = 0; i < dist.length; i++)
			System.out.println(i + ": " + dist[i]);*/
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			int N = sc.nextInt();
			System.out.println("Case #" + cases + ": " + dist[N]);
		}
		sc.close();
	}

}
