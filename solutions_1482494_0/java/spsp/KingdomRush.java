import java.io.*;
import java.util.*;

import static java.lang.Math.*;
public class KingdomRush {
	public static void main (String [] args) throws IOException {
		String[]filename="test A-small A-large B-small B-large C-small C-large D-small D-large".split(" ");
		////////////////// 0      1       2       3       4       5       6       7       8
		String fn=filename[3];
		f = new BufferedReader(new FileReader(fn+".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fn+".out")));
		
		nl();
		int t = ip(tk());
		for (int i = 0; i < t; i++) {
			nl();
			int n = ip(tk());
			int[]one=new int[n],two=new int[n];
			for (int j = 0; j < n; j++) {
				nl();
				one[j]=ip(tk());
				two[j]=ip(tk());
			}
			int res=inf;
			for (int j = 0; j < (1<<n); j++) {
				int[]a=new int[n],b=new int[n];
				for (int k = 0; k < n; k++) {
					a[k]=one[k];b[k]=two[k];
				}
				for (int k = 0; k < n; k++) {
					if((j&(1<<k))!=0)a[k]=inf;
				}
				int cur=0,cnt=0;
				int[]done=new int[n];
				while(true){
					boolean find=false;
					for (int k = 0; k < n; k++) {
						if(done[k]==0){
							if(b[k]<=cur){
								done[k]=2;cur+=2;cnt++;find=true;break;
							}
							else if(a[k]<=cur){
								done[k]=1;cur++;cnt++;find=true;break;
							}
						}
						else if(done[k]==1){
							if(b[k]<=cur){
								done[k]=2;cur++;cnt++;find=true;break;
							}
						}
					}
					if(find==false)break;
				}
				if(cur==2*n)res=min(res,cnt);
			}
			out.println("Case #"+(i+1)+": "+(res<inf?res:"Too Bad"));
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
