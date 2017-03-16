import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class C {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-1-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("outputC.txt"));
		int nrTests = Integer.parseInt(br.readLine());
		for(int tNr = 1; tNr <= nrTests; tNr++) {
			int n = Integer.parseInt(br.readLine());
			long[] ds = new long[n];
			long[] hs = new long[n];
			long[] ms = new long[n];
			int total = 0;
			long slowD = 0, slowM =0;
			long fastD = 0, fastM = Long.MAX_VALUE;
			for(int i = 0; i < n; i++) {
				String[] strs = br.readLine().split(" ");
				ds[i] = Long.parseLong(strs[0]);
				hs[i] = Long.parseLong(strs[1]);
				ms[i] = Long.parseLong(strs[2]);
				
				total += hs[i];
				
				if(fastM >= ms[i]) {
					slowM = fastM;
					slowD = fastD;
					fastM = ms[i];
					fastD = ds[i];
					
					if(hs[i] > 1) {
						slowM = ms[i] + 1;
						slowD = fastD;
					}
				} else {
					slowM = ms[i];
					slowD = ds[i];
				}
			}
			
			if(total < 2) {
				pw.println("Case #" + tNr + ": 0");
			}
			
			long time1 = (360L - slowD) * slowM;
			long time2 = (760L - fastD) * fastM;
			if(time1 < time2) {
				pw.println("Case #" + tNr + ": 0");
			} else {
				pw.println("Case #" + tNr + ": 1");
			}
		}
		
		pw.close();
		br.close();
		System.out.println("done!");
	}
}
