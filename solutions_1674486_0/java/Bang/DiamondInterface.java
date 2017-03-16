import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class DiamondInterface {

	public static class InheritanceGraph {
		public ArrayList<ArrayList<Integer>> inheritance;
		int classCount;
		InheritanceGraph(int classCount) {
			inheritance = new ArrayList<ArrayList<Integer>>();
			this.classCount = classCount; 
			for (int i = 0; i <= classCount; i++) {
				inheritance.add(i, new ArrayList<Integer>());
			}
		}
		 
		void addInheritance(Integer classId, ArrayList<Integer> inheritsFromClasses) {
			ArrayList<Integer> parentClasses;
			if((parentClasses = inheritance.get(classId)) != null) {
				parentClasses = new ArrayList<Integer>();
				inheritance.add(classId, parentClasses);
			}
			for(Integer inheritsFrom: inheritsFromClasses) {
				if (!parentClasses.contains(inheritsFrom)) {
					parentClasses.add(inheritsFrom);
				}
			}
		}
		
		Integer pathCount(Integer classA, Integer classB) {
			Integer pathCount = 0;
			ArrayList<Integer> parents;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(classA);
			while (!q.isEmpty()) {
				Integer c = q.removeFirst();
				parents = inheritance.get(c);
				if (parents != null) {
					if (parents.size() != 0) {
						for (Integer parent : parents) {
							q.add(parent);
							if (parent.equals(classB)) {
								pathCount++;
							}
						}
					}
				}
			}
			return pathCount;
		}
	}
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader("C:\\Projects\\Learning\\src\\diamond.in");
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter("C:\\Projects\\Learning\\src\\diamond.out.txt");
			int N = new Integer(br.readLine());
			for (int cases = 1; cases <= N; cases++) {
				//for every case
				System.out.println(cases);
				int classCount = new Integer(br.readLine());
				System.out.println(classCount);
				InheritanceGraph g = new InheritanceGraph(classCount);
				for (int i = 1; i<= classCount; i++) {
					String classLine = br.readLine();
					StringTokenizer st = new StringTokenizer(classLine);
					int parentCount = Integer.parseInt(st.nextToken());
					System.out.println("parentcount" + parentCount);
					ArrayList<Integer> parents = new ArrayList<Integer>();
					for (int x = 0; x < parentCount; x++) {
						parents.add(Integer.parseInt(st.nextToken()));
					}
					g.addInheritance(i, parents);
				}
				boolean diamondExists = false;
				for (int from = 1; from <= classCount; from++) {
					for (int to = 2; to <= classCount; to++) {
						if (from != to) {
							if (g.pathCount(from, to) > 1) {
								diamondExists = true;
								break;
							}
						}
					}
					if (diamondExists) {
						break;
					}
				}
				String result = diamondExists ? "Yes" : "No";
				fw.write("Case #" + cases + ": " + result + "\n");
				fw.flush();
			}
			
		} catch (Exception e) {
			
		}
		
	}

}
