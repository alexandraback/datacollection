
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

public class Codejam_CloseMatch {
	public static void main(String args[]) throws FileNotFoundException{
		FasterScanner s=new FasterScanner();
		PrintWriter out = new PrintWriter("/home/paresh/Desktop/output");
		int t=s.nextInt();
		int l=1;
		while(t-->0){
			String s1[]=s.nextLine().split(" ");
			char C[]=s1[0].toCharArray();
			char J[]=s1[1].toCharArray();
			boolean b1=false,b2=false;
			int i=0;
			long max=Long.MAX_VALUE;
			String p11="";
			String p12="";
			for(i=0;i<s1[0].length();i++){
				//System.out.println(new String(C)+" "+i);
				if(C[i]=='?' && J[i]=='?'){
					String s11="";
					String s12="";
					for(int j=i;j<s1[0].length();j++){
						if(j==i){
							s11+='0';
							s12+='1';
						}
						else{
							if(C[j]=='?')
								s11+='9';
							else
								s11+=C[j];
							if(J[j]=='?')
								s12+='0';
							else
								s12+=J[j];	
						}
					}
					long k=Math.abs(Long.parseLong(s11)-Long.parseLong(s12));
					if(k<max){
						p11=s11;
						p12=s12;
						max=k;
					}
					if(k==max){
						int k1=p11.compareTo(s11);
						if(k1==1){
							p11=s11;
							p12=s12;
						}
						if(k1==0){
							int k2=p12.compareTo(s12);
							if(k2==1){
								p11=s11;
								p12=s12;
							}
						}
					}
					s11="";
					s12="";
					for(int j=i;j<s1[0].length();j++){
						if(j==i){
							s11+='1';
							s12+='0';
						}
						else{
							if(C[j]=='?')
								s11+='0';
							else
								s11+=C[j];
							if(J[j]=='?')
								s12+='9';
							else
								s12+=J[j];	
						}
					}
					k=Math.abs(Long.parseLong(s11)-Long.parseLong(s12));
					if(k<max){
						p11=s11;
						p12=s12;
						max=k;
					}
					if(k==max){
						int k1=p11.compareTo(s11);
						if(k1==1){
							p11=s11;
							p12=s12;
						}
						if(k1==0){
							int k2=p12.compareTo(s12);
							if(k2==1){
								p11=s11;
								p12=s12;
							}
						}
					}
					C[i]='0';
					J[i]='0';
				}
				else if(C[i]=='?'){
					C[i]=J[i];
				}
				else if(J[i]=='?')
					J[i]=C[i];
				else if(C[i]!=J[i]){
					String s11="";
					String s12="";
					long k;
					if(i==s1[0].length()-1){
						//System.out.println("hi");
						s11=new String(C);
						s12=new String(J);
						//System.out.println(s11+" "+s12);
						int k1=p11.compareTo(s11);
						if(k1==1){
							p11=s11;
							p12=s12;
						}
						if(k1==0){
							int k2=p12.compareTo(s12);
							if(k2==1){
								p11=s11;
								p12=s12;
							}
						}
					}
					if(C[i]<J[i]){
						for(int j=i;j<s1[0].length();j++){
							if(j==i){
								s11+=C[j];
								s12+=J[j];
							}
							else{
								if(C[j]=='?')
									s11+='9';
								else
									s11+=C[j];
								if(J[j]=='?')
									s12+='0';
								else
									s12+=J[j];	
							}
						}
						//System.out.println(s11+" "+s12);
						k=Long.parseLong(s11)-Long.parseLong(s12);
						if(k<max){
							p11=s11;
							p12=s12;
							max=k;
						}
						if(k==max){
							int k1=p11.compareTo(s11);
							if(k1==1){
								p11=s11;
								p12=s12;
							}
							if(k1==0){
								int k2=p12.compareTo(s12);
								if(k2==1){
									p11=s11;
									p12=s12;
								}
							}
						}
					}
					else{
						s11="";
						s12="";
						for(int j=i;j<s1[0].length();j++){
							if(j==i){
								s11+=C[j];
								s12+=J[j];
							}
							else{
								if(C[j]=='?')
									s11+='0';
								else
									s11+=C[j];
								if(J[j]=='?')
									s12+='9';
								else
									s12+=J[j];	
							}
						}
						k=Long.parseLong(s11)-Long.parseLong(s12);
						if(k<max){
							p11=s11;
							p12=s12;
						}
						if(k==max){
							int k1=p11.compareTo(s11);
							if(k1==1){
								p11=s11;
								p12=s12;
							}
							if(k1==0){
								int k2=p12.compareTo(s12);
								if(k2==1){
									p11=s11;
									p12=s12;
								}
							}
						}
					}
					break;
				}
				//System.out.println(C[i]);
			}
			if(i==s1[0].length()){
				//System.out.println("hi");
				String s11=new String(C);
				String s12=new String(J);
				//System.out.println(s11+" "+s12);
				int k1=p11.compareTo(s11);
				if(k1==1){
					p11=s11;
					p12=s12;
				}
				if(k1==0){
					int k2=p12.compareTo(s12);
					if(k2==1){
						p11=s11;
						p12=s12;
					}
				}
			}
			out.print("Case #"+l+": ");
			out.println(p11+" "+p12);
			l++;
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