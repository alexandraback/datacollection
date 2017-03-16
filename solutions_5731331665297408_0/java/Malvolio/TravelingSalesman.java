package round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TravelingSalesman {
	private static final int MAX_ZIP_CODE = 1000000;
	private static BufferedWriter writer;
	private static BufferedReader reader;
	private static int[][] flights;
	private static List<Integer> zipCodes;
	private static int M;
	private static int N;
	
	public static void main(String[] args) throws IOException {
		File file = new File("round1B/C-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1B/output-salesman.txt");
		writer = new BufferedWriter(new FileWriter(outputFile));
		
		int numberOfGames = Integer.parseInt(reader.readLine());
		for (int game = 1; game <= numberOfGames; game++) {
			String[] split = reader.readLine().split(" ");
			N = Integer.parseInt(split[0]);
			M = Integer.parseInt(split[1]);
			zipCodes = new ArrayList<>();
			zipCodes.add(MAX_ZIP_CODE);
			for (int n = 0;n < N; n++) {
				zipCodes.add(Integer.parseInt(reader.readLine()));
			}
			flights = new int[M][2];
			for (int m = 0; m < M; m++) {
				String[] flightData = reader.readLine().split(" ");
				flights[m][0] = Integer.parseInt(flightData[0]);
				flights[m][1] = Integer.parseInt(flightData[1]);
			}
			int startCity = determineStart();
			String outputString = "" + zipCodes.get(startCity);
			List<Integer> singleVisitedCities = new ArrayList<>();
			boolean[] visited = new boolean[N+1];
			visited[startCity] =true;
			singleVisitedCities.add(startCity);
			List<String> possible = fly(outputString, singleVisitedCities, visited);
			
			String answer = possible.get(0);
			for (int p =0 ; p < possible.size(); p++) {
				if(answer.compareTo(possible.get(p)) > 0) {
					answer = possible.get(p);
				}
			}
			
			generateOutput("Case #" + game + ": " + answer);
		}
		reader.close();
		writer.close();
	}
	
	
	private static List<String> fly(String outputString, List<Integer> visitedCities, boolean[] visited) {
		List<String> possibleFlights = new ArrayList<>();
		if (allVisited(visited)) {
			possibleFlights.add(outputString);
		}
		for (int n = 1; n <= N ; n++) {
			if (!visited[n]) {
				int fromCity = canFly(n, visitedCities);
//				System.out.println(n + " " + fromCity);
				if (fromCity >= 0) {
					List<Integer> singleVisitedCities = new ArrayList<>();
					for (int c = 0; c <= fromCity ; c++) {
						singleVisitedCities.add(visitedCities.get(c));
					}
					singleVisitedCities.add(n);
					visited[n] = true;
					possibleFlights.addAll(fly(outputString + zipCodes.get(n), singleVisitedCities, visited));
					visited[n] = false;
				}
			}
		}
		return possibleFlights;
	}


	private static boolean allVisited(boolean[] visited) {
		for (int n = 1; n <= N ; n++) {
			if (!visited[n]) {
				return false;
			}
		}
		return true;
	}


	private static int canFly(int next, List<Integer> visitedCities) {
		for (int c = visitedCities.size() - 1; c >= 0; c--) {
			if (directFlight(next, visitedCities.get(c))) {
				return c;
			}
		}
		return -1;
	}


	private static boolean directFlight(int next, int from) {
		for (int m = 0; m < M ; m++) {
			if(flights[m][0] == next && flights[m][1] == from) {
				return true;
			}
			if(flights[m][0] == from && flights[m][1] == next) {
				return true;
			}
		}
		return false;
	}


	private static int determineStart() {
		int min = MAX_ZIP_CODE;
		int startCity = 0;
		for (int c = 0; c < zipCodes.size(); c++) {
			if (zipCodes.get(c) < min) {
				startCity = c;
				min = zipCodes.get(c);
			}
		}
		return startCity;
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
}
