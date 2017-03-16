package commons;

public class Result {
	int size;
	int [][]graph;
	boolean possible;
	
	public Result (int size) {
		if (size <= 1)
			throw new IllegalArgumentException("Number of buildings must be greater or equal to 2!!!");
		this.size = size;
		graph = new int[size][size];
		possible = true;
	}
	
	public void setImpossible () {
		possible = false;
	}
	
	public void setResults(int from, int to, int value) {
		graph[from][to] = value;
	}
	
	public int getBuildingPaths (int from, int to) {
		return graph[from][to];
	}
	
	@Override
	public String toString() {
		String res = "";
		if (possible) {
			res = "POSSIBLE";
			for (int from = 0; from < size; from++) {
				res += "\r\n";
				for (int to = 0; to < size; to++) {
					if (from == to)
						res += "0";
					else 
						if (graph[from][to] > 0)
						res += "1";//graph[from][to];
					else
						res += "0";
				}			
			}
		} else {
			res = "IMPOSSIBLE";
		}
		return res;
	}
}
