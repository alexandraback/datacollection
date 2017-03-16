import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Exercice2A extends Reader {
	
	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
	
	@Override
	protected String getFileName() {
		return "A-small-attempt0 (1).in";
	}

	@Override
	protected int getNumberOfLinePerCase() {
		return 1;
	}

	@Override
	protected void init(String firstLine) {
		// TODO Auto-generated method stub
		System.out.println("GO");
		for (int i = 1; i < 1000000; i++) {
			int nb = getMinCount(i, 0);
			// System.out.println(i + " " + nb);
			map.put(i, nb);
		}
	}

	@Override
	protected void handleCase(List<String> lines) {
		int num = Integer.parseInt(lines.get(0));
		
		int minCount = getMinCount(num, 0);
		// System.out.println(reverseNum(92));
		printResult("" + minCount);
	}
	
	
	int getMinCount(int n, int depth) {
		if (n == 1) return 1;
		if (map.containsKey(n)) {
			return map.get(n);
		}
		int a = n - 1;
		int b = reverseNum(n);
		for (int i =0; i < depth; i++) {
		//System.out.print(" ");
		}
		// System.out.println(n + " ");
		
		if (b >= n || digitCount(n) != digitCount(b)) {
			int nb = getMinCount(a, depth + 1) + 1;
			// map.put(n, nb);
			return nb;
		} else {
			int ac = getMinCount(a, depth + 1);
			int bc = getMinCount(b, depth + 1);
			int nb = Math.min(ac, bc) + 1;
			return nb;
		}
	}
	
	public int digitCount(long n) {
		return  String.valueOf(n).length();
	}
	
	public int reverseNum(int n) {
		String num = String.valueOf(n);
		String numRev = new StringBuilder(num).reverse().toString();
		return Integer.parseInt(numRev);
	}
	
}
