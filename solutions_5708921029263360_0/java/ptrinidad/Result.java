package commons;

import java.util.LinkedList;
import java.util.List;

public class Result {
	List<Outfit> outfits;
	
	public Result () {
		outfits = new LinkedList<Outfit>();
	}
	
	public void addOutfit (Outfit outfit) {
		outfits.add(outfit);
	}
	
	public void addOutfit (int jacket, int pant, int shirt) {
		outfits.add(new Outfit(jacket,pant,shirt));
	}
	
	@Override
	public String toString() {
		String res = Integer.toString(outfits.size());
		for (Outfit outfit: outfits) {
			res += "\r\n" + outfit;
		}
		
		return res; 
	}
}
