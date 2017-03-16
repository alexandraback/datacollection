import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in=new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out=new PrintWriter("A-small-attempt0.out");
		//InputReader in=new InputReader(System.in);
		//PrintWriter out=new PrintWriter(System.out);
		//Scanner in=new Scanner(System.in);
		
		int pi=in.nextInt();
		for(int qi=1;qi<=pi;qi++){
			String s=in.next();
			int begin=0;
			int end=s.length()-1;
			String head="";
			String tail="";
			while(begin<=end){
				int position=getMaxPosition(s,begin,end);
				char max=s.charAt(position);
				String nowHead="";
				String nowTail="";
				for(int i=position;i<=end;i++){
					if(s.charAt(i)==max){
						nowHead=nowHead+s.charAt(i);
					}
					else{
						nowTail=nowTail+s.charAt(i);
					}
				}
				head=head+nowHead;
				tail=nowTail+tail;
				end=position-1;
			}
			out.println("Case #"+qi+": "+head+tail);
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