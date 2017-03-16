import java.io.*;

public class ProblemA {
	public static void main(String [] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T =  Integer.parseInt(br.readLine());
		for(int i = 0; i < T; i++){
			String[] input = br.readLine().split(" ");
			int N = Integer.parseInt(input[0]);
			int[] s = new int[N];
			int sum = 0;
			for(int j=0; j < N; j++){
				s[j] = Integer.parseInt(input[j+1]);
				sum += s[j];
			}
			
			double safety = 2.0 * sum / N;
			int unsafeN = 0;
			int unsafeSum = 0;
			for(int j=0; j < N; j++){
				if(s[j] < safety){
					unsafeN++;
					unsafeSum += s[j];
				}
			}

			String result = "";
			double newSafety = 1.0 * (unsafeSum + sum) / unsafeN;
			//System.out.println(newSafety);
			for(int j = 0; j < N; j++){
				double required;
				if(s[j] >= safety) required = 0;
				else required = 100* (newSafety - s[j])/sum;
				result += " " + required;
			}
			System.out.println("Case #" + (i+1) + ": " + result.substring(1));
			
		}
	}
}
