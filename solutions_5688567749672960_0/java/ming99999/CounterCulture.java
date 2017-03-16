import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class CounterCulture {

	public static int reverse(int n ) {
		int reverse = 0;
		while( n != 0 ) {
	      reverse = reverse * 10;
	      reverse = reverse + n%10;
	      n = n/10;
	    }
		return reverse;
	}
 	public static int minTimes(int N) {
		int[] times = new int[N+1];
		times[1] = 1;
		for (int i = 1; i <= N; ++i) {
			if (times[i] == 0) {
				times[i] = times[i-1] + 1;
			}
			else times[i] = Math.min(times[i-1] + 1, times[i]);
			int rev = reverse(i);
			if (rev > i && rev <= N) {
				times[rev] = times[i] +1;
			}
			
		}
		// System.out.println(Arrays.toString(times) + "\t" + times[N]);
		return times[N];
	}
 	
 	public static void solution(String inputFile, String outputFile) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File(inputFile)));
		PrintWriter pw = new PrintWriter(new FileWriter(new File(outputFile)));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		int id = 1;
		while ((line = br.readLine()) != null) {
			int n = Integer.parseInt(line);
			int num = minTimes(n);
			pw.println("Case #"+id+": "+num);
			id++;
		}
		br.close();
		pw.close();
	}
	public static void main(String[] args) throws IOException {
		String inputFile = "src/CounterCulture.in";
		String outputFile = "src/CounterCulture.out";
		CounterCulture.solution(inputFile, outputFile);
		// CounterCulture.minTimes(100) ;
	}
}
