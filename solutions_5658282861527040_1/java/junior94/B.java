import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class B {
	
	public static IntReader in = new IntReader();
	public static IntWriter out = new IntWriter();
	
	public static int A, B, K;
	
	public static long[][][][] dp = new long[31][2][2][2];
	
	public static void main(String[] args) {
		final int T = in.readInt();
		
		for(int t=1; t<=T; t++) {
			A = in.readInt();
			B = in.readInt();
			K = in.readInt();
			
			for(int i=0; i<31; i++) {
				for(int j=0; j<2; j++) {
					for(int k=0; k<2; k++) {
						Arrays.fill(dp[i][j][k], -1);
					}
				}
			}
			
			out.printfln("Case #%d: %d", t, dfs(30, false, false, false));
		}
		
		out.close();
	}
	
	public static long dfs(int bit, boolean decA, boolean decB, boolean decK) {
		if(bit < 0) {
			return 1;
		}
		
		int a = decA ? 1 : 0;
		int b = decB ? 1 : 0;
		int k = decK ? 1 : 0;
		
		long res = dp[bit][a][b][k];
		
		if(res > -1) return res;
		
		boolean[] okA = new boolean[2];
		boolean[] okB = new boolean[2];
		boolean[] okK = new boolean[2];
		
		int mask = 1<<bit;
		
		boolean setA = getSet(A, bit);
		boolean setB = getSet(B, bit);
		boolean setK = getSet(K, bit);
		
		okA[0] = decA || bit > 0 || setA;
		okB[0] = decB || bit > 0 || setB;
		okK[0] = decK || bit > 0 || setK;
		
		//out.println(A+" "+bit+" "+setA+" "+okK[0]+" "+okA[0]+" "+okB[0]);
		
		res = 0;
		
		okA[1] = decA || (setA && Integer.lowestOneBit(A) < mask);
		okB[1] = decB || (setB && Integer.lowestOneBit(B) < mask);
		okK[1] = decK || (setK && Integer.lowestOneBit(K) < mask);
		
		for(int ai=0; ai<2; ai++) if(okA[ai]) {
			for(int bi=0; bi<2; bi++) if(okB[bi]) {
				int ki = ai & bi;
				if(!okK[ki]) continue;
				res += dfs(bit-1, decA || (setA && ai==0), decB || (setB && bi==0), decK || (setK && ki==0));
			}
		}
		
		//out.printfln("bit: %d, a: %d, b: %d, k: %d, res: %d", bit, a, b, k, res);
		
		return dp[bit][a][b][k] = res;
	}
	
	public static boolean getSet(int n, int bit) {
		return ((1<<bit) & n) > 0;
	}
}

class IntReader {
	
	private static final int SIZE = 1<<13;
	
	private static InputStream in = System.in;
	
	private int offSet;
	private int bufferSize;
	private byte[] buffer;
	
	private char[] charBuffer;
	
	public IntReader() {
		buffer = new byte[SIZE];
		charBuffer = new char[SIZE];
	}
	
