import java.util.Scanner;
import java.util.HashMap;
public class C {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 1; i<=T; i++) {
			int N = sc.nextInt();
			HashMap<String,Integer> start = new HashMap<String,Integer>();
			HashMap<String,Integer> end = new HashMap<String,Integer>();
			String[][] t = new String[2][N];
			boolean[] removed = new boolean[N];
			int res = 0;
			for(int j = 0; j<N; j++) {
				t[0][j] = sc.next();
				t[1][j] = sc.next();
				if(start.containsKey(t[0][j]) && end.containsKey(t[1][j])) {
					res++;
					removed[j] = true;
				}else if(start.containsKey(t[0][j])) {
					start.put(t[0][j], start.get(t[0][j]) + 1);
				} else {
					start.put(t[0][j],1);
				}
				if(end.containsKey(t[1][j])) {
					end.put(t[1][j], end.get(t[1][j]) + 1);
				} else {
					end.put(t[1][j],1);
				}
			}
			for(int j = 0; j<N; j++) {
				if(removed[j]) continue;
				if(start.get(t[0][j])>=2 && end.get(t[1][j])>=2) {
					start.put(t[0][j], start.get(t[0][j]) - 1);
					end.put(t[1][j], end.get(t[1][j]) - 1);
					removed[j] = true;
					res++;
				}
			}
			System.out.println("Case #" + i + ": " + res);
		}
	}
}