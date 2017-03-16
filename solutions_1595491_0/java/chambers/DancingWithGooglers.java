import java.util.*;


public class DancingWithGooglers {

	private static final Scanner sc = new Scanner(System.in);

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		int T = sc.nextInt();	//number of button presses
		
		for (int i = 0; i < T; i++){
			
			int N = sc.nextInt();	//number of contestants
			int S = sc.nextInt(); 	//number of suprises
			int p = sc.nextInt();	//possible maximum score
						
			int result = 0;
			
			for (int j = 0; j < N; j++){
				
				int t = sc.nextInt();
				
				if (t >= (3 * p - 2))
					result++;
				
				else if (p == 1);
					
				
				else if ((t >= (3 * p - 4)) && (S != 0)){
					result++;
					S--;
				}
				
			}
			
			System.out.println("Case #" + (i + 1) + ": " + result);
			
		}
		
		

	}

}
