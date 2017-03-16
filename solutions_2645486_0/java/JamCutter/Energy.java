import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Energy {

	protected static long maxEnergy ;
	public static void main(String[] args) {
		PrintWriter pw = null;
		try {

			FileWriter fw = new FileWriter("MyFileWriter.txt");

			BufferedWriter bw = new BufferedWriter(fw);
			pw = new PrintWriter(bw);

			System.out.println("args[0]: " + args[0]);
			BufferedReader br = new BufferedReader(new FileReader(args[0]));

			long nTests = Long.valueOf(br.readLine());
			System.out.println("nTests = " + nTests);

			for (int i = 1; i <= nTests; i++) {

				String ernLine = br.readLine();
				StringTokenizer st = new StringTokenizer(ernLine);

				long e = Long.valueOf(st.nextToken());
				long r = Long.valueOf(st.nextToken());
				long n = Long.valueOf(st.nextToken());

				System.out.println("Case #" + i + ", e= " + e + ", r=" + r + ", n=" + n);	
				
				String vLine = br.readLine();				
				long[] vArray = new long[(int) n];
				
				st = new StringTokenizer(vLine);
				int v = 0;
				while (st.hasMoreTokens()){
					vArray[v] = Long.valueOf(st.nextToken());
					v++;
				}
				
				outputEnergy(pw, i,e,r, n, vArray);
			}
			System.out.println("End");

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			pw.close();
		}

	}

	private static void outputEnergy(PrintWriter pw, int i, long e, long r,
			long n, long[] vArray) {
		String output = "Case #" + i + ":";
		
		maxEnergy = e;

		long  gain = getMaxGain (e,r,n, vArray);
		pw.println(output + " "+ gain);
		
	}

	private static long getMaxGain(long e, long r, long n, long[] vArray) {
		
		if (n == 0) {
			return 0;
		}
		
		if (n == 1){
			return e * vArray[0];
		}
		
		long maxGain = 0;
		long[] remainingAcitiviteis = getRemaininActivities(vArray, n);
		
		for (long i = 0; i <= e; i++){
			long cGain = vArray[0] * i;
			long gain = getMaxGain(getDepletedEnergy(e,i, r), r, n-1, remainingAcitiviteis) + cGain;
			
			if (gain > maxGain){
				maxGain = gain;
			}
			
		}
		return maxGain;
	}

	private static long[] getRemaininActivities(long[] vArray, long n) {
		if (n <= 0){
			return null;
		}
		
		long [] rem =  new long [(int) (n-1)];
		
		for (int i =1; i<n; i++){
			rem[i-1] = vArray[i];
		}
		return rem;
	}

	private static long getDepletedEnergy(long e, long i, long r) {
		
		return ((e-i + r) > maxEnergy )? maxEnergy : (e-i + r);
	}

}
