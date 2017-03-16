import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class CounterCulture {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());

		int ans[]=new int[1000002]; 
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
				int b=reverse(i);
				if(ans[a]==0)
					nlist.add(a);
				if(ans[b]==0)
					nlist.add(b);
				done++;
			}
			list=nlist;
		}
		
		for(int cn=1;cn<=T;cn++){
			int N=Integer.parseInt(br.readLine());
			

			
			bw.append("Case #"+cn+": "+ans[N]+"\n");
		}
		bw.flush();
	}
	static int reverse(int a){
		StringBuilder sb=new StringBuilder(""+a);
		return (Integer.parseInt(sb.reverse().toString()));
	}
}
