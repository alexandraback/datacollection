import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class B {
	
	public static IntReader in = new IntReader();
	public static IntWriter out = new IntWriter();
	
	public static int A, B, K;
	//public static int[][][][] dp = new int[31][2][2][2];
	
	public static void main(String[] args) {
		final int T = in.readInt();
		
		for(int t=1; t<=T; t++) {
			A = in.readInt();
			B = in.readInt();
			K = in.readInt();
			int count = 0;
			for(int ai=0; ai<A; ai++) {
				for(int bi=0; bi<B; bi++) {
					if((ai & bi) < K) {
						count++;
					}
				}
			}
			out.printfln("Case #%d: %d", t, count);
		}
		
		out.close();
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