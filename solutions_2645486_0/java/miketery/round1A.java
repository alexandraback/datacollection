import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class round1A {

	public round1A() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] lines=readFile("input.in");
		//gogo(lines);
		gogoB(lines);
	}
	
	public static void gogoB(String[] lines) {
		int T=Integer.parseInt(lines[0]);
		int os=1;
		String output="";
		for(int i=0; i<T; i++) {
			String[] line=lines[os].split(" ");
			int E=Integer.parseInt(line[0]);
			int R=Integer.parseInt(line[1]);
			int N=Integer.parseInt(line[2]);
			int[] act=new int[N];
			line=lines[os+1].split(" ");
			for(int j=0; j<N; j++) {
				act[j]=Integer.parseInt(line[j]);
			}
			int num=0;
			if(R>=E) {
				for(int j=0;j<N;j++){
					num+=E*act[j];
				}
			}
			else {
				num=recursiveB(act,E,E,R,0,0);				
			}	
			output+="Case #"+(i+1)+": "+num+"\n";
			//System.out.println(output);
			os=os+2;
		}
		
		System.out.println(output);
	}
	public static int recursiveB(int[] a, int Emax, int Ecur, int R, int out, int pos){
		if(pos==a.length)
			return out;
		int max=0; int tmp;
		for(int i=0; i<=Emax; i++) {
			if(Ecur-i<0)
				i=Emax+1;
			else {
				int Enew=Ecur-i+R;
				if(Enew>Emax)
					Enew=Emax;
				tmp=recursiveB(a,Emax,Enew,R,out+i*a[pos],pos+1);
			    if(tmp>max)
			    	max=tmp;
			}
		}
		return max;
	}
	public static void gogo(String[] lines) {
		int T=Integer.parseInt(lines[0]);
		int os=1;
		String output="";
		for(int i=0; i<T; i++) {
			String[] line=lines[os+i].split(" ");
			double  r=Double.parseDouble(line[0]);
			double t=Double.parseDouble(line[1]);
			int num=0;
			double ring=(r+1)*(r+1)-r*r;
			while(ring<=t) {
				num++;
				t-=ring;
				r=r+2;
				ring=(r+1)*(r+1)-r*r;
			}
			
			output+="Case #"+(i+1)+": "+num+"\n";
			//System.out.println(output);
			
		}
		
		System.out.println(output);
	}
	
	public static void problemC(String[] lines) {
		int T=Integer.parseInt(lines[0]);
		int os=1;
		String output="";
		for(int i=0; i<T; i++) {
			String[] line=lines[os+i].split(" ");
			int A=Integer.parseInt(line[0]);
			int B=Integer.parseInt(line[1]);
			int num=0;
			for(int n=A; n<=B; n++) {
				if(isPalindrome(n) && sqrtIsInt(n) && isPalindrome((int) Math.sqrt(n)))
					num++;
			}
			output+="Case #"+(i+1)+": "+num+"\n";
		}
		System.out.println(output);
	}
	
	
	
	public static boolean isPalindrome(int x) {
		char[] chars = ("" + x).toCharArray();
		for(int i=0; i<chars.length/2; i++) {
			if(chars[i]!=chars[chars.length-i-1]) {
				return false;
			}
		}
		return true;
	}
	
	public static boolean sqrtIsInt(int x) {
		return Math.pow(((int) Math.sqrt((double) x)),2)==x;
	}
	
	public static void problemB(String[] lines) {
		int T=Integer.parseInt(lines[0]);
		int os=1; //offset
		String output="";
		for(int i=0; i<T; i++) {
			//get NxM param
			//int N=Character.getNumericValue(lines[os].charAt(0));
			String[] NM=lines[os].split(" ");
			int N=Integer.parseInt(NM[0]);
			int M=Integer.parseInt(NM[1]);
			//load lawn into 2D array
			int[][] lawn=new int[N][M];
			os++;
			for(int n=0; n<N; n++) { 
				String[] line=lines[os+n].split(" ");
				for(int m=0; m<M; m++) {
					lawn[n][m]=Integer.parseInt(line[m]);					
				}				
			}
			output+="Case #"+(i+1)+": "+solveLawn(lawn,N,M)+"\n";			
			os+=N; //increment offset for next input
		}
		System.out.println(output);
	}
	
	public static String solveLawn(int[][] lawn, int N, int M) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				int t=0;
				for(int n=0; n<N; n++) {
					if(lawn[i][j]<lawn[n][j]) {
 						t++;
 						n=N;
					}
				}
				for(int m=0; m<M; m++) {
					if(lawn[i][j]<lawn[i][m]) {
 						t++;
 						m=M;
					}
				}
				if(t==2) {
					return "NO";
				}
			}
		}
		return "YES";
	}
	
	public static void problemA(String[] lines) {
		int T=Integer.parseInt(lines[0]);
		int offset=1;
		String output="";
		for(int i=0; i<T; i++) {
			char[][] square=new char[4][4];
			for(int j=0; j<4; j++) {
				square[j]=lines[offset+j].toCharArray();
				//System.out.println(lines[offset+j]);
			}
			offset=offset+5;
			//System.out.println(solveSquare(square));
			//return;
			output+="Case #"+(i+1)+": "+solveSquare(square)+"\n";
		}
		System.out.print(output);
		return;
		
	}
	
	public static String solveSquare(char[][] square) {
		String output;
		char[] test=new char[4];
		//do diagonals
			//diag 1
			for(int i=0; i<4; i++)
				test[i]=square[i][i];
			output=testRow(test);
			if(!output.equals(""))
				return output;
			//diag 2
			char[] test1=new char[4];
			for(int i=0; i<4; i++)
				test1[i]=square[3-i][i];
			output=testRow(test1);
			if(!output.equals(""))
				return output;
			
		//Horizontal
			char[] test2=new char[4];
			
			for(int i=0; i<4; i++) {
				test2=square[i];
				output=testRow(test2);
				if(!output.equals(""))
					return output;
			}
		//verticals
			for(int i=0; i<4; i++) {
				char[] test3=new char[4];
				
				for(int j=0; j<4; j++) {
					test3[j]=square[j][i];
				}
				//System.out.println(new String(square[3]));
				output=testRow(test3);
				if(!output.equals(""))
					return output;
			}
		//else check if any blank spaces
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				if(square[i][j]=='.')
					return "Game has not completed"; 
			}
		}
		//else its a draw
		return "Draw";
	}
	
	public static String testRow(char[] row) {
		int X=0; int O=0; int T=0;
		for(int i=0; i<4; i++) {
			if(row[i]=='.')
				return "";
			if(row[i]=='X')
				X++;
			if(row[i]=='O')
				O++;
			if(row[i]=='T')
				T++;
		}
		//String x=new String(row);
		//System.out.println(x+" "+X+" "+O+" "+T);
		if((O+T)==4) 
			return "O won";
		if((X+T)==4)
			return "X won";
		return "";
	}
	
	public static String[] readFile(String fileName) {
		String[] lines=new String[0];
		try { //read file and all lines
		    FileReader file = new FileReader(fileName);
		    BufferedReader reader = new BufferedReader(file);
		    String line;//=reader.readLine();
		    while((line=reader.readLine()) != null) {
		        lines=push(lines,line);
		    }
		    reader.close();
		} catch (FileNotFoundException e) {
			throw new RuntimeException("File not found");
		} catch (IOException e) {
			throw new RuntimeException("IO Error occured");
		}
		return lines;
	}
	
	public static String[] push(String[] array, String push) {
	    String[] longer = new String[array.length + 1];
	    for (int i = 0; i < array.length; i++)
	        longer[i] = array[i];
	    longer[array.length] = push;
	    return longer;
	}

}
