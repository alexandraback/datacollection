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
			String s = in.nextLine();
			int[] f = new int[26];
			for(int i = 0;i<s.length();i++){
				f[s.charAt(i)-'A']++;
			}
			//System.out.println(Arrays.toString(f));
			HashMap<Integer, String> h = new HashMap<>();
			h.put(0, "zero");
			h.put(1, "one");
			h.put(2, "two");
			h.put(3,"three");
			h.put(4, "four");
			h.put(5, "five");
			h.put(6, "six");
			h.put(7, "seven");
			h.put(8, "eight");
			h.put(9, "nine");
			HashMap<Integer, Character> h2 = new HashMap<>();
			h2.put(0, 'z');
			h2.put(1, 'o');
			h2.put(2, 'w');
			h2.put(3, 'h');
			h2.put(4, 'u');
			h2.put(5, 'v');
			h2.put(6, 'x');
			h2.put(7, 's');
			h2.put(8, 'g');
			h2.put(9, 'n');
			int[] d = new int[10];
			for(int i= 0;i<10;i++){
				while(f[h2.get(magic[i])-'a']>0){
			//		System.out.println("here");
					String temp = h.get(magic[i]);
					for(int j = 0;j<temp.length();j++){
						f[temp.charAt(j)-'a']--;
					}
					d[magic[i]]++;
				}
			}
			
			StringBuilder ans = new StringBuilder();
			for(int i = 0;i<10;i++){
				while(d[i]>0){
					ans.append(i);
					d[i]--;
				}
			}
			out.println("Case #"+t+": "+ans);
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
