package j2012r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static String inputDirectory="src/j2012r1c/";
	public static String inputFile="C.in";
	public static String outputFile="C.out";
	public static PrintWriter output;
	public static int[] toyT;
	public static long[] toyN;;
	public static int[] boxT;
	public static long[] boxN;
	public static long totalBoxes;
	public static long totalToys;
	public static Set<String> done;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int N = s.nextInt();
			int M = s.nextInt();
			s.nextLine();
			 boxT = new int[N];
			 boxN = new long[N];
			 totalBoxes = 0;
			for(int i =0; i< N ;i++) {
				boxN[i] = s.nextLong();
				boxT[i] = s.nextInt();
				totalBoxes+=boxN[i];
			}
			s.nextLine();
			toyT = new int[M];
			toyN = new long[M];
			totalToys=0;
			for(int i =0; i< M ;i++) {
				toyN[i] = s.nextLong();
				toyT[i] = s.nextInt();
				totalToys+=toyN[i];
			}
			ArrayList<State> states = new ArrayList<State>();
			State first = new State();
			states.add(first);
			long best = 0;
			//int safety = 2000000;
			//out("C" + Case);
			done = new HashSet<String>();
			done.add(first.getKey());
			while(states.size() > 0) {
				State next = states.remove(0);
				//out(next.boxed+": B=" + next.boxI + " T="+ next.toyI);
				best = Math.max(next.boxed, best);
				states.addAll(next.getNext());
			}
			
			output.printf("Case #%d: %d\n", Case, best);
		}
		output.flush();
	}
	
	public static class State {
		public long boxI = 0;
		public long toyI = 0;
		public long boxed = 0;
		
		public String getKey() {
			return boxed+" "+boxI+" "+toyI;
		}
		
		public ArrayList<State> getNext() {
			ArrayList<State> result = new ArrayList<State>();
			if ( boxI >= totalBoxes || toyI >= totalToys) {
				return result;
			}
			//out("bI"+boxI);
			long boxSI = boxI;
			int BI = 0;
			while(boxSI >= boxN[BI]) {
				boxSI -= boxN[BI];
				BI++;
			}
			long toySI = toyI;
			int TI = 0;
			while(toySI >= toyN[TI]) {
				toySI -= toyN[TI];
				TI++;
			}
			
			if (boxT[BI] == toyT[TI]) {
				long amount = Math.min(toyN[TI] - toySI, boxN[BI] - boxSI);
				State newState = new State();
				newState.boxed = boxed + amount;
				newState.boxI = boxI + amount;
				newState.toyI = toyI+amount;
				if(!done.contains(newState.getKey())) {
					result.add(newState);
					done.add(newState.getKey());
				}
				return result;
			}
			State eatBoxes = new State();
			eatBoxes.boxed = boxed;
			eatBoxes.boxI = boxI + boxN[BI] - boxSI;
			eatBoxes.toyI = toyI;
			if(!done.contains(eatBoxes.getKey())) {
				result.add(eatBoxes);
				done.add(eatBoxes.getKey());
			}

			State eatToys = new State();
			eatToys.boxed = boxed;
			eatToys.boxI = boxI;
			eatToys.toyI = toyI + toyN[TI] - toySI;
			if(!done.contains(eatToys.getKey())) {
				result.add(eatToys);
				done.add(eatToys.getKey());
			}
			
			return result;
		}
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
