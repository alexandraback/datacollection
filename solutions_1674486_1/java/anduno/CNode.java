import java.util.ArrayList;
import java.util.List;



public class CNode {
	final int ID;
	List<Integer> inherits = new ArrayList<Integer>();

	public CNode(int id, List<Integer> inhList) {
		this.ID = id;
		inherits.addAll(inhList);
	}

	/*public boolean isLeaf() {
		return (left == null && right == null);
	}*/
	/*
	public int compareTo(HNode hNode) {
		if (rate != hNode.rate) {
			return rate > hNode.rate ? +1 : -1;
		} else {
			return value > hNode.value ? +1 : -1;
		}
	}
	
	public int getLevel() {		
		HNode hNode = this;
		int lev = 0;
		while (hNode.up != null) {
			lev++;
			hNode = hNode.up;
		}
		return lev;
	}*/
	
	@Override
	public String toString() {
		return "CNode id=" + ID + ", inher: " + inherits;
	}

}