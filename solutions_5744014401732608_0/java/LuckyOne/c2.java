import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class c2 {

	static String fileName = "E:/tmp/codeJam2016/c2/input_test.txt";
	static String outFileName = "E:/tmp/codeJam2016/c2/output.txt";
	
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
				String[] tmp = line.split(" ");
				int buildings = Integer.parseInt(tmp[0]);
				int ways = Integer.parseInt(tmp[1]);
				int maxWays = 0;
				for(int i = buildings - 2; i > 0; i--) maxWays += i;
				maxWays++;
				if(ways > maxWays){
					System.out.println("Case #" + caseCounter + ": IMPOSSIBLE");
					bw.write("Case #" + caseCounter + ": IMPOSSIBLE\n");
				}else{
					String result = solve(buildings, ways);
					System.out.println("Case #" + caseCounter + ": " + result);
					bw.write("Case #" + caseCounter + ": " + result + "\n");
				}
				//int input = Integer.parseInt(line);
				
				caseCounter++;
			}
			
			// ---------
			
			bw.close();
		}
	}
	
	public static String solve(int buildings, int ways) {
		ways--;
		boolean[] needed = new boolean[buildings];
		needed[0] = true;
		StringBuilder sb = new StringBuilder();
		sb.append("POSSIBLE" + "\n");
		for(int i = 0; i < buildings; i++){
//			boolean connected = (ways > 0);
			
			for(int j = 0; j <= i; j++){
				sb.append("0");
			}
			int k = i + 1;
			while(k < (buildings - 1)){
				if(ways > 0){
					sb.append("1");
					ways--;
					needed[k] = true;
					k++;
				}else{
					sb.append("0");
					k++;
				}
				
			}
//			if(connected){
				if(i != buildings - 1){
					if(needed[i]){
						sb.append("1\n");
					}else{
						sb.append("0\n");
					}
				}
//			}else{
//				sb.append("0\n");
//			}
		}
		
		return sb.toString().trim();
	}
}






