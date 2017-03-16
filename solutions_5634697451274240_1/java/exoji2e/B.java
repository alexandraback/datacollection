import java.util.Scanner;
public class B {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i<=n; i++) {
			String s = sc.next();
			int l = s.length();
			boolean[] stack = new boolean[l];
			for(int j = 0; j<l; j++) {
				if(s.charAt(j) == '+') {
					stack[j] = true;
				}
			}
			int flips = 0;
			boolean passed = true;
			int fail = -1;
			for(int j = l-1; j>=0; j--) {
				if(!stack[j]){
					passed = false;
					fail = j;
					break;
				}
			}
			
			while(!passed) {
				int where = -1;
				if(stack[0]) {
					for(int j = 1; j<=fail; j++) {
						if(!stack[j]){
							where = j-1;
							break;
						}
					}
					stack = flip(where,stack);
				} else {
					stack = flip(fail,stack);
				}
				flips++;
				passed = true;
				fail = -1;
				for(int j = l-1; j>=0; j--) {
					if(!stack[j]){
						passed = false;
						fail = j;
						break;
					}
				}
			}
			System.out.println("Case #" + i + ": " + flips);
			
		}
	}
	public static boolean[] flip(int w, boolean[] b) {
		boolean[] ret = new boolean[b.length];
		for(int i = 0; i<=w; i++) {
			ret[i] = !b[w-i];
		}
		for(int i = w+1; i<b.length; i++) {
			ret[i] = b[i];
		}
		return ret;
	}
	
}