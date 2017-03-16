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
		long[] numbers = readLongArray();
		
		List<Long> list = new ArrayList<Long>(numbers.length-1);
		for (int i = 1; i < numbers.length; i++) {
			list.add(numbers[i]);
		}
		
		final HashMap<Long, ArrayList<Long>> map = new HashMap<Long, ArrayList<Long>>();
		
		final ArrayList<Long> set1 = new ArrayList<Long>();
		final ArrayList<Long> set2 = new ArrayList<Long>();
		
		ArrayList<ArrayList<Long>> compute = CombinationGenerator.compute(list, 1, list.size(), new CombinationValidator<Long>() {
			@Override
			public boolean isValid(List<Long> comb) {
				long sum = 0;
				for (Long Long : comb) {
					sum+= Long;
				}
				ArrayList<Long> arrayList = map.get(sum);
				if (arrayList != null) {
					set1.addAll(arrayList);
					set2.addAll(comb);
					return true;
				}
				
				map.put(sum, (ArrayList<Long>) comb);
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
		new C("C-large.in").start();
		
	}

}
