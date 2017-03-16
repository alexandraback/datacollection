import java.io.*;


public class Main{


	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tCount = Integer.parseInt(in.readLine());
		for (int t = 0; t < tCount; ++t){
			String line = in.readLine();
			int sIndex = line.indexOf(' ');
			int sMax = Integer.parseInt(line.substring(0, sIndex));
			String shyness = line.substring(sIndex + 1);
			
			int sum = 0;
			int needed = 0;
			for (int i = 0; i <= sMax; ++i){
				int s = shyness.charAt(i) - '0';
				if (s == 0)
					continue;
				if (sum < i){
					needed += i - sum;
					sum = i;
				}
				
				sum += s;
			}
			
			System.out.printf("Case #%d: %d\n", (t+1), needed);
		}
		
		
	}

}