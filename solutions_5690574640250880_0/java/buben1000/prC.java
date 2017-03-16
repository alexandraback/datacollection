import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

//remember to change task name; change public class name!
public class prC {

	static void solve() throws Exception{
		int t=nextInt();
		for(int k=1;k<t+1;k++)
		{
			out.println("Case #" + k + ":");
			int r=nextInt();
			int c=nextInt();
			int m=nextInt();
			char[][]mat=new char[r][c];
			for(int row=0;row<r;row++){
				for(int col=0;col<c;col++){
					mat[row][col]='*';
				}
			}
			int remspaces=r*c-m;

			if(remspaces==1)mat[0][0]='c';
			else if(r==1||c==1){
				if(r==1){
					for(int j=0;j<remspaces;j++)mat[0][j]='.';
				}
				else if(c==1)for(int j=0;j<remspaces;j++)mat[j][0]='.';
			}

			else if(r==2||c==2){
				if(remspaces%2==1||remspaces==2){
					out.println("Impossible");
					continue;
				}
				else if(r==2){
					for(int j=0;j<remspaces/2;j++){
						mat[0][j]=mat[1][j]='.';
					}
				}
				else if (c==2){
					for(int j=0;j<remspaces/2;j++){
						mat[j][0]=mat[j][1]='.';
					}
				}
			}
			else if (remspaces==2||remspaces==3||remspaces==5||remspaces==7){

				assert(r>=3&&remspaces>=3);
				out.println("Impossible");
				continue;
			}
			else if(remspaces==4||remspaces==6){
				mat[0][0]=mat[1][0]=mat[0][1]=mat[1][1]='.';
				if(remspaces==6){
					mat[2][0]=mat[2][1]='.';
				}
			}
			else{
				//remspaces>=8,start at 3.
				mat[0][0]=mat[1][0]=mat[0][1]=mat[1][1]=mat[2][0]=mat[2][1]=mat[0][2]=mat[1][2]='.';
				remspaces-=8;
				for(int j=3;j<r&&remspaces>=2;j++){
					mat[j][0]=mat[j][1]='.';
					remspaces-=2;
				}
				for(int j=3;j<c&&remspaces>=2;j++){
					mat[0][j]=mat[1][j]='.';
					remspaces-=2;
				}
				for(int y=2;y<r&&remspaces>0;y++){
					for(int x=2;x<c&&remspaces>0;x++){
						mat[y][x]='.';
						remspaces--;
					}
				}
				assert(remspaces==0);//

			}
			mat[0][0]='c';
			for(int y=0;y<r;y++){
				for(int x=0;x<c;x++){
					out.print(mat[y][x]);
				}
				out.println();
			}
		}
	}

	public static void main(String[] args) throws Exception {
		String filename="C-small-attempt2";// change name here!
		in = new BufferedReader(new FileReader(filename+".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename+".out")));

		//	setTime();
		solve();
		in.close();
		//printTime();
		//	printMemory();
		out.close();
		System.exit(0);
	}
	static double time;
	static void setTime(){
		time=System.currentTimeMillis();
	}
	static void printTime(){
		System.err.println("Time consumed (sec): "+(System.currentTimeMillis()-time)/1024);
	}
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok = new StringTokenizer("");
	//	static long systemTime;
	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime()
				.freeMemory()) / 1000 + " kb");
	}
	static void println(Object o){
		out.println(o);
		//	System.err.println(o);
	}
	static void print(Object o){
		out.print(o);
		//	System.err.print(o);
	}

	static String nextLine() throws Exception{
		return in.readLine();
	}
	static String next() {//if !hasNext returns null
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}