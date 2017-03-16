import java.util.Scanner;
public class D {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i<=n; i++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			String out = "";
			if(s==k) {
				for(int j = 1; j<=k; j++) {
					out = out + j + " ";
				}
				System.out.println("Case #" + i + ": " + out);
			}
		}
	}
}