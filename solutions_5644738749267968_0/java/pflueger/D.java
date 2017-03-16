import java.io.IOException;
import java.util.Arrays;


public class D extends CodeJammer {

	@Override
	public void process() throws IOException {
		int N = reader.readInt();
		double[] Naomi = reader.readDoubleArray();
		double[] Ken = reader.readDoubleArray();
		Arrays.sort(Naomi);
		Arrays.sort(Ken);
		
		int j=-1;
		int bestFair = 0;
		for (int i=0; i<N; i++) {
			j++;
			while (j<N && Ken[j] < Naomi[i]) j++;
			if (j == N) {
				bestFair = N-i;
				break;
			}
		}
		
		int i=-1;
		int bestCheat = N;
		for (j=0; j<N; j++) {
			i++;
			while (i<N && Ken[j] > Naomi[i]) i++;
			if (i==N) {
				bestCheat = j;
				break;
			}
		}
		
		output(bestCheat + " " + bestFair);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		D d = new D();
		d.run(args);
	}

}
