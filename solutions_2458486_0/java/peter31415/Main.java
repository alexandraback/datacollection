import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class Main {

	static String file = "D-small-attempt1";
//	static String file = "d";

	public static void main(String[] args) throws IOException {

		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			String[] v = lines.get(++currentIndex).split(" ");
			int k = Integer.parseInt(v[0]);
			int n = Integer.parseInt(v[1]);
			List<Integer> hand = new ArrayList<Integer>();
			v = lines.get(++currentIndex).split(" ");
			for (int j = 0; j < v.length; j++) {
				hand.add(Integer.parseInt(v[j]));
			}

			int[] needed = new int[n];
			List<List<Integer>> opens = new ArrayList<List<Integer>>();
			for (int j = 0; j < n; j++) {
				v = lines.get(++currentIndex).split(" ");
				needed[j] = Integer.parseInt(v[0]);
				opens.add(new ArrayList<Integer>());
				int kk = Integer.parseInt(v[1]);
				for (int j2 = 2; j2 < 2 + kk; j2++) {
					opens.get(j).add(Integer.parseInt(v[j2]));
				}
			}
			
			List<List<Integer>> parents = new ArrayList<List<Integer>>();
			for (int j = 0; j < needed.length; j++) {
				parents.add(new ArrayList<Integer>());
			}
			for (int j = 0; j < opens.size(); j++) {
				for (int j2 = 0; j2 < opens.get(j).size(); j2++) {
					for (int l = 0; l < needed.length; l++) {
						
						if (needed[l]==opens.get(j).get(j2))
							parents.get(l).add(j);						
					}
					
				}
			}			
			
			for (int j = 0; j < parents.size(); j++) {
				parents.get(j).remove(new Integer(j));
			}
			
			List<Integer> solution = null;
			if (possible(new HashSet<Integer>(),opens, hand, needed))
				solution = getSolution(new HashSet<Integer>(), opens, hand, needed, parents);
			if (solution != null)
				for (int j = 0; j < solution.size(); j++) {
					solution.set(j, solution.get(j) + 1);
				}

			String r = "Case #" + (i + 1) + ": ";
			if (solution == null)
				r += "IMPOSSIBLE";
			else {
				r += format(solution.toArray());
			}

			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();

	}

	static String format(Object[] a) {
		return Arrays.toString(a).replace("[", "").replace("]", "").replace(",", "");
	}

	static boolean possible2(HashSet<Integer> visited, List<Integer> hand, int[] needed, List<List<Integer>> parents) {
		List<Integer> h2 = new ArrayList<Integer>();
		
		for (int i = 0; i < hand.size(); i++) {
			h2.add(hand.get(i));			
		}
		
		for (int i = 0; i < parents.size(); i++) {
			if (parents.get(i).size()==0 && !visited.contains(i))
			{
				if(!h2.remove(new Integer(needed[i])))
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
	static boolean possible(HashSet<Integer> visited, List<List<Integer>> opens, List<Integer> hand, int[] needed) {
		List<Integer> n = new ArrayList<Integer>();
		for (int i = 0; i < needed.length; i++) {
			if(!visited.contains(i))
				n.add(needed[i]);
		}

		for (int i = 0; i < opens.size(); i++) {
			for (int j = 0; j < opens.get(i).size(); j++) {
				n.remove(new Integer(opens.get(i).get(j)));
			}
		}

		for (int i = 0; i < hand.size(); i++) {
			n.remove(hand.get(i));
		}
		
		if (n.size() > 0)
			return false;
		return true;
	}

	public static List<Integer> getSolution(HashSet<Integer> visited, List<List<Integer>> children, List<Integer> hand, int[] needed, List<List<Integer>> parents) {
		List<Integer> s = new ArrayList<Integer>();

		if (visited.size() == needed.length)
			return s;

		if (hand.size() == 0)
			return null;

		boolean isEnd = false;
		for (int i = 0; i < needed.length; i++) {
			if (!visited.contains(new Integer(i)) && hand.contains(needed[i])) {
				if (children.get(i).contains(needed[i])) {
					isEnd = true;
				}

				visited.add(i);
				hand.remove(new Integer(needed[i]));
				hand.addAll(children.get(i));
				List<Integer> tmps = null;
				if (possible(visited,children,hand,needed) && possible2(visited,hand,needed,parents))
					tmps = getSolution(visited, children, hand, needed, parents);
				visited.remove(new Integer(i));
				for (int j = 0; j < children.get(i).size(); j++) {
					hand.remove(new Integer(children.get(i).get(j)));
				}
				hand.add(needed[i]);

				if (tmps != null) {
					s.add(i);
					s.addAll(tmps);
					break;
				}
			}

			if (isEnd) {
				if (s.size() == 0)
					return null;
				else
					return s;
			}
		}

		if (s.size() == 0)
			return null;
		else
			return s;
	}

}
