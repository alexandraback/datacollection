import java.util.Scanner;


public class TrainCars {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			int cars = kb.nextInt();
			
			String[] carList = new String[cars];
			for(int i = 0 ; i < cars; i++) {
				carList[i] = kb.next();
			}
			
			System.out.println("Case #" + c + ": " + solve(carList));
		}
	}

	private static int solve(String[] carList) {
		boolean[] chosenList = new boolean[carList.length];
		return recurse(carList, chosenList, "", 0);
	}
	
	private static int recurse(String[] carList, boolean[] chosenList, String current, int chosen) {
		if(chosen == carList.length) return check(current);
		
		int sum = 0;
		
		for(int i = 0; i < carList.length; i++) {
			if(!chosenList[i]) {
				chosenList[i] = true;
				sum += recurse(carList, chosenList, current + carList[i], chosen+1);
				chosenList[i] = false;
			}
		}
		
		return sum;
	}
	
	private static int check(String str) {
		boolean[] found = new boolean[26];
		char previous = ' ';
		
		for(int i = 0; i < str.length(); i++) {
			char current = str.charAt(i);
			if(current != previous) {
				if(found[current - 'a']) return 0;
				found[current - 'a'] = true;
			}
			
			previous = current;
		}
		
		return 1;
	}
}
