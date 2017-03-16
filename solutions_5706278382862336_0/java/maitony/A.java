package Round1C_2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.math.BigInteger;

public class A {

	public void solve() throws Exception {
		String path = A.class.getProtectionDomain().getCodeSource().getLocation().getPath() + A.class.getPackage().toString().replace("package ", "") + "/";
		String in = path.substring(1) + "input.in";
		String out = path.substring(1) + "input.out";
		
		File file = new File(out);
		if (file.exists()) file.delete();
		
		BufferedReader reader = new BufferedReader(new FileReader(in));
		BufferedWriter writer = new BufferedWriter(new FileWriter(out));
		
		int T = Integer.parseInt(reader.readLine());
		
		BigInteger p, q, k;
		for (int i = 0; i < T; i ++) {
			String[] t = reader.readLine().split("/");
			p = new BigInteger(t[0]);
			q = new BigInteger(t[1]);
			
			int j = 0;
			int n = -1;
			boolean f = false;
			for (j = 0; j < 40 && !f; j ++) {
				p = p.multiply(BigInteger.valueOf(2));
				if (p.compareTo(q) == 0) {
					if (n == -1) {
						n = j;
					}
					f = true;
					break;
				} else {
					if (p.compareTo(q) > 0) {
						if (n == -1) {
							n = j;
						}	
						p = p.subtract(q);
					}
				}
			}
			
			if (!f) {
				System.out.print("Case #" + (i + 1) + ": impossible\n");
				writer.append("Case #" + (i + 1) + ": impossible\n");
			} else {
				System.out.print("Case #" + (i + 1) + ": " + (n + 1) + "\n");
				writer.append("Case #" + (i + 1) + ": " + (n + 1) + "\n");
			}
		}
		
		
		reader.close();
		writer.flush();
		writer.close();
	}
	
	public static void main(String[] args) throws Exception {

		new A().solve();
	}

}
