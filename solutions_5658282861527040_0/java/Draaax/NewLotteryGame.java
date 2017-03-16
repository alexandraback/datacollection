import java.util.Scanner;


public class NewLotteryGame {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) { {
			int a = kb.nextInt();
			int b = kb.nextInt();
			int k = kb.nextInt();
			
			int sum = 0;
			
			for(int i = 0; i < a; i++) {
				for(int j = 0; j < b; j++) {
					int s = i & j;
					if(s < k) sum++;
				}
			}
			
			System.out.println("Case #" + c  + ": " + sum);
		}
		}
	}

}
