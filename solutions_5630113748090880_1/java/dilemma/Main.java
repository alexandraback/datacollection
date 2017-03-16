import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in=new Scanner(new File("B-large.in"));
		PrintWriter out=new PrintWriter("B-large.out");
		//InputReader in=new InputReader(System.in);
		//PrintWriter out=new PrintWriter(System.out);
		//Scanner in=new Scanner(System.in);
		
		int pi=in.nextInt();
		for(int qi=1;qi<=pi;qi++){
			int n=in.nextInt();
			int[] a=new int[10010];
			for(int i=0;i<2*n-1;i++){
				for(int j=0;j<n;j++){
					int u=in.nextInt();
					a[u]++;
				}
			}
			List<Integer> list=new ArrayList<Integer>();
			for(int i=0;i<10010;i++){
				if(a[i]%2==1){
					list.add(i);
				}
			}
			Collections.sort(list);
			out.print("Case #"+qi+":");
			for(Integer i:list){
				out.print(" "+i);
			}
			out.println();
		}
		
		out.close();
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