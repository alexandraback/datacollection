import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for (int i = 1; i <= T; i++) {
			String[] vals = in.nextLine().split(" ");
			int targetX = Integer.parseInt(vals[0]);
			int targetY = Integer.parseInt(vals[1]);
			StringBuilder result = new StringBuilder();
			int jump = 1;
			int currentX = 0, currentY = 0;
			int jumpSign = (int)Math.signum(targetX);
			//get the x right first
			while (currentX != targetX) {
				currentX += jump * jumpSign;
				jump++;
				if (jumpSign == 1)
					result.append("E");
				else
					result.append("W");
				jumpSign *= -1;					
			}
			jumpSign = (int)Math.signum(targetY * -1);
			//then get the y right
			while (currentY != targetY) {
				currentY += jump * jumpSign;
				jump++;
				if (jumpSign == 1)
					result.append("N");
				else
					result.append("S");
				jumpSign *= -1;					
			}
			System.out.println("Case #" + i +": " + result.toString());
		}
		in.close();
	}
}
