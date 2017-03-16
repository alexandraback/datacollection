package roundc;

public class Dir {

	int a;
	int b;
	
	String str = "";

	public Dir(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	

	public Dir(int a, int b, String str) {
		super();
		this.a = a;
		this.b = b;
		this.str = str;
	}



	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + a;
		result = prime * result + b;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (getClass() != obj.getClass()) {
			return false;
		}
		Dir other = (Dir) obj;
		if (a != other.a) {
			return false;
		}
		if (b != other.b) {
			return false;
		}
		return true;
	}



	@Override
	public String toString() {
		return "Dir [a=" + a + ", b=" + b + ", str=" + str + "]";
	}
}