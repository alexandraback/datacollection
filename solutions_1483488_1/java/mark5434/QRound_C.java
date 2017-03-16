package google2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Scanner;

public class QRound_C {
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("d:/in.txt"));
			int i=0;
			while (true) {
				String x = br.readLine();
				if (x==null) break;
				if (i!=0)
					run (x, i);
				i++;
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static private void run(String input, int caseid) {
		int res=0;
		Scanner sc =new Scanner(input);
		int a=sc.nextInt();
		int b=sc.nextInt();
		for (int i=a;i<=b;i++) {
			res+=sol(i,b);
		}
		System.out.printf("Case #%d: %d%n", caseid, res);
	}
	static private int sol(int num, int max) {
		String ii=((Integer)num).toString();
		HashSet<Integer> counted =new HashSet<Integer>();
		int r=0;
		for (int i=0;i<ii.length();i++) {
			StringBuilder sb = new StringBuilder();
			for (int j=i;j<i+ii.length();j++) {
				sb.append(ii.charAt(j%ii.length()));
			}
			if (sb.charAt(0)=='0') continue;
			int xx=Integer.parseInt(sb.toString());
			if (xx<=max&&xx>num&&!counted.contains(xx)) {
				counted.add(xx);
				r++;
			}
		}
		return r;
	}
}