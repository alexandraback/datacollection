import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;

public class Lottery {

	public static void main(String[] args) throws Exception {
		Lottery object = new Lottery();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

					
		
		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int a = (int) st.nval;

			st.nextToken();
			int b = (int) st.nval;
			st.nextToken();

			int k = (int) st.nval;

			long output = object.solve(a, b, k);
		
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}
		
		
		wr.close();
	}

	long counter;
	long a, b, k;
	
	private long solve(long a, long b, long k) {
		
		counter = 0;
		this.a = a;
		this.b = b;
		this.k = k;

		generate(29, 0, 0);

		return counter;

	}

	private void generate(long bit, long first, long second) {
		
		if (first >= a || second >= b)
			return ;
		
		long currentAndMin = (first & second);		
		long currentAndMax = (first & second) | ((1L << (bit + 1L)) - 1);
		
		if (currentAndMin >= k) {
			return;
		}
		
		if (currentAndMax < k) {
			counter += (count(first, bit, a) * count(second, bit, b));
			return ;
		}
				
		long set = (1L << bit);
		generate(bit-1, first, second);		
		generate(bit-1, first | set, second);
		generate(bit-1, first, second | set);
		generate(bit-1, first | set, second | set);				
	}

	private long count(long bits, long bit, long number) {
		
		if (number < bits)
			return 0;
		
		long countOthers = (1L << (bit + 1)) - 1L;
		
		if (number > bits + countOthers) {
			return (1L << (bit + 1L));		
		}
		
		return (number - bits);	
			
	}

}
