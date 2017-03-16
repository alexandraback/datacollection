package com.sokamura.gcj2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.text.DecimalFormat;
import java.text.NumberFormat;

public class PasswordProblem {
	private double solve(int n1, int n2, double[] prop) {
		double[] prop2 = new double[n1+1];
		double tmpProp = 1.0;
		for(int i=1; i<=n1; ++i) {
			prop2[i] = tmpProp * (1.0 - prop[i-1]);
			tmpProp = tmpProp * prop[i-1];
		}
		prop2[0] = tmpProp;
		double expected1 = (n2-n1+1)*prop2[0] + (n2-n1+1+n2+1)*(1.0-prop2[0]);
		double expected2 = 1 + (n2+1);
		double expected[] = new double[n1];
		double tmpProp2 = prop2[0]+prop2[n1];
		for(int i=0; i<n1; ++i) {
			expected[i] = tmpProp2 * (2*(i+1)+n2-n1+1) + (1.0-tmpProp2) * (2*(i+1)+(n2-n1+1+n2+1));
			tmpProp2 += prop2[n1-1-i]; 
		}
		double minExpected = Math.min(expected1, expected2);
		for(int i=0; i<n1; ++i) {
			if(minExpected > expected[i]) {
				minExpected = expected[i];
			}
		}
		return minExpected;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		PasswordProblem pp = new PasswordProblem();
		try {
			FileReader fr = new FileReader("A-small-attempt1.in");
			BufferedReader br = new BufferedReader(fr);
			int lineNum = Integer.parseInt(br.readLine());
			for(int i=1; i<=lineNum; ++i) {
				String tmpLine = br.readLine();
				String[] line1 = tmpLine.split(" ");
				int n1 = Integer.parseInt(line1[0]);
				int n2 = Integer.parseInt(line1[1]);
				tmpLine = br.readLine();
				String[] line2 = tmpLine.split(" ");
				double[] prop = new double[n1];
				for(int j=0; j<n1; ++j) {
					prop[j] = Double.parseDouble(line2[j]);
				}
				DecimalFormat format = new DecimalFormat();
				format.applyPattern("0");
				format.setMaximumFractionDigits(6);
				format.setMinimumFractionDigits(6);
				double ans = pp.solve(n1,n2,prop);
				System.out.println("Case #" + i + ": " + format.format(ans));
			}
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}

}
