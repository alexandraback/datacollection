
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
public class B {

	public static BufferedReader reader = null;
	
	public static File file;
	
	public static Map m = new HashMap();
	
	
	public static void precompute() throws Exception{
		
	}
	
	public static char c [] = new char [101];
	public static char c_temp [] = new char [101];
	
	public static boolean b = false;
	
	public static String solve() throws Exception{
		
		//====================== code ========================================================
		String line = reader.readLine();
		
		int len = line.length();
		
		for(int i = 0; i < len; i ++){
			c[i] = (line.charAt(i) == '+') ? '1' : '0';
		}
		
		c[len] = '-';
		
		b = false;
		
		//=====================================================================================
		return "" + com(len);
	}
	
	public static int com(int len){
		
		cout ("len = " + len);
		
		System.out.print("now is  ");
		for(int i = 0; i < len; i++)
			System.out.print(c[i] + " ");
		
		cout("");
		
		if (len == 1){
//			return (c[0] == '1') ? 0 : 1 ;
			
			cout("c[0] is " + c[0] + " with b => " + b);
			
			if (b)
				return (c[0] == '1') ? 1 : 0 ;
			else
				return (c[0] == '1') ? 0 : 1 ;
			
		} else {
			
			if (c[len - 1] == '1'){
				b = false;
				return com(len - 1);
			}
			else {
				if (c[len - 2] == '0'){

					
					if (b) {
						cout("+ 0");
						return com(len - 1) ;
					} else {
						cout("+ 1");
						b = true;
						return com(len - 1) + 1;
					}

					
				}
				else { 

					//flip the first len elements in c[]
					
					for(int i = 0; i < len - 1; i++)
						c_temp[i] = c[i];
					
					for(int i = 0; i < len - 1; i++)
						c[i] = (c_temp[len - 1 - i - 1] == '1') ? '0' : '1';
					
					for(int i = 0; i < len - 1; i++)
						System.out.print(c[i] + " ");
					
					cout("");
					
//					if (c[len] == '0')
					
					if(b) {
						
						cout ("+ 1");
						return com(len - 1) + 1;}
					else{
						b = true;
						cout ("+ 2");
						return com(len - 1) + 1 + 1;
					}
				}
			}
			
		}
		
	}
	
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		
		file = new File("Test.in");
		file = new File("B-small-attempt2.in");
//		file = new File(Template.class.getName() + "-large-practice.in");

		File fileOut = new File(B.class.getName() + ".out");

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
