import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B {
	
	public static String out="";

	public static int gain(int[] v, int r, int e, int n, int E) {
		int maxsum = 0, i;
		if(r>=E){
			for(i=n-1;i<v.length;i++)
				maxsum+=v[i]*E;
			return maxsum;
		}
		else if (n > v.length)
			return 0;
		else if (n==v.length)
			return e*v[n-1];
		else if (e+r-E<=0){
			for (i = 0; i<=e; i++) {
				maxsum = Math.max(maxsum, gain(v, r, e - i+r, n + 1, E) + i*v[n - 1]);
			}
			return maxsum;
		}
		else {
			for (i = e+r-E; i<=e; i++) {
				maxsum = Math.max(maxsum, gain(v, r, e - i+r, n + 1, E) + i*v[n - 1]);
			}
			return maxsum;
		}
	}
	
	public static void main(String[] args) {
		BufferedReader br = null;
		BufferedWriter writer = null;
		try {

			br = new BufferedReader(new FileReader(
					"C:/codejam/B-small-attempt3.in"));
			int T, i;
			int r, j, res, n, e;
			String tmpd;
			T = Integer.parseInt(br.readLine());
			for (i = 1; i < T + 1; i++) {
				out += "Case #" + i + ": ";
				tmpd = br.readLine();
				String[] d = tmpd.split(" ");
				e = Integer.parseInt(d[0]);
				r = Integer.parseInt(d[1]);
				n = Integer.parseInt(d[2]);
				int[] v=new int[n];
				tmpd = br.readLine();
				d = tmpd.split(" ");
				for(j=0;j<n;j++){
					v[j]=Integer.parseInt(d[j]);
				}
				res=gain(v,r,e,1,e);
				out += res+"\n";
			}
			// }
			System.out.println(out);
			writer = new BufferedWriter(new FileWriter("C:/codejam/output.out"));

			writer.write(out);

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException e) {
			}
		}

	}

}