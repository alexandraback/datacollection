import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class A {
	
	public static int reverse(int n) {
		return Integer.parseInt(new StringBuffer(String.valueOf(n)).reverse().toString());
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		
		int[] levels = {1, 9, 19, 109, 199, 1099, 1999};
		
		for (int i = 1; i <= t; i++) {
			int res = 0;
			int n = Integer.parseInt(in.readLine());
			
			
			if (n < 20) res = n;
			
			else {
								
				int c = String.valueOf(n).length();
				
				for (int j = 0; j < c; j++) {
					res += levels[j];
				}
				
				int halfnum = Integer.parseInt(String.valueOf(n).substring(0, c / 2));
				int secondhalf = Integer.parseInt(String.valueOf(n).substring(c / 2, String.valueOf(n).length()));
				
				//System.out.println("h" + halfnum);
				//System.out.println("sh" + secondhalf);
				
				res += reverse(halfnum);
				res += secondhalf;
			}
			
			System.out.format("Case #%d: %d\n", i, res);
		}
	}

}
