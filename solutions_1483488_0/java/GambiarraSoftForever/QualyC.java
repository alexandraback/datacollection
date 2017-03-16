package google2012.qualy;

import java.io.*;
import java.util.*;

import org.apache.commons.io.FileUtils;

public class QualyC {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("2012/qualy/c/C-small-attempt0.in"));
		int N = sc.nextInt();
		StringBuffer resposta = new StringBuffer();
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int res = 0;
			for (int n = a; n <= b; n++) {
				char num[] = Integer.toString(n).toCharArray();
				//StringBuffer buf = new StringBuffer();
				int prim = num[0];
				int j=1;
				for (; j < num.length; j++) if(num[j]!=prim) break;
				if(j==num.length) continue;
				int f = num[num.length-1]!='0' ? num.length:num.length-1;
				Set<Integer> set = new HashSet<Integer>();
				for (j=0; j < f; j++) {
					StringBuffer buf = new StringBuffer();
					for (int k = j+1; k < num.length; k++) {
						buf.append(num[k]);
					}
					for (int k = 0; k <= j; k++) {
						buf.append(num[k]);
					}
					int t = Integer.parseInt(buf.toString());
					if (t>n && t<=b) set.add(t);
				}
				res += set.size();
			}
			String out = "Case #"+(i+1)+": "+res+"\n";
			System.out.println(out);
			resposta.append(out);
		}
		FileUtils.writeStringToFile(new File("2012/qualy/c/C-small-attempt0.out"), resposta.toString());
		System.exit(0);
	}
}
