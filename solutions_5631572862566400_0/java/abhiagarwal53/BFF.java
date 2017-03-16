package codejam;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BFF {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String inputFile = "C-small-attempt0.in";
		BufferedInputStream bs = new BufferedInputStream(new FileInputStream(inputFile));
		BufferedReader r = new BufferedReader(new InputStreamReader(bs, StandardCharsets.UTF_8));
		int t = Integer.parseInt(r.readLine());
		int count=1;
		String outputFile = "C_small.txt";
		PrintWriter p = new PrintWriter(outputFile);
		
		while(t > 0) {
			int n = Integer.parseInt(r.readLine());		
			int bff[] = new int[n+1];
			String str[] = r.readLine().split(" ");
			Map<Integer,List<Integer>> m = new HashMap<>();
			for(int i=1;i<=n;i++) {				
				int num = Integer.parseInt(str[i-1]); 
				bff[i] = num;
				if(m.get(num) == null)
					m.put(num, new ArrayList<Integer>());
				List<Integer> l = m.get(num);
				l.add(i);
				m.put(num,l);
			}
			long ans = Long.MIN_VALUE;
			for(int i=1;i<=n;i++) {
				boolean included[] = new boolean[n+1];
				List<Integer> list = getCount(included, m, bff, i);
				int size = list.size();
				int bffOfLastElement = bff[list.get(size-1)];
				
				if(!(bffOfLastElement == list.get(size-2) || bffOfLastElement == list.get(0))) {
					list.remove(size-1);
				}				
				ans = Math.max(ans, list.size());
			}
			
			
			System.out.println("Case #"+count+": " + ans);
			t--;
			count++;
		}
		p.close();
		r.close();
	}
	
	public static List<Integer> getCount(boolean[] included, Map<Integer, List<Integer>> m, int[] bff, int start) {
	
		List<Integer> currentCircle = new ArrayList<>();
		List<Integer> bestList = new ArrayList<>();
		currentCircle.add(start);		
		included[start] = true;	
		long ans = Long.MAX_VALUE;
		while(true) {
			int len = currentCircle.size();
			int currentChild = currentCircle.get(len-1);
			int bestFriend = bff[currentChild];
			if(!included[bestFriend]) {
				included[bestFriend] = true;
				currentCircle.add(bestFriend);
			} else {
				if(len == 1) {
					break;
				}
				if(bestFriend == currentCircle.get(len-2)) {
					List<Integer> myFriends = m.get(currentChild);
					if(myFriends == null || myFriends.size() == 0)
						break;
					List<Integer> currentBestList = new ArrayList<>();
					for(Integer fr : myFriends) {						
						if(!included[fr]) {
							boolean newincluded[] = Arrays.copyOf(included,included.length);
							List<Integer> list = getCount(newincluded, m, bff, fr);
							int size = list.size();
							if(size > 1) {
								int bffOfLastElement = bff[list.get(size-1)];
								
								if(!(bffOfLastElement == list.get(size-2) || bffOfLastElement == currentCircle.get(0))) {
									list.remove(size-1);
								}
							}
							if(list.size() > currentBestList.size())
								currentBestList = list;
						}
					}
					if(currentBestList.size() == 0) {						
						break;
					} else {
						for(Integer nu : currentBestList) {
							currentCircle.add(nu);
							included[nu] = true;
						}
					}
				} else {
					break;
				}
			}
		}
		return currentCircle;
	}

}
