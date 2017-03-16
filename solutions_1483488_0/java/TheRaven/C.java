import java.util.*;
public class C {
	public static void main (String [] arg) {
		
		int [][] store = new int [2000010][7];
		for (int i = 1; i<store.length; ++i) {
			int ptr = 0;
			int j = rotate(i);
			while (j != i) {
				if (j > i) store[i][ptr++] = j;
				j = rotate(j);
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			//Something
			int A = sc.nextInt();
			int B = sc.nextInt();
			int count = 0;
			for (int a = A; a<B; ++a)
				for (int i = 0; i<store[a].length && store[a][i] > 0; ++i) 
					if (store[a][i] <= B) count++;
			
			
			int ans = count;
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	public static int rotate(int a) {
		String s = Integer.toString(a);
		do {
			s = s.substring(1) + s.charAt(0);
		} while (s.charAt(0) == '0');
		
		return Integer.parseInt(s);
	
	}
	
}