import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	static PrintWriter out;
	
	static final String problem = "C1";
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
		
		Toy(long count,  int type) {
			this.count = count;
			this.type = type;
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
				long boxRemain = take - remain;
				
				long takeAll = take;
				// сделаем линейный проход
				if (remToys > 0) {
					int i = i1;
					int j = i2;
					
					while (true) {
						if (boxRemain == 0) {
							i++;
							while (i < boxes.length && boxes[i].type != toys[j].type) {
								i++;
							}
							if (i >= boxes.length) {
								long curr = takeAll;
								ans = Math.max(ans, curr); 
								break;
							}
							
							long take2 = Math.min(boxes[i].count, remToys);
							takeAll += take2;
							
							boxRemain = boxes[i].count - take2;
							remToys = take2 - remToys;
							if (boxRemain == 0 && remToys == 0) {
								// миссия выполнена
								long curr = takeAll + gen(i + 1, j + 1, 0);
								ans = Math.max(ans, curr);
								break;
							}
						
						}
						
						if (remToys == 0) {
							j++;
							while (j < toys.length && toys[j].type != boxes[i].type) {
								j++;
							}
							
							if (j >= toys.length) {
								long curr = takeAll;
								ans = Math.max(ans, curr);
								break;
							}
							
							remToys = toys[j].count;
							long take2 = Math.min(boxRemain, toys[j].count);
							takeAll += take2;
							
							boxRemain = take2 - boxRemain;
							remToys = toys[j].count - take2;
							if (boxRemain == 0 && remToys == 0) {
								// миссия выполнена
								long curr = takeAll + gen(i + 1, j + 1, 0);
								ans = Math.max(ans, curr);
								break;
							}
						}
					}
					
				}
				
							
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
		
		ArrayList <Toy> t = new ArrayList<Toy>();
		for (int i = 0; i < m; i++) {
			Toy bb = new Toy(in);
			if (t.size() != 0) {
				if (t.get(t.size() - 1).type == bb.type) {
					t.get(t.size() - 1).count += bb.count;
				} else {
					t.add(bb);
				}
			} else {
				t.add(bb);
			}
		}
		
		toys = new Toy[t.size()];
		for (int i = 0; i < toys.length; i++) {
			toys[i] = t.get(i);
		}
		
		boxes = new Box[b.size()];
		
		for (int i = 0; i < boxes.length; i++) {
			boxes[i] = b.get(i);
		}
		
		res = new long[boxes.length][toys.length][1 + toys.length];
		for (long ar[][] : res) {
			for (long arr[] : ar) {
				Arrays.fill(arr, -1L);
			}
		}
		
		out.print(gen(0, 0, 0));
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