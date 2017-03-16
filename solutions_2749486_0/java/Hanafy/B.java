import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int I = 1; I <= T; I++) {
			int x = in.nextInt(), y = in.nextInt();
			
			String ans = bfs(y, dir1, 0);
			ans += bfs(x, dir2, ans.length());
			System.out.printf("Case #%d: %s\n", I, ans);
		}
	}
	
	static int[] d = {1, -1};
	static String[] dir1 = {"N", "S"};
	static String[] dir2  = {"E", "W"};
	private static String bfs(int cc, String[] dir, int xx) {
		Queue<String> queue1 = new LinkedList<String>();
		Queue<Long> queue2 = new LinkedList<Long>();
		queue1.add("");
		queue2.add(0L);
		
		while(!queue1.isEmpty()){
			long c = queue2.poll();
			String s = queue1.poll();
			int cnt = xx + s.length() + 1;
			
			if(c == cc)
				return s;
			
			for(int i = 0; i < d.length; i++)
			{
				long nc = c + d[i] * cnt;
				
				queue2.add(nc);
				queue1.add(s + dir[i]);
			}
			
		}
		return null;
	}
}
