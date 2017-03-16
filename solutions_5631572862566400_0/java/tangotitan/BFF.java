import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class BFF {

	static int best = 2;
	static Map<Integer,Integer> bffCount;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fstream = new FileInputStream("C-small-attempt1.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		String strLine;

		//Read File Line By Line
		int count = -1;
		int index = 0;
		ArrayList<Integer> bff = null;
		
		while ((strLine = br.readLine()) != null)   {
		  // Print the content on the console
			if(count==-1){
				count++;
				continue;
			}
			String[] entries = strLine.split(" ");
			if(entries.length>2){
				index++;
				bffCount = new HashMap<Integer,Integer>();
				bff = new ArrayList<Integer>();
				for(int i=0;i<entries.length;i++){
					bff.add(Integer.parseInt(entries[i]));
				}
				for(int i=0;i<bff.size();i++){
					int cur = bff.get(i) - 1;
					if(bffCount.containsKey(cur)){
						bffCount.put(cur, bffCount.get(cur)+1);
					}else{
						bffCount.put(cur, 1);
					}
				}
				helper(bff);
				System.out.println("Case #" + index + ": " + best);
				best = 2;
			}
		  }
		//Close the input stream
		br.close();
	}

	
	private static void helper(ArrayList<Integer> bff){
		List<Integer> used = null;
		for(int i=0;i<bff.size();i++){
			used = new ArrayList<Integer>();
			search(bff,i,used);
		}
	}


	private static void search(ArrayList<Integer> bff, int i,
			List<Integer> used) {
		// TODO Auto-generated method stub
		
		if(!used.contains(i)){
			used.add(i);
			search(bff,bff.get(i)-1,used);
			used.remove(used.size()-1);
		}else{
			if(i==used.get(0)){
				best = Math.max(best, used.size());
			}else if(used.size()>1&&i==used.get(used.size()-2)){
				best = Math.max(best, used.size());
				if(bffCount.get(used.get(used.size()-1))>1){
					best = Math.max(best, used.size()+1);
				}
			}
		}
	}
}
