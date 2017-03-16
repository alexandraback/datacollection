import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {

	static int matrix[][];
	public static void main(String args[]){
		
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in),8*1024);
		Scanner sc = new Scanner( br );
		
		
		matrix = new int[][]{
				{0,1,2,3,4,5,6,7},
				{1,4,3,6,5,0,7,2},
				{2,7,4,1,6,3,0,5},
				{3,2,5,4,7,6,1,0},
				{4,5,6,7,0,1,2,3},
				{5,0,7,2,1,4,3,6},
				{6,3,0,5,2,7,4,1},
				{7,6,1,0,3,2,5,4}
		};
		
		int t = sc.nextInt();
		
		for( int caseNo = 1 ; caseNo <= t ; ++caseNo){
			
			int l = sc.nextInt();
			int x = sc.nextInt();
			
			String str = sc.next();
			
			StringBuilder sb = new StringBuilder( str );
			
			
			
			for( int i = 1 ; i < x ; ++i )
				sb = sb.append( str);
			
			int len = l*x;
			int index = 0 ; 
			
			
			boolean I,J,K;
			I = J = K = false;
			
			int product = 0; 
			
			while( index < len && product != 1 ){
			
				int temp = charToInt( sb.charAt(index));
				product = matrix[product][temp];
				++index;
			}
			
			if( product == 1 ) I = true;
			
			product = 0 ; 
			
			while( index < len && product != 2 ){
				
				int temp = charToInt( sb.charAt(index));
				product = matrix[product][temp];
				
				++index;
			}
			
			if(product == 2 ) J = true;
			
			product = 0 ; 
			
			while( index < len && product != 3 ){
				
				int temp = charToInt( sb.charAt(index));
				product = matrix[product][temp];
				++index;
			}
			
			if( product == 3 ) K = true;
			
			product = 0 ; 
			
			while( index < len ){
				int temp = charToInt( sb.charAt(index));
				product = matrix[product][temp];
				++index;
			}
			
			if( I && J && K && ( product == 0))
			System.out.printf("Case #%d: %s\n",caseNo , "YES");
			
			else
				System.out.printf("Case #%d: %s\n",caseNo , "NO");
		}
		
	}
	
	
	// can be blocked = RICHARD
	// can't be blocked = GABRIEL
	static int charToInt(char ch ){
		
		if( ch == 'i') return 1;
		if( ch == 'j' ) return 2;
		if( ch == 'k') return 3;
		
		return -1;
	}
	
	static boolean ans( int product , long exp){
	
		if( product == 0)
		return false;
		
		if( product == 4){
			
			if( exp%2 == 0) return false;
			else return true;
		}
		
		else{
			
			if( exp <= 1 ) 
				return false;
			
			else if( (exp -2 )%4 == 0 )
				return true;
			
			else 
				return false;
		}
	}

	static class MyScanner {
	      BufferedReader br;
	      StringTokenizer st;
	 
	      public MyScanner() {
				br = new BufferedReader( new InputStreamReader(System.in) ,8*1024);
	      }
	 
	      String next() {
	          while (st == null || !st.hasMoreElements()) {
	              try {
	                  st = new StringTokenizer(br.readLine());
	              } catch (IOException e) {
	                  e.printStackTrace();
	              }
	          }
	          return st.nextToken();
	      }
	 
	      int nextInt() {
	          return Integer.parseInt(next());
	      }
	 
	      long nextLong() {
	          return Long.parseLong(next());
	      }
	 
	      double nextDouble() {
	          return Double.parseDouble(next());
	      }
	 
	      String nextLine(){
	          String str = "";
		  try {
		     str = br.readLine();
		  } catch (IOException e) {
		     e.printStackTrace();
		  }
		  return str;
	      }

	   }

	static class MyWriter 
{
	    BufferedWriter bw;

	    public  MyWriter() {
	       bw = new BufferedWriter(new OutputStreamWriter(System.out),8*1024);
	    }

	    void print(String s)
	    {
	    	try {
				bw.write( s , 0 , s.length() );
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	    }
	    
	    void println(String s)
	    {
	    	try {
				bw.write( s , 0 , s.length() );
				bw.newLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	    }

	 void close()
	 {
		 try {
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
	}

}
