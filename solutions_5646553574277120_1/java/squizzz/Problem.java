import java.util.*;

public class Problem {
	public static void main(String... args) {
		for (DataSet dataSet : new DataSets())
			handleDataSet(dataSet);
	}


	private static void handleDataSet(DataSet dataSet) {
		System.out.println(
			"Case #" + dataSet.number + ": " + dataSet.getResult());
	}

	public static class DataSet {
		public final long number, v;
		public final int c;
		public final long[] d;

		public DataSet(long number, int c, long v, long[] d) {
			this.number = number;
			this.c = c;
			this.v = v;
			this.d = d;
		}

		public String getResult() {
			List<Long> a = new ArrayList<>();
			int indexD = 0;
			long max = 0;
			long numNewD = 0;
			while (max < v) {
				if ((indexD >= d.length) || (max + 1 < d[indexD])) {
					a.add(max + 1);
					++numNewD;
				} else {
					a.add(d[indexD]);
					++indexD;
				}
				max = calculateMax(a);
			}
			return "" + numNewD;
		}

		public long calculateMax(List<Long> a) {
			long max = 0;
			for (long x: a)
				max += x;
			return ((long) c) * max;
		}
	}

	public static class DataSets implements Iterable<DataSet> {
		public Iterator<DataSet> iterator() {
			return new DataSetsIterator();
		}		
	}

	public static class DataSetsIterator implements Iterator<DataSet> {
		private final long numberOfDataSets;
		private final Scanner sc;
		private long indexOfCurrentDataSet; //zero based

		public DataSetsIterator() {
			sc = new Scanner(System.in);
			numberOfDataSets = sc.nextLong();
			sc.nextLine();
			indexOfCurrentDataSet = 0;
		}

		public boolean hasNext() {
			return indexOfCurrentDataSet < numberOfDataSets;
		}

		public DataSet next() {
			int c = sc.nextInt();
			long d[] = new long[sc.nextInt()];
			long v = sc.nextLong();
			for (int i = 0; i < d.length; ++i)
				d[i] = sc.nextLong();
			DataSet dataSet = new DataSet(indexOfCurrentDataSet + 1, c, v, d);
			++indexOfCurrentDataSet;
			return dataSet;
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}
	}
}
