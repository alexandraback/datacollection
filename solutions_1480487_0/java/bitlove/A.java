import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;



public class A {
	
	public static boolean check (int N , int[] values , int sum, int index , double prob){
		double bm = values[index] + sum * prob;
		
		double left = 1.0 - prob;
		for(int i = 0 ; i < N ; i ++){
			if(index == i)
				continue;
			
			
			int value = values[i];
			if(value < bm){
				double p = (bm - value) / sum;
				left = left - p;
				if(left < 0)
					return true;
			}
		}
		
		return false;
	}
	public static double solve(int N, int[] values, int sum , int index){
		double left = 0, right = 1.0;
		
		while((right - left) > 0.00000001){
			double mid = (right + left) / 2.0;
			boolean check = check(N , values , sum , index , mid);
			if(check){
				right = mid;
			}else{
				left = mid;
			}
		}
		return right;
	}
	
	public static double[] solve(int N, int[] values){
		int sum = 0;
		for(int i = 0 ; i < N ; i ++){
			sum = sum + values[i];
		}
		double[] result = new double[N];
		for(int i = 0  ; i < N ; i ++)
			result[i] = solve(N , values , sum, i);
		return result;
	}
	
	public static void main(String args[]) throws IOException{
		//BufferedReader reader = new BufferedReader(new FileReader(new File("A-large-practice.in")));
		BufferedReader reader = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
		//BufferedReader reader = new BufferedReader(new FileReader(new File("test.txt")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("A.txt")));
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		for(int i = 0 ; i < T ; i ++){
			line = reader.readLine();
			String tokens[] = line.split("\\s+");
			int N = Integer.parseInt(tokens[0]);
			int[] values = new int[N];
			for(int j = 1 ; j < N + 1 ; j ++){
				values[j - 1] = Integer.parseInt(tokens[j]);
			}
			double[] p = solve(N , values);
			writer.write("Case #" + (i + 1) + ":");
			for(int j = 0 ; j < N ; j ++){
				if(p[j] < 0.00000001)
					writer.write(" " + 0);
				else
					writer.write(" " + p[j] * 100.0);
			}
			writer.write("\r\n");
		}
		reader.close();
		writer.close();
	}

}
