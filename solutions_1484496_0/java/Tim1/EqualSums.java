package gcj2012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class EqualSums {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer t = Integer.parseInt(br.readLine());
		int init = t;
		main: while (t-- > 0) {
			String[] parts = br.readLine().split("\\s+");
			int n = Integer.parseInt(parts[0]);
			int[] arr = new int[n];
			for(int i = 0; i < n; i++){
				arr[i] = Integer.parseInt(parts[i+1]);
			}
			Arrays.sort(arr);
			Map<Integer, List<List<Integer>>> sums = new HashMap<Integer, List<List<Integer>>>();
			for(int i = 1; i <= 1048576; i++){
				int s1 = 0;
				List<Integer> l = new ArrayList<Integer>();
				for(int j = 0; j < 20; j++){
					if(((i >>> j)&1) == 1){
						s1 += arr[j];
						l.add(j);
					}
				}
				List<List<Integer>> ll = sums.get(s1);
				if(ll == null){
					ll = new ArrayList<List<Integer>>();
				} else {
					for(List<Integer> list : ll){
						boolean diff = true;
						for(int mem : list){
							if(l.contains(mem)){
								diff = false;
								break;
							}
						}
						if(diff){
							System.out.println("Case #"+(init-t)+":");
							boolean isFirst = true;
							for(int mem : list){
								System.out.print((isFirst?"":" ") + arr[mem]);
								isFirst = false;
							}
							System.out.println();
							isFirst = true;
							for(int mem : l){
								System.out.print((isFirst?"":" ") + arr[mem]);
								isFirst = false;
							}
							System.out.println();								
							continue main;
						}
					}
				}
				ll.add(l);
				sums.put(s1, ll);
			}
			System.out.println("Case #"+(init-t) + ": Impossible");
		}
	}
}
