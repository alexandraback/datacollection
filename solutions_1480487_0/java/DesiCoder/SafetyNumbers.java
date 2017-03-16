import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class SafetyNumbers {
	public static void main(String[] args) throws Exception {
		String sb = null;

		BufferedReader is = new BufferedReader(new FileReader(new File(
				"D:\\A-small-attempt1.in")));
		BufferedWriter os = new BufferedWriter(new FileWriter("D:\\out.txt"));
		os.flush();
		int T = Integer.parseInt(is.readLine());

		for (int i = 0; i < T; i++) {
			sb = is.readLine();
			String num[] = sb.split(" ");

			int N = Integer.parseInt(num[0]);
			int nums[] = new int[N];
			double ans[] = new double[N];
			int sum = 0;
			for(int j=0;j<N;j++){
				nums[j] = Integer.parseInt(num[j+1]);
				sum += nums[j];
			}
			 double total = sum*2.0/N;
			
			
			double xx = 0;
			int xx_count = 0;
			for(int ii=0;ii<N;ii++){
				ans[ii] = (total-nums[ii])*100/sum;
				if(ans[ii] < 0){					
					xx_count++;
					xx -= ans[ii];
					ans[ii] = 0;
				}
					
				
			}
			
			if(xx_count > 0){
				double haha = xx / (N-xx_count); 
				for(int ii=0;ii<N;ii++){
					if(ans[ii] > 0){
						ans[ii] -= haha;
					}
				}
			}
			
			os.write("Case #" + (i+1) + ": " );
			
			for(int ii=0;ii<N;ii++){
				os.write(ans[ii] + " ");
			}
			os.write("\n");
			os.flush();
		}

	}
	
}
