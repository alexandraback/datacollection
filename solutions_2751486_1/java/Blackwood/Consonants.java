import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;



public class Consonants {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw;
		FileOutputStream fos = new FileOutputStream("C:\\Users\\Administrator\\Downloads\\codejam.out");
		bw = new BufferedWriter(new OutputStreamWriter(fos));
		Scanner reader = new Scanner (System.in);
		int nCases = reader.nextInt();
		reader.nextLine();

		for(int i=1; i<=nCases; i++) {
			String s = reader.nextLine();
			String sa[] = s.split(" ");
			String str = sa[0];
			int n = new Integer(sa[1]);
			ArrayList<Cons> allCons = new ArrayList<Cons>();
			char chars[] = str.toCharArray();
			int start = -1;
			int length = 0;
			for(int j=0; j<chars.length; j++) {
				if(isCons(chars[j])) {
					if(start == -1) {
						start = j;
						length++;
					} else {
						length++;
					}
				} else {
					if(length>=n) {
						allCons.add(new Cons(str.substring(start, start+length), start, length));
					}
					start = -1;
					length = 0;
				}
			}
			if(length>=n) {
				allCons.add(new Cons(str.substring(start, start+length), start, length));
			}
			Cons cur,last=null;
			long result = 0;
			for(int j=0; j<allCons.size(); j++) {
				cur = allCons.get(j);

				int from,to;
				if(last== null) {
					from = 0;
					to = str.length() - 1;
				} else {
					from = last.start+last.length-1-(n-2);
					to = str.length() - 1;
				}
				for(int k=n; k<cur.length; k++) {
					result += (cur.start-from + to -(cur.start+cur.length-1));
					result += (cur.length-k+1);
				}
				result += (cur.start-from+1)*(to-(cur.start+cur.length-1)+1);
				last = cur;
			}
			String line ="Case #" + i + ": " + result;
			System.out.println(line);

			bw.write(line);
			bw.newLine();
			//System.out.println();
		}
		bw.close();
	}
	
	private static boolean isCons(char c) {
		// TODO Auto-generated method stub
		if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u') {
			return false;
		}
		return true;
	}

	private static class Cons {
		public Cons(String conStr, int start, int length) {
			this.conStr = conStr;
			this.start = start;
			this.length = length;
		}
		String conStr;
		int start;
		int length;
		public String toString() {
			return conStr + " " + start + " " + length;
		}
	}
}
