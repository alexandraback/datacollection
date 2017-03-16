import java.io.*;
import java.util.*;

import static java.lang.Math.*;
public class SafetyinNumbers {
	public static void main (String [] args) throws IOException {
		String[]filename="test A-small A-large B-small B-large C-small C-large D-small D-large".split(" ");
		////////////////// 0      1       2       3       4       5       6       7       8
		String fn=filename[1];
		f = new BufferedReader(new FileReader(fn+".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fn+".out")));
		
		nl();
		int tcnt = ip(tk());
		for (int ti = 0; ti < tcnt; ti++) {
			nl();
			int n=ip(tk());
			int[]J=new int[n];
			double sum=0;
			int max=0;
			for (int i = 0; i < n; i++) {
				J[i]=ip(tk());
				sum+=J[i];
				max=max(max,J[i]);
			}
			double y=2./n;
			int c=0;
			for (int i = 0; i < n; i++) {
				if(J[i]/sum>=y){
					c++;
				}
			}
			if(c==0);
			else{
				for (int i = 0; i < n; i++) {
					int x=J[i];
					if(x==max)continue;
					int cc=0;
					int min=inf;
					int mx=0;
					double sumless=0;
					for (int k = 0; k < n; k++) {
						if(J[k]<=x){
							cc++;
							sumless+=J[k]/sum;
							mx=max(mx,J[k]);
						}
						else min=min(min,J[k]);
					}
					if(sum/cc+mx<min){
						y=(1+sumless)/cc;
						break;
					}
				}
			}
			out.print("Case #"+(ti+1)+":");
			for (int i = 0; i < n; i++) {
				out.print(" "+((y-J[i]/sum)*100<0?0.:(y-J[i]/sum)*100));
			}
			out.println();
		}
		
		out.close();
		System.exit(0);
	}
	static BufferedReader f;
	static StringTokenizer st;
	static void nl() throws IOException
	{
		st = new StringTokenizer(f.readLine());
	}
	static String tk()
	{
		return st.nextToken();
	}
	static void fill(Object array,int val){
		if(array instanceof int[])Arrays.fill((int[])array,val);
		else for(Object o:(Object[])array)fill(o,val);
	}
    //static String min(String a,String b){return a.compareTo(b)<0?a:b;}
	static int ip(String s){return Integer.parseInt(s);}
	static long lp(String s){return Long.parseLong(s);}
	static int inf=Integer.MAX_VALUE/2;
	static int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
	static boolean isPrime(int number)
    {
    	if (number < 2) return false;
    	if (number == 2) return true;
    	if (number % 2 == 0) return false;
    	for (int i = 3; i * i <= number; i += 2)
    		if (number % i == 0) return false;
    	return true;
    }
	static public class Comp implements Comparable<Comp> {
        public int compareTo(Comp other) {// myself first asc
            if (len == other.len)
                return str.compareTo(other.str);// myself first asc
            return other.len - len;// other first desc
        }

        int len;
        String str;
        public Comp(int len, String str) {
            super();
            this.len = len;
            this.str = str;
        }
    }
}
