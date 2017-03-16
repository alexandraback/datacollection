import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Ivan Pryvalov (ivan.pryvalov@gmail.com)
 */
public class GCJ2014_R1C_A implements Runnable{

	boolean debug = false;
	private void solve() throws IOException {
		int T = scanner.nextInt(); //100
		for (int test = 0; test < T; test++) {
			String line = scanner.nextLine(); //"a/b"
			StringTokenizer tok = new StringTokenizer(line, "/");
			long a = Long.parseLong(tok.nextToken()); //10^12
			long b = Long.parseLong(tok.nextToken());			
			long gcd = gcd(a,b);
			a/=gcd;
			b/=gcd;
			
			int result = -1;
			int curPow = 1;
			long curVal = 2;
			for(;;){
				if (curPow>40){
					break;
				}
				if (a*curVal-b >=0){
					result = curPow;
					break;
				}				
				curVal *= 2;
				curPow++;
			}
			
			
			String res = "impossible";
			if (result>=0 && getPower(b)>=0){
				res = "" + result;
			}
			
			String answer = String.format("Case #%d: %s", test+1, res);
			out.println(answer);
			if (inputFromFile){
				System.out.println("Test "+(test+1)+" out of "+T+".\n\t"+answer);
			}
		}
		
	}

	private int getPower(long b) {
		int res = 0;
		long cur = 1;
		while(cur<b){
			cur *= 2;
			res++;
		}		
		return cur==b? res : -1;
	}

	private long gcd(long a, long b) {
		if (a==0) return b;
		return gcd(b%a, a);
	}

	/////////////////////////////////////////////////
	final int BUF_SIZE = 1024 * 1024 * 8;//important to read long-string tokens properly
	final int INPUT_BUFFER_SIZE = 1024 * 1024 * 8 ;
	final int BUF_SIZE_INPUT = 1024;
	
	final int BUF_SIZE_OUT = 1024;
	
	boolean inputFromFile = true;
//	String filenamePrefix = "A-small-attempt0";
//	String filenamePrefix = "A";
	String filenamePrefix = "A-large";
	String inSuffix = ".in";
	String outSuffix = ".out";
	
