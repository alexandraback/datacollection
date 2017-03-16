import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int n = s.nextInt();
			int m = s.nextInt();
			int k = s.nextInt();
			
			int count = getX(n, m, k);
			System.out.printf("Case #%d: %d\n", (current++), count);			
		}
	}
	
	static int getX(int n, int m, int k) {
		if (n > m) return getX(m, n, k);
		
		// n = 1 to 4
		// m = 1 to 5
		if (n == 1 || n == 2) {
			return k;
		} else if (n == 3){
			switch(m) {
			case 3:
				int arr33[] = {1, 2, 3, 4, 4, 
						       5, 6, 7, 8};
				return arr33[k-1];
			case 4:
				int arr34[] = {1, 2, 3, 4, 4, 
						       5, 6, 6, 7, 8,
						       9, 10};
				return arr34[k-1];
			case 5:
				int arr35[] = {1, 2, 3, 4, 4, 
						       5, 6, 6, 7, 8,
						       8, 9, 10, 11, 12};
				return arr35[k-1];
			case 6:
			default:
				int arr36[] = {1, 2, 3, 4, 4,
						       5, 6, 6, 7, 8, 
						       8, 9, 10, 10, 11, 
						       12, 13, 14};
				return arr36[k-1];
			}
		} else { //if (n == 4)
			switch(m) {
			case 4:
				int arr44[] = {1, 2, 3, 4, 4, 
						       5, 6, 6, 7, 7,
						       8, 8, 9, 10, 11,
						       12};
				return arr44[k-1];
			case 5:
			default:
				int arr45[] = {1, 2, 3, 4, 4,
						      5, 6, 6, 7, 7, 
						      8, 8, 9, 9, 10,
						      10, 11, 12, 13, 14};
				return arr45[k-1];
			}
		}
	}
}
