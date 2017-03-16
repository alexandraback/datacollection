import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class safety {
	
	public static double total(double[] n){
		double total = 0;
		for(int i = 1; i < n[0] + 1; i++){
			total+= n[i];
		}
		return total;
	}
	
	public static void change(double[][] n, double[][] q, double m){
		for(int i = 0; i < m; i++){
			for(int j = 1; j < n[i][0] + 1; j++){
				if(n[i][j] > (total(n[i]) * 2 / n[i][0])){
					q[i][j] = 0.000000001;
				}
			}
		}
	}
	
	public static double[][] clone(double[][] n, double m){
		double[][] clone = new double[50][201];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n[i].length; j++){
				clone[i][j] = n[i][j];
			}
		}
		return clone;
	}
	
	public static int count(double[] n){
		int counter = 0;
		for(int i = 1; i < n[0] + 1; i++){
			if(n[i] != 0.000000001){
				counter++;
			}
		}
		return counter;
	}
	
	public static double[][] dif(double[][] n, double m){
		double dif[][] = new double[50][201];
		double clone[][] = clone(n, m);
		change(n, clone, m);
		double votes;
		double votes2;
		for(int i = 0; i < m; i++){
			dif[i][0] = n[i][0];
			for(int j = 1; j < n[i][0] + 1; j++){
				votes = total(n[i]) + total(clone[i]);
				votes2 = total(n[i]);
				if(clone[i][j] != 0.000000001){
					dif[i][j] = (((votes / count(clone[i])) - clone[i][j])/votes2) * 100;
				}
			}
		}
		return dif;
	}
	public static void main(String[] args) throws IOException{
		Scanner reader = new Scanner(new File("safety.in"));
		PrintWriter out = new PrintWriter(new File("safety.out"));
		
		double n = reader.nextInt();
		double cont[][] = new double[50][201];
		for(int i = 0; i < n; i++){
			cont[i][0] = reader.nextInt();
			for(int j = 1; j < cont[i][0]+1; j++){
				cont[i][j] = reader.nextInt();
			}
		}
		double result[][] = dif(cont, n);
		for(int i = 0; i < n; i++){
			out.print("Case #" + (i+1) + ": ");
			for(int j = 1; j < cont[i][0] + 1; j++){
				out.print(result[i][j] + " ");
			}
			out.println();
		}
		out.close();
		System.exit(0);
	}

}
