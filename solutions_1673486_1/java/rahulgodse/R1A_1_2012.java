import java.io.BufferedReader;
import java.io.InputStreamReader;


public class R1A_1_2012 {

	public static void main(String[] args) {
		
		try {
			
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int T = Integer.parseInt(bf.readLine());
			
			for (int i=0; i<T; i++) {
				
				String[] strTemp = bf.readLine().split(" ");
				int A = Integer.parseInt(strTemp[0]);
				int B = Integer.parseInt(strTemp[1]);
				
				double[] P = new double[A];
				double[] CorrectP = new double[A];
				
				strTemp = bf.readLine().split(" ");
				double correctP = 1;
				for (int j=0; j<A; j++) {
					P[j] = Double.parseDouble(strTemp[j]);
					correctP = correctP * P[j];
					CorrectP[j] = correctP;
				}
				
				double keyStrokes = B + 2;
				
				for (int x=0; x<A; x++) {
					double k = CorrectP[A-x-1] * (2*x + B - A + 1);
					k += (1-CorrectP[A-x-1]) * (2*x + 2*B - A + 2);
					keyStrokes = Math.min(keyStrokes, k);
				}
				
				System.out.println("Case #" + (i+1) + ": " + keyStrokes);
				
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
}
