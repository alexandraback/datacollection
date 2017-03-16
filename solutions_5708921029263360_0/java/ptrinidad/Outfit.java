package commons;

public class Outfit {
	int jacket,pant,shirt;
	public Outfit (int jacket, int pant, int shirt) {
		this.jacket = jacket;
		this.pant = pant;
		this.shirt = shirt;
	}
	
	@Override
	public String toString() {
		return Integer.toString(jacket) + " " + Integer.toString(pant) + " " + Integer.toString(shirt);
	}
	
	
}
