package org.digiharbor.gene;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Console;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CJ2012 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		new CJ2012();
	}
	public CJ2012() throws FileNotFoundException, IOException {
		BufferedReader sysin = new BufferedReader(new InputStreamReader(System.in));

		String stage = "Qual";
		System.out.printf("Stage %s Problem to run: (ae, a0, a1, al, be...): ", stage);
		String cmd = sysin.readLine().toUpperCase().trim();
		char problem = cmd.charAt(0);
		String fname = "";
		if (cmd.charAt(1) == 'E')
			fname = stage + "/" + problem + "-example";
		else if (cmd.charAt(1) == 'L')
			fname = stage + "/" + problem + "-large";
		else
			fname = stage + "/" + problem + "-small-attempt" + cmd.charAt(1);

		String inf = fname + ".in";
		String outf = fname + ".out";
		BufferedReader f = new BufferedReader(new FileReader(inf));
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));
		int cnt = Integer.parseInt(f.readLine());

		long start = System.currentTimeMillis();
		System.out.printf("Running %s => %s ...", inf, outf);
		switch (problem) {
		case 'A':
			new A_SpeakingInTongues(cnt, f, out);
			break;
		case 'B':
			new B_DancingWithTheGooglers(cnt, f, out);
			break;
		case 'C':
			new C_RecycledNumbers(cnt, f, out);
			break;
		case 'D':
			new D_HallOfMirrors(cnt, f, out);
			break;
		}
		long finish = System.currentTimeMillis();
		System.out.printf(" %dmsec", finish - start);
		f.close();
		out.close();
	}

	class A_SpeakingInTongues {
		public A_SpeakingInTongues(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			String key = "yhesocvxduiglbkrztnwjpfmaq";
			for (int i = 0; i < cnt; i++) {
				String ln = infile.readLine();
				String res = "";
				for (int p = 0; p < ln.length(); p++) {
					if (ln.charAt(p) == ' ')
						res += ' ';
					else
						res += key.charAt(ln.charAt(p) - 'a');
				}
				outfile.write(String.format("Case #%d: %s\r\n", i + 1, res));
			}
		}
	}
	class B_DancingWithTheGooglers {
		public B_DancingWithTheGooglers(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			Scanner in = new Scanner(infile);
			for (int i = 0; i < cnt; i++) {
				int nGoog = in.nextInt();
				int nSurprise = in.nextInt();
				int best = in.nextInt();

				int bestcnt = 0;
				int surprises = 0;
				int surescore = best * 3 - 2;  // i.e. >=22 ensures a best of 8 (8,7,7)
				if (surescore < 0)
					surescore = 0;
				int surprisescore = surescore - 2;  // i.e. 20,21 could get an 8 with a surprise (8,7,6) (8,6,6)
				if (surprisescore < 0)
					surprisescore = 0;
				for (int j = 0; j < nGoog; j++) {
					int total = in.nextInt();
					if (total >= best && total >= surescore)
						bestcnt++;
					else if (total >= best && total >= surprisescore)
						surprises++;
				}
				int res = bestcnt + (nSurprise >= surprises ? surprises : nSurprise);
				outfile.write(String.format("Case #%d: %d\r\n", i + 1, res));
			}
		}
	}
	class C_RecycledNumbers {
		public C_RecycledNumbers(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int a = Integer.parseInt(ln[0]);
				int b = Integer.parseInt(ln[1]);
				int len = ln[0].length();
				int rescnt = 0;
				String[] rvals = new String[len];
				int rvc;
				for (int v = a; v <= b; v++) {
					String val = Integer.toString(v);
					if (val.length() < len)
						val = "0000000000".substring(0, len - val.length()) + val;
					rvc = 0;
					for (int r = 1; r < len; r++) {
						String rval = val.substring(len - r) + val.substring(0, len - r);
						int rv = Integer.parseInt(rval);
						if (rv > v && rv <= b) {
							boolean isnew = true;
							for (int k = 0; k < rvc; k++)
								if (rvals[k].equals(rval))
									isnew = false;
							if (isnew) {
								rvals[rvc++] = rval;
								rescnt++;
							} 
//							else
//								for (int k = 0; k < rvc; k++) {
//									outfile.write(String.format("%s <= %s < %s <= %s\r\n", ln[0], val, rval, ln[1]));
//								}
						}
					}
				}
				outfile.write(String.format("Case #%d: %d\r\n", i + 1, rescnt));
			}
		}
	}
	class D_HallOfMirrors {
		public D_HallOfMirrors(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {

		}
	}
}
