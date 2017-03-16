import java.util.*;
import java.io.*;
import java.math.*;



public class Solver
{
	
	public int[] convert(String[] s) {
		int[] res = new int[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Integer.parseInt(s[i]);
		}
		return res;
	}
	
	public double[] convertD(String[] s) {
		double[] res = new double[s.length];
		for(int i = 0;i < s.length; i++) {
			res[i] = Double.parseDouble(s[i]);
		}
		return res;
	}
	
	public void printArr(int[][] s) {
		for(int[] row : s) {
			for(int el : row) {System.out.print(el);}
			System.out.println("");
		}
	}
	
	public String solve(BufferedReader reader) {
		try{
			int[] dims = convert(reader.readLine().split(" "));
			double[] probs = convertD(reader.readLine().split(" "));
			int a = dims[0];
			int b = dims[1];
			double opt = b+2;
			double prod = 1;
			for(int i = a; i >= 0; i--) {
				if(prod*(2*i + b - a + 1) + (1-prod)*(2*i + 2*b - a + 2) < opt ) {
					opt = prod*(2*i + b - a + 1) + (1-prod)*(2*i + 2*b - a + 2);
				}
				if(i != 0) {
					prod *= probs[a-i];
				}
			}
			return "" + (opt);
		}
		catch(Exception e) {
			e.printStackTrace();
			return "";
		}
			
	}
	
	public static void main(String[] args)
	{	
		try
		{			
			FileReader flrdr = new FileReader(new File("test.in"));
			BufferedReader br = new BufferedReader(flrdr);
			FileWriter writer = new FileWriter("output.txt");
			int n = Integer.parseInt(br.readLine());
			Solver s = new Solver();
			for(int i = 1; i < n+1; i++)
			{
				//System.out.println("Case #" + i + ": " + s.solve4(br) + "\n");
				writer.write("Case #" + i + ": " + s.solve(br) + "\n");
			}
			writer.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void checkFiles(String f1, String f2) {
		try {
			FileReader flrd1 = new FileReader(new File(f1));
			FileReader flrd2 = new FileReader(new File(f2));
			BufferedReader br1 = new BufferedReader(flrd1);
			BufferedReader br2 = new BufferedReader(flrd2);
			int count = 1;
			while(br1.readLine().equals(br2.readLine())) {
				count++;
			}
			System.out.println(count);
		}
		catch(Exception e) {e.printStackTrace();}
	}
}