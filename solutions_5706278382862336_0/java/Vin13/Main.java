import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
 
public class Main {
	
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				String[] line = br.readLine().split("/");
				
				int a = Integer.parseInt(line[0]);
				int b = Integer.parseInt(line[1]);
//				System.out.print(a + "/" + b + " ");
				
				int gen = 1;
				
				boolean possible = false;
				boolean found = false;
				for (int j = 0; j < 40; j++) {
					a *= 2;
					if (a == b) {
						possible = true;
						break;
					}
					if (a >= b) {
						found = true;
						a -= b;
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