import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int n = s.nextInt();
			Vector<String> cars = new Vector<String>();
			for (int i = 0; i < n; i++) {
				cars.add(s.next());
			}
			
			int count = 0;
			Vector<String> all = getAll(cars);
			//for (int i = 0; i < all.size(); i++) {
			//	if (isValid(all.elementAt(i))) count++;
			//}
			count = all.size();
			System.out.printf("Case #%d: %d\n", (current++), count%1000000007);			
		}
	}
	
	static String zipString(String s) {
		boolean[] flag = new boolean[26];
		char cur = '-';
		
		char[] zip = new char[26];
		int pos = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c != cur) {
				if (flag[c-'a']) return "";
				flag[c-'a'] = true;
				cur = c;
				zip[pos++] = cur;
			}
		}
		return new String(zip, 0, pos);
	}
	
	static Vector<String> getAll(Vector<String> cars) {
		Vector<String> vec = new Vector<String>();
		String ele;
		if (cars.size() ==  1) {
			ele = cars.elementAt(0);
			ele = zipString(ele);
			if (ele.length() != 0) vec.add(ele);
			return vec;
		}
		
		for (int i = 0; i < cars.size(); i++) {
			String first = cars.elementAt(i);
			Vector<String> copy = (Vector<String>) cars.clone();
			copy.remove(i);
			Vector<String> rest = getAll(copy);
			for (int j = 0; j < rest.size(); j++) {
				ele = first + rest.elementAt(j);
				ele = zipString(ele);
				if (ele.length() != 0) vec.add(ele);
			}
		}
		return vec;
	}
}
