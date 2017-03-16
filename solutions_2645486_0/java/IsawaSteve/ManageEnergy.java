import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * for the manage your energy challenge.
 * Google code jam 2013 round 1a.
 * @author Jay
 *
 */
public class ManageEnergy {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String size = sc.nextLine();
			String[] sizeArr = size.split(" ");
			int e = Integer.parseInt(sizeArr[0]);
			int r = Integer.parseInt(sizeArr[1]);
			int n = Integer.parseInt(sizeArr[2]);
			
			String size2 = sc.nextLine();
			String[] sizeArr2 = size2.split(" ");
			ArrayList<Integer> tasks = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				tasks.add(Integer.parseInt(sizeArr2[i]));
			}
			
			int gain = calcAllERoute(e,e,r,n,tasks,0);
			
			
			if (pos != total) {
//				sc.nextLine();
			}
			System.out.println("Case #"+pos+": "+gain);
		}
	}

	private static int calcAllERoute(int e, int curE, int r, int n,
			ArrayList<Integer> tasks, int task) {
		if (task >= tasks.size()) {
			return 0;
		}
		ArrayList<Integer> potentials = new ArrayList<Integer>();
		for (int i = 0; i <= curE;i++) {
			potentials.add(calcThisE(i,tasks.get(task)) + calcAllERoute(e,Math.min(e,curE-i+r),r,n, tasks, task+1));
		}
		return maxGain(potentials);
	}

	private static int maxGain(ArrayList<Integer> potentials) {
		int start = 0;
		for (int i = 0; i < potentials.size();i++) {
			if (potentials.get(i) > start) {
				start = potentials.get(i);
			}
		}
		return start;
	}

	private static int calcThisE(int energySpent, Integer taskValue) {
		return energySpent * taskValue;
	}

}
