import java.util.*;

class Pair implements Comparable<Pair> {
	public int x, y, play;
	
	public Pair(int _x, int _y) {
		x = _x;
		y = _y;
		play = 0;
	}
	
	public Pair() {
		x = 0;
		y = 0;
		play = 0;
	}
	
	@Override
	public int compareTo(Pair arg0) {
		return x-arg0.x;
	}
	
	public String toString() {
		return x+" "+y+" "+play;
	}
}

class CP implements Comparator<Pair> {

	@Override
	public int compare(Pair arg0, Pair arg1) {
		// TODO Auto-generated method stub
		return arg0.y-arg1.y;
	}
	
}
public class b1 {
	
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		String bad = "Too Bad";
		
		for(int i = 1; i <= test; ++i) {
			int n = input.nextInt(), a[] = new int[n], b[] = new int[n], c[] = new int[2*n], play[] = new int[2*n];
			Pair all[] = new Pair[2*n];
			for(int j = 0; j < n; ++j) {
				a[j] = input.nextInt();
				b[j] = input.nextInt();
				all[2*j] = new Pair(a[j], 1);
				all[2*j+1] = new Pair(b[j], 2);
				c[2*j] = 1;
				c[2*j+1] = 2;
			}
			
//			Pair thx[] = new Pair[2*n];
			Arrays.sort(all);
			
			int time = -1;
			int star = 0;
			for(int j = 0; j < 2*n; ++j) {
//				System.out.print(all[j].x + " ");
				if(star < all[j].x) {
					for(int k = j-1; k >= 0; --k) {
						if(all[k].play < 1 && all[k].x <= star && all[k].y == 2) {
							all[k].play = 1;
							star += all[k].y;
//							if(star >= all[j].x) {
//								break;
//							}
						}
					}
					if(star < all[j].x) {
						for(int k = j-1; k >= 0; --k) {
							if(all[k].play < 1 && all[k].x <= star) {
								all[k].play = 1;
								star += all[k].y;
								if(star >= all[j].x) {
									break;
								}
							}
						}
					}
//					if(all[j].x <= star && all[j].y == 2) {
//						all
//					}
				}
//				else {
					if(all[j].x <= star && all[j].y == 2) {
						star += all[j].y;
						all[j].play = 1;
					}
//				}
			}
			
//			for(int j = 0; j < 2*n; ++j) {
//				for(int k = j; k < 2*n; ++)
//			}
			
//			System.out.println(" " + star);
			
			if(star < all[2*n-1].x) {
//				System.out.println(Arrays.toString(all));
				System.out.println("Case #" + i + ": " + bad);
			}
			else {
				int sum = 0;
				for(int j = 0; j < 2*n; ++j) {
					if(all[j].y == 2) {
						all[j].play = 1;
					}
					sum += all[j].play;
				}
//				System.out.println(Arrays.toString(all));
				
				System.out.println("Case #" + i + ": " + sum);
			}
//			System.out.println(Arrays.toString(all));
		}
	}
}
