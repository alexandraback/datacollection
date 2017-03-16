import java.util.*;


public class Recycled {
	public static void main (String[] args) { 
		Scanner sc = new Scanner(System.in);
		int lines = sc.nextInt();
		for (int i=0; i<lines; i++) {
			int min = sc.nextInt();
			int max = sc.nextInt();
			
			int count = 0;
			for (int n=min; n<=max; n++) {
				int d = countDigit(n);
				ArrayList<Integer> swappedValues = new ArrayList<Integer>();
				for (int s=1; s<=d; s++) {
					int tens = tenPowerOf(s);
					int headDigits = d-s;
					int head = n/tens;
					int tail = n%tens;
					
					int minTail = minWithNumberOfDigits(s);
					if (tail>=minTail) {
						int newNum = tail*tenPowerOf(headDigits)+head;
						if (newNum>=min && newNum<=max && newNum!=n) {
							int size = swappedValues.size();
							Boolean isNew = true;
							for (int j=0; j<size; j++) {
								int val = swappedValues.get(j);
								if (val==newNum) {
									isNew = false;
									break;
								}
							}
							if (isNew) {
								swappedValues.add(newNum);
								count++;
							}
						}
					}
				}
			}
			
			count /= 2;
			System.out.println("Case #"+(i+1)+": "+count);
		}
	}
	
	static int countDigit (int n) {
		int digits = 1;
		n = n/10;
		while (n>0) {
			digits++;
			n = n/10;
		}
		return digits;
		
	}
	
	static int tenPowerOf(int p) {
		int res = 0;
		if (p>0) {
			res = 10; // power of 1
			for (int i=2; i<=p; i++) {
				res *= 10;
			}
		}
		return res;
	}
	
	static int minWithNumberOfDigits(int d) {
		return tenPowerOf(d-1);
	}
}
