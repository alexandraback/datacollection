import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in=new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out=new PrintWriter("C-small-attempt0.out");
		//InputReader in=new InputReader(System.in);
		//PrintWriter out=new PrintWriter(System.out);
		//Scanner in=new Scanner(System.in);
		
		int pi=in.nextInt();
		for(int qi=1;qi<=pi;qi++){
			int n=in.nextInt();
			int[] a=new int[n];
			for(int i=0;i<n;i++){
				a[i]=in.nextInt()-1;
			}

			int ans=0;
			List<BFF> list=new ArrayList<BFF>();
			for(int i=0;i<n;i++){
				boolean[] use=new boolean[n];
				int now=i;
				int count=1;
				int sum=1<<i;
				use[i]=true;
				while(true){
					int next=a[now];
					use[next]=true;
					if(a[next]==now){
						ans=Math.max(ans,count);
						list.add(new BFF(sum,count,now));
						break;
					}
					count++;
					sum=sum|(1<<next);
					if(a[next]==i){
						ans=Math.max(ans,count);
						break;
					}
					if(use[a[next]]==true){
						break;
					}
					now=next;
				}
			}
			/*
			 * for(BFF bff:list){ out.println(bff.members+" "+bff.count); }
			 */
			int m=list.size();
			int nn=1<<m;
			for(int i=1;i<nn;i++){
				int p=i;
				int sum=0;
				int count=0;
				int j=0;
				boolean OK=true;
				while(p!=0){
					if(p%2==1){
						BFF bff=list.get(j);
						if((sum|bff.members)!=(sum+bff.members)){
							OK=false;
							break;
						}
						sum=sum+bff.members;
						count=count+bff.count;
					}
					p=p/2;
					j++;
				}
				if(OK==true){
					ans=Math.max(ans,count);
				}
			}
			out.println("Case #"+qi+": "+ans);
		}
		
		out.close();
	}
	
	static class BFF{
		int members;
		int count;
		int tail;
		
		public BFF(int members,int count,int tail){
			this.members=members;
			this.count=count;
			this.tail=tail;
		}
	}
	
	static int getMaxPosition(String s,int begin,int end){
		char max=0;
		int position=0;
		for(int i=begin;i<=end;i++){
			if(s.charAt(i)>max){
				position=i;
				max=s.charAt(i);
			}
		}
		return position;
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