import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;

public class Main {
	public Main() throws IOException {
		String input;
		int t;

		input = br.readLine();
		t = Integer.valueOf(input);

		for (int i = 0; i < t; i++) {
			if (i > 0)
				sb.append("\r\n");

			input = br.readLine();

			sb.append("Case #");
			sb.append(i + 1);
			sb.append(": ");

			work(input, i);
		}

		System.out.print(sb);
	}

	class MyData {
		public int indexN = 0;
		public int indexM = 0;
		public long[] numB;
		public int[] typeB;
		public long[] numT;
		public int[] typeT;
		public long total = 0;

		public MyData(long[] _numB, int[] _typeB, long[] _numT, int[] _typeT, int n, int m) {
			numB = new long[n];
			typeB = new int[n];
			numT = new long[m];
			typeT = new int[m];

			for (int i = 0; i < n; i++) {
				numB[i] = _numB[i];
				typeB[i] = _typeB[i];
			}

			for (int i = 0; i < m; i++) {
				numT[i] = _numT[i];
				typeT[i] = _typeT[i];
			}
		}

		MyData clone(int n, int m) {
			MyData ret = new MyData(numB, typeB, numT, typeT, n, m);
			ret.indexN = this.indexN;
			ret.indexM = this.indexM;
			ret.total = this.total;

			return ret;
		}
	}

	long getMax(MyData data, long max, int n, int m) {
		long ret;
		MyData temp;

		if (data.indexN == n) {
			return Math.max(max, data.total);
		}

		if (data.indexM == m) {
			return Math.max(max, data.total);
		}

		if (data.typeB[data.indexN] == data.typeT[data.indexM]) {
			if (data.numB[data.indexN] < data.numT[data.indexM]) {
				data.total += data.numB[data.indexN];
				data.numT[data.indexM] -= data.numB[data.indexN];
				data.indexN++;
				return getMax(data, max, n, m);
			} else if (data.numB[data.indexN] == data.numT[data.indexM]) {
				data.total += data.numB[data.indexN];
				data.numB[data.indexN] -= data.numB[data.indexN];
				data.numT[data.indexM] -= data.numB[data.indexN];
				data.indexN++;
				data.indexM++;
				return getMax(data, max, n, m);
			} else {
				data.total += data.numT[data.indexM];
				data.numB[data.indexN] -= data.numT[data.indexM];
				data.indexM++;
				return getMax(data, max, n, m);
			}
		}

		temp = data.clone(n, m);
		temp.indexN++;
		ret = getMax(temp, max, n, m);

		if (ret > max)
			max = ret;

		temp = data.clone(n, m);
		temp.indexM++;
		ret = getMax(temp, max, n, m);

		if (ret > max)
			max = ret;

		return max;
	}

	private void work(String input, int t) throws IOException {
		//debug("t:", t, input);
		long ret = 0;
		String[] inputArray = input.split(" ");
		int n = Integer.valueOf(inputArray[0]);
		int m = Integer.valueOf(inputArray[1]);
		long[] numB = new long[n];
		int[] typeB = new int[n];
		long[] numT = new long[m];
		int[] typeT = new int[m];

		String input2 = br.readLine();
		String[] inputArray2 = input2.split(" ");
		for (int i = 0; i < n; i++) {
			numB[i] = Long.valueOf(inputArray2[2 * i]);
			typeB[i] = Integer.valueOf(inputArray2[2 * i + 1]);
		}

		input2 = br.readLine();
		inputArray2 = input2.split(" ");
		for (int i = 0; i < m; i++) {
			numT[i] = Long.valueOf(inputArray2[2 * i]);
			typeT[i] = Integer.valueOf(inputArray2[2 * i + 1]);
		}

		MyData data = new MyData(numB, typeB, numT, typeT, n, m);
		ret = getMax(data, 0, n, m);
		
		sb.append(ret);
	}

	StringBuilder sb = new StringBuilder();
	BufferedReader br = new BufferedReader(
		new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
			new Main();
	}

	public static void debug(Object... arr) {
		System.err.println(Arrays.deepToString(arr));
	}
}
