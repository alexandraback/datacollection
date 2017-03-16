import java.util.Scanner;

/**
 * if a point in the middle has a lower height than one of its surroundings in two direction
 * output No
 * @author Rex
 *
 */
public class Lawnmower {
	
	private int[][] myLawn;
	
	public Lawnmower(int[][] lawn) {
		myLawn = lawn;
	}
	
	public boolean checkPossible() {
		int[] horizontalMax = new int[myLawn.length];
		int[] verticalMax = new int[myLawn[0].length];
		for (int i = 0; i < myLawn.length; i++) {
			int max = 0;
			for (int j = 0; j < myLawn[0].length; j++)
				if (max < myLawn[i][j])
					max = myLawn[i][j];
			horizontalMax[i] = max;
		}
		for (int i = 0; i < myLawn[0].length; i++) {
			int max = 0;
			for (int j = 0; j < myLawn.length; j++)
				if (max < myLawn[j][i])
					max = myLawn[j][i];
			verticalMax[i] = max;
		}
		for (int i = 0; i < myLawn.length; i++)
			for (int j = 0; j < myLawn[0].length; j++) {
				if (myLawn[i][j] < Math.min(horizontalMax[i], verticalMax[j]))
					return false;
			}
		return true;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numSets = scanner.nextInt();
		for (int i = 0; i < numSets; i++) {
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int[][] lawn = new int[N][M];
			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++) {
					lawn[j][k] = scanner.nextInt();
				}
			System.out.print("Case #" + (i + 1) + ": ");
			if (new Lawnmower(lawn).checkPossible())
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}
