import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class C {
	public static void main(String[] args) {
		C obj = new C();
		String filame = "input.txt";
		if (args.length > 0) {
			filame = args[0];
		}
		obj.redFile(filame);

	}

	public void redFile(String filename) {
		File file = new File(filename);
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			Integer testCasesCount = Integer.parseInt(br.readLine());
			readTestCases(br, testCasesCount);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void readTestCases(BufferedReader br, int testCasesCount)
			throws IOException {
		int testCaseNumber = 1;
		for (String line; (line = br.readLine()) != null;) {
			String[] cdv = line.split("\\s+");
			line = br.readLine();
			String[] ds = line.split("\\s+");
			processCase(cdv,ds, testCaseNumber++);
		}
	}

	private void processCase(String[] cdv, String[] ds, int testCasesCount) {
		int value = Integer.parseInt(cdv[2]);
		List<Integer> list = new ArrayList<Integer>();
		for (String string : ds) {
			list.add(Integer.parseInt(string));
		}
		
		//System.out.println(cdv);
		//System.out.println(list);
		int ans = 0;
		
		for(int i=1; i <= value; i++){
			if(!possibleToFind(i, list)){
				//System.out.println("Cant " + i);
				list.add(i);
				Collections.sort(list);
				ans ++;
			}
		}
		System.out.println("Case #"+ testCasesCount +": "+ ans);
	
		
//		int cells = Integer.parseInt(ds);
//		int width = Integer.parseInt(visitorsLine[2]);

		
//		System.out.println("Case #"+ testCasesCount +": "+ fin);
		//System.out.println();
		
		
	}

	private boolean possibleToFind(int i, List<Integer> list) {

		Set<Integer> mySet = new HashSet<Integer>();
		mySet.addAll(list);
	
		
		for (Set<Integer> s : powerSet(mySet)) {
			if(i == summSet(s)){
				//System.out.println(s);
				return true;
			}
		}
		return false;

	}
	
	private int summSet(Set<Integer> s) {
		int summ = 0;
		for (Integer integer : s) {
			summ += integer;
		}
		return summ;
	}

	public static <T> Set<Set<T>> powerSet(Set<T> originalSet) {
	    Set<Set<T>> sets = new HashSet<Set<T>>();
	    if (originalSet.isEmpty()) {
	    	sets.add(new HashSet<T>());
	    	return sets;
	    }
	    List<T> list = new ArrayList<T>(originalSet);
	    T head = list.get(0);
	    Set<T> rest = new HashSet<T>(list.subList(1, list.size())); 
	    for (Set<T> set : powerSet(rest)) {
	    	Set<T> newSet = new HashSet<T>();
	    	newSet.add(head);
	    	newSet.addAll(set);
	    	sets.add(newSet);
	    	sets.add(set);
	    }		
	    return sets;
	}
}
