import java.util.Scanner;
public class A {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i<=n; i++) {
			int m = sc.nextInt();
			if(m == 0) {
				System.out.println("Case #" + i + ": INSOMNIA");
				continue;
			}
			boolean[] found = new boolean[10];
			int now = m;
			int x = now;
			while(x>0) {
				found[x%10] = true;
				x = x/10;
			}
			boolean passed = true;
			for(int j = 0; j<10;j++) {
				if(!found[j]) {
					passed = false;
					break;
				}
			}
			while(!passed) {
				now += m;
				x = now;
				while(x>0) {
					found[x%10] = true;
					x = x/10;
				}
				passed = true;
				for(int j = 0; j<10;j++) {
					if(!found[j]) {
						passed = false;
						break;
					}
				}
			}
			System.out.println("Case #" + i + ": " + now);
			
		}
	}
}