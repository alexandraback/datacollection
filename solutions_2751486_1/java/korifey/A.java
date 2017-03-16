package gcj2013.round1c;


import java.util.*;
import java.math.*;
import org.korifey.ffalg.*;

import common.AbstractRunner;

public class A extends AbstractRunner {
		
	
	@Override
	public void handleCase(int caseNumber) throws Exception {				
		String[] ss = scanner.nextLine().split(" ");
		String s = ss[0];
		int n = Integer.parseInt(ss[1].trim());
		int curContin = 0, lastMatch = -1;
		long res = 0;
		for (int i=0; i<s.length(); i++) {
			int r = 0;
			if ("aeiou".indexOf(s.charAt(i)) >= 0) {
				curContin = 0;
				if (lastMatch >= 0) r = lastMatch - n + 2;  
			} else {
				curContin++;
				if (curContin >= n) {
					lastMatch = i;
				}
				if (lastMatch >= 0) r = lastMatch - n + 2;
			}
			res =  res + r;
		}
		
		out.write(res+"\n");
	}
	
	public static void main(String[] args) throws Exception {
		new A().init(SIZE.large).execute();
	}
}

