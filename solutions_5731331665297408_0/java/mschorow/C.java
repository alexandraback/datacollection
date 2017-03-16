import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();

		for (int testCase = 1; testCase <= t; testCase++) {
			String result = "";
			int n = s.nextInt();
			int m = s.nextInt();
			int[] cities = new int[n];
			int minZIP = 1000000;
			int startCity = 0;
			for (int i = 0; i < n; i++) {
				cities[i] = s.nextInt();
				if (cities[i] < minZIP) {
					minZIP = cities[i];
					startCity = i;
				}
			}
			HashMap<Integer, ArrayList<Integer>> adjacencies = new HashMap<Integer, ArrayList<Integer>>();
			for (int i = 0; i < n; i++) {
				adjacencies.put(i, new ArrayList<Integer>());
			}
			for (int i = 0; i < m; i++) {
				int a = s.nextInt()-1;
				int b = s.nextInt()-1;
				adjacencies.get(a).add(b);
				adjacencies.get(b).add(a);
			}
			result = bestPath(adjacencies, startCity, cities);

			System.out.println("Case #" + testCase + ": " + result);
		}

	}

	private static String bestPath(
			HashMap<Integer, ArrayList<Integer>> adjacencies, int startCity,
			int[] cityZIPs) {
		ArrayList<Path> paths = new ArrayList<Path>();
		ArrayList<Path> finishedPaths = new ArrayList<Path>();
		paths.add(new Path("" + cityZIPs[startCity], startCity));
		while (paths.size() > 0) {
			Path p = paths.remove(0);
			boolean done = true;
			for (int i = 0; i < cityZIPs.length; i++) {
				if (!p.visitedCities.contains(i)) {
					done = false;
					break;
				}
			}
			if (done) {
				finishedPaths.add(p);
				continue;
			}
			int currentCity = p.currentCity;
			ArrayList<Integer> destinations = new ArrayList<Integer>();
			for (Integer i:adjacencies.get(currentCity)) {
				if (!p.visitedCities.contains(i)) {
					destinations.add(i);
				}
			}
			if (currentCity != startCity) {
				Path returnPath = p.clone();
				returnPath.currentPath.pop();
				returnPath.currentCity = returnPath.currentPath.peek();
				paths.add(returnPath);
			}
			if(destinations.size()<1){
				continue;
			}
			int bestZIP = 100000;
			int bestDest = -1;
			for (Integer d:destinations) {
				if(cityZIPs[d] < bestZIP){
					bestZIP = cityZIPs[d];
					bestDest = d;
				}
			}
			int newCity = bestDest;
			Path newPath = p.clone();
			newPath.ZIP += cityZIPs[newCity];
			newPath.visitedCities.add(newCity);
			newPath.currentCity = newCity;
			newPath.currentPath.push(newCity);
			paths.add(newPath);

		}
		String bestZIP = finishedPaths.get(0).ZIP;
		for (Path p : finishedPaths) {
			if (p.ZIP.compareTo(bestZIP) < 0) {
				bestZIP = p.ZIP;
			}
		}

		return bestZIP;

	}


	static class Path {
		String ZIP = "";
		HashSet<Integer> visitedCities = new HashSet<Integer>();
		int currentCity;
		Stack<Integer> currentPath = new Stack<Integer>();

		public Path(String s, int start) {
			ZIP = s;
			visitedCities.add(start);
			currentCity = start;
			currentPath.push(start);
		}

		public Path() {

		}

		public Path clone() {
			Path other = new C.Path();
			other.ZIP = ZIP;
			other.visitedCities = (HashSet<Integer>) visitedCities.clone();
			other.currentCity = currentCity;
			other.currentPath = (Stack<Integer>) currentPath.clone();
			return other;

		}
	}

}
