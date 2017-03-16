package gcj2012.round1b;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;

import org.korifey.ffalg.NumberTheory;
import org.korifey.ffalg.Probabilities;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class C extends AbstractRunner {
	
	@Override
	public void handleCase(int caseNumber) throws Exception {
		int n = scanner.nextInt();
		long [] x = new long[n];
		long sum = 0; 
		for (int i=0; i<n; i++) {
			x[i] = scanner.nextLong();
			sum += x[i];
		}
		
		out.write("\n");
		int[] pp = new int[n];
		long max = NumberTheory.powMod(3, n, 1000000000);
		long s1 = 0, s2 = 0;
		for (long i=1; i<max;i++) {
			for (int j=n-1; j>=0; j--) {
				if (pp[j] == 2) {
					pp[j] = 0;
					s2 -= x[j];
				} else {
					if (pp[j] == 1) {				
					  s1 -= x[j];
					  s2 += x[j];
					} else {
						s1+= x[j];
					}					
					
					pp[j]++;										
					break;
				}				
			}
			
			if (s1 == s2) {
				String str1 = "";
				String str2 = "";
				for (int j=0; j<n; j++) {
					if (pp[j] == 1) str1+=" "+x[j];
					if (pp[j] == 2) str2+=" "+x[j];
				}
				out.write(str1.substring(1)+"\n");
				out.write(str2.substring(1)+"\n");
				return;
			}
		}
		
		
		
		out.write("Impossible\n");
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		new C().init(SIZE.small).execute();
	}

}
