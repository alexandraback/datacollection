package Q1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;

public class C2 {
	
	private static final BigDecimal[] fairSquares = {
		new BigDecimal("1"),
		new BigDecimal("4"),
		new BigDecimal("9"),
		new BigDecimal("121"),
		new BigDecimal("484"),
		new BigDecimal("10201"),
		new BigDecimal("12321"),
		new BigDecimal("14641"),
		new BigDecimal("40804"),
		new BigDecimal("44944"),
		new BigDecimal("1002001"),
		new BigDecimal("1234321"),
		new BigDecimal("4008004"),
		new BigDecimal("100020001"),
		new BigDecimal("102030201"),
		new BigDecimal("104060401"),
		new BigDecimal("121242121"),
		new BigDecimal("123454321"),
		new BigDecimal("125686521"),
		new BigDecimal("400080004"),
		new BigDecimal("404090404"),
		new BigDecimal("10000200001"),
		new BigDecimal("10221412201"),
		new BigDecimal("12102420121"),
		new BigDecimal("12345654321"),
		new BigDecimal("40000800004"),
		new BigDecimal("1000002000001"),
		new BigDecimal("1002003002001"),
		new BigDecimal("1004006004001"),
		new BigDecimal("1020304030201"),
		new BigDecimal("1022325232201"),
		new BigDecimal("1024348434201"),
		new BigDecimal("1210024200121"),
		new BigDecimal("1212225222121"),
		new BigDecimal("1214428244121"),
		new BigDecimal("1232346432321"),
		new BigDecimal("1234567654321"),
		new BigDecimal("4000008000004"),
		new BigDecimal("4004009004004"),
		new BigDecimal("100000020000001"),
		new BigDecimal("100220141022001"),
		new BigDecimal("102012040210201"),
		new BigDecimal("102234363432201"),
		new BigDecimal("121000242000121"),
		new BigDecimal("121242363242121"),
		new BigDecimal("123212464212321"),
		new BigDecimal("123456787654321"),
		new BigDecimal("400000080000004"),
		new BigDecimal("10000000200000001"),
		new BigDecimal("10002000300020001"),
		new BigDecimal("10004000600040001"),
		new BigDecimal("10020210401202001"),
		new BigDecimal("10022212521222001"),
		new BigDecimal("10024214841242001"),
		new BigDecimal("10201020402010201"),
		new BigDecimal("10203040504030201"),
		new BigDecimal("10205060806050201"),
		new BigDecimal("10221432623412201"),
		new BigDecimal("10223454745432201"),
		new BigDecimal("12100002420000121"),
		new BigDecimal("12102202520220121"),
		new BigDecimal("12104402820440121"),
		new BigDecimal("12122232623222121"),
		new BigDecimal("12124434743442121"),
		new BigDecimal("12321024642012321"),
		new BigDecimal("12323244744232321"),
		new BigDecimal("12343456865434321"),
		new BigDecimal("12345678987654321")
	};
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int cases = Integer.valueOf(in.readLine());
		
		for ( int cas=0 ; cas<cases ; cas++ ) {
			String[] line = in.readLine().split(" ");
			BigDecimal min = new BigDecimal(line[0]);
			BigDecimal max = new BigDecimal(line[1]);
			
			int start = 0;
			for ( start=0 ; start<fairSquares.length ; start++ ) {
				if ( min.compareTo(fairSquares[start]) <= 0 ) {
					break;
				}
			}
			int end;
			for ( end=start ; end<fairSquares.length ; end++ ) {
				if ( max.compareTo(fairSquares[end]) < 0 ) {
					break;
				}
			}
			System.out.println("Case #" + (cas+1) + ": " + (end - start));
		}
		in.close();
		out.close();
	}
}
