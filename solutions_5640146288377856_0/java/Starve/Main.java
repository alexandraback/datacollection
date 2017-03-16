import java.util.Scanner;


public class Main {

	
	private int solveOne(int width, int height, int ship) {
		if (ship == 1) {
			return width * height;
		} else if (width == ship) {
			return (height - 1) + ship;
		} else {
			int wTime = width / ship;
			
			int result = wTime * height;
			result += ship;
			
			if (width % ship == 0) {
				result--;
			}
			
			return result;
		}
	}
	
	public void solve() {
		
		Scanner scanner = new Scanner(System.in);
		
		int num = scanner.nextInt();
		
		for (int i=0; i<num; i++) {
			int height = scanner.nextInt();
			int width = scanner.nextInt();
			int ship = scanner.nextInt();
			
			int result = solveOne(width, height, ship);
			
			System.out.println("Case #" + (i+1) + ": " + result);
		}
		
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
		
	}

}
