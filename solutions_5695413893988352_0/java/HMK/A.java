package round2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;

public class A {
	
	public static void main(String[] args) throws FileNotFoundException{
		FasterScanner in = new FasterScanner();
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		int T = in.nextInt();
		int[] magic = {0,2,4,6,7,8,3,5,1,9};
		for(int t=1;t<=T;t++){
			String[] s = in.nextLine().split(" ");
			int i = 0;
			String[] ans = new String[2];
			ans[0]="";
			ans[1]="";
			while(i<s[0].length()){
				if(s[0].charAt(i)!='?' && s[1].charAt(i)!='?'){
					if(s[0].charAt(i)!=s[1].charAt(i)){
						break;
								
					}
					else{
						ans[0]+=s[0].charAt(i);
						ans[1]+=s[1].charAt(i);
					}
				}
				else{
					if(s[0].charAt(i)=='?' && s[1].charAt(i)=='?'){
						ans[0]+="0";
						ans[1]+="0";
					}
					else if(s[0].charAt(i)=='?'){
						ans[0]+=s[1].charAt(i);
						ans[1]+=s[1].charAt(i);
					}
					else if(s[1].charAt(i)=='?'){
						ans[0]+=s[0].charAt(i);
						ans[1]+=s[0].charAt(i);
					}
				}
				i++;
			}
			if(i<s[0].length()){
				int large = 0;
				if(s[0].charAt(i)<s[1].charAt(i)){
					large = 1;
				}
				int small = 1-large;
				ans[0]+=s[0].charAt(i);
				ans[1]+=s[1].charAt(i);
				i++;
				while(i<s[0].length()){
					if(s[large].charAt(i)=='?' && s[small].charAt(i)=='?'){
						ans[large]+='0';
						ans[small]+='9';
					}
					else if(s[large].charAt(i)=='?'){
						ans[large]+='0';
						ans[small]+=s[small].charAt(i);
					}
					else if(s[small].charAt(i)=='?'){
						ans[large]+=s[large].charAt(i);
						ans[small]+='9';
					}
					else{
						ans[small]+=s[small].charAt(i);
						ans[large]+=s[large].charAt(i);
					}
					i++;
				}
				out.println("Case #"+t+": "+ans[0]+" "+ans[1]);
			}
			else{
				out.println("Case #"+t+": "+ans[0]+" "+ans[1]);
			}
		}
		out.close();
	}
	
	static class FasterScanner {

	    private byte[] buf = new byte[1024];
	    private int curChar;
	    private int numChars;

	    public int read() {
	        if (numChars == -1) {
	            throw new InputMismatchException();
	        }
	        if (curChar >= numChars) {
	            curChar = 0;
	            try {
	                numChars = System.in.read(buf);
	            } catch (IOException e) {
	                throw new InputMismatchException();
	            }
	            if (numChars <= 0) {
	                return -1;
	            }
	        }
	        return buf[curChar++];
	    }

	    public String nextLine() {
	        int c = read();
	        while (isSpaceChar(c)) {
	            c = read();
	        }
	        StringBuilder res = new StringBuilder();
	        do {
	            res.appendCodePoint(c);
	            c = read();
	        } while (!isEndOfLine(c));
	        return res.toString();
	    }

	    public String nextString() {
	        int c = read();
	        while (isSpaceChar(c)) {
	            c = read();
	        }
	        StringBuilder res = new StringBuilder();
	        do {
	            res.appendCodePoint(c);
	            c = read();
	        } while (!isSpaceChar(c));
	        return res.toString();
	    }

	    public long nextLong() {
	        int c = read();
	        while (isSpaceChar(c)) {
	            c = read();
	        }
	        int sgn = 1;
	        if (c == '-') {
	            sgn = -1;
	            c = read();
	        }
	        long res = 0;
	        do {
	            if (c < '0' || c > '9') {
	                throw new InputMismatchException();
	            }
	            res *= 10;
	            res += c - '0';
	            c = read();
	        } while (!isSpaceChar(c));
	        return res * sgn;
	    }

	    public int nextInt() {
	        int c = read();
	        while (isSpaceChar(c)) {
	            c = read();
	        }
	        int sgn = 1;
	        if (c == '-') {
	            sgn = -1;
	            c = read();
	        }
	        int res = 0;
	        do {
	            if (c < '0' || c > '9') {
	                throw new InputMismatchException();
	            }
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
