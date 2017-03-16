import java.util.*;

public class B {
	static Vector<Set<Integer>> num = new Vector<Set<Integer>>();
	
	static void fill() {
		for(int i = 0; i < 33; ++i) {
			num.add(new TreeSet<Integer>());
		}
		
		for(int i = 0; i <= 10; ++i) {
			for(int j = i; j <= i+2; ++j) {
				for(int k = j; k <= i+2; ++k) {
					if(k <= 10) {
						int sum = i+j+k;
						int diff1 = k-i, diff2 = j-i;
//						if(sum == 13) {
//							System.out.println(i + " " + j + " " + k);
//						}
						if(diff1 == 2) {
							if(diff2 < 2) {
								num.get(3*k+2).add(sum);
//								if(sum == 13) {
//									System.out.println("Strict");
//								}
							}
							else {
								num.get(3*k+1).add(sum);
//								if(sum == 13) {
//									System.out.println("Non");
//								}
							}
						}
						else {
							num.get(3*k).add(sum);
//							if(sum == 13) {
//								System.out.println("Binhthuong");
//							}
						}
					}
				}
			}
		}
	}
	
	static int[] check(int score, int p) {
		int r[] = new int[3];
		
		int size = num.size();
		for(int i = 0; i < size; ++i) {
			Set<Integer> temp = num.get(i);
			if(temp.contains(score)) {
				if(i/3 >= p) {
					r[0] = 1;
					if(i%3 == 2 && r[2] >= 0) {
						r[2] = 1;
					}
					else {
						r[2] = -1;
					}
				}
				if(i%3 != 0) {
					r[1] = 1;
				}
			}
		}
		
		if(r[2] < 0) {
			r[2] = 0;
		}
//		System.out.println("check " + score + " " + Arrays.toString(r));
		return r;
	}
	
	public static void main(String args[]) {
		fill();
		
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for(int i = 1; i <= test; ++i) {
			int N = input.nextInt(), S = input.nextInt(), p = input.nextInt();
			int t[] = new int[N];
			for(int j = 0; j < N; ++j) {
				t[j] = input.nextInt();
			}
			int result = 0;
			//int high[] = new int[N], strict[] = new int[N], nons[] = new int[N];
			int high = 0, strict = 0, nons = 0;
			for(int j = 0; j < N; ++j) {
				int temp[] = check(t[j], p);
				high += temp[0];
				nons += temp[1];
				strict += temp[2];
			}
//			System.out.println(N + " " + S + " " + p);
//			System.out.println(high + " " + nons + " " + strict);
			if(nons < S) {
				result = 0;
			}
			else {		
				if(strict > S) {
					result = high + S -strict;
				}
				else {
					result = high;
				}
			}
			
			System.out.println("Case #" + i + ": " + result);
		}
	}
}
