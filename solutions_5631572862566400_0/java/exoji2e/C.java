import java.util.Scanner;
import java.lang.Math;
public class C {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 1; i<=T; i++) {
			int N = sc.nextInt();
			int[] map = new int[N];
			for(int j = 0; j<N; j++) {
				map[j] = sc.nextInt() - 1;
			}
			boolean visited[] = new boolean[N];
			int free[] = new int[N];
			int cycle[] = new int[N];
			int duo[] = new int[N];
			for(int j = 0; j<N; j++) {
				if(cycle[j] != 0)
					continue;
				int start = j;
				boolean vnow[] = new boolean[N];
				int next = start;
				int count = 1;
				vnow[next] = true;
				boolean fail = false;
				while(true) {
					next = map[next];
					if(vnow[next]) {
						fail = (next != start);
						break;
					}
					vnow[next] = true;
					count++;
				}
				if(!fail){
					cycle[next] = count;
					next = map[next];
					while(next!=start) {
						cycle[next] = count;
						next = map[next];
					}
				}
			
			}
			for(int j = 0; j<N; j++) {
				if(cycle[j] == 0) {
					int count = 1;
					int next = j;
					while(cycle[next] == 0) {
						count++;
						next = map[next];
					}
					free[next] = Math.max(free[next],count-1);
				}
			}
			int max = 0;
			for(int j = 0; j<N; j++) {
				int score = cycle[j];
				if(cycle[j] == 2) {
					score += free[j] + free[map[j]];
				}
				if(score>max)
					max = score;
			}
			System.out.println("Case #" + i + ": " + max);
		}
	}
}