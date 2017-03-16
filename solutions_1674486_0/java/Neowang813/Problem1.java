import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.*;

public class Problem1 {
	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "A-small-attempt0.in";
		String outputFile = "pro1.out";
		Scanner inputScanner = new Scanner(new FileInputStream("d:\\codejam\\"
				+ inputFile));
		PrintStream ps = new PrintStream(new FileOutputStream("d:\\codejam\\"
				+ outputFile));
		int totalCaseNum = inputScanner.nextInt();
		inputScanner.nextLine();
		// -----------------------------------------------

		// -----------------------------------------------
		for (int caseNum = 1; caseNum <= totalCaseNum; caseNum++) {
			String line = inputScanner.nextLine();
			String prefix = "Case #" + caseNum + ": ";
			StringBuilder output = new StringBuilder(prefix);
			// -----------------------------------------------
			Scanner sc = new Scanner(line);
			int N = sc.nextInt();
			List<List<Integer>> vlist = new ArrayList<List<Integer>>();
			List<Set<Integer>> check = new ArrayList<Set<Integer>>();
			for (int v = 0; v < N; v++) {
				String vline = inputScanner.nextLine();
				Scanner vsc = new Scanner(vline);
				int dads = vsc.nextInt();
				List<Integer> dadList = new ArrayList<Integer>();
				for (int dad = 0; dad < dads; dad++) {
					dadList.add(vsc.nextInt()-1);
				}
				vlist.add(dadList);
				check.add(null);
			}
			
			boolean find = false;
			for (int i=0;i<N;i++){
				Set<Integer> set=findDads(i,vlist, check);
				if (set == null){
					
					find = true;
					break;
				}
			}
			if (find){
				output.append("Yes");
				
			}else{
				output.append("No");
			}

			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}

	static Set<Integer> findDads(int start, List<List<Integer>> vlist,
			List<Set<Integer>> res) {
		if (res.get(start) != null) {
			return res.get(start);
		}

		List<Integer> dadList = vlist.get(start);
		if (dadList.size() == 0) {
			Set<Integer> s = new HashSet<Integer>(1);
			s.add(start);
			return s;
		}

		Set<Integer> dadSet = new HashSet<Integer>();
		for (int dad : dadList) {
			Set<Integer> dads = findDads(dad, vlist, res);
			if (dads == null) {
				return null;
			}
			if (Collections.disjoint(dadSet, dads)) {
				dadSet.addAll(dads);
			} else {
				return null;
			}
		}
		res.set(start, dadSet);
		return dadSet;

	}
}
