import java.util.*;

public class BTS {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);


		int numCases = scan.nextInt();
		for (int cse = 1; cse <= numCases; cse++) {
			int numCities = scan.nextInt();
			int numFlights = scan.nextInt();

			int smallestCity = 0;
			int smallestCityIndex = -1;

			final int[] cities = new int[numCities];
			for (int i = 0; i < numCities; i++) {
				cities[i] = scan.nextInt();
				if (smallestCityIndex == -1 || cities[i] < smallestCity) {
					smallestCityIndex = i;
					smallestCity = cities[i];
				}
			}

			List<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < numCities; i++) {
				edges.add(new ArrayList<Integer>());
			}

			for (int i = 0; i < numFlights; i++) {
				int u = scan.nextInt() - 1;
				int v = scan.nextInt() - 1;

				edges.get(u).add(v);
				edges.get(v).add(u);
			}

			for (int i = 0; i < numCities; i++) {
				Collections.sort(edges.get(i), new Comparator<Integer>() {
					@Override
					public int compare(Integer u, Integer v) {
						return cities[u] - cities[u];
					}
				});
			}

			boolean[] visited = new boolean[numCities];
			StringBuilder str = new StringBuilder();
			dfs(smallestCityIndex, cities, edges, visited, str);
			System.out.printf("Case #%d: %s\n", cse, str);
		}
	}

	public static void dfs(int city, int[] cities, List<ArrayList<Integer>> edges, boolean[] visited, StringBuilder str) {
		str.append(String.valueOf(cities[city]));
		visited[city] = true;
		for (int nextCity : edges.get(city)) {
			if (!visited[nextCity]) {
				dfs(nextCity, cities, edges, visited, str);
			}
		}
	}
}
