import java.io.*;

public class CJ1A2 {
	
	static long getMaxGain (int E, int R, int N, int[] v) {
		long gain = 0;
		int maxVal = v[0];
		for (int i = 0; i < N; i++) {
			gain += v[i];
			if (v[i] > maxVal)
				maxVal = v[i];
		}
		if (R >= E)
			gain *= E;
		else {
			gain *= R;
			gain += (maxVal * (E - R));
		}
		return gain;
	}
	public static void main (String[] args) {
		String fName = "B-small-attempt0";
		try {
			BufferedReader inp = new BufferedReader(new FileReader(fName + ".in"));
			PrintWriter op = new PrintWriter(new FileWriter(fName + ".out"));
//			PrintStream op = System.out;
			String l = inp.readLine();
			String[] lArr;
			int n = Integer.parseInt(l);
			for (int ii = 1; ii <= n; ii++) {
				l = inp.readLine();
				lArr = l.split (" ");
				int E = Integer.parseInt(lArr[0]);
				int R = Integer.parseInt(lArr[1]);
				int N = Integer.parseInt(lArr[2]);
				l = inp.readLine();
				lArr = l.split (" ");
				int[] v = new int [N];
				for (int i = 0; i < N; i++) 
					v[i] = Integer.parseInt(lArr[i]);

				long maxGain = getMaxGain (E, R, N, v);
				op.println("Case #" + ii + ": " + maxGain);
				System.out.println("Case #" + ii + ": " + maxGain);
			}
			op.close();
			inp.close();
		}catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
