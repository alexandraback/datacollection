import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class AllPerms {
 

	public static Set<List<Integer>> allPerms(List<Integer> list) {
		Set<List<Integer>> result = new HashSet<>();
		if (list == null) {
			return null;
		} else if (list.size() == 0) {
			result.add(new ArrayList<>());
			return result;
		}
 
		Integer firstChar = list.get(0);
		List<Integer> rem = new ArrayList<>(list);
		rem.remove(0);
		Set<List<Integer>> perms = allPerms(rem);
		for (List<Integer> newString : perms) {
			for (int i = 0; i <= newString.size(); i++) {
				result.add(Add(newString, firstChar, i));
			}
		}
		return result;
	}
 
	public static List<Integer> Add(List<Integer> str, Integer c, int j) {
		List<Integer> s = new ArrayList<>();
		s.addAll(str);
		s.add(j, c);
		return s;
	}
 
}