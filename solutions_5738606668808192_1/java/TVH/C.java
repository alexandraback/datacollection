import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("C.out"));
		int T = in.nextInt();
		int N = in.nextInt();
		int J = in.nextInt();
		BigInteger lowerBound = new BigInteger("2");
		lowerBound = lowerBound.pow(N - 1);
		int found = 0;
		out.println("Case #1:");
		while (found < J) {
			lowerBound = lowerBound.add(BigInteger.ONE);
			BigInteger i = lowerBound;
			//System.out.println(i);
			if (i.remainder(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
				continue;
			}
			String s = i.toString(2);
			//System.out.println("Trying "+s);
			ArrayList<BigInteger> reps = new ArrayList<BigInteger>();
			for (int j = 2; j <= 10; j++) {
				reps.add(new BigInteger("0"));
			}
			//System.out.println(s);
			for (int j = 0; j < N; j++) {
				if (s.charAt(j) == '1') {
					
					for (int k = 0; k < 9; k++) {
						BigInteger cur = reps.get(k);
						//System.out.println("+"+new BigInteger("" + (k + 2)).pow(N-j-1));
						reps.set(k, cur.add(new BigInteger("" + (k + 2)).pow(N-j-1)));
					}
				}
			}
			//System.out.println(reps);
			boolean valid = true;
			for (BigInteger j : reps) {
				if (j.isProbablePrime(10000)) {
					valid = false;
					break;
				}
			}
			//System.out.println(valid);
			if (!valid) {
				continue;
			}
		
			ArrayList<BigInteger> diviss = new ArrayList<BigInteger>();
			for (int k = 0; k < 9; k++) {
			
				BigInteger cur = reps.get(k);
				//System.out.println(":"+cur+":");
				BigInteger divis = new BigInteger("2");
				while(true){
					if(divis.compareTo(new BigInteger("100000"))>0){
						valid = false;
						break;
					}
//					if(cur.subtract(BigInteger.valueOf(divis)).equals(BigInteger.ZERO)){
//						valid = false;
//						break;
//					}
					if (cur.remainder(divis).equals(BigInteger.ZERO)) {
						//if (cur.divide(BigInteger.valueOf(divis)).multiply(BigInteger.valueOf(divis)).equals(cur)) {
						//System.out.println(divis);	
						diviss.add(divis);
							break;
						//}
					}
					divis = divis.add(BigInteger.ONE);
				}
			}
			if (!valid) {
				continue;
			}
			if (diviss.size() < 9) {
				continue;
			}
			//System.out.println(s + " " + diviss.size() + " " + diviss + " " + reps);
			found++;
			out.print(s);
			for (BigInteger k : diviss) {
				out.print(" " + k);
			}
			System.out.println(found);
			out.println();
		}
		out.close();
	}

}
