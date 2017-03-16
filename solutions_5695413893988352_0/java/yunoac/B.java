package R1B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
		
	private static Scanner reader;
	private static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			writer.printf("Case #%d: ", tc);
			char[] s1 = reader.next().toCharArray();
			char[] s2 = reader.next().toCharArray();
			
			int[] d1 = new int[s1.length];
			for(int i = 0; i < s1.length; i++) {
				d1[i] = Character.getNumericValue(s1[i]);
			}
			
			int[] d2 = new int[s2.length];
			for(int i = 0; i < s2.length; i++) {
				d2[i] = Character.getNumericValue(s2[i]);
			}
			
			best = Integer.MAX_VALUE;
			bestv1 = -1;
			bestv2 = -1;
			
			brute(0, 0, d1, d2);
			
			writer.println(toStr(b1) + " " + toStr(b2));
		}
		reader.close();
		writer.close();
	}
	
	static void solve(int[] s1, int[] s2) {

		for(int i = 0; i < s1.length; i++) {
			if(s1[i] == s2[i] && s2[i] == '?') {
				if(i == 0) {
					s1[i] = s2[i] = '0';						
				} else {
					if(s1[i - 1] == s2[i - 1]) {
						s1[i] = s2[i] = '0';
					} else {
						int x = s1[i - 1];
						int y = s2[i - 1];
						if(x < y) {
							s1[i] = '9';
							s2[i] = '0';
						} else {
							s2[i] = '9';
							s1[i] = '0';
						}
					}
				}
			} else if(s1[i] == '?') {
				s1[i] = s2[i];
			} else if(s2[i] == '?') {
				s2[i] = s1[i];
			}
		}
	}
	
	static int best, bestv1, bestv2;
	static int[] b1, b2;
	
	static void brute(int i, int j, int[] s1, int[] s2) {
		if(i < s1.length) {
			
			if(s1[i] != -1) {
				brute(i + 1, j, s1, s2);
			} else {
				for(int d = 0; d <= 9; d++) {
					s1[i] = d;
					brute(i + 1, j, s1, s2);
					s1[i] = -1;
				}
			}
			
		} else if(j < s2.length) {
			
			if(s2[j] != -1) {
				brute(i, j + 1, s1, s2);
			} else {
				for(int d = 0; d <= 9; d++) {
					s2[j] = d;
					brute(i, j + 1, s1, s2);
					s2[j] = -1;
				}
			}
			
		} else {
			String x1 = toStr(s1);
			String x2 = toStr(s2);
			int v1 = Integer.parseInt(x1);
			int v2 = Integer.parseInt(x2);
			int delta = Math.abs(v1 - v2);
			
			if(v1 == 23 && v2 == 23) {
				System.out.println(v1 + " " + v2);
				
			}
			
			if(delta < best) {
				best = delta;
				bestv1 = v1;
				bestv2 = v2;
				b1 = Arrays.copyOf(s1, s1.length);
				b2 = Arrays.copyOf(s2, s2.length);
				
			} else if(delta == best) {
				if(bestv1 > v1) {
					bestv1 = v1;
					bestv2 = v2;
					b1 = Arrays.copyOf(s1, s1.length);
					b2 = Arrays.copyOf(s2, s2.length);
					
				} else if(bestv1 == v1 && bestv2 > v2) {
					bestv1 = v1;
					bestv2 = v2;
					b1 = Arrays.copyOf(s1, s1.length);
					b2 = Arrays.copyOf(s2, s2.length);
					
				}
			}
		}
		
	}
	
	static String toStr(char[] c) {
		StringBuilder sb = new StringBuilder();
		for(char x : c) {
			sb.append(x);
		}
		return sb.toString();
	}
	
	static String toStr(int[] c) {
		StringBuilder sb = new StringBuilder();
		for(int x : c) {
			sb.append(x);
		}
		return sb.toString();
	}

}