	public int readInt() {
		int number = 0;
		boolean neg = false;
		
		try {
			if(offSet == bufferSize) {
				offSet = 0;
				bufferSize = in.read(buffer);
			}
			
			for(; offSet < bufferSize && buffer[offSet] != '-' && buffer[offSet] < '0'; offSet++) {
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			if(buffer[offSet] == '-') {
				neg = true;
				offSet++;
				if(offSet == bufferSize) {
					offSet = 0;
					bufferSize = in.read(buffer);
				}
			}
			
			for(; offSet < bufferSize && buffer[offSet] >= '0' && buffer[offSet] <= '9'; offSet++) {
				number = number * 10 - '0' + buffer[offSet];
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			offSet++;
		} catch(IOException io) {
			io.printStackTrace();
			System.exit(0);
		}
		
		return neg ? -number : number;
	}
	
	public long readLong() {
		long number = 0;
		boolean neg = false;
		
		try {
			if(offSet == bufferSize) {
				offSet = 0;
				bufferSize = in.read(buffer);
			}
			
			for(; offSet < bufferSize && buffer[offSet] != '-' && buffer[offSet] < '0'; offSet++) {
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			if(buffer[offSet] == '-') {
				neg = true;
				offSet++;
				if(offSet == bufferSize) {
					offSet = 0;
					bufferSize = in.read(buffer);
				}
			}
			
			for(; offSet < bufferSize && buffer[offSet] >= '0' && buffer[offSet] <= '9'; offSet++) {
				number = number * 10 - '0' + buffer[offSet];
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			offSet++;
		} catch(IOException io) {
			io.printStackTrace();
			System.exit(0);
		}
		
		return neg ? -number : number;
	}
	
	public double readDouble() {
		return Double.parseDouble(readWord());
	}
	
	public String readLine() {
		StringBuffer sb = new StringBuffer();
		
		try {
			if(offSet == bufferSize) {
				offSet = 0;
				offSet = in.read(buffer);
			}
			
			for(; offSet < bufferSize && buffer[offSet] < ' '; offSet++) {
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			if(bufferSize == -1) {
				return null;
			}
			
			int count = 0;
			
			for(; offSet < bufferSize && buffer[offSet] != '\r' && buffer[offSet] != '\n'; offSet++) {
				charBuffer[count] = (char)buffer[offSet];
				
				count++;
				
				if(count == SIZE) {
					count = 0;
					sb.append(charBuffer, 0, count);
				}
				
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			offSet++;
			
			sb.append(charBuffer, 0, count);
		} catch(IOException io) {
			io.printStackTrace();
			System.exit(0);
		}
		
		return sb.toString();
	}
	
	public String readWord() {
		StringBuffer sb = new StringBuffer();
		
		try {
			if(offSet == bufferSize) {
				offSet = 0;
				offSet = in.read(buffer);
			}
			
			for(; offSet < bufferSize && buffer[offSet] < ' '; offSet++) {
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			if(bufferSize == -1) {
				return null;
			}
			
			int count = 0;
			
			for(; offSet < bufferSize && buffer[offSet] != ' ' && buffer[offSet] != '\r' && buffer[offSet] != '\n'; offSet++) {
				charBuffer[count] = (char)buffer[offSet];
				
				count++;
				
				if(count == SIZE) {
					count = 0;
					sb.append(charBuffer, 0, count);
				}
				
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			offSet++;
			
			sb.append(charBuffer, 0, count);
		} catch(IOException io) {
			io.printStackTrace();
			System.exit(0);
		}
		
		return sb.toString();
	}

	public char[] readWord(int n) {
		char[] word = new char[n];
		
		try {
			if(offSet == bufferSize) {
				offSet = 0;
				offSet = in.read(buffer);
			}
			
			for(; offSet < bufferSize && buffer[offSet] < ' '; offSet++) {
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			if(bufferSize == -1) {
				return null;
			}
			
			for(int wi=0; offSet < bufferSize && buffer[offSet] != '\r' && buffer[offSet] != '\n'; offSet++) {
				word[wi++] = (char)buffer[offSet];
				
				if(offSet == bufferSize-1) {
					offSet = -1;
					bufferSize = in.read(buffer);
				}
			}
			
			offSet++;
		} catch(IOException io) {
			io.printStackTrace();
			System.exit(0);
		}
		
		return word;
	}

}

class IntWriter {
	
	private BufferedWriter output;
	
	public IntWriter() {
		output = new BufferedWriter(new OutputStreamWriter(System.out));
	}
	
	public void println() {
		try {
			output.append("\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public void print(Object o) {
		try {
			output.append(o.toString());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void println(Object o) {
		try {
			output.append(o.toString()+"\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public void printf(String format, Object... args) {
		try {
			output.append(String.format(format, args));
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void printfln(String format, Object... args) {
		try {
			output.append(String.format(format, args)+"\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void flush() {
		try {
			output.flush();
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void close() {
		try {
			output.close();
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

}