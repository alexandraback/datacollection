
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.math.*;

public class Problem {
	
	boolean containsVowel(String sub) {
		if(sub.length() > limit) {
			sub = sub.substring(sub.length()-limit, sub.length());
		}
		if(sub.contains("a") || 
				sub.contains("e") ||
				sub.contains("i") ||
				sub.contains("o") ||
				sub.contains("u"))
			return true;
		return false;
	}

	int limit = 1000;
	public void doStuff() throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int caseNum = 1;
		br.readLine();
		
		
		
		
		while(br.ready()) {
			String s = br.readLine();
			long x = Long.valueOf(s.split(" ")[0]);
			long y = Long.valueOf(s.split(" ")[1]);
			
			long goal = x  + y*10000000L;
			
			HashMap<Long, ArrayList<Integer>>hm = new HashMap<Long, ArrayList<Integer>>();
			hm.put(0L, new ArrayList<Integer> ());	
			
			HashMap<Long, ArrayList<Integer>>hmg = new HashMap<Long, ArrayList<Integer>>();
			hmg.put(goal, new ArrayList<Integer> ());
			boolean term = false;
			ArrayList<Integer> ans = new ArrayList<Integer>();
			ArrayList<Integer> ansR = new ArrayList<Integer>();
			
			for(int i=1; i<30; i++) {
				HashMap<Long, ArrayList<Integer>> hmNew = new HashMap<Long, ArrayList<Integer>>();
				for(Long l : hm.keySet()) {
					if(hmg.containsKey(l)) {
						term = true;
						ans = hm.get(l);
						break;
					}
					
					long xxr = l + i;
					long xxl = l - i;
					long xxu = l + 10000000L*i;
					long xxd = l - 10000000L*i;
					
					ArrayList<Integer> xxrl = (ArrayList<Integer>) hm.get(l).clone();
					ArrayList<Integer> xxll = (ArrayList<Integer>) hm.get(l).clone();
					ArrayList<Integer> xxul = (ArrayList<Integer>) hm.get(l).clone();
					ArrayList<Integer> xxdl = (ArrayList<Integer>) hm.get(l).clone();
					xxrl.add(1); xxll.add(2);
					xxul.add(3); xxdl.add(4);
					hmNew.put(xxr, xxrl);
					hmNew.put(xxl, xxll);
					hmNew.put(xxu, xxul);
					hmNew.put(xxd, xxdl);
				}
				hm = hmNew;
				if(term)
					break;
				
				
			}
			
			String sout = "";
			for(Integer iii : ans) {
				if(iii == 1)
					sout += "E";
				else if(iii == 2)
					sout += "W";
				else if(iii == 3)
					sout += "N";
				else if(iii == 4)
					sout += "S";
			}
			//System.out.println( "," + ans);
			System.out.println("Case #" + caseNum + ": " + sout);
			caseNum++;
		}

	}
	public static void main(String [] args) throws Exception{
		Problem A = new Problem();
		A.doStuff();
	}
}
