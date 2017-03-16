//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class wall{
	
	public static Long[] sortedKeys;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt6.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("wall.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			HashSet[] arr = new HashSet[676061];
			int numTribes = Integer.parseInt(br.readLine());
			int last = 0;
			
			for(int i = 0; i < numTribes; i++){
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				long d = Long.parseLong(st.nextToken());
				long n = Long.parseLong(st.nextToken());
				long w = Long.parseLong(st.nextToken());
				long e = Long.parseLong(st.nextToken());
				long s = Long.parseLong(st.nextToken());
				long dd = Long.parseLong(st.nextToken());
				long dp = Long.parseLong(st.nextToken());
				long ds = Long.parseLong(st.nextToken());
				
				for(int j = 0; j < n; j++){
					int day = (int)(d + dd * j);
					last = Math.max(last, day);
					long east = e + dp * j;
					long west = w + dp * j;
					long strength = s + ds * j;
					if(arr[day] == null){
						arr[day] = new HashSet<AttackData>();
					}
					arr[day].add(new AttackData(east, west, strength));
				}
			}
			
			HashSet<AttackData> successful = new HashSet<AttackData>();
			HashMap<Long, Long> wall = new HashMap<Long, Long>();
			sortedKeys = new Long[0];
			int ans = 0;
			
			for(int i = 0; i <= last+1; i++){
				if(arr[i] == null){
					continue;
				}
				for(AttackData attack : (HashSet<AttackData>)(arr[i])){
					if(success(attack, wall)){
						successful.add(attack);
					}
				}
				
				Iterator it = successful.iterator();
				
				while(it.hasNext()){
					ans++;
					AttackData ad = (AttackData)(it.next());
					it.remove();
					construct(ad, wall);
				}
			}
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	static class AttackData{
		public long east;
		public long west;
		public long strength;
		public AttackData(long e, long w, long s){
			east = e;
			west = w;
			strength = s;
		}
	}
	
	public static boolean success(AttackData ad, HashMap<Long, Long> wall){
		long h = 0;
		int i = 0;
		while(i < sortedKeys.length && sortedKeys[i] <= ad.west){
			h += wall.get(sortedKeys[i]);
			i++;
		}
		if(h < ad.strength){
			return true;
		}
		while(i < sortedKeys.length && sortedKeys[i] < ad.east){
			h += wall.get(sortedKeys[i]);
			
			if(h < ad.strength){
				return true;
			}
			
			i++;
		}
		return false;
	}
	
	public static void construct(AttackData ad, HashMap<Long, Long> wall){
		long h = 0;
		int i = 0;
		while(i < sortedKeys.length && sortedKeys[i] <= ad.west){
			h += wall.get(sortedKeys[i]);
			i++;
		}
		long added = 0;
		if(h < ad.strength){
			if(!wall.keySet().contains(ad.west)){
				wall.put(ad.west, (long)(0));
			}
			wall.put(ad.west, wall.get(ad.west) + ad.strength - h);
			added = ad.strength - h;
			h = ad.strength;
		}
		while(i < sortedKeys.length && sortedKeys[i] <= ad.east){
			if(wall.get(sortedKeys[i]) > 0){
				added -= wall.get(sortedKeys[i]);
				if(added >= 0){
					wall.put(sortedKeys[i], (long)(0));
				} else {
					wall.put(sortedKeys[i], -added);
					added = 0;
				}
			}
			h += wall.get(sortedKeys[i]);
			if(h < ad.strength){
				wall.put((long)sortedKeys[i], wall.get(sortedKeys[i]) + ad.strength - h);
				added += ad.strength - h;
			}
			
			i++;
		}
		if(!wall.keySet().contains(ad.east)){
			wall.put(ad.east, (long)(0));
		}
		wall.put(ad.east, wall.get(ad.east)-added);
		
		sortedKeys = wall.keySet().toArray(new Long[0]);
		Arrays.sort(sortedKeys);
	}
}