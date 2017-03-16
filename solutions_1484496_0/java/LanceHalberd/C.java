package j2012r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static String inputDirectory="src/j2012r1b/";
	public static String inputFile="C.in";
	public static String outputFile="C.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int N = s.nextInt();
			long[] S = new long[N];
			Map<Long, Integer> found = new HashMap<Long, Integer>();
			for(int i = 0; i < N; i++) {
				S[i] = s.nextInt();
			}
			boolean printedSolution = false;
			output.printf("Case #%d:\n", Case);
			Arrays.sort(S);
			for(int i=0;i < N; i++) {
				long myValue = S[i];
				if (found.containsKey(myValue)) {
					output.printf("%d\n", myValue);
					printSet(getSet(myValue, found, S));
					printedSolution = true;
					break;
				}
				Iterator<Long> values = found.keySet().iterator();
				Map<Long, Integer> newEntries = new HashMap<Long, Integer>();
				newEntries.put(myValue, -1);
				while(values.hasNext()) {
					long value = values.next();
					long newValue = value + myValue;
					if (found.containsKey(newValue)) {
						ArrayList<Long> mySet = getSet(value, found, S);
						mySet.add(myValue);
						printSets(mySet, getSet(newValue, found, S));
						//output.printf("%d ", myValue);
						//printSet(value, found, S);
						//printSet(newValue, found, S);
						printedSolution = true;
						break;
					} else {
						newEntries.put(newValue, i);
					}
				}
				if(printedSolution) {
					break;
				}
				found.putAll(newEntries);
			}
			if(!printedSolution) {
				output.printf("Impossible\n");
			}
			
		}
		output.flush();
	}
	
	public static void printSets(ArrayList<Long> first, ArrayList<Long> second) {
		for(int i=0;i<first.size(); i++) {
			long value = first.get(i);
			if(second.contains(value)) {
				second.remove(second.indexOf(value));
				first.remove(i--);
			}
		}
		printSet(first);
		printSet(second);
	}
	public static void printSet(ArrayList<Long> set) {
		for(int i=0;i<set.size(); i++) {
			output.printf("%d", set.get(i));
			if ( i < set.size()-1) {
				output.printf(" ");
			}
		}
		output.printf("\n");
	}
	
	public static ArrayList<Long> getSet(Long sum, Map<Long, Integer> found, long[] S) {
		ArrayList<Long> set = new ArrayList<Long>();
		while(true) {
			int next = found.get(sum);
			if (next == -1) {
				set.add(sum);
				break;
			}
			long value = S[next];
			set.add(value);
			sum -= value;
		}
		return set;
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
