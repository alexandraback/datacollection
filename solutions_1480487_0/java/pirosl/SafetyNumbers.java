import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SafetyNumbers {
	public static void main(String args[]) {
		try {
			FileInputStream fstream = new FileInputStream("in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter ofstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(ofstream);
			  
			int t = Integer.parseInt(br.readLine());
			for(int i=0;i<t;++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(st.nextToken());
				int[] points = new int[n];
				double[] factors = new double[n];
				double sum = 0.0;
				for(int j=0;j<n;++j) {
					points[j] = Integer.parseInt(st.nextToken());
					sum += points[j];
				}
				double ss = 0.0;
				for(int j=1;j<n;++j) {
					factors[j] = ((double)points[0] - (double)points[j]) / sum;
					ss += factors[j];
				}
				
				double[] bb = new double[n];
				double ps = 0.0;
				bb[0] = (1.0 - ss) / (double)n;
				int count = 0;
				if(bb[0] < 0.0)
					ps += bb[0];
				else
					++count;
				for(int j=1;j<n;++j) {
					bb[j] = bb[0] + factors[j];
					if(bb[j] < 0.0)
						ps += bb[j];
					else
						++count;
				}
				if(ps < 0.0) {
					ps /= count;
					for(int j=0;j<n;++j) {
						if(bb[j] < 0.0)
							bb[j] = 0.0;
						else
							bb[j] += ps;
					}
				}
				out.write("Case #" + (i+1) +": ");
				for(int j=0;j<n;++j) {
					out.write("" + String.format("%.6f",new Double(100*bb[j])) + " ");
				}
				out.write("\r\n");
			}
			
			in.close();
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
}
