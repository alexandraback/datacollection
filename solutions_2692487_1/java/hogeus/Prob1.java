
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;

public class Problem {
	public void doStuff() throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int caseNum = 1;
		while(br.ready()) {
			int first = Integer.valueOf(br.readLine().split(" ")[0]);
			String[] sl = br.readLine().split(" ");
			ArrayList<Integer> al = new ArrayList<Integer>();
			for(String s : sl) {
				al.add(Integer.valueOf(s));
			}
			Collections.sort(al);

			HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
			hm.put(first, 0);
			while(al.size() > 0) {
				HashMap<Integer, Integer>addList = new HashMap<Integer, Integer>();
				for(Integer key : hm.keySet()) {
					if(key <= al.get(0)) {
						int curVal = key;
						int curOps = hm.get(key);
						if(curVal > 1) {
							while(curVal <= al.get(0)) {
								curVal = curVal + curVal -1;
								curOps++;
							}
							curVal = curVal + al.get(0);

							if(addList.get(curVal) == null) {
								addList.put(curVal, curOps);
							}
							else if(addList.get(curVal) > curOps)
								addList.put(curVal,curOps);
						}
						
						if(addList.get(key) == null)
							addList.put(key, hm.get(key)+1);
						else if(addList.get(key) > (hm.get(key)+1))
							addList.put(key, hm.get(key)+1);
					}
					else if(key > al.get(0)) {
						if(addList.get(key+al.get(0)) == null )
							addList.put(key+al.get(0), hm.get(key));
						else if(addList.get(key+al.get(0)) > hm.get(key))
							addList.put(key+al.get(0), hm.get(key));
					}
				}
				hm = new HashMap<Integer, Integer>();
				hm.clear();
				for(Integer k : addList.keySet()) {
					hm.put(k, addList.get(k));
				}
				al.remove(al.get(0));
			}

			int min = 100000;
			for(Integer val : hm.values()) {
				if(val < min)
					min = val;
			}
			System.out.println("Case #" + caseNum + ": " + min);
			caseNum++;
		}

	}
	public static void main(String [] args) throws Exception{
		Problem A = new Problem();
		A.doStuff();
	}
}
