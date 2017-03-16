//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class energy{
	public static int regen;
	public static int max;
	public static boolean[] fSol;
	public static int[] eSol;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt4.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			max = Integer.parseInt(st.nextToken());
			regen = Integer.parseInt(st.nextToken());
			int numActivities = Integer.parseInt(st.nextToken());
			
			eSol = new int[numActivities+1];
			Arrays.fill(eSol, -1);
			eSol[0] = max;
			eSol[numActivities] = 0;
			fSol = new boolean[numActivities+1];
			fSol[0] = true;
			fSol[numActivities] = true;
			
			PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
			
			st = new StringTokenizer(br.readLine());
			int[] vals = new int[numActivities];
			for(int i = 0; st.hasMoreElements(); i++){
				vals[i] = Integer.parseInt(st.nextToken());
				pq.add(new Pair(i+1, vals[i]));
			}
			
			while(!pq.isEmpty()){
				int i = pq.poll().key;
				if(!fSol[i-1]){
					eSol[i-1] = max - regen;
					recurBack(eSol, i-1);
				}
				if(!fSol[i]){
					eSol[i] = 0;
					recurForward(eSol, i);
				}
				fSol[i-1] = true;
				fSol[i] = true;
			}
			
			long ans = 0;
			for(int i = 0; i < numActivities; i++){
				ans += (Math.min(max, eSol[i] + regen) - eSol[i+1]) * vals[i];
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	static class Pair implements Comparable<Pair>{
		public int key;
		public int value;
		public Pair(int k, int v){
			key = k;
			value = v;
		}
		public int compareTo(Pair o){
			return o.value == value ? o.key - key : o.value - value;
		}
	}
	
	public static boolean recurBack(int[] arr, int i){
		if(!fSol[i-1]){
			eSol[i-1] = eSol[i]-regen;
			if(eSol[i-1] < 0){
				eSol[i-1] = 0;
				return true;
			}
			if(!recurBack(arr, i-1)){
				eSol[i] = eSol[i-1] + regen;
				return false;
			}
		} else {
			if(eSol[i-1] >= eSol[i] - regen){
				return true;
			} else {
				eSol[i] = eSol[i-1] + regen;
				return false;
			}
		}
		return false; //illegal
	}
	
	public static boolean recurForward(int[] arr, int i){
		if(!fSol[i+1]){
			eSol[i+1] = eSol[i]+regen;
			if(eSol[i+1] >= max){
				eSol[i+1] = max;
				return true;
			}
			if(!recurForward(arr, i+1)){
				eSol[i] = eSol[i+1] - regen;
				return false;
			}
		} else {
			if(eSol[i+1] <= eSol[i] + regen){
				return true;
			} else {
				eSol[i] = eSol[i+1] - regen;
				return false;
			}
		}
		return false; //illegal
	}
}