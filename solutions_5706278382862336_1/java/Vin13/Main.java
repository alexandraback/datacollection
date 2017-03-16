import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
 
public class Main {
	
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("A-large.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				String[] line = br.readLine().split("/");
				

				BigInteger a = new BigInteger(line[0]);
				BigInteger b = new BigInteger(line[1]);
				
//				int a = Integer.parseInt(line[0]);
//				int b = Integer.parseInt(line[1]);
//				System.out.print(a + "/" + b + " ");
				
				int gen = 1;
				
				boolean possible = false;
				boolean found = false;
				for (int j = 0; j < 40; j++) {
					a = a.multiply(BigInteger.valueOf(2));
					if (a.equals(b)) {
						possible = true;
						break;
					}
					if (a.compareTo(b) >= 0) {
						found = true;
						a = a.subtract(b);
					}
					if (!found)
						gen++;
				}
				
				if (possible)
					System.out.println("Case #" + (i+1) + ": " + gen);
				else
					System.out.println("Case #" + (i+1) + ": impossible");
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}