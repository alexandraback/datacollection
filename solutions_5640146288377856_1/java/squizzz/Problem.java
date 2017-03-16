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
		public final long number;
		public final long rows;
		public final long columns;
		public final long ship;

		public DataSet(long number, long rows, long columns, long ship) {
			this.number = number;
			this.rows = rows;
			this.columns = columns;
			this.ship = ship;
		}

		public String getResult() {
			long a = (rows - 1) * (columns / ship);
			long b = ((columns - 1) / ship) + ship;
			return Long.toString(a + b);
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
			++indexOfCurrentDataSet;
			DataSet dataSet = new DataSet(indexOfCurrentDataSet, sc.nextLong(), sc.nextLong(), sc.nextLong());
			return dataSet;
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}
	}
}
