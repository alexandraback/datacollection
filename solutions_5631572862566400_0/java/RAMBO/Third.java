import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.*;


public class Third {
	static long mod=1000000007;
	static ArrayList<Integer> g[];
	static int f[];
	static int n;
	static int sum, ans;
	static boolean vis[];
	static boolean inStack[];
	static int parent[];
	
    public static void main(String[] args) throws Exception{           	
    	// InputReader in = new InputReader(System.in);       
    	//PrintWriter pw=new PrintWriter(System.out);   
    	 
    	 try(BufferedReader br = new BufferedReader(new FileReader("paint.in"))) {
    		 PrintWriter pw = new PrintWriter("paint2.out", "UTF-8");
    	//int t=in.readInt();
    	int t=Integer.parseInt(br.readLine());
    	  for(int v=1;v<=t;v++)
          {
          	//int ans=0;
          	int n=Integer.parseInt(br.readLine());
          	String l[]=br.readLine().split(" ");
          	f = new int[n];

          	g = new ArrayList[n];
          	for(int i = 0; i < n; i++)
          	g[i] = new ArrayList<Integer>();

          	for(int i = 0; i < n; i++){
          	f[i] = Integer.parseInt(l[i]) - 1;
          	g[f[i]].add(i);
          	}

          	sum = 0;
          	ans = 0;
          	vis = new boolean[n];
          	inStack = new boolean[n];
          	parent = new int[n];

          	for(int i = 0; i < n; i++){
          	if(!vis[i]){
          	parent[i] = -1;
          	vis[i] = true;
          	dfs(i);
          	}
          	}

          	ans = Math.max(ans, sum);
          	pw.println("Case #" + v + ": " + ans);
          	}

          	pw.close();
          	}
    }
          	static void dfs(int curr){
          	inStack[curr] = true;
          	int nxt = f[curr];
          	if(!vis[nxt]){
          	vis[nxt] = true;
          	parent[nxt] = curr;
          	dfs(nxt);
          	}
          	else if(inStack[nxt]){
          	int length = 1;
          	int x = curr;
          	while(x != nxt){
          	x = parent[x];
          	length++;
          	}
          	if(length > 2)
          	ans = Math.max(ans, length);
          	else{
          	sum += 2;
          	for(int j = 0; j < g[curr].size(); j++){
          	if(g[curr].get(j) == nxt){
          	g[curr].remove(j);
          	break;
          	}
          	}
          	for(int j = 0; j < g[nxt].size(); j++){
          	if(g[nxt].get(j) == curr){
          	g[nxt].remove(j);
          	break;
          	}
          	}
          	sum += depth(curr);
          	sum += depth(nxt);
          	}
          	}

          	inStack[curr] = false;
          	}

          	static int depth(int x){
          	int ans = 0;
          	for(int j = 0; j < g[x].size(); j++)
          	ans = Math.max(ans, 1 + depth(g[x].get(j)));
          	return ans;
          	}
    	 
	public static long  ways(int n, int r, long MOD)
	{
	  //  vector<long long> f(n + 1,1);
	    long f[]=new long[n+1];
	    Arrays.fill(f,1);
	    for (int i=2; i<=n;i++)
	        f[i]= (f[i-1]*i) % MOD;
	    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
	}
	public static long  InverseEuler(long n, long MOD)
	{
	    return pow(n,MOD-2,MOD);
	}
	static boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        if (number <= 3) {
            return true;
        }
        if (number % 2 == 0 || number % 3 == 0) {
            return false;
        }
        int i = 5;
        while (i * i <= number) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
            i += 6;
        }
        return true;
    }
	
public static long gcd(long x,long y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
	
public static int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else 
		return gcd(y,x%y);
}
public static int abs(int a,int b)
{
	return (int)Math.abs(a-b);
}
public static long abs(long a,long b)
{
	return (long)Math.abs(a-b);
}
public static int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
public static int min(int a,int b)
{
	if(a>b)
		return b;
	else 
		return a;
}
public static long max(long a,long b)
{
	if(a>b)
		return a;
	else
		return b;
}
public static long min(long a,long b)
{
	if(a>b)
		return b;
	else 
		return a;
}

static boolean isPowerOfTwo (long v) {
	return (v & (v - 1)) == 0;
}
public static long pow(long n,long p,long m)
{
	 long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    if(result>=m)
	    result%=m;
	    p >>=1;
	    n*=n;
	    if(n>=m)
	    n%=m;
	}
	return result;
}

static class Pair implements Comparable<Pair>
{
	int a,b;
	Pair (int a,int b)
	{
		this.a=a;
		this.b=b;
	}

	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
		if(this.a!=o.a)
		return Integer.compare(this.a,o.a);
		else
			return Integer.compare(this.b, o.b);
		//return 0;
	}
	public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair p = (Pair)o;
            return p.a == a && p.b == b;
        }
        return false;
    }
    public int hashCode() {
        return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
    }
} 
    
static long sort(int a[],int n)
{  	int b[]=new int[n];	
	return mergeSort(a,b,0,n-1);}
static long mergeSort(int a[],int b[],long left,long right)
{ long c=0;if(left<right)
 {   long mid=left+(right-left)/2;
	 c= mergeSort(a,b,left,mid);
	 c+=mergeSort(a,b,mid+1,right);
	 c+=merge(a,b,left,mid+1,right); }	
	return c;	 }
static long merge(int a[],int  b[],long left,long mid,long right)
{long c=0;int i=(int)left;int j=(int)mid; int k=(int)left;
while(i<=(int)mid-1&&j<=(int)right)
{ if(a[i]<=a[j]) {b[k++]=a[i++]; }
else	{ b[k++]=a[j++];c+=mid-i;}}
while (i <= (int)mid - 1)   b[k++] = a[i++]; 
while (j <= (int)right) b[k++] = a[j++];
for (i=(int)left; i <= (int)right; i++) 
	a[i] = b[i];  return c;  }
    
    
   static  class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public long readLong() {
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
        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return readString();
        }

        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }

     static class OutputWriter
    {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer)
        {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects)
        {
            print(objects);
            writer.println();
        }

        public void close()
        {
            writer.close();
        }

        public void flush()
        {
            writer.flush();
        }

    }
    /* USAGE

    //initialize
        InputReader in 		= new InputReader(System.in);
        OutputWriter out	=	new OutputWriter(System.out);

    //read int
    int i = in.readInt();
    //read string
    String s = in.readString();
    //read int array of size N
    int[] x = IOUtils.readIntArray(in,N);
    //printline
    out.printLine("X");


    //flush output
    out.flush();

    //remember to close the
    //outputstream, at the end
    out.close();

    */
  static   class IOUtils {

        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
                array[i] = in.readInt();
            return array;
    }
    }
//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//StringBuilder sb=new StringBuilder("");
	 //InputReader in = new InputReader(System.in);
  // OutputWriter out = new OutputWriter(System.out);
	//PrintWriter pw=new PrintWriter(System.out);
	//String line=br.readLine().trim();
	       	
	//int t=Integer.parseInt(br.readLine());
  //	while(t-->0)
  	//{
  	//int n=Integer.parseInt(br.readLine());
	//long n=Long.parseLong(br.readLine());
	//String l[]=br.readLine().split(" ");
  //int m=Integer.parseInt(l[0]);
	//int k=Integer.parseInt(l[1]);
	//String l[]=br.readLine().split(" ");
	//l=br.readLine().split(" ");
	/*int a[]=new int[n];
	for(int i=0;i<n;i++)
	{
		a[i]=Integer.parseInt(l[i]);
	}*/
	   //System.out.println(" ");	     	
	
	//}
}
