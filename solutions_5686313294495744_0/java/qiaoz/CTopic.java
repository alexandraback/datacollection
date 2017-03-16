import java.util.HashSet;
import java.util.Scanner;

public class CTopic {
	static Scanner sc;
	static int N;
	static String[][] graph;
	static HashSet<String> f;
	static HashSet<String> s;
	static HashSet<Integer> added;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			graph = new String[N][2];
			f = new HashSet<>();
			s = new HashSet<>();
			
			for (int j = 0; j < N; j++) {
				graph[j][0]= sc.next();
				graph[j][1] =sc.next();
				f.add(graph[j][0]);
				s.add(graph[j][1]);
			}
			brute();
			System.out.printf("Case #%d: %d\n", t, N- brute());
		}
		
		sc.close();
	}
	
	public static int brute () {
		int best = N;
		for (int i = 0; i < (1 << N); i++) {
			HashSet<String> a = new HashSet<>();
			HashSet<String> b = new HashSet<>();
			int count = 0;
			for (int j = 0; j < N; j++) {
				if ((i >> j & 1) == 1) {
					count++;
					a.add(graph[j][0]);
					b.add(graph[j][1]);
				}
				if (a.size() == f.size() && b.size() == s.size()) {
					best = Math.min(count, best);
				}
			}
		}
		return best;
	}
	
	
}