	PrintStream out;
	ByteScanner scanner;
	ByteWriter writer;
	
//	@Override
	public void run() {
		try{
			InputStream bis = null;
			OutputStream bos = null;
			if (inputFromFile){
				File baseFile = new File(getClass().getResource("/").getFile());
				bis = new BufferedInputStream(
						new FileInputStream(new File(
								baseFile, filenamePrefix+inSuffix)),
								INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(
						new FileOutputStream(
								new File(baseFile, filenamePrefix+outSuffix)));
				out = new PrintStream(bos);
			}else{
				bis = new BufferedInputStream(System.in, INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(System.out);
				out = new PrintStream(bos);
			}
			scanner = new ByteScanner(bis, BUF_SIZE_INPUT, BUF_SIZE);
			writer = new ByteWriter(bos, BUF_SIZE_OUT);
			
			solve();
			out.flush();
		}catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public interface Constants{
		final static byte ZERO = '0';//48 or 0x30
		final static byte NINE = '9';
		final static byte SPACEBAR = ' '; //32 or 0x20
		final static byte MINUS = '-'; //45 or 0x2d	
		
		final static char FLOAT_POINT = '.';
	}
	
	public static class EofException extends IOException{
	}
	
	public static class ByteWriter implements Constants {
		
		int bufSize = 1024;
		byte[] byteBuf = new byte[bufSize];
		OutputStream os;
		
		public ByteWriter(OutputStream os, int bufSize){
			this.os = os;
			this.bufSize = bufSize;
		}
		
		public void writeInt(int num) throws IOException{
	         int byteWriteOffset = byteBuf.length;
	         if (num==0){
	        	 byteBuf[--byteWriteOffset] = ZERO;
	         }else{
	        	 int numAbs = Math.abs(num);
	        	 while (numAbs>0){
	        		 byteBuf[--byteWriteOffset] = (byte)((numAbs % 10) + ZERO);
	        		 numAbs /= 10;
	        	 }
	        	 if (num<0)
	        		 byteBuf[--byteWriteOffset] = MINUS;
	         }
	         os.write(byteBuf, byteWriteOffset, byteBuf.length - byteWriteOffset);
		}
		
		/**
		 * Please ensure ar.length <= byteBuf.length!
		 * 
		 * @param ar
		 * @throws IOException
		 */
		public void writeByteAr(byte[] ar) throws IOException{
			for (int i = 0; i < ar.length; i++) {
				byteBuf[i] = ar[i];
			}
			os.write(byteBuf,0,ar.length);
		}
		
		public void writeSpaceBar() throws IOException{
			byteBuf[0] = SPACEBAR;
			os.write(byteBuf,0,1);
		}
		
	}
	
	public static class ByteScanner implements Constants{
		
		InputStream is;
		
		public ByteScanner(InputStream is, int bufSizeInput, int bufSize){
			this.is = is;
			this.bufSizeInput = bufSizeInput;
			this.bufSize = bufSize;
			
			byteBufInput = new byte[this.bufSizeInput];
			byteBuf = new byte[this.bufSize];
		}
		
		public ByteScanner(byte[] data){
			byteBufInput = data;
			bufSizeInput = data.length;
			bufSize = data.length;
			byteBuf = new byte[bufSize];
			byteRead = data.length;
			bytePos = 0;
		}
		
		private int bufSizeInput;
		private int bufSize;
		
		byte[] byteBufInput;
		byte by=-1;
		int byteRead=-1;
		int bytePos=-1;

		byte[] byteBuf;
		int totalBytes;
		
		boolean eofMet = false;
		
		private byte nextByte() throws IOException{
			
			if (bytePos<0 || bytePos>=byteRead){
				byteRead = is==null? -1: is.read(byteBufInput);
				bytePos=0;
				if (byteRead<0){
					byteBufInput[bytePos]=-1;//!!!
					if (eofMet)
						throw new EofException();
					eofMet = true;
				}
			}
			return byteBufInput[bytePos++];
		}
		
		/**
		 * Returns next meaningful character as a byte.<br>
		 * 
		 * @return
		 * @throws IOException
		 */
		public byte nextChar() throws IOException{
			while ((by=nextByte())<=0x20);
			return by;
		}
		
		/**
		 * Returns next meaningful character OR space as a byte.<br>
		 * 
		 * @return
		 * @throws IOException
		 */
		public byte nextCharOrSpacebar() throws IOException{
			while ((by=nextByte())<0x20);
			return by;
		}
		
	    /**
	     * Reads line.
	     * 
	     * @return
	     * @throws IOException
	     */
	    public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    public byte[] nextLineAsArray() throws IOException {
            readToken((byte)0x20);
            byte[] out = new byte[totalBytes];
            System.arraycopy(byteBuf, 0, out, 0, totalBytes);
            return out;
	    }
	    
		
	    /**
	     * Reads token. Spacebar is separator char.
	     * 
	     * @return
	     * @throws IOException
	     */
	    public String nextToken() throws IOException {
            readToken((byte)0x21);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    /**
	     * Spacebar is included as separator char
	     * 
	     * @throws IOException
	     */
	    private void readToken() throws IOException {	    	
            readToken((byte)0x21);
	    }
	    
	    private void readToken(byte acceptFrom) throws IOException {
            totalBytes = 0;
            while ((by=nextByte())<acceptFrom);
            byteBuf[totalBytes++] = by;
            while ((by=nextByte())>=acceptFrom){
                byteBuf[totalBytes++] = by;
            }
	    }
		
	    public int nextInt() throws IOException{
			readToken();
			int num=0, i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		public long nextLong() throws IOException{
			readToken();
			long num=0;
			int i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		/*
		//TODO test Unix/Windows formats
		public void toNextLine() throws IOException{
			while ((ch=nextChar())!='\n');
		}
		*/
		
		public double nextDouble() throws IOException{
			readToken();
			char[] token = new char[totalBytes];
			for (int i = 0; i < totalBytes; i++) {
				token[i] = (char)byteBuf[i];
			}
			return Double.parseDouble(new String(token));
		}
		
		public int[] loadIntArray(int size) throws IOException{
			int[] a = new int[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			return a;
		}
		
		public long[] loadLongArray(int size) throws IOException{
			long[] a = new long[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextLong();
			}
			return a;
		}
	    
	}
	
	public static abstract class Timing{
		private static int counter = 0;
		protected String name = "Timing"+(++counter);
		private boolean debug;
		
		public Timing(boolean debug) {
			super();
			this.debug = debug;
		}
		
		public abstract void run();
		public void start(){
			long time1 = System.currentTimeMillis();
			run();
			long time2 = System.currentTimeMillis();
			if (debug)
				System.out.println(name+" time = "+(time2-time1)/1000.0+" s.");
		}
		
	}
	
	public static class TimeMonitor{
		public boolean printNow = true;
		String name;
		public TimeMonitor(String name, boolean printNow) {
			super();
			this.name = name;
			this.printNow = printNow;
		}
		long time1 = 0, time2 = 0;
		public TimeMonitor start(){
			time1 = System.currentTimeMillis();
			return this;
		}
		public void stop(){
			time2 = System.currentTimeMillis();
			if (printNow) printStat();
		}
		public void printStat(){
			if (time2==0){
				System.out.println("['"+name+"' is still running..."+"]");
			}else{
				System.out.println("['"+name+"', time = "+(time2-time1)/1000.0+" s."+"]");
			}
		}
	}
	
	public static class Alg{
		public static interface BooleanChecker{
			public boolean check(long arg);
		}
		
		public static class BinarySearch{
					
			/**
			 * This check returns boolean value, result of function.
			 * It should be monotonic.
			 * 
			 * @return
			 */
			public BooleanChecker bc;
			
			
			/**
			 * Returns following element: <pre> 0 0 [1] 1 1</pre>
			 */
			public long search(long left, long right){
				while (left<=right){
					long mid = (left+right)/2;
					if (bc.check(mid)){
						right = mid-1;
					}else{
						left = mid+1;
					}
				}
				return left;
			}
			
			/**
			 * Optional.<br>
			 * Returns following element: <pre> 1 1 [1] 0 0</pre>
			 */
			public long searchInverted(long left, long right){
				while (left<=right){
					long mid = (left+right)/2;
					if (!bc.check(mid)){
						right = mid-1;
					}else{
						left = mid+1;
					}
				}
				return left - 1; 
			}
		}
	}
	
	public static class Modulo{
		long mod = (long)1e9+7;
		
		public Modulo(long mod) {
			super();
			this.mod = mod;
		}

		public long inv(long a) {
			long res =  pow(a, mod-2);
			return res;
		}

		public long pow(long a, long x) {
			if (x==0)
				return 1;
			long part = 1;
			if ((x&1)!=0)
				part = a;
			return (part * pow((a*a)%mod, x>>1)) % mod;
		}
		
		public long c(long n, long m){
			long res = 1;
			for(int i=1; i<=m; i++){
				res = (res * (n-m+i)) % mod;
				res = (res * inv(i)) % mod;
			}
			return res;
		}
		
	}
	
	
	/**
	 * Added 26.04.2013. 
	 * See KROK 2013, Round 1, Problem D.
	 */
	static class DisjointUnionSet implements Cloneable{
		
		int[] rank;
		int[] parent;
		
		protected DisjointUnionSet clone(){
			DisjointUnionSet cloned = new DisjointUnionSet(parent.length);
			for(int i=0; i<parent.length; i++){
				cloned.parent[i] = parent[i];
				cloned.rank[i] = rank[i];
			}
			return cloned;
		}

		public DisjointUnionSet(int n) {
			rank = new int[n];
			parent = new int[n];
			
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}
		
		@Override
		public String toString() {
			return "disj [parents=" + Arrays.toString(parent) + "]";
		}

		/**
		 * Problem specific or general?
		 * O(N * alpha)
		 * 
		 * @param set2
		 */
		public void union(DisjointUnionSet set2){
			for(int i=0; i<parent.length; i++){
				parent[find(i)] = parent[find(set2.find(i))];
			}
		}
		
		
		/**
		 * @param index1 range 0..n-1
		 * @param index2
		 */
		public void union(int index1, int index2){
			int p1 = find(index1);
			int p2 = find(index2);
			
			if (rank[p1] > rank[p2]){
				parent[p2] = p1;
			}else if (rank[p2] > rank[p1]){
				parent[p1] = p2;
			}else{
				parent[p2] = p1;
				rank[p1]++;
			}
		}

		/**
		 *  O(alpha(n)) 
		 * 
		 * @param index
		 * @return
		 */
		private int find(int index) {
			if (parent[index] != index)
				parent[index] =  find(parent[index]);
			return parent[index];
		}
		
		/**
		 * O(N alpha(N)) ==> see find()
		 * 
		 * @return
		 */
		public int getCountDisjointSets(){
			int[] used = new int[parent.length];
			for(int i=0; i<parent.length; i++){
				used[find(i)] = 1;
			}
			int res = 0;
			for(int i=0; i<parent.length; i++){
				res += used[i];
			}
			return res;
		}
	}

	private static Random rnd = new Random();
	public static class ArrayUtils{
		public static void shuffle(int[] a){
			for(int j=a.length-1; j>=1; j--){
				int i = rnd.nextInt(j+1);
				swap(a, i, j);
			}
		}
		
		public static void swap(int[] a, int i, int j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	
	public static void main(String[] args) {
		new GCJ2014_R1C_A().run();
	}
	
}