import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class A{
	
	public static String out="";
	
	public static String num(String r, String t){
		BigInteger R=new BigInteger(r);
		BigInteger T=new BigInteger(t);
		BigInteger one=new BigInteger("1");
		BigInteger two=new BigInteger("2");
		BigInteger newr= R.multiply(two).subtract(one).divide(two).divide(two);
		BigInteger rr=R.multiply(two).subtract(one);
		BigInteger newrq=newr.multiply(newr);
		BigInteger res=sqrt(T.divide(two).add(newrq));
		res=res.subtract(newr).subtract(one);
		BigInteger tmp=res.add(one);
		BigInteger resq=tmp.multiply(tmp);
		BigInteger used=(resq.multiply(two)).add(rr.multiply(tmp));
		while(used.compareTo(T)<=0){
			res=res.add(one);
			tmp=res.add(one);
			resq=tmp.multiply(tmp);
			used=(resq.multiply(two)).add(rr.multiply(tmp));
		}
		return res.toString();
	}
	
	public static BigInteger sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}
	
	
	public static void main(String[] args) {
		BufferedReader br = null;
		BufferedWriter writer = null;
		try {

			br = new BufferedReader(new FileReader(
					"C:/codejam/A-small-attempt0.in"));
			int T, i;
			String r, t, res, tmpd;
			T = Integer.parseInt(br.readLine());
			for (i = 1; i < T + 1; i++) {
				out += "Case #" + i + ": ";
				tmpd = br.readLine();
				String[] d = tmpd.split(" ");
				r = d[0];
				t = d[1];
				res=num(r,t);
				out += res+"\n";
				System.out.println(out);
			}
			// }

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