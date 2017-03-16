import java.io.File;
import java.lang.StringBuilder;
import java.util.Scanner;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Set;
import java.util.Arrays;

public class DI{
	
	public static HashMap<Long, ArrayList<Long>> hm = new HashMap<Long, ArrayList<Long>>();
	
	public static void main(String[] args) throws Exception{
		File input = new File("A-small-attempt0.in");
		File output = new File("output.out");
		FileWriter fw = new FileWriter(output);
		Scanner s = new Scanner(input);
		
		long numloops = s.nextInt();
		StringBuilder sb = new StringBuilder();
		
		for(long n=0; n<numloops; n++){
			sb.append("Case #" + (n+1) + ": ");
			System.out.println("Case #" + (n+1) + ": ");
			long numinset = s.nextInt();
			
			hm.clear();
			
			for(long boxnum=1; boxnum<=numinset; boxnum++){
				long numinhfrom = s.nextInt();
				ArrayList<Long> al = new ArrayList<Long>();
				
				for(int i=0; i<numinhfrom; i++){
					al.add((long)s.nextInt());
				}
				
				hm.put(boxnum, al);
			}
			
			//ArrayList<Long> visited = new ArrayList<Long>();
			Set<Long> keys = hm.keySet();
			
			boolean yes = false;
			
			//ArrayList<String> paths = new ArrayList<String>();
			
			for(Long l : keys){
				//l is local "root"
				//if find the same node twice from here, then must be diamond
				if(yes)
					break;
				
				ArrayList<Long> visited = new ArrayList<Long>();
				ArrayList<Long> ret = traverse(l);
				
				System.out.println("Collection:\n"+Arrays.toString(ret.toArray()));
				
				if(ret == null){
						System.out.println("Found match null");
						yes = true;
						break;
				}
					
				while(!ret.isEmpty()){
					long temp = ret.remove(ret.size()-1);
						
					if(visited.contains(temp)){
						System.out.println("Found match");
						yes = true;
						break;
					}
					visited.add(temp);
				}
				
			}
			
			if(yes)
				sb.append("Yes\n");
			else
				sb.append("No\n");
			//sb.append(numrepeats + "\n");
		}
		fw.write(sb.toString());
		fw.close();
	}
	
	public static ArrayList<Long> traverse(Long l){
		ArrayList<Long> children = hm.get(l);
		if(children == null){
			ArrayList<Long> ret = new ArrayList<Long>();
			ret.add(l);
			return ret;
		}
		ArrayList<Long> visited = new ArrayList<Long>();
		
		for(Long kid: children){
			ArrayList<Long> ret = traverse(kid);
			
			if(ret == null)
				return null;
				
			while(!ret.isEmpty()){
				long temp = ret.remove(ret.size()-1);
				//if(visited.contains(temp)){
					//System.out.println("Found match");
					//ret = null;
					//return ret;
				//}
				visited.add(temp);
			}
			
		}
		
		visited.add(l);
		return visited;
	}
}
