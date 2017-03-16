import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class qt32 {
	private static boolean isP(String s) {
		StringBuffer s1 = new StringBuffer(s);
		StringBuffer s2 = new StringBuffer(s);
		s1 = s1.reverse();
		return(s1.toString().equals(s2.toString()));
	}
	
	public static void test8(BufferedReader in) throws IOException {
		File out = new File("out.txt");
		FileWriter fw = new FileWriter(out);
		BufferedWriter bw = new BufferedWriter(fw);
		
		int cases = Integer.parseInt(in.readLine());
		for (int j = 1;j<=cases;j++) {
			bw.write("Case #"+j+": ");
			String ab = in.readLine();
			String tokens[] = ab.split(" ");
			int lena = tokens[0].length();
			int lenb = tokens[1].length();
			int minl = lena/2 + lena%2;
			int maxl = lenb/2 + lenb%2;
			int ans = 0;
			BigInteger a = new BigInteger(tokens[0]);
			BigInteger b = new BigInteger(tokens[1]);
			
			for (int i = minl;i<=maxl;i++) {
				int len = i/2;
				int mid = i%2;
				int mink = (int)Math.pow(10, len-1);
				int maxk = (int)Math.pow(10, len);
				for (int k = mink;k<maxk;k++) {
					BigInteger c;
					if (mid==1) {
						for (int l=0;l<10;l++) {
							String temp;
							if (k==0) {
								temp = String.valueOf(l);
							}
							else {
								temp = String.valueOf(k)+String.valueOf(l)+new StringBuffer(String.valueOf(k)).reverse().toString();
							}
							c = new BigInteger(temp);
							c = c.multiply(c);
							if (isP(c.toString()) && (c.compareTo(a)!=-1) && (c.compareTo(b)!=1)) {
								ans++;
							}
						}
					}else {
						c = new BigInteger(
							String.valueOf(k)+new StringBuffer(String.valueOf(k)).reverse().toString()
						);
						c = c.multiply(c);
						if (c.compareTo(a)!=-1 && c.compareTo(b)!=1 && isP(c.toString())) {
							ans++;
						}
					}
				}
			}
			bw.write(ans+"\n");
		}	
		in.close();
		bw.close();
	}	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File conf = new File("A.in");
		FileReader fr=new FileReader(conf);
		BufferedReader in=new BufferedReader(fr);
		test8(in);
	}
}
