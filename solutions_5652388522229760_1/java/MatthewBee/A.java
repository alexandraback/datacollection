import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class A {

	public static BufferedReader reader = null;
	
	public static String [] a = new String [1000001];
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
//		File file = new File("A-small-attempt0.in");
		
		File file = new File("A-large.in");
		
//		File file = new File("test.txt");

		File fileOut = new File("A-large.out");

		BufferedWriter out = null;

		reader = new BufferedReader(new FileReader(file));

		int num = Integer.parseInt(reader.readLine());

		out = new BufferedWriter(new FileWriter(fileOut));

		for(int n = 0; n <= 1000000; n ++){
//			String res = compute(n);
			
			a[n] = compute(n);
			
			if (a[n] == "INSOMNIA")
				System.out.println(n + " : " + a[n]);
		}
		
		for (int i = 0; i < num; i++) {

			int n = Integer.parseInt(reader.readLine());
			
			out.write("Case #" + (i + 1) + ": " + a[n] + "\n");
			System.out.println("Case #" + (i + 1) + ": " + a[n] + "\n");
		}
		
		out.close();

		reader.close();
	}
	
	
public static String compute(int _n) throws Exception{
		
//		long n = Long.parseLong(reader.readLine());

		long n = (long)_n;
		
		if(n == 0)
			return "INSOMNIA"; 
		
		int len = Long.toString(n).length();
		
		boolean b [] = new boolean [10];
		for (int i = 0; i < 10; i++)
			b[i] = false;
		
		for (long i = 1; i <= Math.pow(10, 6); i++){
			
			long v = n * i;
			
//			System.out.println(v+ "");

			while (v != 0){
				int r = (int) (v % 10);
				
				v = v - r;
				
				v /= 10;
				
				b[r] = true;
				
			}
			
			boolean ok = true;
			
			for (int x = 0; x < 10; x++)
				if (!b[x])
					ok = false;
			
			if(ok)
				return n * i + "";
			
		}
		
		return "INSOMNIA";
	}
}



















