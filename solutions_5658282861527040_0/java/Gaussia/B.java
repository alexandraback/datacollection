import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		run();
	}
	
	public static void run() {		
		Scanner scn = new Scanner(System.in);
		int T = scn.nextInt();
		for (int t =1; t<=T; t++){
			int A = scn.nextInt();
			int B = scn.nextInt();
			int K = scn.nextInt();
			
			int count = 0;
			

			
			for (int a = 0; a<A; a++) {
				for (int b = 0; b<B; b++) {
					int result = a&b;
					if (result<K) {
						count ++;
					}
				}
			}
			
			System.out.println("Case #" + t + ": " + count);
		}
	}
    
}
