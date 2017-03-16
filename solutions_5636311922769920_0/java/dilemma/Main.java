import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in=new Scanner(new File("D-small-attempt0.in"));
		PrintWriter out=new PrintWriter("D-small-attempt0.out");
		//InputReader in=new InputReader(System.in);
		//PrintWriter out=new PrintWriter(System.out);
		//Scanner in=new Scanner(System.in);
		
		int pi=in.nextInt();
		for(int qi=1;qi<=pi;qi++){
			int k=in.nextInt();
			int c=in.nextInt();
			int s=in.nextInt();
			out.print("Case #"+qi+":");
			for(int i=1;i<=s;i++){
				out.print(" "+i);
			}
			out.println();
		}
		
		out.close();
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