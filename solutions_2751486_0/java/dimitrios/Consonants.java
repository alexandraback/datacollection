import java.util.Vector;

public class Consonants {

	public static class IntRange {
		public int start, finish;
		public IntRange(int a, int b) {
			start = a;
			finish = b;
		}
		public String toString() {
			return "["+start+"; "+finish+"]";
		}
	}

	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			String s = sc.next();
			int n = sc.nextInt();
			Vector<IntRange> ranges = new Vector<IntRange>();
			int start = -1;
			int end = 0;
			for(int i=0; i<s.length(); i++) {
				char c = s.charAt(i);
				if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u') {
					if(start==-1) start = i;
					end = i;
					if(end - start + 1 == n) {
						ranges.add(new IntRange(start, end));
						i = start;
						start = -1;
					}
				} else start = -1;
			}
			int min = 0;
			int count = 0;
			for(int i=0; i<ranges.size(); i++) {
				IntRange r = ranges.elementAt(i);
				count+= (r.start-min+1) * (s.length()-r.finish);
				min = r.start + 1;
				/*
				aaSDFeioFRGoiZXCV
				2-4
				8-10
				13-15
				14-16
				*/
			}
			System.out.printf("Case #%d: %d\n", t, count);
		}
	}

}