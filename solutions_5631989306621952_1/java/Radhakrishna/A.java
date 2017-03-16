package org.rk.onea;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {
	public void solve(String in) throws Exception {
		Scanner sc = new Scanner(new File(in));
		int N = sc.nextInt();
		for(int i=0;i<N;i++) {
			String s = sc.next();
			String o = "";
			o += s.charAt(0);
			for(int j=1;j<s.length();j++) {
				if(o.charAt(0) > s.charAt(j)) {
					o += s.charAt(j);
				} else {
					o = s.charAt(j) + o;
				}
			}
			System.out.println("Case #"+(i+1)+": "+o);
		}
		sc.close();
	}
}
