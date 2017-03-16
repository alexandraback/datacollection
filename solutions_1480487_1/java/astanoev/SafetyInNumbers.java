import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;


public class SafetyInNumbers {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(
					"files/aInput.txt"));
			BufferedWriter bw = new BufferedWriter(new FileWriter(
					"files/aOutput.txt"));
			String strLine;
			strLine = br.readLine();
			int size = Integer.parseInt(strLine);
			for (int i = 1; i <= size; i++) {
				String[] s = br.readLine().split(" ");
				int N = Integer.parseInt(s[0]);
				int[] points = new int[N];
				int X = 0;
				for(int j=0;j<N;j++){
					points[j] = Integer.parseInt(s[1+j]);
					X += points[j];
				}
				double[] res = CalcSafety(points,N,X);
				bw.write("Case #" + i + ": ");
				DecimalFormat df = new DecimalFormat("#.######");
				for(int j=0;j<N;j++){
					bw.write(res[j] + " ");
				}
				bw.newLine();
			}
			bw.close();
			br.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

	private static double[] CalcSafety(int[] points, int N, int X) {
		double[] res = new double[N];
		boolean[] zeroed = new boolean[N];
		double sum = 0;
		int totalZeroed = 0;
		for(int i=0;i<N;i++){
			res[i] = 200.0/N - points[i]*100.0/X;
			if(res[i]<0){
				sum += points[i];
				res[i] = 0;
				zeroed[i] = true;
				totalZeroed++;
			}
		}
		for(int i=0;i<N;i++){
			if(!zeroed[i]){
				res[i] = (200.0*X-100.0*sum)/(X*1.0*(N-totalZeroed))-points[i]*100.0/X;//res[i]/(1.0-sum/100.0);
			}
		}
		return res;
	}

}
