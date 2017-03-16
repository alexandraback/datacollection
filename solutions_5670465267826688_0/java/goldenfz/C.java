package Q2015;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {

	public static void main(String args[]) throws NumberFormatException,
			IOException {
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("C-small-attempt1.out");
		int T = in.readInt();
		int x, l;
		char str[];
		int num[];
		int sign;
		int cur;
		int result;
		ArrayList<Integer> left;
		HashSet<Integer> impossible;
		boolean find;
		for (int i = 1; i <= T; i++) {
			l = in.readInt();
			x = in.readInt();
			str = in.readNext().toCharArray();
			num=new int[str.length];
			if(onlyOneLetter(str,num)){
				print(out, "NO", i);
				continue;
			}
			left = new ArrayList<Integer>();
			impossible = new HashSet<Integer>();
			find=false;
			cur = 1;
			sign = 1;
			for (int j = 0; j < l* x - 1; j++) {
				result = cal(cur, num[j % l]);
				if(result<0){
					sign*=-1;
					result*=-1;
				}
				cur=result;
			    if (sign == 1 && cur ==2)
						left.add(j);
			}
			if (left.isEmpty()) {
				print(out, "NO", i);
				continue;
			}
			for (int s =0; s <left.size(); s++) {
				cur = 1;
				sign = 1;
				for (int j =left.get(s)+1; j < l * x-1; j++) {
					result = cal(cur, num[j % l]);
					if(result<0){
						sign*=-1;
						result*=-1;
					}
					cur=result;
					if (sign == 1 && cur == 3&&!impossible.contains(j+1)){
						cur=1;
						for(int k=j+1;k<l*x;k++){
							result = cal(cur, num[k % l]);
							if(result<0){
								sign*=-1;
								result*=-1;
							}
							cur=result;
						}
						if(sign==1&&cur==4){
							find=true;
							break;
						}else{
							impossible.add(j+1);
						}
						cur=3;
						sign=1;
					}
				}
				if(find)
					break;
				
			}
			if(find){
				print(out, "YES", i);
			}else
				print(out, "NO", i);
			
		}
		out.flush();
		out.close();

	}
	private static boolean onlyOneLetter(char str[],int num[]){
		num[0]=str[0]-'i'+2;
		boolean diff=true;
		for(int i=1;i<str.length;i++){
			num[i]=str[i]-'i'+2;
			if(str[i]!=str[0])
				diff=false;
		}
		return diff;
	}
	private static void print(PrintWriter out, Object t, int cases) {
		out.println("Case #" + cases + ": " + t);
	}

	private static int cal(int i, int j) {
		if (i == j)
			return -1;
		if (i == 1)
			return j;
		if (j == 1)
			return i;
		if (i == 2)
			return j == 3 ? 4 : -3;
		if (i == 3)
			return j == 2 ? -4 : 2;
		return j == 2 ? 3 : -2;
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("C-small-attempt1.in"));

		}

		private String readNext() throws IOException {

			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		private int readInt() throws IOException, NumberFormatException {

			return Integer.parseInt(readNext());

		}

		private long readLong() throws IOException, NumberFormatException {

			return Long.parseLong(readNext());

		}

		private double readDouble() throws IOException, NumberFormatException {

			return Double.parseDouble(readNext());

		}
	}
}
