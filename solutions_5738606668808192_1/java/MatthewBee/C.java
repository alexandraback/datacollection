
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


/**
 * 
 */

/**
 * @author Fei
 * 
 * start at 9:48 22/03/2016
 *
 */
public class C {

	public static BufferedReader reader = null;
	
	public static File file;
	
	public static Map m = new HashMap();
	
	public static Set s = new HashSet();
	
	public static String precompute() throws Exception{

		String res = "";
		
		int x = 2;

		long start = Long.parseLong("1000000000000001", x);
		long end = Long.parseLong("1111111111111111", x);

		cout("start is" + start + " and end is " + end);

		int cnt = 0;

		for (long i = start; i <= end; i++) {

			String s = Long.toBinaryString(i);
			
			if (s.endsWith("0"))
				continue;
			
			
			long base [] = new long [11];
			
			
			base[2] = check_prime_2(s);
			
			if (base[2] == -1)
				continue;
			
			if (i % 11 != 0)
				continue;

			base[10] = 11;
			
			if (!checkmod(i, 5, 2))
				continue;

			boolean b = true;

			for (int y = 3; y <= 9; y++) {
				
				long l = Long.parseLong(s, y);

//				cout (" now s = " + i + " " + y + " => " + l);
				
				if (l % 2 == 0){
					base[y] = 2;
					continue;
				}
				
				if (l % 5 == 0){
					base[y] = 5;
					continue;
				}
				
				if (l % 3 == 0){
					base[y] = 3;
					continue;
				}

				
				b = false;
				break;
					
			}

			if (b){
				for (int y = 2; y <= 10; y++) 
					cout(i + " base " + y + "  is " + Long.parseLong(Long.toBinaryString(i), y));
				cnt++;}

			if (b && cnt <= 50){
			res += "" + Long.toBinaryString(i);
			
			for (int y = 2; y <= 10; y++) 
				res += " " + base[y];
			
			res += "\n";
			}
			
		}

		cout("cnt is " + cnt);	
		
		cout(res);
		
		return res;
		
	}
	
	
	public static String precompute_large() throws Exception{

		String res = "";
		
		int x = 2;

		String s_start = "1";
		String s_end = "1";
		for (int i = 0; i < 30; i++){
			s_start += "0";
			s_end += "1";
		}
		
		s_start += "1";
		s_end += "1";
		
		long start = Long.parseLong(s_start, x);
		long end = Long.parseLong(s_end, x);

		cout("start is" + start + " and end is " + end + " => " + (end - start));

		int cnt = 0;
		
		BigInteger mod10 = new BigInteger("10");

		for (long i = start; i <= end; i++) {

//			cout ("=> " + i);
			
			String s = Long.toBinaryString(i);
			
			if(s.charAt(s.length() - 1) == '0')
				continue;
				
			long base [] = new long [11];
			
			BigInteger reallyBig = new BigInteger(s);
			
			BigInteger mod = new BigInteger("11");
			
			BigInteger reminder = reallyBig.remainder(mod);
			
			if(reminder.intValue() != 0)
				continue;
				
			base[10] = 11;
			
			boolean b = true;
			
			for (int y = 2; y <= 9; y++) {
				
//				int l = getlastDigit(s, y);
				
				BigInteger bi = new BigInteger(s, y);
				
				int l = bi.remainder(mod10).intValue();
				
//				if (y == 2) cout (i + " => 2 => " + l);
				
				if (l % 2 == 0) {
					base[y] = 2;
					continue;
				}

				if (l % 5 == 0) {
					base[y] = 5;
					continue;
				}

//				if (l % 3 == 0) {
//					base[y] = 3;
//					continue;
//				}
				
				b = false;
				break;
				
			}
			
			if (b) {
//				cout(i +  "  is OK");
				
				cnt++;
				
				res += "" + Long.toBinaryString(i);
				
				for (int y = 2; y <= 10; y++) 
					res += " " + base[y];
				
				res += "\n";
				
//				for (int y = 2; y <= 10; y++) 
//					cout(y + " => " + base[y]);
				
				
				for (int rad = 2; rad <= 10; rad++){
					
					BigInteger bi = new BigInteger(s, rad);
					
//					cout (i + " bi  with radix " + rad + " is " + bi.toString());
					
					if( bi.remainder( new BigInteger("" + base[rad])).intValue() != 0 ){
						cout("Wrong");
						break;
					}
					
				}
				
				
				
			}
			
			
			if(cnt == 500)
				break;
		}

		cout("cnt is " + cnt);	
		
//		cout(res);
		
		return res;
		
	}
	
	
	
	public static long check_prime_2(String s){
		
		long l = Long.parseLong(s, 2);
		
		for (long i = 2; i < l / 2; i++){
			
			if (l % i == 0)
				return i;
		}
		
		return -1;
		
	}
	
	
	
	public static boolean checkmod(long l, int base, long mod){
		l = Long.parseLong(Long.toBinaryString(l), base);
		if (l % mod == 0)
			return true;
		else
			return false;
	}
	
	
	public static long check_prime(long l, int base ){
		
		l = Long.parseLong(Long.toBinaryString(l), base);
		
		for (long i = 2; i < l / 2; i++){
			
			if (l % i == 0)
				return i;
		}
		
		return -1;
		
	}
	
	
	public static String solve() throws Exception{
		
		//====================== code ========================================================
		String line = reader.readLine();
		
		
		//=====================================================================================
		return "";
	}
	
	
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		file = new File("Test.in");
		file = new File("B-small-attempt2.in");
		file = new File("B-large.in");

		File fileOut = new File(C.class.getName() + ".out");

		BufferedWriter out = null;

		int num;

		reader = new BufferedReader(new FileReader(file));

		num = Integer.parseInt(reader.readLine());

		out = new BufferedWriter(new FileWriter(fileOut));

		String res = "";
		
		res = precompute_large();
		
//		res = precompute();
		
//		for (int case_i = 1; case_i < num + 1; case_i++) {
//			
////			res = solve();
//
//			out.write("Case #" + case_i + ": " + res + "\n");
//			
////			cout ("Case #" + case_i + ": " + res + "\n");
//		}
		
		out.write("Case #" + 1 + ": \n" + res );

		reader.close();
		out.close();

	}
	
	public static int toint(String s){
		return Integer.parseInt(s);
	}
	
	public static void cout(String s){
		System.out.println(s);
	}
	
	public static void cout(int i){
		System.out.println(i + "");
	}
	
	public static int commonDivisor(int n, int m) {
		
		while (n % m != 0) {
			int temp = n % m;
			n = m;
			m = temp;
		}
		return m;
	}

	public static int commonMultiple(int n, int m) {
		return n*m/commonDivisor(n,m);
	}
	

}
