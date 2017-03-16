
public class Triplet {
	private int total;
	public Triplet(int totalScore){
		total = totalScore;
	}
	
	int getTotal() {
		return total;
	}
	
	boolean isSuprisable() {
		if (total < 2 || total > 28) {
			return false;
		} else {
			return true;
		}
	}
	int getBest(boolean suprising) {
		int extra = total%3;
		int mean = total/3;
		int result = -1;
		
		switch (extra) {
		case 0:
			if (suprising) {
				if (mean >= 1 && mean <= 9) {
					result = (mean+1); // m-1, m, m+1
				} else {
					result = -1;
				}
			} else {
				result = mean; // m, m, m
			}
			break;
		case 1:
			if (suprising) {
				if (mean >= 1 && mean <= 9) {
					result = mean+1; // m-1, m+1, m+1 
				} else {
					result = -1;
				}
			} else {
				result = mean+1; // m, m, m+1
			}
			break;
		case 2:
			if (suprising) {
				if (mean >= 0 && mean <= 8) {
					result = mean + 2; // m, m, m+2
				} else {
					result = -1;
				}
			} else {
				result = mean + 1; // m, m+1, m+1
			}
		default:
			break;
		}
		
		return result;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + total;
		return result;
	}
}
