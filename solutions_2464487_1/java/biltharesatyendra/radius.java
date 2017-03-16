import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
 
/**
* Built using CHelper plug-in
* Actual solution is at the top
* @author Egor Kulikov (egor@egork.net)
*/
 
class AndrewAndTheBirthday {
int[] types;
double[][][][] result = new double[51][50][51][51];
int typeCount, count;
 
public void solve(int testNumber, InputReader in, OutputWriter out) {
count = in.readInt();
typeCount = in.readInt();
types = IOUtils.readIntArray(in, count);
MiscUtils.decreaseByOne(types);
ArrayUtils.fill(result, -1);
out.printLine(calculate(0, 0, 0, 0));
}
 
private double calculate(int step, int type, int same, int max) {
max = Math.max(max, same);
if (result[step][type][same][max] != -1)
return result[step][type][same][max];
if (step == count)
return result[step][type][same][max] = max;
if (types[step] != -1)
return result[step][type][same][max] = calculate(step + 1, types[step], type == types[step] ? same + 1 : 1, max);
result[step][type][same][max] = 0;
for (int i = 0; i < typeCount; i++)
result[step][type][same][max] += calculate(step + 1, i, type == i ? same + 1 : 1, max);
return result[step][type][same][max] /= typeCount;
}
}
 
class InputReader {
 
private InputStream stream;
private byte[] buf = new byte[1024];
private int curChar;
private int numChars;
private SpaceCharFilter filter;
 
public InputReader(InputStream stream) {
this.stream = stream;
}
 
public int read() {
if (numChars == -1)
throw new InputMismatchException();
if (curChar >= numChars) {
curChar = 0;
try {
numChars = stream.read(buf);
} catch (IOException e) {
throw new InputMismatchException();
}
if (numChars <= 0)
return -1;
}
return buf[curChar++];
}
 
public int readInt() {
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
 
public String readString() {
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
 
public boolean isSpaceChar(int c) {
if (filter != null)
return filter.isSpaceChar(c);
return isWhitespace(c);
}
 
public static boolean isWhitespace(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
public String next() {
return readString();
}
 
public interface SpaceCharFilter {
public boolean isSpaceChar(int ch);
}
}
 
class OutputWriter {
private final PrintWriter writer;
 
public OutputWriter(OutputStream outputStream) {
writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
}
 
public OutputWriter(Writer writer) {
this.writer = new PrintWriter(writer);
}
 
public void print(Object...objects) {
for (int i = 0; i < objects.length; i++) {
if (i != 0)
writer.print(' ');
writer.print(objects[i]);
}
}
 
public void printLine(Object...objects) {
print(objects);
writer.println();
}
 
public void close() {
writer.close();
}
 
}
 
class IOUtils {
 
public static int[] readIntArray(InputReader in, int size) {
int[] array = new int[size];
for (int i = 0; i < size; i++)
array[i] = in.readInt();
return array;
}
 
}
 
class MiscUtils {
 
public static void decreaseByOne(int[]...arrays) {
for (int[] array : arrays) {
for (int i = 0; i < array.length; i++)
array[i]--;
}
}
 
}
 
class ArrayUtils {
 
public static void fill(double[][] array, double value) {
for (double[] row : array)
Arrays.fill(row, value);
}
 
public static void fill(double[][][] array, double value) {
for (double[][] row : array)
fill(row, value);
}
 
public static void fill(double[][][][] array, double value) {
for (double[][][] row : array)
fill(row, value);
}
 
}

public class radius {
	


	public static void main(String args[]){
		

InputStream inputStream = System.in;
OutputStream outputStream = System.out;
InputReader in = new InputReader(inputStream);
OutputWriter out = new OutputWriter(outputStream);
AndrewAndTheBirthday solver = new AndrewAndTheBirthday();
int T = Integer.parseInt(in.next());

		int ca;
		
		for(ca=1;ca<=T;ca++){
		String a,b;
		a=in.next();
		b=in.next();
		BigInteger r,t,n;
		r=new BigInteger(a);
		t=new BigInteger(b);
		n = solve(r,t);
		//System.out.println("n is " + n);
		System.out.println("Case #" + ca +": "+ n);
		}
		
	}

	private static BigInteger solve(BigInteger r, BigInteger t) {
		BigInteger lo,hi,mid,next;
		lo=BigInteger.ONE;
		BigInteger two = new BigInteger("2");
		hi = t;
	//	System.out.println("we will start from " + lo + "  and  " + hi);
		while(true){
			mid = lo.add(hi);
			
			mid = mid.divide(two);
			next = mid.add(BigInteger.ONE);
			BigInteger fir,sec;
			fir = value(mid,r);
			if(fir.equals(t))return mid;
			if(fir.max(t).equals(fir)){
				hi=mid.subtract(BigInteger.ONE);
				//System.out.println(" fir is higher so hi is" + hi);
				
			}
			else {
			
				sec= value(mid.add(BigInteger.ONE),r);
				if(sec.equals(t))return mid.add(BigInteger.ONE);
				if(sec.max(t).equals(sec))return mid;
				lo = mid.add(BigInteger.ONE);
				//System.out.println(" fir is lo so lo is" + lo);
			}
			
			
			
		}
		
		
		
	}

	private static BigInteger value(BigInteger n, BigInteger r) {
		//System.out.println("for " + n + " and " + r);
		r=r.add(r);
		r= r.subtract(BigInteger.ONE);
		r=r.multiply(n);
	//	System.out.println(" n*(r-1) is " + r);
		n = n.multiply(n);
		n=n.add(n);
		//System.out.println("2*n^2 is " + n);
		n=n.add(r);
		//System.out.println("polynomial evaluates to " + n);
		return n;
		
	}
}
