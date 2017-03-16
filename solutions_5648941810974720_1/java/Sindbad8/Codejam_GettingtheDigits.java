
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;

public class Codejam_GettingtheDigits {
	public static void main(String args[]){
		FasterScanner s=new FasterScanner();
		PrintWriter out = null;
		try {
			out = new PrintWriter("/home/paresh/Desktop/output");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int t=s.nextInt();
		int l=1;
		while(t-->0){
			String s1=s.nextLine();
			int a[]=new int[26];
			for(int i=0;i<s1.length();i++)
				a[s1.charAt(i)-'A']++;
			int ans[]=new int[10];
			ans[0]=a[25];
			a[25]=0;
			a[4]-=ans[0];
			a['R'-'A']-=ans[0];
			a['O'-'A']-=ans[0];
			ans[4]=a['U'-'A'];
			a['U'-'A']=0;
			a['F'-'A']-=ans[4];
			a['O'-'A']-=ans[4];
			a['R'-'A']-=ans[4];
			ans[8]=a['G'-'A'];
			a['G'-'A']=0;
			a['I'-'A']-=ans[8];
			a['E'-'A']-=ans[8];
			a['H'-'A']-=ans[8];
			a['T'-'A']-=ans[8];
			ans[6]=a['X'-'A'];
			a['X'-'A']=0;
			a['I'-'A']-=ans[6];
			a['S'-'A']-=ans[6];
			ans[5]=a['F'-'A'];
			a['F'-'A']=0;
			a['I'-'A']-=ans[5];
			a['V'-'A']-=ans[5];
			a['E'-'A']-=ans[5];
			ans[9]=a['I'-'A'];
			a['I'-'A']=0;
			a['N'-'A']-=2*ans[9];
			a['E'-'A']-=ans[9];
			ans[2]=a['W'-'A'];
			a['W'-'A']=0;
			a['T'-'A']-=ans[2];
			a['O'-'A']-=ans[2];
			ans[1]=a['O'-'A'];
			a['O'-'A']=0;
			a['N'-'A']-=ans[1];
			a['E'-'A']-=ans[1];
			ans[3]=a['R'-'A'];
			ans[7]=a['S'-'A'];
			out.print("Case #"+l+": ");
			for(int i=0;i<10;i++)
				for(int j=0;j<ans[i];j++)
				out.print(i);
			l++;
			out.println();
		}
		out.close();
	}
	public static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int snumChars;
		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}