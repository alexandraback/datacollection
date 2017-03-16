import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new FileInputStream(new File("C.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("C.out")));
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			out.printf("Case #%d:%n", t);
			int n = scan.nextInt(), j = scan.nextInt();
			for(int bitmask=0;bitmask<1 << (n-2);bitmask++) {
				String str = Integer.toBinaryString(bitmask);
				while(str.length() < n-2) {
					str = "0" + str;
				}
				str = "1" + str + "1";
				boolean isGood = true;
				for(int base=2;base<=10;base++) {
					BigInteger bi = new BigInteger(str, base);
					if(bi.isProbablePrime(100)) {
						isGood = false;
						break;
					}
				}
				if(!isGood)
					continue;
				StringBuilder tmp = new StringBuilder();
				tmp.append(str);
				boolean good = true;
				for(int base=2;base<=10;base++) {
					BigInteger bi = new BigInteger(str, base);
					boolean found = false;
					for(long p=2;p<100_000;p++) {
						if(bi.mod(BigInteger.valueOf(p)).equals(BigInteger.ZERO)) {
							tmp.append(" ").append(p+"");
							found = true;
							break;
						}
					}
					if(!found) {
						good = false;
						break;
					}
				}
				if(!good)
					continue;
				out.println(tmp.toString().trim());
				j--;
				if(j == 0)
					break;
			}
		}
		scan.close();
		out.close();
	}
}
