package code.jam.round1b;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import code.jam.template.Template;

public class SafetyInNumbers extends Template {

	private static final double FACTOR = 1e6;
	
	@Override
	protected String testCase(Scanner in) {
		int N = in.nextInt();
		final int[] J = new int[N];
		for (int i = 0; i < N; ++i) {
			J[i] = in.nextInt();
		}
		double[] result = result(J, N);
		final StringBuilder builder = new StringBuilder();
		for (double d : result) {
			builder.append(factorIt(d));
			builder.append(' ');
		}
		return builder.toString().trim();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		new SafetyInNumbers().run();
	}

	private double[] result(int[] J, int N) {
		final double[] res = new double[N];
		int X = getX(J); 
		int newX = X;
		double P = getP(X << 1, N);
		
		int count = 0;
		for (int k = 0; k < N; ++k) {
			if (J[k] >= P) {
				count++;
				newX -= J[k];
				J[k] = -1;
			}
		}
		  
		P = getP(X + newX, N - count);		
		for (int i = 0; i < N; ++i) {
			if (X == 0 || J[i] < 0) {
				res[i] = 0;
				continue;
			}
			res[i] = (P - J[i]) / X;
			res[i] = 100 * res[i];
		}		
		return res;
	}
	
	private int getX(int[] J) {
		int result = 0;
		for (int j : J) result += j;
		return result;
	}
	
	private double getP(int X, int N) {
		return X / (double) N;
	}
	
	private double factorIt(double y) {
		return Math.round(y * FACTOR) / FACTOR;
	}
}
