import java.util.*;


public class RecycledNumbers {

	private static final Scanner sc = new Scanner(System.in);
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		int T = sc.nextInt();
		
		
		for (int i = 0; i < T; i++){
			
			int A = sc.nextInt();
			int B = sc.nextInt();
			
			int m;
			
			HashMap<Integer, Integer> mMap = new HashMap<Integer, Integer>();

			int results = 0;
			
			final int digits = 1 + (int)Math.floor(Math.log10(A));
			
			
			for (int n = A; n < B; n++){
				
				if (digits == 1)
					break;
				
				//System.out.println(n);
					
				m = flipNumber(n, 1);
				mMap.put(m, m);
				
				if (n < m && m <= B)
						results++;
				
				if (digits > 2){
					m = flipNumber(n, 2);
					if (n < m && m <= B && !mMap.containsKey(m)){
						mMap.put(m,	m);
						results++;
					}
				}
				
				
				if (digits > 3){
					m = flipNumber(n, 3);
					if (n < m && m <= B && !mMap.containsKey(m)){
						mMap.put(m,	m);
						results++;
					}
				}
				
				if (digits > 4){
					m = flipNumber(n, 4);
					if (n < m && m <= B && !mMap.containsKey(m)){
						mMap.put(m,	m);
						results++;
					}
				}
				
				if (digits > 5){
					m = flipNumber(n, 5);
					if (n < m && m <= B && !mMap.containsKey(m)){
						mMap.put(m,	m);
						results++;
					}
				}
				
				if (digits > 6){
					m = flipNumber(n, 6);
					if (n < m && m <= B && !mMap.containsKey(m)){
						mMap.put(m,	m);
						results++;
					}
				}
				
				mMap.clear();

				
			}
			System.out.println("Case #" + (i + 1) + ": " + results);

			
		}

	}
	
	private static int flipNumber(int x, int way){
		
		String num = "" + x;
		
		if (way == 1)
			num = num.substring(num.length() - 1) + num.substring(0, num.length() - 1);
		
		else if (way == 2)
			num = num.substring(num.length() - 2) + num.substring(0, num.length() - 2);
		
		else if (way == 3)
			num = num.substring(num.length() - 3) + num.substring(0, num.length() - 3);

		else if (way == 4)
			num = num.substring(num.length() - 4) + num.substring(0, num.length() - 4);

		else if (way == 5)
			num = num.substring(num.length() - 5) + num.substring(0, num.length() - 5);

		else if (way == 6)
			num = num.substring(num.length() - 6) + num.substring(0, num.length() - 6);

		int p = Integer.parseInt(num);
		return p;
		
	}

}
