import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class A {
	
	public static double solve(int A , int B , double[] p){
		double all = 1.0;
		for(int i = 0 ; i < A; i ++){
			all = all * p[i];
		}
		
		double r = all * (B + 1 - A) + (1.0 - all) * (2 * B + 2 - A);
		for(int i = A ; i > 0 ; i --){
			double tp = p[i - 1];
			all = all / tp;
			
			double cost = 2 * ( A + 1 - i);
			double tr = all * (B + 1  + cost - A) + (1.0 - all) * (2 * B + 2 + cost - A);
			if(tr < r)
				r = tr;
		}
		
		double tr = B + 2;
		if(tr < r)
			r = tr;
		return r;
	}
	
	public static void main(String args[]) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
		//BufferedReader reader = new BufferedReader(new FileReader(new File("test.txt")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("A.txt")));
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		for(int i = 0 ; i < T ; i ++){
			line = reader.readLine();
			String tokens[] = line.split("\\s+");
			int A = Integer.parseInt(tokens[0]);
			int B = Integer.parseInt(tokens[1]);
			line = reader.readLine();
			tokens = line.split("\\s+");
			double[] p = new double[A];
			for(int j = 0 ; j < A ; j ++){
				p[j] = Double.parseDouble(tokens[j]);
			}
			double result = solve(A, B , p); 
			
			writer.write("Case #" + (i + 1) + ": " + result + "\r\n");
		}
		reader.close();
		writer.close();
	}

}
