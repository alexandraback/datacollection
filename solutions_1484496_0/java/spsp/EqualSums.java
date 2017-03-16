import java.io.*;
import java.util.*;

import static java.lang.Math.*;
public class EqualSums {
	public static void main (String [] args) throws IOException {
		String[]filename="test A-small A-large B-small B-large C-small C-large D-small D-large".split(" ");
		////////////////// 0      1       2       3       4       5       6       7       8
		String fn=filename[5];
		f = new BufferedReader(new FileReader(fn+".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fn+".out")));
		
		nl();
		int tcnt = ip(tk());
		for (int ti = 0; ti < tcnt; ti++) {
			nl();
			int n=ip(tk());
			int[]x=new int[n];
			for (int i = 0; i < n; i++) {
				x[i]=ip(tk());
			}
			HashMap<Integer,Integer>hm=new HashMap<Integer,Integer>();
			out.println("Case #"+(ti+1)+":");
			boolean find=false;
			for (int i = 0; i < (1<<n); i++) {
				int sum=0;
				for (int j = 0; j < n; j++) {
					if((i&(1<<j))>0){
						sum+=x[j];
					}
				}
				if(hm.containsKey(sum)){
					int v=hm.get(sum);
					boolean first=true;
					for (int j = 0; j < n; j++) {
						if((v&(1<<j))>0){
							if(first){
								out.print(x[j]);
								first=false;
							}
							else out.print(" "+x[j]);
						}
					}
					out.println();
					first=true;
					for (int j = 0; j < n; j++) {
						if((i&(1<<j))>0){
							if(first){
								out.print(x[j]);
								first=false;
							}
							else out.print(" "+x[j]);
						}
					}
					out.println();
					find=true;
					break;
				}
				else hm.put(sum, i);
			}
			if(find==false)
				out.println("Impossible");
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
