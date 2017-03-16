import java.io.*;
import java.util.*;

class bullseye {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("bullseye.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bullseye.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long r = Long.parseLong(st.nextToken());
			long t = Long.parseLong(st.nextToken());
			double test = 1./2. * ((Math.sqrt(1. - 4.*(double)r + 4.*Math.pow((double)r, 2.) + 8.*(double)t) - 3.)/2. - (double)r);
			long numRings = (long)Math.ceil(test);
			long answer = 0;
			for (long j = numRings - 2; j <= numRings + 2; j++)
			{
				long m = r + 2*j;
				double test1 = 1. + 3.*m/2. + Math.pow((double)m, 2.)/2. + r/2. - Math.pow((double)r, 2.)/2.;
				double test2 = 1. + 3.*(m+2.)/2. + Math.pow(m+2., 2.)/2. + r/2.- Math.pow((double)r, 2.)/2.;
				if (test1 <= t && t < test2) 
				{
					answer = j+1;
					break;
				}
			}
			out.println("Case #" + (i+1) + ": " + answer);
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}

