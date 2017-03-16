import java.io.*;
import java.util.*;
 
class Ovation
{
   public static void main(String args[]) throws IOException
   {
      String s;
      BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
      StringTokenizer st = new StringTokenizer(f.readLine());
      
      int n = Integer.parseInt(st.nextToken());
      for(int i=0;i<n;i++){
    	   st = new StringTokenizer(f.readLine());
		   int num = Integer.parseInt(st.nextToken());
		   int[] mat = new int[num+1];
		   s = st.nextToken();
		   for(int j=0;j<=num;j++)
			   mat[j] = Integer.parseInt(s.substring(j, j+1));
		   int extra = 0,stand = 0;
		   for(int j=0;j<=num;j++){
			   if(j>stand){
				   extra+=j-stand;
				   stand+=j-stand;
			   }
			   stand+=mat[j];
		   }
		   out.format("Case #%d: %d\n",i+1,extra);
	   }
      out.close();                                 
      System.exit(0);  
   }
}