import java.util.Scanner;

public class B {
	private int getFlips(String cakeStack) {
		int flips = 0;
		char[] panArray = cakeStack.toCharArray();
		/*for (int i = 0; i < panArray.length; i++) {
			panArray[i] = (panArray[i] == '+') ? '-' : '+';
			if (i + 1 < panArray.length && panArray[i] == panArray[i + 1]) {
				i = -1;
				flips++;
			}
		}
		if (panArray[0] == '+') {
			flips++;
		}*/
		for (int i = 0; i < panArray.length - 1; i++) {
			if (panArray[i] != panArray[i + 1]) {
				flips++;
			}
		}
		if (flips % 2 == 0) {
			if (panArray[0] == '-')
				flips++;
		} else if (panArray[0] == '+') {
			flips++;
		}
		return flips;
	}

	public static void main(String[] args) {
		Scanner in = null;
		B b = new B();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			in.nextLine();
			for (int test = 1; test <= count; test++) {
				String cakeStack = in.nextLine();
				int result = b.getFlips(cakeStack);
				System.out.println("Case #" + test + ": " + result);
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
