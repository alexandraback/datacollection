import java.util.Set;
import java.util.TreeSet;


public class Nodes {

	public  TreeSet<Integer> parents = new TreeSet<Integer>();
	public int nodeNum;

	public Nodes(int me) {
		nodeNum = me;
	}

	public boolean hasParent() {
		// TODO Auto-generated method stub
		return parents.size() > 0;
	}


}
