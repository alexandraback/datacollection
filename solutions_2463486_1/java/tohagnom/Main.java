import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(inpFile));
		out = new PrintWriter(outFile);
		new Main().run();
		out.close();
	}

	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String fileName = "c";
	static String inpFile = fileName + ".in";
	static String outFile = fileName + ".out";

	String ns() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		} catch (Exception e) {
			return null;
		}
	}

	String nline() {
		try {
			return br.readLine();
		} catch (Exception e) {
			return null;
		}
	}

	int ni() {
		return Integer.valueOf(ns());
	}

	long nl() {
		return Long.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}

	boolean isPal(String s) {
		for (int i = 0; i < s.length(); ++i)
			if (s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		return true;
	}

	public void run() {
		
		Vector<BigInteger> v=new Vector<BigInteger>();
		try{
			Scanner in=new Scanner(new File("c1.out"));
			while(in.hasNext())
			{
				v.add(in.nextBigInteger());
			}
		}catch(IOException e){}
		int T=ni();
		for(int step=1; step<=T; ++step){
			BigInteger a=new BigInteger(ns()), b=new BigInteger(ns());
			int ans=0;
			int vs=v.size();
			for(int i=0; i<vs; ++i){
				if(v.get(i).compareTo(a)>=0 && v.get(i).compareTo(b)<=0)
					++ans;
			}
			out.println("Case #"+step+": "+ans);
		}
		/*
		BigInteger buf;
		for (int i = 1; i < 10; ++i) {
			buf = valueOf(i * i);
			if (isPal(buf.toString()))
				out.println(buf);
		}
		StringBuilder sb = new StringBuilder("2");
		for (;;) {
			
			buf = new BigInteger(sb.toString() + sb.reverse().toString());
			buf = buf.multiply(buf);
			if (isPal(buf.toString()))
				out.println(buf);
			if (buf.toString().length() > 100)
				break;
			String s = "";
			sb.reverse();
			for (int j = 0; j < 3; ++j) {
				s = sb.toString()+(char) (j + '0');
				sb.reverse();
				s+=sb.toString();
				buf = new BigInteger(s);
				//out.println(buf.toString());
				buf = buf.multiply(buf);
				if (isPal(buf.toString()))
					out.println(buf);
				sb.reverse();
			}
			sb.append("0");
		}
		StringBuilder s=new StringBuilder("");
		for (int i = 1; i <= 1000; ++i) {
			sb = new StringBuilder(Integer.toBinaryString(i));
			s = new StringBuilder("");
			s.append(sb.toString());
			sb.reverse();
			s.append(sb.toString());
			buf = new BigInteger(s.toString(), 10);
			buf = buf.multiply(buf);
			if (isPal(buf.toString())) {
				out.println(buf);
				if (buf.toString().length() > 100)
					break;
				for (int j = 0; j < 3; ++j) {
					sb.reverse();
					s = new StringBuilder(sb.toString());
					s.append((char) (j + '0'));
					sb.reverse();
					s.append(sb.toString());
					buf = new BigInteger(s.toString());
					//System.out.println(buf);
					buf = buf.multiply(buf);
					if (isPal(buf.toString()))
						out.println(buf);
				}
			}
			if (i % 1000000 == 0) {
				System.out.println(i);
				System.out.flush();
			}
		}*/
	}
	
}
