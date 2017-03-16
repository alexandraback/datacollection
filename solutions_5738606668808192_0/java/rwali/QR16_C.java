/**
 * 
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * @author rohit
 *
 */
public class QR16_C {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		FileReader fr = new FileReader(new File("/home/rohit/Desktop/codejam/c/small.in"));
		BufferedReader br = new BufferedReader(fr);
		
		FileWriter fw = new FileWriter(new File("/home/rohit/Desktop/codejam/c/small.out"));
		BufferedWriter bw = new BufferedWriter(fw);
		
		int tc = Integer.valueOf(br.readLine().trim());
		
		for(int i=0;i<tc;i++){
			String ss[] = br.readLine().trim().split(" ");
			int n = Integer.parseInt(ss[0].trim());
			int j = Integer.parseInt(ss[1].trim());
			
			String s = getBase(n-2);
			int found=0;
			List<List<String>> ans = new ArrayList<>();
			while(found<j){
				List<String> f = getFactors("1" + s + "1");
				if(!f.isEmpty()) {
					found++;
					ans.add(f);
				}
				s = getNext(s);
			}
			
			bw.write("Case #" + (i+1) + ":\n");
			for(List<String> an : ans){
				bw.write(an.get(0));
				for(int k=1;k<10;k++){
					bw.write(" " + an.get(k));
				}
				bw.write("\n");
			}

		}
		
		bw.close();
		br.close();
		fw.close();
		fr.close();
	}

	private static String getNext(String s) {

		int i=s.length()-1;
		StringBuffer sb = new StringBuffer();
		for(;i>=0;i--){
			if(s.charAt(i)=='0')
				break;
		}
		for(int j=0;j<i;j++){
			sb.append(s.charAt(j));
		}
		sb.append("1");
		for(int j=i+1;j<s.length();j++){
			sb.append("0");
		}
		return sb.toString();
	}

	private static List<String> getFactors(String s) {
		List<String> ret = new ArrayList<>();
		ret.add(s);
		
		for(int b=2;b<=10;b++){
			BigInteger ss = getValueInBase(s,b);
			BigInteger fac = isPrime(ss);
			if(fac.compareTo(BigInteger.valueOf(-1)) == 0)
				return new ArrayList<>();
			else
				ret.add(fac.toString());
		}
		return ret;
	}

	private static BigInteger isPrime(BigInteger ss) {
		
		BigInteger lim  = sqrt(ss);
		if(ss.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
			return BigInteger.valueOf(2);
		
		for(BigInteger i=BigInteger.valueOf(3);i.compareTo(lim)<0; i= i.add(BigInteger.valueOf(2))){
			if(ss.mod(i).equals(BigInteger.ZERO))
				return i;
		}
		return BigInteger.valueOf(-1);
	}

	
	private static BigInteger sqrt(BigInteger num) {

		if (num.equals(BigInteger.valueOf(0)) || num.equals(BigInteger.valueOf(1))) {
			return num;
		}

		BigInteger ans = num.divide(BigInteger.valueOf(2));

		while( ans.compareTo(num.divide(ans)) > 0){
			BigInteger a = num.divide(ans);
			BigInteger b = a.add(ans);
			ans = b.divide(BigInteger.valueOf(2));
		}
		return ans;
	}
	
	private static BigInteger getValueInBase(String s, int b) {		
		return new BigInteger(s, b);
	}

	private static String getBase(int n) {
		
		StringBuffer sb = new StringBuffer();
		for(int i=0;i<n;i++){
			sb.append("0");
		}
		return sb.toString();
	}
}
