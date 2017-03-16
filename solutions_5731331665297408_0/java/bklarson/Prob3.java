package Round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;

public class Prob3 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(2);
		int numCities = nums[0];
		int numFlights = nums[1];
		int[] zipCodes = new int[numCities];
		ArrayList<Flight> flights = new ArrayList<Flight>(numFlights);
		for(int i = 0; i < numCities; i++) {
			zipCodes[i] = readInt();
		}
		for(int i = 0; i < numFlights; i++) {
			int[] a = readIntArray(2);
			flights.add(new Flight(a[0], a[1]));
		}
		
		ArrayList<Integer> idealOrder = new ArrayList<Integer>(numCities);
		for(int i = 0; i < numCities; i++) {
			int bestCity = -1;
			int cityZip = Integer.MAX_VALUE;
			for(int j = 0; j < numCities; j++) {
				if(zipCodes[j] < cityZip && !idealOrder.contains(j)) {
					cityZip = zipCodes[j];
					bestCity = j;
				}
			}
			idealOrder.add(bestCity);
		}

		for (int i = 0; i < numCities; i++) {
			ArrayList<Integer> citiesRemaining = new ArrayList<Integer>(
					idealOrder);
			int nextCity = citiesRemaining.remove(i);
			ArrayList<Integer> cityOrder = new ArrayList<Integer>();
			String solution = findSolution(citiesRemaining, flights, nextCity, cityOrder, zipCodes);
			if (solution != null) {
				out.print("" + zipCodes[nextCity] + solution);
				return;
			}
		}
	}

	private static String findSolution(ArrayList<Integer> cities,
			ArrayList<Flight> flights, int currentCity, ArrayList<Integer> cityOrder, int[] zipCodes) {
		if (cities.isEmpty()) {
			return "";
		}
		String bestPossible = null;
		for (int i = 0; i < cities.size(); i++) {
			if(bestPossible != null) {
				break;
			}
			ArrayList<Integer> citiesRemaining = new ArrayList<Integer>(cities);
			int nextCity = citiesRemaining.remove(i);
			for (int j = 0; j < flights.size(); j++) {
				if ((flights.get(j).a == currentCity && flights.get(j).b == nextCity)
						|| (flights.get(j).a == nextCity && flights.get(j).b == currentCity)) {
					ArrayList<Flight> newFlights = new ArrayList<Flight>(
							flights);
					newFlights.remove(j);
					ArrayList<Integer> newCityOrder = new ArrayList<Integer>(cityOrder);
					newCityOrder.add(currentCity);
					String solution = findSolution(citiesRemaining, newFlights,
							nextCity, newCityOrder, zipCodes);
					if (solution != null) {
						solution = "" + zipCodes[nextCity] + solution;
						if(bestPossible == null || solution.compareTo(bestPossible) < 0) {
							bestPossible = solution;
						}
					}
				}
			}
		}
		ArrayList<Integer> newCityOrder = new ArrayList<Integer>(cityOrder);
		while (!newCityOrder.isEmpty()) {
			int nextCity = newCityOrder.remove(newCityOrder.size() - 1);
			String solution = findSolution(cities, flights, nextCity, newCityOrder,
					zipCodes);
			if (solution != null) {
				if(bestPossible == null || solution.compareTo(bestPossible) < 0) {
					bestPossible = solution;
				}
			}
		}
		return bestPossible;
	}

	private static class Flight {
		final public int a;
		final public int b;
		public Flight(int a, int b) {
			this.a = a - 1;
			this.b = b - 1;
		}
		@Override
		public String toString() {
			return "" + a + "-" + b;
		}
	}

	private static double[] readDoubleArray(int maxItems) throws IOException {
		double[] array = new double[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Double.parseDouble(data[i]);
		}
		return array;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Integer.parseInt(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}
}
