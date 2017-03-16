package google2012;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

public class QRound_B {
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
		int n=sc.nextInt();
		int s=sc.nextInt();
		int p=sc.nextInt();
		if (p>0) {
			for (int i=0;i<n;i++) {
				int now=sc.nextInt();
				if (now<p) continue;
				if (now>=3*p-2) res++;
				else if (s>0) {s--;res++;}
			}
		}
		else {
			res=n;
		}
		System.out.printf("Case #%d: %d%n", caseid, res);
	}
}