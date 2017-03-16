import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class Mejn {
	
	public static Set<Integer> diamonds = new HashSet<Integer>();
	public static Map<Integer, HashSet<Integer>> mapa = new HashMap<Integer, HashSet<Integer>>();
	
	public static void main(String[] args) throws IOException {
		File file = new File("/Users/highend/a.in");
		Map<Integer, Node> nodes = new HashMap<Integer, Node>();
		GcjReader reader = new GcjReader(new InputStreamReader(new FileInputStream(file)));
		for(int finish = reader.readInt(), i =0;i<finish;i++) {
			nodes.clear();
			diamonds.clear();
			mapa.clear();
			hasDiamond = false;
			wasThere.clear();
			int numOfClasses = reader.readInt();
			for(int j=0;j<numOfClasses;j++) {
				Node node = new Node();
				node.value = j+1;
				int numOfBaseClasses = reader.readInt();
				for(int x=0;x<numOfBaseClasses;x++) {
					int baseClassNum = reader.readInt();
					node.inheritsFrom.add(baseClassNum);
				}
				nodes.put(node.value, node);
			}
			System.out.print("Case #" + (i+1) + ": ");
			for(int j=1;j<=numOfClasses;j++) {
				//if(!wasThere.contains(j)) {
					Node node = nodes.get(j);
					calc(nodes, node.inheritsFrom, node.value);
					if(hasDiamond) {
						System.out.println("Yes");
						break;
					}
				//}
			}
			if(!hasDiamond) {
				System.out.println("No");
			}
		}
	}
	
	public static void calc(Map<Integer, Node> nodes, List<Integer> inheritsFrom, int value) {
		wasThere.add(value);
		for(int base : inheritsFrom) {
			if(!mapa.containsKey(base)) {
				mapa.put(base, new HashSet<Integer>());
			}
			Set<Integer> secik = mapa.get(base);
			if(secik.contains(value)) {
				hasDiamond = true;
			} else {
				secik.add(value);
			}
			Node baseNode = nodes.get(base);
			if(baseNode != null) {
				calc(nodes, baseNode.inheritsFrom, value);
			}
		}
	}
	
	public static boolean hasDiamond = false;
	public static Set<Integer> wasThere = new HashSet<Integer>();
}

class Node {
	public List<Integer> inheritsFrom = new ArrayList<Integer>();
	public List<Integer> baseClassFor = new ArrayList<Integer>();
	public int value;
}

