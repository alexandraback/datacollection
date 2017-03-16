import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.ListIterator;
import java.util.TreeMap;



public class OneCA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if(args.length < 1)
			return;
		
		String inputFileName = args[0];
		File inputFile = new File(inputFileName);
		
		
		BufferedReader in = null;
		try {
			in = new BufferedReader(new FileReader(inputFile));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.out.println("File not found: "+inputFileName);
			return;
		}
		
		
		String line = null;
		try {
			line = in.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("First line nonexistent: "+inputFileName);
			return;
		}
		
		int numCases = Integer.parseInt(line);
		
		HashMap<Integer, ArrayList<Integer>> oneLevel = new HashMap<Integer, ArrayList<Integer>>();
		
		for(int i = 1; i <= numCases; i++){
			try {
				line = in.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				System.out.println("Input ran out at line "+ i +" of "+ numCases);
				return;
			}
			
			int numClasses = Integer.parseInt(line);
			
			for(int cl = 1; cl <= numClasses; cl++){
				try {
					line = in.readLine();
				} catch (IOException e) {
					e.printStackTrace();
					System.out.println("Input ran out at line "+ i +" of "+ numCases);
					return;
				}
				
				String[] classInfo = line.split(" ");
				int numInherits = Integer.parseInt(classInfo[0]);
				
				//build inheritance list
				ArrayList<Integer> inheritances = new ArrayList<Integer>();
				for(int inher = 1; inher <= numInherits; inher++){
					inheritances.add(Integer.parseInt(classInfo[inher]));
				}
				
				oneLevel.put(cl, inheritances);
				//WHAT TO DO FOR EACH CLASS
			}
			
			boolean found = false;
			for(int cl = 1; cl <= numClasses; cl++){
				HashSet<Integer> fullInher = new HashSet<Integer>();
				
				ArrayList<Integer> levelList = null;
				if(oneLevel.get(cl) != null)
					levelList = (ArrayList<Integer>) oneLevel.get(cl).clone();
				
				found = recurBuildSet(fullInher, oneLevel, levelList);
				
				if(found)
					break;
			}
			System.out.println("Case #"+i+": "+(found == true ? "Yes" : "No"));
			//WHAT TO DO FOR EACH OCCURANCE
		}
	}
	
	HashMap<Integer, HashSet<Integer>> solved = new HashMap<Integer, HashSet<Integer>>();
	private static boolean recurBuildSet(HashSet<Integer> set, HashMap<Integer, ArrayList<Integer>> oneLevel, ArrayList<Integer> curList){
		if(curList == null || curList.isEmpty())
			return false;
		
		Integer zero = curList.get(0);
		
		if(set.contains(zero)){
//			System.out.println(set.toString());
			return true;
		}
		
		set.add(zero);
		curList.remove(0);
		
		ArrayList<Integer> nextList = (ArrayList<Integer>) oneLevel.get(zero).clone();
		
		return recurBuildSet(set, oneLevel, nextList) || recurBuildSet(set, oneLevel, curList) || false;
	}
}
