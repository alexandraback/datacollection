import java.util.*;
public class B {

	Scanner sc = new Scanner(System.in);
	void doIt()
	{
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			boolean state = solve();
			System.out.print("Case #" + t + ": ");

			System.out.println(state ? "YES" : "NO");
		}
	}
	boolean solve()
	{
		int H = sc.nextInt();
		int W = sc.nextInt();
		int [][] brd = new int[H][W];
		boolean [][] used = new boolean[H][W];
		TreeSet<Integer> nums = new TreeSet<Integer>();
		for(int h = 0; h < H; h++) {
			for(int w = 0; w < W; w++) {
				brd[h][w] = sc.nextInt();
				nums.add(brd[h][w]);
			}
		}
		//System.out.println(nums);
		for(Integer n: nums) {
			//System.out.println(n);
			for(int h = 0; h < H; h++) {
				boolean ok = true;
				for(int w = 0; w < W; w++) {
					if(used[h][w] == false && brd[h][w] > n) { ok = false; break; }
				}
				if(ok == true) 
					for(int w = 0; w < W; w++) 
						used[h][w] = true;
			}
			for(int w = 0; w < W; w++) {
				boolean ok = true;
				for(int h = 0; h < H; h++) {
					if(used[h][w] == false && brd[h][w] > n) { ok = false; break; }
				}
				if(ok == true) 
					for(int h = 0; h < H; h++) 
						used[h][w] = true;
			}
			for(int h = 0; h < H; h++) {
				for(int w = 0; w < W; w++) {
					if(brd[h][w] <= n && used[h][w] == false) return false;
				}
			}
		}
		return true;
	}

	public static void main(String[] args) {
		new B().doIt();

	}

}
