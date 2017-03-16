import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class NewLotteryGame {

	private static ArrayList<Long> getNums(final String line) {
		ArrayList<Long> nums = new ArrayList<Long>();
		final String strs[] = line.split(" ");
		for(final String str : strs) {
			nums.add(Long.parseLong(str));
		}
		return nums;
	}
	
	private static Long calculate(final ArrayList<Long> nums) {
		long result = 0;
		
		long A = nums.get(0);
		long B = nums.get(1);
		long K = nums.get(2);
		
		for (long k=0; k<K; k++) {
			
			for (long a=0; a<A; a++) {
				
				for(long b=0; b<B; b++) {
//					if (a < k && b < k) break;
					
					if ((a & b) == k)
						result++;
				}
			}
		}
		
		return result;
	}
	
	public static void main(String args[]) throws IOException {
		if(args.length == 0) {
			System.out.println("No file. Exit this program");
			System.exit(1);
		}
		
		final BufferedReader br = new BufferedReader(new FileReader(args[0]));
		final BufferedWriter bw = new BufferedWriter(new FileWriter(args[0] + "_output.txt"));
		
		final int gamesCount = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=gamesCount; i++) {
			
			ArrayList<Long> nums = getNums(br.readLine());
			
			long result = calculate(nums);
			
			final String resultStr = "Case #" + i + ": " + result;
			bw.write(resultStr);
			bw.newLine();			
		}
		
		bw.close();
	}
}
