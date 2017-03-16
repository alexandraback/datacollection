
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
public class D {

	public static BufferedReader reader = null;
	
	public static File file;
	
	public static Map m = new HashMap();
	
	
	public static void precompute() throws Exception{
		
	}
	
	
	public static String solve() throws Exception{
		
		//====================== code ========================================================
		
		String [] lines = reader.readLine().split(" ");
		
		int K = toint(lines[0]);
		int C = toint(lines[1]);
		int S = toint(lines[2]);
		
		if (K == S){
			
			String res = "";
			
			for (int i = 1; i <= K; i++)
				res  += i + " ";
			
			return res;
			
		}
		
		
		//=====================================================================================
		return "";
	}
	
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		file = new File("Test.in");
		file = new File("D-small-attempt0.in");
//		file = new File(Template.class.getName() + "-large-practice.in");

		File fileOut = new File(D.class.getName() + ".out");

		BufferedWriter out = null;

		int num;

		reader = new BufferedReader(new FileReader(file));

		num = Integer.parseInt(reader.readLine());

		out = new BufferedWriter(new FileWriter(fileOut));

		String res = "";
		
		precompute();
		
		for (int case_i = 1; case_i < num + 1; case_i++) {
			
			res = solve();

			out.write("Case #" + case_i + ": " + res + "\n");
			
			cout ("Case #" + case_i + ": " + res + "\n");
		}

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
