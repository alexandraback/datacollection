import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


class Main {
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
	public static void main(String[] args)
	{
		BufferedReader br = null;
		File file = new File("output.txt");
		FileWriter fw = null;
		BufferedWriter bw = null;
		try {
			br = new BufferedReader(new FileReader("A-large (1).in"));
			try {
				fw = new FileWriter(file.getAbsoluteFile());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			bw = new BufferedWriter(fw);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int test;
		try {
			test = Integer.parseInt(br.readLine());
			for (int z = 1; z <= test; ++ z){
				String tmp = br.readLine();
				String [] parsed = tmp.split(" ");
				BigInteger r = new BigInteger(parsed[0]);
				BigInteger t = new BigInteger(parsed[1]);
				BigInteger n = new BigInteger("0");
				r = r.add(r);
				r = r.subtract(new BigInteger("1"));
				n = n.subtract(r);
				r = r.multiply(r);
				t = t.multiply(new BigInteger("8"));
				r = r.add(t);
				n = n.add(sqrt(r));
				n = n.divide(new BigInteger("4"));
				bw.write("Case #" + z + ": " + n.toString() +"\n");
			}
			bw.close();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
