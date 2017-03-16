import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class DBrute2016 {
	
	private static final String file = "./D-small-attempt0.in";
	private static final String fileOut = "./Dout.txt";
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		PrintWriter out = new PrintWriter(fileOut);
		String line = br.readLine();
		int T = Integer.parseInt(line);
		for(int cas = 1; cas <= T; cas++){
			String[] sp = br.readLine().split(" ");
			int K = Integer.parseInt(sp[0]);
			int C = Integer.parseInt(sp[1]);
			BigInteger pow = new BigInteger(""+K);
			pow = pow.pow(C-1);
			BigInteger actual = BigInteger.ONE;
			String ans = "Case #"+cas+": ";
			for(int i = 0; i < K; i ++){
				ans+=actual+" ";
				actual=actual.add(pow);
			}
			out.println(ans.trim());
		}
		out.close();
		br.close();
	}

}