package com.nbarraille.gcj;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.Map;
import java.util.Set;


public class GCJ {
	protected static final String TEST_CASE = "B-large"; // CHANGE THIS WHEN CHANGING PROBLEM
	protected static final boolean RUN_ALL_CASES = true;
	protected static final boolean DEBUG = true;
	
	// DO WHATEVER TO SOLVE THE CASE
	// AND APPEND THE OUTPUT TO SB
	protected static void solveCase() throws IOException {
		long nbLevels = Long.valueOf(readLine());
		Long[][] stars = new Long[(int)nbLevels][];
		
		for (int i = 0; i < nbLevels; i++) {
			stars[i] = readLongArray();
		}
		
		Arrays.sort(stars, new Comparator<Long[]>() {
            @Override
            public int compare(final Long[] entry1, final Long[] entry2) {
                final long time1 = entry1[1];
                final long time2 = entry2[1];
                if (time1 > time2) {
                	return -1;
                } else if (time1 < time2) {
                	return 1;
                } else {
                	return 0;
                }
            }
        });
		
		for (int i = 0; i < stars.length; i++) {
			System.out.println("[" + stars[i][0] + ", " + stars[i][1]);
		}
		
		int nbStars = 0;
		
		long nbMoves = 0;
		while (nbStars < nbLevels * 2) {
			System.out.println("I have " + nbStars + " stars");
			boolean hasChanged = false;
			for (int i = 0; i < nbLevels; i++) {
				if (stars[i][1] != null && stars[i][1] <= nbStars) {
					if (stars[i][0] != null) {
						System.out.println("Eating [" + i + ", 1] for 2 stars");
						nbStars += 2;
					} else {
						System.out.println("Eating [" + i + ", 1] for 1 stars");
						nbStars += 1;
					}
					stars[i][1] = null;
					stars[i][0] = null;
					hasChanged = true;
					nbMoves++;
					break;
				}
			}
			if (! hasChanged) {
				for (int i = 0; i < nbLevels; i++) {
					if (stars[i][0] != null && stars[i][0] <= nbStars) {
						System.out.println("Eating [" + i + ", 0] for 1 stars");
						stars[i][0] = null;
						nbStars += 1;
						hasChanged = true;
						nbMoves++;
						break;
					}
				}
				if (!hasChanged) {
					sb.append("Too Bad");
					return;
				}
			}
		}
		sb.append(nbMoves);
		
	}
	
	
	
	
	
	
	
	// DONT TOUCH THIS
	public static void main(String[] args) throws Exception {
		run();
	}
	
	protected static final String filePrefix = "/Users/nbarraille/Downloads/" + GCJ.TEST_CASE + ".";
	protected static final String input = filePrefix + "in";
	protected static final String output = filePrefix + "out";
	protected static BufferedReader in;
	protected static FileWriter out;
	protected static int nbTests;
	protected static long startTime;
	protected static StringBuilder sb;
	protected static Set<String> dict;
	
	protected static void run() throws NumberFormatException, IOException {
		start();
		for (int i = 0; i < nbTests; i++) {
			sb = new StringBuilder("Case #" + (i + 1) + ": ");
			if (GCJ.DEBUG) {
				print(sb);
			}
			GCJ.solveCase();
			out.write(sb.toString());
			if (GCJ.DEBUG) {
				print("   OUTPUT: " + sb.substring(sb.indexOf(":") + 2));
			}
			if (i != nbTests - 1) {
				out.write("\n");
			}
		}
		
		finish();
	}
	
	protected static Long[] readLongArray() throws IOException {
		String[] arr = readLine().split(" ");
		Long[] res = new Long[arr.length];
		for (int i = 0; i < arr.length; i++) {
			res[i] = Long.valueOf(arr[i]);
		}
		return res;
	}
	
	protected static double[] readDoubleArray() throws IOException {
		String[] arr = readLine().split(" ");
		double[] res = new double[arr.length];
		for (int i = 0; i < arr.length; i++) {
			res[i] = Double.valueOf(arr[i]);
		}
		return res;
	}
	
	protected static String[] readStringArray() throws IOException {
		return readLine().split(" ");
	}
	
	protected static String readLine() throws IOException {
		String s = in.readLine();
		if (GCJ.DEBUG)
			System.out.println("   " + s);
		
		return s;
	}
	
	protected static void start() throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader(input));
		out = new FileWriter(output);
		startTime = System.currentTimeMillis();
		
		// Manual solving
//		long[] params = readLongArray();
//		long nbWords = params[1];
//		nbTests = (int)params[2];
//		dict = new HashSet<String>();
//		for (int i = 0; i <= nbWords; i++) {
//			dict.add(readLine());
//		}
		
		if (GCJ.RUN_ALL_CASES)
			nbTests = Integer.valueOf(in.readLine());
		else {
			nbTests = 1;
			in.readLine();
		}
	}
	
	protected static void finish() throws IOException {
		in.close();
		out.close();
		
		long endTime = System.currentTimeMillis();
		// TEST
		System.out.println("### Executed in " + (endTime - startTime) + " ms");
	}
	
	protected static void print(String s) {
		System.out.println(s);
	}
	
	protected static void print(StringBuilder sb) {
		print(sb.toString());
	}
	
	protected static <T> String toString(Collection<T> c) {
		StringBuilder sb = new StringBuilder("[");
		for (T e : c) {
			sb.append(e).append(", ");
		}
		sb.append("]");
		return sb.toString();
	}
	
	protected static String toString(Object[] array) {
		StringBuilder sb = new StringBuilder("[");
		for (Object o : array) {
			sb.append(o).append(", ");
		}
		sb.append("]");
		return sb.toString();
	}
	
	protected static <T> void print(Collection<T> c) {
		print(toString(c));
	}
	
	protected static void print(Object[] arr) {
		print(toString(arr));
	}
	
	protected static <K, V> void print(Map<K, V> m) {
		print(toString(m));
		
	}
	
	protected static <K, V> String toString(Map<K, V> m) {
		StringBuilder sb = new StringBuilder("{");
		for (Map.Entry<K, V> e : m.entrySet()) {
			sb.append("   ").append(e.getKey()).append(" ==>").append(e.getValue());
		}
		sb.append("}");
		return sb.toString();
	}
}
