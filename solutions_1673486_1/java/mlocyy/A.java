package R1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
	static Scanner s;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		s = new Scanner(new File("a.txt"));
		int T = s.nextInt();
		for(int t=1;t<=T;t++) {
			int a = s.nextInt();
			int b = s.nextInt();
			List<Double> P = new ArrayList<Double>();
			for (int i=0;i<a;i++) {
				P.add(s.nextDouble());
			}
			double res = b+2;
			
			double R1 = P.get(0);
			for (int i=1; i<a; i++) R1*=P.get(i);
			double r1b=(1f-R1)*(b-a+1+b+1);
			double r1 = R1*(b-a+1) + r1b;
			if (r1<res) res = r1;
			
			R1 /= P.get(P.size()-1);
			double r2b = (1f-R1)*((b-a)+3+b+1);
			double r2 = R1*(b-a+3) + r2b;
			if (r2<res) res = r2;
			
			if (a>1) {
				R1 /= P.get(P.size()-2);
				double r3b = (1f-R1)*((b-a)+5+b+1);
				double r3 = R1*(b-a+5) + r3b;
				if (r3<res) res = r3;
			}
			System.out.println("Case #"+t+": "+res);
		}
		s.close();
	}
}
