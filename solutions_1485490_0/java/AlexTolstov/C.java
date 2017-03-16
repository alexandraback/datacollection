import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	static PrintWriter out;
	
	static final String problem = "C";
	static final String path = "C:/gcj/";
	
	static class Box {
		long count;
		int type;
		
		Box(Scanner in) {
			count = in.nextLong();
			type = in.nextInt();
		}
		
		Box(long count,  int type) {
			this.count = count;
			this.type = type;
				
		}
	}
	
	static class Toy {
		long count;
		int type;
		
		Toy (Scanner in) {
			count = in.nextLong();
			type = in.nextInt();
		}
	}
	
	Box boxes[];
	Toy toys[];
	
	long getRemainCount(int i1, int i2, int takenPrevCount) {
		long ans = 0;
		for (int i = i2 - 1; i >= 0; i--) {
			if (takenPrevCount != 0) {
				if (boxes[i1].type == toys[i].type) {
					ans = ans + toys[i].count;
					takenPrevCount--;
				}
			} else {
				break;
			}
		}
		//asserT(ans <= boxes[i1].count);
		return Math.max(0, boxes[i1].count - ans);
	}
	
	
	long res[][][];
	
	long gen(int i1, int i2, int takenPrevCount) {
		if (i1 == boxes.length || i2 == toys.length) {
			return 0L;
		}
		if (res[i1][i2][takenPrevCount] != -1L) {
			return res[i1][i2][takenPrevCount];
		}
		long ans = 0;
		long remain = getRemainCount(i1, i2, takenPrevCount);
		
		// go next only
		if (remain == 0) {
			ans = gen(i1 + 1, i2, 0);
		} else {
			if (toys[i2].type == boxes[i1].type) {
				long take = Math.min(toys[i2].count, remain);
				ans = take + gen(i1, i2 + 1, takenPrevCount + 1);
				
				long remToys = toys[i2].count - take;
				/*if (rem > 0) {
					
					long sumTake = take;
					for (int ii = i1 + 1; ii < boxes.length; ii++) {
						if (boxes[ii].type == toys[i2].type) {
							take = Math.min(rem, remainBig);
							long ans2 = 
						}
					}
					
				}
				*/
				
			
			} else {
				long ans2 = gen(i1, i2 + 1, takenPrevCount);
				if (ans < ans2) {
					ans = ans2;
				}
				
				ans2 = gen(i1 + 1, i2, 0);
				if (ans < ans2) {
					ans = ans2;
				}
			}
		}
		res[i1][i2][takenPrevCount] = ans;
		return ans;
	}
	
	void solveOne(int test) {
		out.print("Case #"+test+": ");
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		ArrayList <Box> b = new ArrayList<Main.Box>();
		for (int i = 0; i < n; i++) {
			Box bb = new Box(in);
			if (b.size() != 0) {
				if (b.get(b.size() - 1).type == bb.type) {
					b.get(b.size() - 1).count += bb.count;
				} else {
					b.add(bb);
				}
			} else {
				b.add(bb);
			}
		}
		
		toys = new Toy[m];
		for (int i = 0; i < toys.length; i++) {
			toys[i] = new Toy(in);
		}
		
		boxes = new Box[b.size()];
		
		for (int i = 0; i < boxes.length; i++) {
			boxes[i] = b.get(i);
		}
		
		if (boxes.length == 1) {
			long ans = 0;
			for (int i = 0; i < toys.length; i++) {
				if (toys[i].type == boxes[0].type) {
					ans = ans + toys[i].count;
				}
			}
			out.print(Math.min(boxes[0].count, ans));
		} else if (boxes.length == 2) {
			long sum1 = 0;
			long ans = 0;
			for (int i = -1; i < toys.length; i++) {
				if (i != -1) {
					if (toys[i].type == boxes[0].type) {
						sum1 += toys[i].count;
					}
				}
				
				long sum2 = 0;
				for (int j = i + 1; j < toys.length; j++) {
					if (toys[j].type == boxes[1].type) {
						sum2 += toys[j].count;
					}
				}
				
				ans = Math.max(ans, Math.min(boxes[0].count, sum1) + Math.min(boxes[1].count, sum2));
			}
			out.print(ans);
		} else if (boxes.length == 3) {
			long ans = 0;
			
			long sum1 = 0;
			for (int i = -1; i < toys.length; i++) {
				if (i != -1) {
					if (toys[i].type == boxes[0].type) {
						sum1 += toys[i].count;
					}
				}
				
				long sum2 = 0;
				for (int j = i + 1; j < toys.length; j++) {
					if (toys[j].type == boxes[1].type) {
						sum2 += toys[j].count;
					}
					
					long sum3 = 0;
					for (int k = j + 1; k < toys.length; k++) {
						if (toys[k].type == boxes[2].type) {
							sum3 += toys[k].count;
						}
					}
					
					ans = Math.max(ans, Math.min(boxes[0].count, sum1) + Math.min(boxes[1].count, sum2) + Math.min(boxes[2].count, sum3));
				}
				
				// 2ю можем вообще не брать
				long sum3 = 0;
				for (int k = i + 1; k < toys.length; k++) {
					if (toys[k].type == boxes[2].type) {
						sum3 += toys[k].count;
					}
				}
				ans = Math.max(ans, Math.min(boxes[0].count, sum1) + Math.min(boxes[2].count, sum3));
			}
			
			if (boxes[0].type == boxes[2].type) {
				long t = 0;
				for (int i = 0; i < toys.length; i++) {
					if (toys[i].type == boxes[0].type) {
						t = t + toys[i].count;
					}
				}
				t = Math.min(boxes[0].count + boxes[2].count, t);
				ans = Math.max(ans, t);
			}
			
			out.print(ans);
		}
		
		/*
		res = new long[boxes.length][toys.length][1 + toys.length];
		for (long ar[][] : res) {
			for (long arr[] : ar) {
				Arrays.fill(arr, -1L);
			}
		}
		
		
		
		out.print(gen(0, 0, 0));
		*/
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			solveOne(i);
			out.println();
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}