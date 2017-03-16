import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.commons.collections4.BidiMap;
import org.apache.commons.collections4.bidimap.DualHashBidiMap;


public class User {

		public static class BFF {

			public static Integer doTest(Integer n, String kids) {
				String bffArray[] = kids.split(" ");
				HashMap<Integer, Integer> kidMap = new HashMap<Integer,Integer>();
				HashMap<Integer, HashSet<Integer>> bffSetMap = new HashMap<Integer, HashSet<Integer>>();
				for (int i=1; i<=n; i++){
					Integer bff = Integer.parseInt(bffArray[i-1]);
					kidMap.put(i, bff);
					HashSet <Integer> bffSet =  bffSetMap.get(bff);
					if (null==bffSet){
						bffSet = new HashSet<Integer>();
						bffSetMap.put(bff, bffSet);
					}
					bffSet.add(i);
				}
				
				Integer longestCircle = 0;
				
				for (Integer i=1; i<=n; i++){
					//reduceSuperBffs(kidMap);
					int circleSize = findCircle(i, kidMap, n, bffSetMap);
					if (circleSize>longestCircle) longestCircle = circleSize;
					if (longestCircle == n) break;
				}
				
				return longestCircle;
			}

			private static int findCircle(Integer i,
					HashMap<Integer, Integer> kidMap, Integer kidCount, HashMap<Integer, HashSet<Integer>> bffSetMap) {
				int result =0;
				LinkedList<Integer> seenKids = new LinkedList<Integer>();
				Integer currentKid = i;
				while(!seenKids.contains(currentKid)){
					seenKids.add(currentKid);
					currentKid = kidMap.get(currentKid);
					result++;
				}
				if (currentKid != i && result == kidCount){
					return i-1;
				}
				if (currentKid != i && !seenKids.isEmpty()){
					HashSet<Integer> bffOfFirst = bffSetMap.get(seenKids.getFirst());
					HashSet<Integer> bffOfLast = bffSetMap.get(seenKids.getLast());
					if (null!= bffOfFirst && !seenKids.containsAll(bffOfFirst)){
						result++;
					}
					if (null!= bffOfLast && !seenKids.containsAll(bffOfLast)){
						result++;
					}
				}
				return result;
			}

	}

		private static final String FILENAME = "C-small-attempt0.in";
		private static final String OUTFILENAME = FILENAME.substring(0,FILENAME.lastIndexOf("."))+".out";
		public static String newline = System.getProperty("line.separator");

		private static PrintWriter out;
		private static BufferedReader input;
		
		public static void main(String[] args) throws IOException {
			setupIO();
			
			int T = Integer.parseInt(input.readLine());
			
			for (int t=1; t<=T; t++){
				String line = input.readLine();
				Integer N = Integer.parseInt(line);
				String kids = input.readLine();
				Object result = BFF.doTest(N, kids);
				out.println("Case #" + t + ": " +result);
				System.out.println("Case #" + t + ": " +result);
			}
			out.close();
		}
		
		private static void setupIO() throws IOException{
			out = new PrintWriter(new FileWriter(OUTFILENAME));
			//	PrintStream out = System.out;
				
				FileReader fr = null;
				try {
					fr = new FileReader(FILENAME);
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				input = new BufferedReader(fr);
		}
	}