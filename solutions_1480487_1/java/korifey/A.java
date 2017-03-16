package gcj2012.round1b;


import java.util.Arrays;
import java.util.Comparator;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class A extends AbstractRunner {
	
	
	@Override
	public void handleCase(int caseNumber) throws Exception {		
		int n = scanner.nextInt();
		int[] point = new int[n];
		int sum = 0;
		
		for (int i=0; i<n; i++) {
			point[i] = scanner.nextInt();
			sum += point[i];
		}
		
		int rsum = sum;
		int nr = n;
		for (int i=0; i<n; i++) {
			if (n*point[i] >= sum*2) {
				rsum -= point[i];
				nr --;
			}
		}
		
		
		
		for (int i=0; i<n; i++) {
			if (i !=0) out.write(" ");
			if (n*point[i] >= sum*2) out.write("0.0");
			else { 
				double res = (sum + rsum - point[i]*nr)*1.0/ (sum*nr);				
				out.write(100*res+"");
			}
		}
		out.write("\n");
		
	}
	
	public static void main(String[] args) throws Exception {
		new A().init(SIZE.large).execute();
	}
}

