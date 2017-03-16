import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import com.google.common.collect.Maps;
import com.google.common.collect.Sets;

public class QualificationC {
	public static void printtable() {
		char[] ns = new char[] {'1','i','j','k','w','x','y','z'};
		Map<Character,String> p = Maps.newHashMap();
		p.put('1',"1");
		p.put('i',"i");
		p.put('j',"j");
		p.put('k',"k");
		p.put('w',"-1");
		p.put('x',"-i");
		p.put('y',"-j");
		p.put('z',"-k");
		System.out.print("\t\t");
		for (int i = 0; i < ns.length; i++) {
			System.out.print(p.get(ns[i])+"\t");
		}
		System.out.println();
		System.out.println();
		for (int i = 0; i < ns.length; i++) {
			System.out.print(p.get(ns[i])+"\t\t");
			for (int j = 0; j < ns.length; j++) {
				System.out.print(p.get(multiply(ns[i],ns[j]))+"\t");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws Exception {
		//printtable();
		String fileName = "C:\\Users\\Srinivgp\\Documents\\C-large.in";
		List<String> lines = Files.readAllLines(Paths.get(fileName));
		int T = Integer.parseInt(lines.get(0));
		for (int t = 0; t < T; t++) {
			String[] LX = lines.get(t*2+1).split(" ");
			int L = Integer.parseInt(LX[0]);
			//int X = Integer.parseInt(LX[1]);
			long bx = Long.parseLong(LX[1]);
			int rx = (int)(bx % 4);
			int X = (int)Math.min((long)(40+rx), bx);
			String dijkstra = lines.get(t*2+2);
			StringBuffer sb = new StringBuffer();
			for (int i = 0; i < X; i++) {
				sb.append(dijkstra);
			}
			String ijk = sb.toString();
			String product = multiply(ijk);
			String reversedProduct = multiplyReverse(ijk);
			
			Set<Integer> starts = Sets.newHashSet();
			Set<Integer> ends = Sets.newHashSet();
			for (int i = 0; i < L*X; i++) {
				if (product.charAt(i) == 'i') {
					starts.add(i+1);
				}
				if (reversedProduct.charAt(i) == 'k') {
					ends.add(i-1);
				}
			}
			
			String works = "NO";
			Set<Character> possible = Sets.newHashSet();
			for (int i = 0; i < L*X; i++) {
				Set<Character> newPossible = Sets.newHashSet();
				Character c = ijk.charAt(i);
				if (starts.contains(i)) {
					newPossible.add(c);
				}
				for (Character p : possible) {
					newPossible.add(multiply(p, c));
				}
				if (ends.contains(i) && newPossible.contains('j')) {
					works = "YES";
					break;
				}
				possible = newPossible;
			}
			System.out.println("Case #" + (t+1) +": " + works);
		}
    }
	static char[][] table = new char[][]
	{
		{'1', 'i', 'j', 'k', 'w', 'x', 'y', 'z'},
		{'i', 'w', 'k', 'y', 'x', '1', 'z', 'j'},
		{'j', 'z', 'w', 'i', 'y', 'k', '1', 'x'},
		{'k', 'j', 'x', 'w', 'z', 'y', 'i', '1'},
		{'w', 'x', 'y', 'z', '1', 'i', 'j', 'k'},
		{'x', '1', 'z', 'j', 'i', 'w', 'k', 'y'},
		{'y', 'k', '1', 'x', 'j', 'z', 'w', 'i'},
		{'z', 'y', 'i', '1', 'k', 'j', 'x', 'w'}
	};
	static Map<Character, Integer> index = null;
	public static char multiply(char a, char b) {
		if (index == null) {
			index = Maps.newHashMap();
			index.put('1', 0);
			index.put('i', 1);
			index.put('j', 2);
			index.put('k', 3);
			index.put('w', 4);
			index.put('x', 5);
			index.put('y', 6);
			index.put('z', 7);
		}
		return table[index.get(a)][index.get(b)];
	}
	public static String multiply(String list) {
		StringBuffer sb = new StringBuffer();
		char c = '1';
		for (int i = 0; i < list.length(); i++) {
			c = multiply(c, list.charAt(i));
			sb.append(c+"");
		}
		return sb.toString();
	}
	public static String multiplyReverse(String list) {
		char[] sb = new char[list.length()];
		char c = '1';
		for (int i = list.length() - 1; i >= 0; i--) {
			c = multiply(list.charAt(i), c);
			sb[i] = c;
		}
		return new String(sb);
	}
}
