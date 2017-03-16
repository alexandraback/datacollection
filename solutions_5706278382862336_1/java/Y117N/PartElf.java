import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class PartElf {
	public static void main(String[] args) throws IOException{
		 BufferedReader in = new BufferedReader(new FileReader("input1C_A/A-large.in"));//TODO: change
		 PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("input1C_A/sol.out")));//TODO: change
		 //DecimalFormat df = new DecimalFormat("###.0000000");
		 String str = in.readLine();
		 int cases = Integer.valueOf(str);
		 for(int i=1; i<=cases;i++){
			 str= in.readLine();
			 
			 String[] input=str.split("/"); //input stored as input[0],input[1],...
			 long P = Long.parseLong(input[0]);
			 long Q = Long.parseLong(input[1]);
			 String ans="impossible";
			 int count=check(P,Q);
			 if(count>=0)
				 ans=""+count;
			 
			 if(i<cases){
				out.print("Case #"+i+": ");
			 	out.println(ans);
			 }
			 else{
				 out.print("Case #"+i+": ");
				 out.print(ans);
			 }
			 
		 }
		 out.close();
		 System.out.println("System terminated");
	}
	public static int check(long P, long Q){
		int count=0;
		 if(P==Q){
			 return 0;
		 }
		 else{
			 long[] pq = reduce(P,Q);
			 P=pq[0];
			 Q=pq[1];
			 
			 while(Q%2==0){
				 count++;
				 Q/=2;
			 System.out.println("P:"+P+" Q:"+Q);
				 if(P>=Q){
					 P-=Q;
					 if(P==0){
						 return count;
					 }
					 else{
						 int temp = check(P,Q);
						 if(temp>=0)
							 return count;
						 else
							 return -1;
					 }
				 }
				 pq = reduce(P,Q);
				 P=pq[0];
				 Q=pq[1];
			 }
			 return -1;
		 }
		 
	}
	public static long[] reduce(long P, long Q){
		long g=gcm(P,Q);
		long[] pq = new long[2];
		pq[0]=P/g;
		pq[1]=Q/g;
		return pq;
	}
	public static long gcm(long a, long b) {
	    return b == 0 ? a : gcm(b, a % b); 
	}

}
