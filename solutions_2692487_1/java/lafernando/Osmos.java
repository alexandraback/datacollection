import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Osmos {

	private static Map<String, Long> memo = new HashMap<String, Long>();
	
	public static void main(String[] args) throws Exception {
		Object[] data = JamUtils.getInput("/home/laf/Downloads/A-large.in");
		String[] input = (String[]) data[1];
		List<Long> motes = new ArrayList<Long>();
		List<String> result = new ArrayList<String>();
		for (int i = 0; i < input.length; i+=2) {
			long me = Long.parseLong(input[i].split(" ")[0]);
			motes.clear();
			String[] ms = input[i + 1].split(" ");
			for (int j = 0; j < ms.length; j++) {
				motes.add(Long.parseLong(ms[j]));
			}
			Collections.sort(motes);
			result.add("" + solve(me, motes));
		}
		JamUtils.writeOutput(result, "/home/laf/Downloads/A-large.out");
	}
	
	private static String makeMemoKey(long me, List<Long> motes) {
		StringBuffer buff = new StringBuffer();
		buff.append(me + ":");
		for (Long x : motes) {
			buff.append(x + ":");
		}
		return buff.toString();
	}
	
	private static long solve(long me, List<Long> motes) {
		String key = makeMemoKey(me, motes);
		if (memo.containsKey(key)) {
			return memo.get(key);
		}
		long result = isOK(me, motes);
		long res;
		if (result == 0) {
			res = 0;
		} else {
			List<Long> nmotes = new ArrayList<Long>(motes);
			nmotes.remove(nmotes.size() - 1);
			long v1 = 1 + solve(me, nmotes);
			nmotes.add(motes.get(motes.size() - 1));
			if (result != -1) {
				nmotes.add(result);
				Collections.sort(nmotes);
				long v2 = 1 + solve(me, nmotes);
				res = Math.min(v1, v2);
			} else {
				res = v1;
			}
		}
		memo.put(key, res);
		return res;
	}
	
	private static long isOK(long me, List<Long> motes) {
		long current = me;
		for (Long mt : motes) {
			if (mt < current) {
				current += mt;
			} else {
				if (current == 1) {
					return -1;
				} else {
				    return current - 1;
				}
			}
		}
		return 0;
	}
	
}
