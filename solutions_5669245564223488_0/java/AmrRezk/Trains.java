import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Trains {
	static int counter = 0;
	boolean flag = false;
	static HashMap<String, Integer> count = new HashMap<String, Integer>();

	public static void getLongest(String current, String set[],
			boolean marked[]) {
		if (noMoreConcatenation(current, set, marked)) {
			for (String s : set)
				if (s.equals(current))
					return;
			if (count.containsKey(current))
				count.put(current, count.get(current) + 1);
			else
				count.put(current, 1);
			return;
		} else
			for (int i = 0; i < set.length; i++) {
				if (!marked[i]
						&& current.charAt(current.length() - 1) == set[i]
								.charAt(0)) {
					marked[i] = true;
					getLongest(current + set[i], set, marked);
					marked[i] = false;
				}
			}
	}

	public static boolean noMoreConcatenation(String current, String set[],
			boolean marked[]) {
		for (int i = 0; i < set.length; i++) {
			if (!marked[i]
					&& current.charAt(current.length() - 1) == set[i].charAt(0)) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("textfile.txt"));
		PrintWriter out = new PrintWriter("output" + ".out");
		int cases = Integer.parseInt(input.nextLine());
		for (int j = 0; j < cases; j++) {
			count = new HashMap<String, Integer>();
			int num = Integer.parseInt(input.nextLine());
			String set[] = input.nextLine().split(" ");
			ArrayList<String> common = new ArrayList<String>();
			ArrayList<String> unCommon = new ArrayList<String>();
			label:for(String s:set)
			{
				for(String ss:set)
				{
					for(int i=0;i<ss.length();i++)
					{
						if(s.contains(""+ss.charAt(i))){
							common.add(s);
							continue label;
						}
					}
				}
				unCommon.add(s);
			}
			set = new String[common.size()];
			common.toArray(set);
			if(num==1){
				out.write("Case #"+(j+1)+": "+1+"\n");
				continue;
			}
	
			boolean marked[] = new boolean[set.length];
			for (int i = 0; i < set.length; i++) {
				marked[i] = true;
				getLongest(set[i], set, marked);
				marked[i] = false;
			}
			HashMap<String, Integer> finalmap = new HashMap<String, Integer>();
			for (String x : count.keySet())
				finalmap.put(x, count.get(x));
			for (String x : count.keySet()) {
				for (String y : count.keySet()) {
					if (!x.equals(y) && x.contains(y))
						finalmap.remove(y);
				}
			}
			int result = 1;
			for (String x : finalmap.keySet())
				result *= finalmap.get(x);
			result = result * finalmap.size();
			if(unCommon.size()!=0)
				result=result*unCommon.size();
			out.write("Case #"+(j+1)+": "+result+"\n");
		}
		out.close();
	}
	
}
