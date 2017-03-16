package r3p1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

public class r3p1 {
	public static double[][] matMul(int N, double A[][],double B[][]) {
		double C[][] = new double[N][N];
		for (int i = 0; i < N; i++)
			for (int k = 0; k < N; k++)
				for (int j = 0; j < N; j++)
					C[i][j] += A[i][k] * B[k][j];
		return C;
	}
	
	public static double[][] matSum(int N, double B[][], double A[][]) {
		double C[][] = new double[N][N];
		for (int i = 0; i < N; i++)
			for (int k = 0; k < N; k++)
				C[i][k] = A[i][k] + B[i][k];
		return C;
	}
	
	

	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(new DataInputStream(new FileInputStream("./src/r3p1/a-small.in"))));
			BufferedWriter out = new BufferedWriter(new FileWriter("./src/r3p1/a-small.out"));

			int line = Integer.parseInt(in.readLine());

			for (int i = 0; i < line; i++) {
				String inLine[] = in.readLine().split(" ");
				int size = Integer.parseInt(inLine[0]);
				double matrix[][] = new double[size][size];
				double sum[][] = new double[size][size];
				String result = "No";
				
				out.append("Case #" + (i + 1) + ": ");

				for (int l = 0; l < size; l++) {
					String inLine2[] = in.readLine().split(" ");
					for (int k = 1; k < inLine2.length; k++) {
						matrix[l][Integer.parseInt(inLine2[k])-1] = 1;
					}
				}
				
				double temp[][] = new double[size][size];
				for (int l = 0; l < size; l++) {
					for (int k = 0; k < size; k++) {
						temp[l][k] = matrix[l][k];
						sum[l][k] = matrix[l][k];
					}
				}
				
				out: for(int m=0;m<size;m++){
					temp = matMul(size,temp,matrix);
					sum = matSum(size,temp,sum);
					for (int l = 0; l < size; l++) {
						for (int k = 0; k < size; k++) {
							if (sum[l][k]>1){
								result = "Yes";
								break out;
							}
						}
					}
				}
				out.append(result+"\n");
			}
			out.flush();
			in.close();
			out.close();
		} catch (Exception e) {// Catch exception if any
			e.printStackTrace();
		}

	}
}
