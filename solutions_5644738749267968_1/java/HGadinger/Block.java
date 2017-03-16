package qd;

public class Block {

	public Block(double weight, boolean n) {
		w = weight;
		Naomi = n;
	}

	double w = 0;
	boolean Naomi = true;// owner
	boolean chk = false;// checked for score

	public String toString() {
		return (Naomi ? "N" : "K") + " " + w;
	}

}
