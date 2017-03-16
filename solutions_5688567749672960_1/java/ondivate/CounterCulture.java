import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class CounterCulture {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		LinkedList<Integer> list=new LinkedList<Integer>();
		list.add(1);
		int ctr=0, done=0;
		while(done<1000000){
			ctr++;
			LinkedList<Integer> nlist=new LinkedList<Integer>();
			for(int i:list){
				if(ans[i]!=0)
					continue;
				ans[i]=ctr;
				int a=i+1;
				int b=(int) reverse(i);
				if(ans[a]==0)
					nlist.add(a);
				if(ans[b]==0)
					nlist.add(b);
				done++;
			}
			list=nlist;
		}
		
		map=new TreeMap<Long,Integer>();	
//		for(int i=1;i<1000000;i++){
//			if(ans[i]!=solve(i))
//				System.out.println("WRONG!");
//		}
			
		solve(10000000000l);
		
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			long N=Long.parseLong(br.readLine());
		
			bw.append("Case #"+cn+": "+solve(N)+"\n");
		}
		bw.flush();
	}
	
	static long reverse(long a){
		StringBuilder sb=new StringBuilder(""+a);
		return (Long.parseLong(sb.reverse().toString()));
	}
	
	static int ans[]=new int[1000002]; 
	static TreeMap<Long,Integer> map;
	static long solve(long a){
		if(a<2)
			return 1;
		if(map.containsKey(a))
			return map.get(a);
//		System.out.println("solving "+a);
		long ret=a;
		if(a%10==0)
			ret=Math.min(ret, solve(a-1)+1);
		if(digits(a-2)<digits(a))
			ret=Math.min(ret, solve(a-2)+2);
		if(a%10==1){
			if(reverse(a)<a)
				ret=Math.min(ret, solve(reverse(a))+1);
		}
		
		
		for(int i=1;i<digits(a);i++){
			long na=change(a,i);
			if(na<a)
				ret=Math.min(ret, solve(na)+(a-na));
		}
		
		map.put(a, (int) ret);
		return ret;
	}
	static long change(long a, int b){
		String end="00000000000000000001";
		int digits=(a+"").length()-1;
		
		return Long.parseLong((a+"").substring(0,digits-b+1)+end.substring(20-b,20));
	}
	
	static int digits(long a){
		return (a+"").length();
	}
}
