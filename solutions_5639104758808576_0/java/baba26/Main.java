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
			
			int ans = 0 ; 
			
			int n = sc.nextInt();
			String shyness = sc.next();
			
			int[] shy = new int[n+1];
			int[] array = new int[n+1];
			
			for( int i = 0 ; i <= n; ++i )
				shy[i] = shyness.charAt(i) - '0' ;
			
			array[0] = 0 ; 
			
			for( int i = 1 ;  i <= n ; ++i) {
			
				array[i] = array[i-1] + shy[i-1];
				ans += Math.max( i - array[i] , 0 );
				array[i] = Math.max( i , array[i]);
				
			}
			
			System.out.printf("Case #%d: %d\n",caseNo , ans);
			
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
