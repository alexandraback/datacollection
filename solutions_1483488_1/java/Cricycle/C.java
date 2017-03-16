import java.util.*;

public class C {
	private int[] tens = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
	public static void main(String[] args) {
		C c = new C();
		c.solve();
	}
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int ii = 1; ii <= t; ++ii) {
			int a = in.nextInt();
			int b = in.nextInt();
			long total = 0;
			for(int check = a; check < b; ++check) {
				total += countRecycle(check, b);
			}
			System.out.printf("Case #%d: %d\n", ii, total);
		}
	}
	
	public int countRecycle(int num, int max) {
		int size = getSize(num); //12345, size = 4, 10000, size = 4, 9999, size = 3
		HashSet<Integer> valid = new HashSet<Integer>();
		for(int i = 1; tens[i] <= num; ++i) {
			int newNum = (num/tens[i]) + (num%tens[i])*(tens[size-i+1]);
			if(newNum <= max && newNum > num)
				valid.add(newNum);
		}
		return valid.size();
	}
	
	public int getSize(int a) {
		int size = 0;
		while(tens[size] <= a)
			++size;
		return size - 1;
	}
}