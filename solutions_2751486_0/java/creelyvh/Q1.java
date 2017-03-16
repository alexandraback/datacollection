import java.util.*;

public class Q1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncas = sc.nextInt();
		for(int cas = 0; cas < ncas; cas++) {
			String str = sc.next();
			char[] ca = str.toCharArray();
			int n = sc.nextInt();
			
			int ret = 0;
			
			for(int lo = 0; lo < ca.length; lo++) {
				for(int hi = lo+1; hi <= ca.length; hi++) {
					//System.out.println(str.substring(lo, hi));
					int count = 0;
					for(int i = lo; i < hi; i++) {
						if(ca[i] == 'a' || ca[i] == 'e' || ca[i] == 'i' || ca[i] == 'o' || ca[i] == 'u') {
							count = 0;
						}
						else {
							count++;
						}
						if(count >= n) {
							//System.out.println(str.substring(lo, hi));
							ret++;
							break;
						}
					}
				}
			}
			System.out.println("Case #" + (cas+1) + ": " + ret);
		}
		

	}

}
