import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {

	public static void main(String args[]){
		
		BufferedReader br = new BufferedReader( new InputStreamReader(System.in),8*1024);
		Scanner sc = new Scanner( br );
		
		int t = sc.nextInt();
		
		for( int caseNo = 1 ; caseNo <= t ; ++caseNo){
			
			int x = sc.nextInt();
			int r = sc.nextInt();
			int c = sc.nextInt();
			
			
			int s = Math.min( r , c);
			int b = Math.max( r , c);
			
			
			System.out.printf("Case #%d: %s\n",caseNo , ans(x,s,b));
			
		}
		
	}
	
	
	// can be blocked = RICHARD
	// can't be blocked = GABRIEL
	
	static String ans( int x , int s , int b ){
		
		if( x >= 7 ) // can be blocked always
			return "RICHARD";
		
		if( x == 1 ) // can never be blocked
			return "GABRIEL";
		
		if( (s*b)%x != 0 )  // can not be filled
			return "RICHARD";
		
		if( x == 2 ){
			
			if( b >= 2 ) // can't be blocked
				return "GABRIEL";
			
			else // can be blocked
				return "RICHARD";
		}
		
		if( x == 3 ){
					
				if( s == 1 ) // can be blocked
					return "RICHARD";
				
				else  // can never be blocked
					return "GABRIEL";
				}
		
		if( x == 4 ){
			
			if( s <= 2 ) // always blocked
				return "RICHARD";
			
			else
				return "GABRIEL";
			
		}
		
		if( x == 5 ){
			
			if( s <= 2 ) // can be blocked
				return "RICHARD";
			
			else  // never blocked
				return "GABRIEL";
		}
		
				
		if( x == 6 ){
					
					if( s <= 3 ) // can be blocked
						return "RICHARD";
						
					else  // never blocked
						return "GABRIEL";
				}


		return "locha";
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
