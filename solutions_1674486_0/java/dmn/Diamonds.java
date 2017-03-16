package algos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

public class Diamonds {

	public static void main(String[] args) throws IOException {

		BufferedReader reader = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));

		Integer testCases = Integer.valueOf(reader.readLine());
		for (int i=1; i<= testCases ; i++) {

			Integer classes = Integer.valueOf(reader.readLine());
			Map<Integer, List> inh = new HashMap<Integer, List>();
			for (int j=1; j <= classes; j++) {
				List<String> values = Arrays.asList(reader.readLine().split(" "));
				values = values.subList(1, values.size());
				List<Integer> newList = new ArrayList<Integer>();
				for (String str : values)
					newList.add(Integer.valueOf(str));
				inh.put(j, newList);
			}
			
			List<Integer> result = new ArrayList<Integer>();
			boolean inheritance = false;
			
			for(Map.Entry<Integer, List> entry : inh.entrySet()) {
				List<Integer> values = entry.getValue();
				for (Integer val : values) {
					result.add(checkInh(inh, val));
				}
			
				HashSet<Integer> dups = new HashSet<Integer>(result);
				if (dups.size() != result.size() && result.size() > 1) {
					inheritance = true;
					break;
				}
				result = new ArrayList<Integer>();
				dups = new HashSet<Integer>();
			}
			
			if(inheritance)
				System.out.println("Case #"+i+": Yes");
			else
				System.out.println("Case #"+i+": No");
			
			inh = new HashMap<Integer, List>();
			inheritance = false;
		}
	}
	
	public static int checkInh(Map<Integer, List> map, Integer key) {
		
		if (map.get(key).isEmpty())
			return key;
		
		List<Integer> values = map.get(key);
		for (Integer val : values) {

				return checkInh(map, val);
		}
		
		return 0;
	}
}
