import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] argv) {
		Scanner in = new Scanner(System.in);
		int T, tt;
		long ll, rr=0, mm;
		T = in.nextInt();
		FileOutputStream out;
		try
        {
			out=new FileOutputStream("D://out.txt");
		for (tt = 0; tt < T; ++tt) {
			long t, r;
			r = in.nextLong();
			t = in.nextLong();
			BigInteger br = new BigInteger("1");
			BigInteger bt = new BigInteger("1");
			BigInteger left = new BigInteger("1");
			BigInteger right = new BigInteger("1");
			BigInteger mid = new BigInteger("1");
			BigInteger tmp1 = new BigInteger("1");
			BigInteger tmp2 = new BigInteger("2");
			BigInteger tmp4 = new BigInteger("4");
			br = br.valueOf(r);
			bt = bt.valueOf(t);
			ll = (1-2*r)/4; rr = 907106780;
			while (ll <= rr) {
				mm = (ll+rr)/2;
				mid = mid.valueOf(mm);
				//System.out.println(mm);
				//System.out.println(mid.toString());
				BigInteger t3 = new BigInteger("1");
				t3 = (((br.multiply(tmp2)).add(mid.add(mid))).subtract(tmp1)).multiply(mid);
				//System.out.println(t3.toString());
				if (t3.compareTo(bt) > 0) rr = mm-1;
				else ll = mm + 1;
			}
			String ans = "Case #"+(tt+1)+": "+rr;
			ans += "\r\n";
			byte[] buff=new byte[]{};

	            buff=ans.getBytes();
	            //FileOutputStream out=new FileOutputStream("D://out.txt");
	            out.write(buff,0,buff.length);
	        
		}
        }catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
	}
}
