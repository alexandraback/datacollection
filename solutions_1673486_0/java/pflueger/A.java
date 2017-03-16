import java.io.*;
import java.util.*;

public class A extends CodeJammer {

	public void process() throws IOException {
		int[] l1 = reader.readArray();
		int a = l1[0];
		int b = l1[1];
		double[] p = reader.readDoubleArray();
		double best = b+2;
		double prod = 1;
		for (int k=a; k>=0; k--) {
			if (k != a) prod *= (p[a-k-1]);
			double q = 1-prod;
			double option = (2*k+b-a+1) + q*(b+1);
			if (option < best) best = option;
		}
		output(best);
	}

	public static void main(String[] args) {
		A a = new A();
		a.run(args);
	}
}	
