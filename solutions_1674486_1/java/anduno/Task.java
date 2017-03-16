import java.io.File;
import java.util.*;


public class Task {

	static boolean findDiamond(int testId, Map<Integer, CNode> id2class) {
		Queue<CNode> queue = new LinkedList<CNode>();
		queue.add(id2class.get(testId));
		
		Set<Integer> path = new HashSet<Integer>();
		
		while (!queue.isEmpty()) {			
			CNode current = queue.poll();
			if (!path.add(current.ID)) {
				return true;
			}
			//System.out.println(current);
			for (Integer id : current.inherits) {
				queue.add(id2class.get(id));
			}
		}
		return false;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {		
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int t = 1; t <= test; t++) {			
			int N = scan.nextInt();
			//System.out.println("test " + t + ", N = " + N);
			
			TreeMap<Integer, CNode> id2class = new TreeMap<Integer, CNode>(); 		
			List<Integer> doubleInherits = new ArrayList<Integer>();
			
			for (int id = 1; id <= N; id++) {
				int inh = scan.nextInt(); //1 or 2
				//System.out.println("   inh " + inh);
				
				List<Integer> inhList = new ArrayList<Integer>();
				for (int i = 0; i < inh; i++) {
					inhList.add(scan.nextInt());
				}				
				CNode c = new CNode(id, inhList);						
				id2class.put(id, c);
				if (inhList.size() > 1) {
					doubleInherits.add(id);
				}
			}
						
			//System.out.println("id2class " + id2class);
			//System.out.println("doubleInherits " + doubleInherits);
			
			boolean hasDiamond = false;
			for (Integer doubl : doubleInherits) {
				if (findDiamond(doubl, id2class)) {
					hasDiamond = true;
					break;
				}
			}
			System.out.println("Case #" + t + ": " + (hasDiamond ? "Yes" : "No"));
		}/**/
	}

}
