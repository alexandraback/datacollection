package codejam2016r1c;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class r_c {
	static int a;
	static int b;
	static int c;
	static int k;
	static int ab2n[] = new int[100];
	static int ac2n[] = new int[100];
	static int bc2n[] = new int[100];
	static ArrayList<Integer> ral = new ArrayList<Integer>();
	static ArrayList<Integer> rbl = new ArrayList<Integer>();
	static ArrayList<Integer> rcl = new ArrayList<Integer>();
	static int resn =0;
	
	static ArrayList<Integer> al = new ArrayList<Integer>();
	static ArrayList<Integer> bl = new ArrayList<Integer>();
	static ArrayList<Integer> cl = new ArrayList<Integer>();
	
	static void recur_do (int ai, int bi, int ci, int n) {
		while (true) {
			int iab=ai+bi*10;
			int iac=ai+ci*10;
			int ibc=bi+ci*10;
			if (ab2n[iab]==k || ac2n[iac]==k || bc2n[ibc]==k) {
				ci++;
				int inc = ci/c;
				ci%=c;
				bi+=inc;
				inc = bi/b;
				bi%=b;
				ai+=inc;
				inc = ai/a;
				if (inc==1) break;
				continue;
			}

			al.add(ai);
			bl.add(bi);
			cl.add(ci);
			n++;
			
			ab2n[iab]++;
			ac2n[iac]++;
			bc2n[ibc]++;
			
			
			ci++;
			int inc = ci/c;
			ci%=c;
			bi+=inc;
			inc = bi/b;
			bi%=b;
			ai+=inc;
			inc = ai/a;
			if (inc==1) {
				if (n > resn) {
					resn = n;
					ral.clear();
					ral.addAll(al);
					rbl.clear();
					rbl.addAll(bl);
					rcl.clear();
					rcl.addAll(cl);
				}
				ab2n[iab]--;
				ac2n[iac]--;
				bc2n[ibc]--;
				al.remove(al.size()-1);
				bl.remove(bl.size()-1);
				cl.remove(cl.size()-1);
				break;
			}
			
			
			recur_do(ai, bi, ci, n);
			ab2n[iab]--;
			ac2n[iac]--;
			bc2n[ibc]--;
			n--;
			al.remove(al.size()-1);
			bl.remove(bl.size()-1);
			cl.remove(cl.size()-1);
		}

		if (n > resn) {
			resn = n;
			ral.clear();
			ral.addAll(al);
			rbl.clear();
			rbl.addAll(bl);
			rcl.clear();
			rcl.addAll(cl);
		}
	}
	static String doit() {
		recur_do(0, 0, 0, 0);
		
		StringBuilder sb = new StringBuilder();
		for (int i=0;i<ral.size();i++) {
			sb.append('\n');
			sb.append(ral.get(i)+1);
			sb.append(' ');
			sb.append(rbl.get(i)+1);
			sb.append(' ');
			sb.append(rcl.get(i)+1);
		}
		return resn + sb.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/in.txt"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			resn=0;
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			k = sc.nextInt();
			pw.printf("Case #%d: %s\n", casei+1, doit());
		}
		sc.close();
		pw.close();
	}
}
