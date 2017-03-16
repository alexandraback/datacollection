import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;


public class BFFs {
	public static void main(String[] args){
		File a = new File("C-small-attempt3.in");
		Scanner input = null;
		try {
			input = new Scanner(a);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//Scanner input = new Scanner(System.in);
		
		File b = new File("C-output.txt");
		FileWriter fw = null;
		try {
			fw = new FileWriter(b);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int number = input.nextInt();
		input.nextLine();
		int cases = number;
		
		while(number > 0){
			int n = input.nextInt();
			String result = "";
			int maxLength = 0;
			ArrayList<Integer> edges = new ArrayList<Integer>();
			edges.add(0);
			HashMap<Integer,HashSet<Integer>> reverse = new HashMap<Integer,HashSet<Integer>>();
			
			for (int i = 1; i <= n; i++){
				int d = input.nextInt();
				edges.add(d);
				if(reverse.containsKey(d)){
					reverse.get(d).add(i);
				} else{
					reverse.put(d,new HashSet<Integer>());
					reverse.get(d).add(i);
				}
			}

			for (int i = 1; i <= n; i++){
				HashSet<Integer> traveled = new HashSet<Integer>();
				
				int length = 0;
				int currentIndex = i;
				int startIndex = i;
				int lastIndex = i;
				boolean cycle = false;
				boolean last = false;
				boolean invalid = false;
				traveled.add(i);
				System.out.println("Start: " + currentIndex);
				while(!cycle && !invalid && !last){
					System.out.println(currentIndex);
					if (edges.get(currentIndex) == startIndex){
						cycle = true;
					}  else if  (edges.get(currentIndex) == lastIndex){
						last = true;
					} else if (traveled.contains(edges.get(currentIndex))){
						invalid =  true;
					}
					traveled.add(currentIndex);
					lastIndex =  currentIndex;
					currentIndex = edges.get(currentIndex);
					length++;
				}
				if (!invalid){
					if (!cycle){
						int length2 = findLongest(reverse, startIndex, lastIndex, traveled);
						length = length + length2;
					}
					System.out.println("Length: " + length);
					if (length > maxLength){
						maxLength = length;
					}
				}
			}
			
			result = "" + maxLength;
			
			try {
				fw.write("Case #" + (cases - number + 1) + ": " + result + "\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			number--;
		}
		
		try {
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int findLongest(HashMap<Integer,HashSet<Integer>> reverse, int location, int EndLocation, HashSet<Integer> traveled){
		if(reverse.get(location) == null){
			return 0;
		}
		HashSet<Integer> prev = new HashSet<Integer>(reverse.get(location));
		HashSet<Integer> intersect = new HashSet<Integer>(traveled);
		intersect.retainAll(prev);
		prev.removeAll(intersect);
		if(prev.size() == 0){
			return 0;
		}
		
		Iterator<Integer> iter = prev.iterator();
		int MaxLength = 0;
		while(iter.hasNext()){
			int next = iter.next();
			HashSet<Integer> newTravel = new HashSet<Integer>(traveled);
			newTravel.add(next);
			int length = findLongest(reverse, next, EndLocation, newTravel);
			if(length > MaxLength){
				MaxLength = length;
			}
		}
		if(reverse.get(EndLocation) == null){
			if (MaxLength > 0){
				return MaxLength + 1;
			} else{
				return 0;
			}
		}
		HashSet<Integer> after = new HashSet<Integer>(reverse.get(EndLocation));
		HashSet<Integer> intersect2 = new HashSet<Integer>(traveled);
		intersect2.retainAll(after);
		after.removeAll(intersect2);
		if(after.size() == 0){
			if (MaxLength > 0){
				return MaxLength + 1;
			} else{
				return 0;
			}
		}
		Iterator<Integer> iter2 = prev.iterator();
		while(iter2.hasNext()){
			int next = iter2.next();
			HashSet<Integer> newTravel = new HashSet<Integer>(traveled);
			newTravel.add(next);
			int length = findLongest(reverse, location, next, newTravel);
			if(length > MaxLength){
				MaxLength = length;
			}
		}
		return MaxLength + 1;
	}
}
