import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.TreeSet;

public class Main {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ia;

		int T = Integer.parseInt(in.readLine());

		TreeSet<BigInteger> ts = new TreeSet<BigInteger>();
		BigInteger end = new BigInteger("100000000");
		//BigInteger end = new BigInteger("100000000000000000000000000000000000000000000000000");
		for(BigInteger bg = end;0 < bg.signum(); bg = bg.subtract(BigInteger.ONE)){
			String f = bg.toString();
			String r = (new StringBuffer(f)).reverse().toString();
			if(f.equals(r)){
				BigInteger tmp = bg.multiply(bg);
				f = tmp.toString();
				r = (new StringBuffer(f)).reverse().toString();
				if(f.equals(r)){
					System.err.println(bg.toString() + "\t" + f.toString());
					ts.add(new BigInteger(f));
				}
			}
		}
		for(int i = 1;i <= T; ++i){
			System.out.print("Case #" + i + ": ");
			ia = in.readLine().split(" ");
			BigInteger f = new BigInteger(ia[0]);
			BigInteger t = new BigInteger(ia[1]);
			BigInteger tmp = null;
			Iterator<BigInteger> it = ts.iterator();
			BigInteger count = new BigInteger("0");
			while(it.hasNext()){
				tmp = it.next();
				if(0 <= tmp.subtract(f).signum()){
					break;
				}
			}
			if(tmp != null){
				while(true){
					if(tmp.subtract(t).signum() <= 0){
						count = count.add(BigInteger.ONE);
					}
					if(it.hasNext()){
						tmp = it.next();
					} else {
						break;
					}
				}
			}
			System.out.println(count.toString());
		}
	}

}
