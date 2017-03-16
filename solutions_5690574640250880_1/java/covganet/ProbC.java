import java.io.*;
import java.util.*;

public class ProbC {
	static PrintWriter pw = null;
	
	public static final char STAR = '*', DOT = '.', INITIAL = 'c';
	public static final String IMPOSSIBLE = "Impossible";
	
	public static void main(String[] args) throws Exception {
	  BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
	  pw = new PrintWriter(new FileWriter("outC.txt"));
	  int nrTests = Integer.parseInt(br.readLine());
	  for(int test = 1; test <= nrTests; test++) {
	  	String[] strs = br.readLine().split(" ");
	  	int R = Integer.parseInt(strs[0]);
	  	int C = Integer.parseInt(strs[1]);
	  	int M = Integer.parseInt(strs[2]);
	  	
	  	writeOut(test);
	  	
	  	if(M == 0) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, DOT);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	
	  	if(M == R * C - 1) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, STAR);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	
	  	if(R == 1 || C == 1) {
	  		int nrm = 0, nrl = R * C - M - 1;
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			for(int j = 0; j < chr.length; j++) {
	  				if(nrm < M) {
	  					chr[j] = STAR;
	  					nrm++;
	  				} else if(nrl > 0) {
	  					chr[j] = DOT;
	  					nrl--;
	  				} else {
	  					chr[j] = INITIAL;
	  				}
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	
	  	if(R == 2 || C == 2) {
	  		if(M % 2 == 1 || M == R * C - 2) {
	  			pw.println(IMPOSSIBLE);
	  			continue;
	  		}
	  		if(R == 2) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			Arrays.fill(chr, DOT);
		  			for(int j = 0; j < M / 2; j++) {
		  				chr[j] = STAR;
		  			}
		  			if(i == 0) {
		  				chr[chr.length - 1] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
	  		} else {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			if(i >= R - M / 2) {
		  				Arrays.fill(chr, STAR);
		  			} else {
		  				Arrays.fill(chr, DOT);
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
	  		}
	  		continue;
	  	}
	  	
	  	// R >= 3 && C >= 3
	  	// go through empty spaces
	  	int nrEmpty = R * C - M;
	  	if(nrEmpty == 4) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, STAR);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  				chr[1] = DOT;
	  			} else if(i == 1) {
	  				chr[0] = chr[1] = DOT;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	if(nrEmpty == 6) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, STAR);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  				chr[1] = DOT;
	  				chr[2] = DOT;
	  			} else if(i == 1) {
	  				chr[0] = chr[1] = chr[2] = DOT;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	if(nrEmpty == 8) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, STAR);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  				chr[1] = DOT;
	  				chr[2] = DOT;
	  			} else if(i == 1) {
	  				chr[0] = chr[1] = chr[2] = DOT;
	  			} else if(i == 2) {
	  				chr[0] = chr[1] = DOT;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	if(nrEmpty == 9) {
	  		for(int i = 0; i < R; i++) {
	  			char[] chr = new char[C];
	  			Arrays.fill(chr, STAR);
	  			if(i == 0) {
	  				chr[0] = INITIAL;
	  				chr[1] = DOT;
	  				chr[2] = DOT;
	  			} else if(i <= 2) {
	  				chr[0] = chr[1] = chr[2] = DOT;
	  			}
	  			pw.println(new String(chr));
	  		}
	  		continue;
	  	}
	  	if(nrEmpty >= 10) {
	  		if(nrEmpty % 2 == 0 && R >= nrEmpty / 2) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			Arrays.fill(chr, STAR);
		  			if(i < nrEmpty / 2) {
		  				chr[0] = chr[1] = DOT;
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
		  		continue;
	  		} else if(nrEmpty % 2 == 0 && C >= nrEmpty / 2) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			Arrays.fill(chr, STAR);
		  			if(i < 2) {
		  				for(int j = 0; j < nrEmpty / 2; j++) {
		  					chr[j] = DOT;
		  				}
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
		  		continue;
	  		} else if(nrEmpty % 2 == 1 && R >= (nrEmpty - 3) / 2) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			Arrays.fill(chr, STAR);
		  			if(i < (nrEmpty - 3) / 2) {
		  				chr[0] = chr[1] = DOT;
		  			}
		  			if(i < 3) {
		  				chr[2] = DOT;
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
		  		continue;
	  		} else if(nrEmpty % 2 == 1 && C >= (nrEmpty - 3) / 2) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			Arrays.fill(chr, STAR);
		  			if(i < 2) {
		  				for(int j = 0; j < (nrEmpty - 3) / 2; j++) {
		  					chr[j] = DOT;
		  				}
		  			}
		  			if(i == 2) {
		  				chr[0] = chr[1] = chr[2] = DOT;
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
		  		continue;
	  		} else if(nrEmpty % C != 1) {
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = new char[C];
		  			if(i * C >= nrEmpty) {
		  				Arrays.fill(chr, STAR);
		  			} else if((i + 1) * C <= nrEmpty) {
		  				Arrays.fill(chr, DOT);
		  			} else {
		  				Arrays.fill(chr, STAR);
		  				for(int j = 0; i * C + j < nrEmpty; j++) {
		  					chr[j] = DOT;
		  				}
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  			pw.println(new String(chr));
		  		}
		  		continue;
	  		} else {
	  			char[][] chrs = new char[R][C];
		  		for(int i = 0; i < R; i++) {
		  			char[] chr = chrs[i];
		  			if(i * C >= nrEmpty) {
		  				Arrays.fill(chr, STAR);
		  			} else if((i + 1) * C <= nrEmpty) {
		  				Arrays.fill(chr, DOT);
		  			} else {
		  				Arrays.fill(chr, STAR);
		  				for(int j = 0; i * C + j < nrEmpty; j++) {
		  					chr[j] = DOT;
		  				}
		  			}
		  			if(i == 0) {
		  				chr[0] = INITIAL;
		  			}
		  		}
		  		chrs[nrEmpty / C - 1][C - 1] = STAR;
		  		chrs[nrEmpty / C][1] = DOT;
		  		for(int i = 0; i < R; i++) {
		  			pw.println(new String(chrs[i]));
		  		}
		  		continue;	  			
	  		}
	  	}
	  	
	  	// now we have nrEmpty either 2, 3, 5 or 7 and R >= 3 and C >= 3
	  	pw.println(IMPOSSIBLE);
	  }
	  
	  pw.close();
  }
	
	static void writeOut(int testNr) {
		pw.println("Case #" + testNr + ":");
	}
}
