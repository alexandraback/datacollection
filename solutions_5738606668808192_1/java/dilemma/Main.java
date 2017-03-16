import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in=new Scanner(new File("C-large.in"));
		PrintWriter out=new PrintWriter("C-large.out");
		//InputReader in=new InputReader(System.in);
		//PrintWriter out=new PrintWriter(System.out);
		//Scanner in=new Scanner(System.in);
		
		in.nextInt();
		in.nextInt();
		in.nextInt();
		char[] a=new char[32];
		for(int i=0;i<a.length;i++){
			a[i]='0';
		}
		a[0]=a[31]='1';
		BigInteger baseNumber=new BigInteger(String.valueOf(a),2);
		long n=0;
		long[][] ans=new long[500][11];
		String[] ansString=new String[500];
		int sum=0;
		while(true){
			BigInteger now=baseNumber.add(BigInteger.valueOf(2*n));
			String s=now.toString(2);
			boolean OK=true;
			long[] factors=new long[11];
			for(int i=2;i<=10;i++){
				BigInteger m=new BigInteger(s,i);
				long u=tryToFindFactor(m);
				factors[i]=u;
				if(u==-1){
					OK=false;
					break;
				}
			}
			if(OK==true){
				ansString[sum]=s;
				for(int i=2;i<=10;i++){
					ans[sum][i]=factors[i];
				}
				sum++;
				if(sum>=500){
					break;
				}
			}
			n++;
		}
		out.println("Case #1:");
		for(int i=0;i<500;i++){
			out.print(ansString[i]+" ");
			for(int j=2;j<10;j++){
				out.print(ans[i][j]+" ");
			}
			out.println(ans[i][10]);
		}
		
		out.close();
	}
	
	static long tryToFindFactor(BigInteger n){
		for(int i=2;i<10000;i++){
			if(n.remainder(BigInteger.valueOf(i)).compareTo(BigInteger.ZERO)==0){
				return i;
			}
		}
		return -1;
	}
	
	static BigInteger getAnswer(long n){
		if(n==0){
			return BigInteger.ZERO;
		}
		boolean[] has=new boolean[10];
		BigInteger m=BigInteger.valueOf(n);
		BigInteger nn=BigInteger.valueOf(n);
		int ans=0;
		while(true){
			ans++;
			addNumber(has,m);
			if(check(has)==true){
				return m;
			}
			m=m.add(nn);
		}
	}
	
	static void addNumber(boolean[] has,BigInteger n){
		BigInteger m=new BigInteger(n.toString());
		while(m.compareTo(BigInteger.ZERO)!=0){
			int u=m.mod(BigInteger.TEN).intValue();
			has[u]=true;
			if(check(has)==true){
				return;
			}
			m=m.divide(BigInteger.TEN);
		}
	}
	
	static boolean check(boolean[] has){
		for(int i=0;i<10;i++){
			if(has[i]==false){
				return false;
			}
		}
		return true;
	}
	
	static class InputReader {
		BufferedReader br;
		StringTokenizer st;

		public InputReader (File f){
			try{
				br=new BufferedReader(new FileReader(f));
			}catch(FileNotFoundException e){
				e.printStackTrace();
			}
		}

		public InputReader (InputStream in){
			br=new BufferedReader(new InputStreamReader(in));
		}

		public String next(){
			while(st==null||!st.hasMoreTokens()){
				try{
					st=new StringTokenizer(br.readLine());
				}catch(IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		public boolean hasNext(){
			while(st==null||!st.hasMoreTokens()){
				String s=null;
				try{
					s=br.readLine();
				}catch(IOException e){
					e.printStackTrace();
				}
				if(s==null)
					return false;
				st=new StringTokenizer(s);
			}
			return true;
		}

		public int nextInt(){
			return Integer.parseInt(next());
		}

		public long nextLong(){
			return Long.parseLong(next());
		}

		public double nextDouble(){
			return Double.parseDouble(next());
		}
	}
}