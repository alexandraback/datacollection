import java.util.*;
import java.math.*;
import java.io.*;

class Main{
	static String solve(BigInteger r, BigInteger t){
		BigInteger ans = BigInteger.ZERO;
		BigInteger left = BigInteger.ZERO;
		BigInteger right = new BigInteger(t.toString());
	//	BigInteger right = new BigInteger("10");
		BigInteger two = new BigInteger("2");
		while(left.compareTo(right) <= 0){
			BigInteger mid = left.add(right).divide(two);
		//	mid = new BigInteger("5");
		//	System.out.println("mid"+mid.toString());
			BigInteger tmp = two.multiply(mid).multiply(mid);
			BigInteger tmp2 = (((two.multiply(r)).subtract(BigInteger.ONE)).multiply(mid));
			tmp = tmp.add(tmp2);
		//	System.out.println("aaa"+tmp.toString());
		//	System.out.println("r"+r.toString());
			if(tmp.compareTo(t) <= 0){
				if(ans.compareTo(mid) < 0)
					ans = new BigInteger(mid.toString());
				left = mid.add(BigInteger.ONE);
			}else{
				right = mid.subtract(BigInteger.ONE);
			}
		//	break;
		}
		return ans.toString();
	}

	public static void main(String[] args) throws Exception{
		FileReader fr = new FileReader("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("gcjans.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		String s = br.readLine();
		int T = Integer.parseInt(s);
		for(int caseT = 1;caseT <= T;++caseT){
			s = br.readLine();
			String tmp[] = s.split(" ");
			BigInteger r = new BigInteger(tmp[0]);
			BigInteger t = new BigInteger(tmp[1]);
			bw.write("Case #" + String.valueOf(caseT) + ": " + solve(r,t));
			bw.newLine();
		}
		bw.flush();
		bw.close();
		br.close();
		fw.close();
		br.close();
		fr.close();
	}
}

