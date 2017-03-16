import java.util.Scanner;


public class A {


	public static void main(String[] args) {
		String S, SS[];
		boolean possible, sum;
		long total;
		long P, Q;
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for (int t = 1; t <= T; t++) {
			possible = true;
			sum = true;
			total = 0;
			S = input.next();
			SS = S.split("/");
			P = Long.parseLong(SS[0]);
			Q = Long.parseLong(SS[1]);
			while(possible && Q > P) {
				while(Q > P) {
					if(Q%2 != 0) {
						possible = false;
						break;
					}
					Q /= 2;
					if(sum) total++;
				}
				sum = false;
				if(Q < P) {
					P -= Q;
					if(Q <= 0 || Q%2 != 0) {
						possible = false;
						break;
					}
				}
			}
			
			if (possible) {
				System.out.format("Case #%d: %d\n", t, total);
			} else {
				System.out.format("Case #%d: impossible\n", t);
			}
		}
		input.close();
	}
	

}
