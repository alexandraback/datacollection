
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
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

//			for (int y = 2; y <= 10; y++) 
//				cout(i + " base " + y + "  is " + Long.parseLong(Long.toBinaryString(i), y));

//			long base3;
//			long l = Long.parseLong(s, 3);
//			if (l % 2)
//			
			
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
		
		res = precompute();
		
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
