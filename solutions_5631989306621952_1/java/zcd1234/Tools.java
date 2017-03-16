package tools;


import java.io.File;
import java.io.IOException;
import java.util.LinkedList;

import javax.swing.JFileChooser;

public class Tools {
	public static String chooseFile(){
		String s = "";
		String currentDir = System.getProperty("user.dir");
		JFileChooser fileChooser = new JFileChooser(currentDir+"/inputs");
		if (fileChooser.showOpenDialog(fileChooser) == JFileChooser.APPROVE_OPTION) {
		  File file = fileChooser.getSelectedFile();
		  s = file + "";
		  s = s.replace("\\", "/");
	    }
		return s;
	}
	public static String getOutputName(String inputName){
		File inputFile = new File(inputName);
		String fileName = inputFile.getName();
		String dirName = inputFile.getParent().replace("\\", "/");
		return dirName + "/output_" + fileName;
	}
	public static int[] intArray(String s,String delimit){
		String[] ss = s.split(delimit);
		int N = ss.length;
		int[] a = new int[N];
		for(int n=0;n<N;n++)
			a[n] = Integer.parseInt(ss[n]);
		return a;
	}
	public static long[] longArray(String s,String delimit){
		String[] ss = s.split(delimit);
		int N = ss.length;
		long[] a = new long[N];
		for(int n=0;n<N;n++)
			a[n] = Long.parseLong(ss[n]);
		return a;
	}
	public static double[] doubleArray(String s, String delimit){
		String[] ss = s.split(delimit);
		int N = ss.length;
		double[] a = new double[N];
		for(int n=0;n<N;n++)
			a[n] = Double.parseDouble(ss[n]);
		return a;
	}
	public static void print(Object o){
		System.out.print(o.toString());
	}
	public static void println(Object o){
		System.out.println(o.toString());
	}
	public static void println(){
		System.out.println();
	}
	public static void print(Object[][] oA){
		for(Object[] ob:oA){
			for(Object o:ob)
				print(o+" ");
			println();
		}
	}
	public static void print(int[][] N){
		for(int[] n:N){
			for(int i:n)
				print(i+" ");
			println();
		}
	}
	public static void print(int[] N){
		print("[");
		for(int n:N){
			print(n+",");
		}
		println("]");
	}
	
	public static void print(long[] N){
		print("[");
		for(long n:N){
			print(n+",");
		}
		println("]");
	}
	public static void print(double[] d){
		print("[");
		for(double di:d){
			print(di+",");
		}
		println("]");
	}
	public static <T> void print(LinkedList<T> t){
		print("[");
		for(T ti:t){
			print(ti+",");
		}
		println("]");
	}
	public static long gcd(long a, long b){
		long c = a % b;
		if(c==0)
			return b;
		else
			return gcd(b,c);
	}
	public static int gcd(int a, int b){
		int c = a % b;
		if(c==0)
			return b;
		else
			return gcd(b,c);
	}
	public static long C(long n,long k){
    	if(k==0) return 1;
    	if(2*k > n)
    		return C(n,n-k);
    	long up = 1;
    	long down = 1;
    	for(int i=1;i<=k;i++){
    		up *= (n-i+1);
    		down *= i;
    		if(up > 1e6){
    			long t = gcd(up,down);
    			up /= t;
    			down /= t;
    		}
    	}
    	return (up / down);
	}
	public static long C(int n,int k){
    	if(k==0) return 1;
    	if(2*k > n)
    		return C(n,n-k);
    	long up = 1;
    	long down = 1;
    	for(int i=1;i<=k;i++){
    		up *= (n-i+1);
    		down *= i;
    		if(up > 1e6){
    			long t = gcd(up,down);
    			up /= t;
    			down /= t;
    		}
    	}
    	return (up / down);
	}
	public static long mul(long a,long b){
		long c = gcd(a,b);
		return a * b / c;
	}
	public static int mul(int a,int b){
		int c = gcd(a,b);
		return a * b / c;
	}
	public static long convert(String binary){
		int L = binary.length();
		long power = 1;
		long r = 0;
		for(int i=0;i<L;i++){
			char c = binary.charAt(L-1-i);
			if(c=='1'){
				r += power;
			}
			power = power * 2;
		}
		return r;
	}
	public static long[] power2(int N){
		long[] p = new long[N+1];
		long value = 1;
		for(int i=0;i<=N;i++){
			p[i] = value;
			value *= 2;
		}
		return p;
	}
	public static long[] p2(int N){
		long[] p = new long[N+1];
		for(int i=0;i<=N;i++)
			p[i] = 1<<i;
		return p;
	}
	public static long perm(long n, long mod){
		long re = 1L;
		for(int i=1;i<=n;i++){
			re = re*i%mod;
		}
		return re;
	}
	public static void sort(int[] x){
		int N = x.length;
		for(int i=0;i<N-1;i++)
			for(int j=i+1;j<N;j++){
				if(x[i] > x[j]){
					int xi = x[i];
					x[i] = x[j];
					x[j] = xi;
				}
			}
	}
	public static void sort(long[] x){
		int N = x.length;
		for(int i=0;i<N-1;i++)
			for(int j=i+1;j<N;j++){
				if(x[i] > x[j]){
					long xi = x[i];
					x[i] = x[j];
					x[j] = xi;
				}
			}
	}
	public static void sort(double[] x){
		int N = x.length;
		for(int i=0;i<N-1;i++)
			for(int j=i+1;j<N;j++){
				if(x[i] > x[j]){
					double xi = x[i];
					x[i] = x[j];
					x[j] = xi;
				}
			}
	}
	public static int largerThan(String s1, String s2){
		//s1 > s2?
		int L1 = s1.length();
		int L2 = s2.length();
		int L = Math.min(L1, L2);
		for(int i=0;i<L;i++){
			char c1 = s1.charAt(i);
			char c2 = s2.charAt(i);
			if(c1-c2>0)
				return 1;
			else if(c1-c2<0)
				return -1;
		}
		if(L1==L2)
			return 0;
		return L1>L2?1:-1;
	}
	static class intpair{
		int a;
		int b;
		intpair(int a, int b){
			this.a = a;
			this.b = b;
		}
		public int hashCode(){
			return a*10 + b;
		}
		public boolean equals(Object o){
			if(this==o)
				return true;
			intpair o1 = (intpair) o;
			if(o1.a==a && o1.b==b)
				return true;
			return false;
		}
	}

}
