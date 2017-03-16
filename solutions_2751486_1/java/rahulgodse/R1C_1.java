import java.io.BufferedReader;
import java.io.InputStreamReader;


public class R1C_1 {
	
	private static final String VOWELS = "aeiou";
	
	public static void main(String[] args) {
		
		try {
		
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int T = Integer.parseInt(bf.readLine());
			
			for (int i=0; i<T; i++) {
				
				String[] strTemp = bf.readLine().split(" ");
				String name = strTemp[0];
				int n = Integer.parseInt(strTemp[1]);
				int count = 0;
				int startPoint = name.length();
				
				long nValue = 0;
				
				for (int x=name.length()-1; x>=0; x--) {
					if (VOWELS.contains(name.substring(x, x+1))) {
						count=0;
					} else {
						count++;
					}
					if (count >= n) {
						startPoint = x + n -1;
					}
					nValue += ((long) name.length() - (long) startPoint);
					
				}
				
				System.out.println("Case #" + (i+1) + ": " + nValue);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
		
	}
}
