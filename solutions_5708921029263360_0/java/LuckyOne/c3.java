import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class c3 {

	static String fileName = "E:/tmp/codeJam2016/c3/input_test.txt";
	static String outFileName = "E:/tmp/codeJam2016/c3/output.txt";
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		// TODO Auto-generated method stub

		try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFileName));
			String line;

			line = br.readLine();
			int testCases = Integer.parseInt(line);
			int caseCounter = 1;
			
			// ---------
			while ((line = br.readLine()) != null) {
				String[] split = line.split(" ");
				int jacket = Integer.parseInt(split[0]);
				int pant = Integer.parseInt(split[1]);
				int shirt = Integer.parseInt(split[2]);
				int k = Integer.parseInt(split[3]);
				//int input = Integer.parseInt(line);
				String result = solve(jacket, pant, shirt, k);
				System.out.println("Case #" + caseCounter + ": " + result);
				bw.write("Case #" + caseCounter + ": " + result +"\n");
				
				caseCounter++;
			}
			
			// ---------
			
			bw.close();
		}
	}
	public static String solve(int jacket, int pant, int shirt, int k) {
		int[][] jacketPant = new int[jacket][pant];
		int[][] jacketShirt = new int[jacket][shirt];
		int[][] pantShirt = new int[pant][shirt];
		
		StringBuilder tmp = new StringBuilder();
		int numberOutfits = 0;
		
		for(int j = 0; j < jacket; j++){
			for(int p = 0; p < pant; p++){
				for(int s = 0; s < shirt; s++){
					if(jacketPant[j][p] < k &&
					   jacketShirt[j][s] < k &&
					   pantShirt[p][s] < k){
						tmp.append((j+1) + " " + (p+1) + " " + (s+1) + "\n");
						jacketPant[j][p]++;
						jacketShirt[j][s]++;
						pantShirt[p][s]++;
						numberOutfits++;
					}
				}
			}
		}
		
		return numberOutfits + "\n" + tmp.toString().trim();
	}
}






