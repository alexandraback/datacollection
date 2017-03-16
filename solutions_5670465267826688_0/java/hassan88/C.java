import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("C-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("C-small.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim()), L, X;
		for (int c = 1; c <= cases; c++) {
			st = new StringTokenizer(br.readLine());
			L = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			StringBuffer inp = new StringBuffer(br.readLine().trim()), input = new StringBuffer("");
			for(int i = 0;i < X;i++)
				input = input.append(inp);
			out.println("Case #" + c + ": " + solve(input.toString().toCharArray()));
		}
		out.close();
	}
	public static String solve(char [] arr) {
		char [] suffix = arr.clone();
		boolean [] suffixSign = new boolean[suffix.length];
		suffix[suffix.length-1] = arr[arr.length-1];
		for(int i = arr.length-2;i >= 0;i--) {
			if(signChange(suffix[i], suffix[i+1]))
				suffixSign[i] = !suffixSign[i+1];
			else
				suffixSign[i] = suffixSign[i+1];
			suffix[i] = multiply(suffix[i], suffix[i+1]);
		}
		char start = '1';
		boolean sign = false;
		for(int i = 0;i < arr.length;i++) {
			if(signChange(start, arr[i]))
				sign = !sign;
			start = multiply(start, arr[i]);
			if(start == 'i' && !sign) {
				char start2 = '1';
				boolean sign2 = false;
				for(int j = i+1;j < arr.length-1;j++) {
					if(signChange(start2, arr[j]))
						sign2 = !sign2;
					start2 = multiply(start2, arr[j]);
					if(start2 == 'j' && suffix[j+1] == 'k' && !suffixSign[j+1] && !sign2) {
						return "YES";
					}
				}
			}
		}
		return "NO";
	}
	public static char multiply(char a1, char a2) {
		if(a1 == '1')return a2;
		if(a1 == a2) return '1';
		if(a2 == '1')return a1;
		if(a1 == 'i')return (a2=='j')?'k':'j';
		if(a1 == 'j')return (a2=='k')?'i':'k';
		return (a2=='i')?'j':'i';
	}
	public static boolean signChange(char a1, char a2) {
		return ( (a1 == a2) || (a1 == 'i' && a2 == 'k') || (a1 == 'j' && a2 == 'i') || (a1 == 'k' && a2 == 'j') );
	}
}