import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.text.*;

class Falling{
	public static void main (String [] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("falling.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("falling.out")));
		int numCases = Integer.parseInt(f.readLine());
		
		for(int time=1; time<=numCases; time++){
			StringTokenizer st=new StringTokenizer(f.readLine());
			int N =Integer.parseInt(st.nextToken());
			int X = Integer.parseInt(st.nextToken());
			int Y= Integer.parseInt(st.nextToken());
			int layer=0; 
			while((2*(layer+1)+1)*((layer+1)+1)<=N)
				layer++;
			int left=N-(2*layer+1)*(layer+1);
			double prob=0;
			if (X==0){
				if (Y%2==1){
					prob=0;
				}
				else{
					if (Y/2<=layer){
						prob=1;
					}
					else
						prob=0;
				}
			}
			if (X<0){
				int position=1;
				while(Y!=0){
					Y--;
					X--;
					position++;
				}
				if (X%2==-1){
					prob=0;
				}
				else{
					int onLayer=X/-2;
					
					if (onLayer<=layer){
						prob=1;
					}
					else if (onLayer==layer+1){
						if (left>=2*onLayer+position)
							prob=1;
						else{
							for(int i=position; i<=left; i++){
								prob+=combo(i-1, position-1)/Math.pow(2, i);
							}
						}
							
						
					}
					else
						prob=0;
				}
				
					
			}
			if (X>0){
				int position=1;
				while(Y!=0){
					Y--;
					X++;
					position++;
				}
				if (X%2==1){
					prob=0;
				}
				else{
					int onLayer=X/2;
					
					if (onLayer<=layer){
						prob=1;
					}
					else if (onLayer==layer+1){
						if (left>=2*onLayer+position)
							prob=1;
						else{
							for(int i=position; i<=left; i++){
								prob+=combo(i-1, position-1)/Math.pow(2, i);
							}
						}
							
						
					}
					else
						prob=0;
				}
			}
			
			
			out.println("Case #"+time+": "+prob);
		}
                   
		out.close();                                  
		System.exit(0);                               
	}
	
	 static double combo(int a, int b){
		 BigInteger temp=new BigInteger("1");
		 for(int i=0; i<b; i++){
			 temp=temp.multiply(new BigInteger(Integer.toString(a-i)));
		 }
		 for(int i=1; i<=b; i++){
			 temp=temp.divide(new BigInteger(Integer.toString(i)));
		 }
		 return temp.doubleValue();
	 }
}