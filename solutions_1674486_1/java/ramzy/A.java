import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class A {

	static C[] arr;
	static int N;
	static class C {
		HashSet<Integer> set;
		ArrayList<Integer> list;
		HashSet<Integer> anc = null;
		int val;
		C(HashSet<Integer> set, ArrayList<Integer> list, int val) {
			this.set = set;
			this.val = val;
			this.list = list;
		}
		boolean isSubClass(int val) {
			if(set.contains(val))
				return true;
			for(int num : set) {
				if(arr[num-1].isSubClass(val)) {
					return true;
				}
			}
			return false;
		}
		boolean is() {
			for(int i = 0; i < list.size()-1; i++) {
				for(int j = i+1; j < list.size(); j++) {
					if(arr[list.get(i)-1].haveSupClass(arr[list.get(j)-1])) {
						return true;
					}
				}
			}
			return false;
		}
		HashSet<Integer> anc() {
			if(anc == null) {
				anc = new HashSet<Integer>();
				anc.add(val);
				anc.addAll(set);
				for(int num :set) {
					anc.addAll(arr[num-1].anc());
				}
			}
			return anc;
		}
		private boolean haveSupClass(C c) {
			for(int num : anc()) {
				HashSet<Integer> other = c.anc();
				if(other.contains(num))
					return true;
			}
			return false;
		}
	}
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("src/A.in"));
		PrintWriter output = new PrintWriter("src/A.out");
		int T = input.nextInt();
		for(int t = 1; t <= T; t++) {
			String o = "Case #" + t + ": ";
			N = input.nextInt();
			arr = new C[N];
			for(int i = 0; i < N; i++) {
				int n = input.nextInt();
				HashSet<Integer> set = new HashSet<Integer>(n);
				ArrayList<Integer> list = new ArrayList<Integer>(n);
				for(int j = 0; j < n; j++) {
					int num = input.nextInt();
					set.add(num);
					list.add(num);
				}
				arr[i] = new C(set, list, i+1);
			}

			boolean result = false;
			for(int i = 0; i < N; i++) {
				if(arr[i].is()) {
					result = true;
					break;
				}
			}
			o += result ? "Yes" : "No";
			output.println(o);
			System.out.println(o);
		}
		input.close();
		output.close();
	}
	
}
