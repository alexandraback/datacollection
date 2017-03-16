import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;
import java.math.*;

/**
 * @author Xing Liu
 * 
 *         Google code jam 2014 template.
 **/
public class B {
	// competition logic !
	private String getResult(long A, long B, long K) {
		long max = A & B;
		int d = 0;
		long zeros = 0;
		long result = 0;
		long tmp =  0;
		

		if(A<B){
			tmp = B;
			B= A;
			A = tmp;
		}
		
		int[] da = getDigits(A);
		int[] db = getDigits(B);
		int[] dk = getDigits(K);

		
		
		for(long i = 0; i< A;i++){
			
			for(long m = 0;m<B;m++){
				
				if((i&m) < K) {
					//System.out.println(i&m);
					result++;
				}
			}
		}
		
		

		

		return String.valueOf(result);
	}

	private long getZeros(int[] dd) {
		long result = 0;
		for (int e : dd) {
			if (e == 0)
				result++;
		}
		return result;
	}

	private static int[] getDigits(long in) {
		int d = 0;
		ArrayList<Integer> result = new ArrayList<Integer>();

		while (in != 0) {
			d = (int) (in % 2);
			result.add(d);
			in = in / 2;
		}

		int[] ret = new int[result.size()];
		for (int i = 0; i < result.size(); i++) {
			ret[i] = result.get(i);
		}
		return ret;
	}

	public static void main(String[] args) throws Exception {

		B me = new B();
		FileReader fr = new FileReader("B-small-attempt1.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);
		String result = null;

		int T = Integer.valueOf(br.readLine());

		for (int t = 1; t <= T; t++) {

			long[] par = me.getLongTokens(br.readLine());

			System.out.println("Case : " + t);
			bw.write("Case #" + t + ": " + me.getResult(par[0], par[1], par[2]));
			bw.write('\n');
		}

		br.close();
		fr.close();
		bw.close();
		fw.close();
	}

	// ================================================
	// helper functions.
	private long[] getLongTokens(String line) {
		String[] tokens = line.split(" +");

		long[] result = new long[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			result[i] = Long.valueOf(tokens[i]);
		}
		return result;
	}

	private String[] getTokens(String line) {
		return line.split(" +");
	}

}
