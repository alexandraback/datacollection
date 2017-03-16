import java.util.Scanner;


public class Q2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncas = sc.nextInt();
		
		for(int cas = 0; cas < ncas; cas++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			System.out.print("Case #" + (cas+1) + ": ");
			
			if(x >= 0) {
				for(int i = 0; i < x; i++) {
					System.out.print("WE");
				}
			}
			else {
				for(int i = 0; i < -x; i++) {
					System.out.print("EW");
				}
			}
			
			if(y >= 0) {
				for(int i = 0; i < y; i++) {
					System.out.print("SN");
				}
			}
			else {
				for(int i = 0; i < -y; i++) {
					System.out.print("NS");
				}
			}
			
			System.out.print("\n");
		}

	}

}
