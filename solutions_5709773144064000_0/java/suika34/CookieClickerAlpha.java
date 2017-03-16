import java.io.BufferedReader;
import java.io.InputStreamReader;


public class CookieClickerAlpha {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);

			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] array = line.split(" ");
				double C = Double.parseDouble(array[0]);
				double F = Double.parseDouble(array[1]);
				double X = Double.parseDouble(array[2]);
				
				double result = solve(C, F, X);

				System.out.println("Case #"+i+": "+result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	private static double solve(double C, double F, double X) {
		double result = 0.0;

		int n = (int)Math.ceil(X/C - 1 - 2/F);
		if (n<0) {
			n = 0;
		}
		for (int i=0; i<n; i++) {
			result += C/(2+F*i);
		}
		result += X/(2+F*n);
		
		return result;
	}

}
