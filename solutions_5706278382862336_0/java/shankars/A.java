package btest;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class A {
	private static String[] list;
	public static void main(String args[]) throws FileNotFoundException {
		File f = new File("A-small-attempt0.in");
		Scanner sc = new Scanner(new FileInputStream(f));
		int t = sc.nextInt(); sc.nextLine();
		for(int ii=0;ii<t;++ii) {
			String str = sc.nextLine();
			String[] longs = str.split("/");
			long p = Long.parseLong(longs[0]);
			long q = Long.parseLong(longs[1]);
			System.out.print("Case #"+ (ii+1) + ": ");
			int cnt = 0; boolean impossible = false;
			long g = GCD(p,q);
			p /= g ; q /= g;
			if((q & (q - 1)) != 0) {
				impossible = true;
			} else {
				do { 
					p *= 2 ; 
					++cnt;
				} while( cnt < 40 && (p < q));
				if(cnt >= 40) impossible = true; 
			}
				
			if(impossible) {
				System.out.println("impossible");
			} else {
				System.out.println(cnt);
			}
		}
		sc.close();
		
	}
	public static long GCD(long a, long b) { return b==0 ? a : GCD(b, a%b); }

	
	private static void solve() {
		if(list.length > 1) {
			StringBuilder sb = new StringBuilder("");
			char last = (char) (list[0].charAt(0) + 1);
			for(int j=0;j<list[0].length();++j) {
				if(list[0].charAt(j) != last ) {
					last = list[0].charAt(j);
					sb.append(last);
				}
			}
			String compresd = sb.toString();
			//System.out.println("\n" + compresd);

			int[][] maxc = new int[list.length][compresd.length()];
			for(int i=0;i<list.length;++i)
				Arrays.fill(maxc[i],0);

			boolean impossible = false;
			for(int i=0;i<list.length;++i) {
				last = (char) (list[i].charAt(0) + 1);
				int cnt = 0;
				for(int j=0,cind = 0;j<=list[i].length();++j) {
					if(j >= list[i].length() || list[i].charAt(j) != last) {
						if(cind > 0)
							maxc[i][cind - 1] = cnt;
						if(( j < list[i].length() ^ cind < compresd.length()) || (cind < compresd.length() && list[i].charAt(j) != compresd.charAt(cind))) {
							impossible = true;
							break;
						}
						if(list[i].length() <= j)
							break;
						last = list[i].charAt(j);
						cind ++ ;
						cnt = 0;
					} 
					++cnt;
				}
				if(impossible) 
					break;
			}
			
			/*
			System.out.println("");
			for(int i=0;i<maxc.length;++i) {
				for(int j=0;j<maxc[i].length;++j)
					System.out.print(maxc[i][j] + " ");
				System.out.println("");
			}*/
			
			if(!impossible) {
				int total = 0;
				for(int i=0;i<maxc[0].length;++i) {
					int least = Integer.MAX_VALUE;
					for(int j=0;j<maxc.length;++j) {
						int c = 0;
						for(int k = 0; k<maxc.length;++k) {
							c +=  Math.abs(maxc[j][i] - maxc[k][i]);
						}
						least = Math.min(c, least);
					}
					//System.out.println("least " + compresd.charAt(i) + " " + least);
					total += least;
				}
				System.out.println(total);
			} else {
				System.out.println("Fegla Won");
			}
		} else {
			System.out.println("0");
		}
	}
}
