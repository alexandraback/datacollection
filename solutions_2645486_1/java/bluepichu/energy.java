//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class energy{
	public static long regen;
	public static long max;
	public static boolean[] fSol;
	public static long[] eSol;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));
		
		long testCases = Long.parseLong(br.readLine());
		
		for(long t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			max = Long.parseLong(st.nextToken());
			regen = Long.parseLong(st.nextToken());
			long numActivities = Long.parseLong(st.nextToken());
			
			eSol = new long[(int)numActivities+1];
			Arrays.fill(eSol, -1);
			eSol[0] = max;
			eSol[(int)numActivities] = 0;
			fSol = new boolean[(int)numActivities+1];
			fSol[0] = true;
			fSol[(int)numActivities] = true;
			
			PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
			
			st = new StringTokenizer(br.readLine());
			long[] vals = new long[(int)numActivities];
			for(long i = 0; st.hasMoreElements(); i++){
				vals[(int)i] = Long.parseLong(st.nextToken());
				pq.add(new Pair(i+1, vals[(int)i]));
			}
			
			while(!pq.isEmpty()){
				long i = pq.poll().key;
				if(!fSol[(int)i-1]){
					eSol[(int)i-1] = max - regen;
					recurBack(eSol, i-1);
				}
				if(!fSol[(int)i]){
					eSol[(int)i] = 0;
					recurForward(eSol, i);
				}
				fSol[(int)i-1] = true;
				fSol[(int)i] = true;
			}
			
			long ans = 0;
			for(long i = 0; i < numActivities; i++){
				ans += (Math.min(max, eSol[(int)i] + regen) - eSol[(int)i+1]) * vals[(int)i];
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	static class Pair implements Comparable<Pair>{
		public long key;
		public long value;
		public Pair(long k, long v){
			key = k;
			value = v;
		}
		public int compareTo(Pair o){
			return o.value == value ? (int)(o.key - key) : (int)(o.value - value);
		}
	}
	
	public static boolean recurBack(long[] arr, long i){
		if(!fSol[(int)i-1]){
			eSol[(int)i-1] = eSol[(int)i]-regen;
			if(eSol[(int)i-1] < 0){
				eSol[(int)i-1] = 0;
				return true;
			}
			if(!recurBack(arr, i-1)){
				eSol[(int)i] = eSol[(int)i-1] + regen;
				return false;
			}
		} else {
			if(eSol[(int)i-1] >= eSol[(int)i] - regen){
				return true;
			} else {
				eSol[(int)i] = eSol[(int)i-1] + regen;
				return false;
			}
		}
		return false; //illegal
	}
	
	public static boolean recurForward(long[] arr, long i){
		if(!fSol[(int)i+1]){
			eSol[(int)i+1] = eSol[(int)i]+regen;
			if(eSol[(int)i+1] >= max){
				eSol[(int)i+1] = max;
				return true;
			}
			if(!recurForward(arr, i+1)){
				eSol[(int)i] = eSol[(int)i+1] - regen;
				return false;
			}
		} else {
			if(eSol[(int)i+1] <= eSol[(int)i] + regen){
				return true;
			} else {
				eSol[(int)i] = eSol[(int)i+1] - regen;
				return false;
			}
		}
		return false; //illegal
	}
}