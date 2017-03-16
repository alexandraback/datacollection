package codejam;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class C extends CodeJam {

	public C(String file) throws Exception {
		super(file);
	}

	@Override
	public Object processCase(int caseNumber) throws Exception {
		int[] numbers = readIntArray();
		
		List<Integer> list = new ArrayList<Integer>(numbers.length-1);
		for (int i = 1; i < numbers.length; i++) {
			list.add(numbers[i]);
		}
		
		final HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		
		final ArrayList<Integer> set1 = new ArrayList<Integer>();
		final ArrayList<Integer> set2 = new ArrayList<Integer>();
		
		ArrayList<ArrayList<Integer>> compute = CombinationGenerator.compute(list, 1, list.size(), new CombinationValidator<Integer>() {
			@Override
			public boolean isValid(List<Integer> comb) {
				int sum = 0;
				for (Integer integer : comb) {
					sum+= integer;
				}
				ArrayList<Integer> arrayList = map.get(sum);
				if (arrayList != null) {
					set1.addAll(arrayList);
					set2.addAll(comb);
					return true;
				}
				
				map.put(sum, (ArrayList<Integer>) comb);
				return false;
			}
		}, true);
		
		if (!set1.isEmpty()) {
			StringBuilder r = new StringBuilder();
			r.append('\n');
			r.append(toString(set1));
			r.append('\n');
			r.append(toString(set2));
			return r.toString();
		} else {
			return "Impossible";
		}
	}
	
	public static void main(String[] args) throws IOException, InterruptedException, Exception {
		new C("C-small-attempt0.in").start();
		
	}

}
