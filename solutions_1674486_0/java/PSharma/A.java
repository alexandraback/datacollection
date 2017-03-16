import java.util.*;
import java.io.*;

public class A
{
	private Scanner reader;
	private PrintWriter writer;
	
	public A(String inFile, String outFile)
	{
		try {
			reader = new Scanner(new File(inFile));
			writer = new PrintWriter(new File(outFile));
			init();
		}
		catch (Exception ex ) {
			ex.printStackTrace();
		}	
	}
	
	HashMap<Integer, List<Integer>> map;
	
	private void init() {
		int T = reader.nextInt();
		for (int i=1; i<=T; i++) {
			map = new HashMap<Integer, List<Integer>>();
			int N = reader.nextInt();
			for (int k=1; k<=N; k++) {
				int M = reader.nextInt();
				List<Integer> list = new ArrayList<Integer>();
				for (int j=0; j<M; j++)
					list.add(reader.nextInt());
				
				map.put(k, list);
			}
			
			String ret = hasDiamondLink() ? "Yes" : "No";
			
			String out = "Case #"+i+": " + ret +"\n";
			writer.write(out);
			writer.flush();
		}
		
		writer.close();
	}
	
	private boolean hasDiamondLink() {
		for (int key : map.keySet()) {
			List<Integer> list = map.get(key);
			Set<Integer> visitedSet = new HashSet<Integer>();
			List<Integer> visitList = new ArrayList<Integer>();
			if(!list.isEmpty()) {
				visitList.addAll(list);
				while(!visitList.isEmpty()) {
					int k = visitList.remove(0);
					if (visitedSet.contains(k)) {
						return true;
					}
					else {
						visitList.addAll(map.get(k));
						visitedSet.add(k);
					}
				}
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) 
	{
		new A("/Users/prabhaks/work/workspace/Test/src/in.txt", "/Users/prabhaks/work/workspace/Test/src/out.txt");
	}
}