package round1A;

import java.util.Scanner;;

public class BullsEye {
 public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

	int cases = sc.nextInt();

	for (int cs = 1; cs <= cases; cs++) {
		
		long r = sc.nextLong();
		
		long t = sc.nextLong();
		
		int i = 1;
		
		int count = 0;
		
		while (true) {
		
			long temp = (r + i)*(r+i) - (r+i-1)*(r+i-1);
			t -= temp;
			if(t >= 0){
				count++;
			} else {
				break;
			}
			i += 2;
		}
		

		System.out.println("Case #" + cs + ": " + count);
	}
}
}
