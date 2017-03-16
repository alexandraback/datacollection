import java.util.*;

public class recycled_numbers {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int T = scanner.nextInt();
		int[] answers = new int[T];
		
		for (int c = 0; c < T; c++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			
			int numdigits;
			for (numdigits = 1; A-Math.pow(10,numdigits) >= 0; numdigits++);			
			
			HashSet<Integer> done = new HashSet<Integer>();
			
			int n = A;
			int possiblem;
			answers[c] = 0;
			while (n <= B) {
				possiblem = n;
				int possiblemsthisround = 0;
				for (int i = 0; i <= numdigits; i++) {
					if ((possiblem%10) != 0) {
						possiblem = (possiblem%10)*((int)Math.pow(10,numdigits-1)) + (possiblem-(possiblem%10))/10;
						if ((possiblem <= B) && (possiblem > n)) {
							if (done.contains(possiblem) == false) {
								done.add(possiblem);
								possiblemsthisround++;
							}
							done.add(possiblem);
						}
					}
					else possiblem = (possiblem%10)*((int)Math.pow(10,numdigits-1)) + (possiblem-(possiblem%10))/10;
				}
				if (possiblemsthisround > 0) answers[c] += possiblemsthisround*(possiblemsthisround + 1)/2;
				n++;
			}
		}
		for (int i = 0; i < T; i++) {
			int j = i+1; 
			System.out.println("Case #"+j+": "+answers[i]);
		}
	
	}
}
