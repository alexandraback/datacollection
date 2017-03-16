import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Enclosure {
	public static void main(String[] args) throws IOException{
		 BufferedReader in = new BufferedReader(new FileReader("input1C_C/C-small-attempt0.in"));//TODO: change
		 PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("input1C_C/sol.out")));//TODO: change
		 //DecimalFormat df = new DecimalFormat("###.0000000");
		 String str = in.readLine();
		 int cases = Integer.valueOf(str);
		 for(int i=1; i<=cases;i++){
			 str= in.readLine();
			 
			 String[] input=str.split("\\s"); //input stored as input[0],input[1],...
			 int N = Integer.parseInt(input[0]);
			 int M = Integer.parseInt(input[1]);
			 int K = Integer.parseInt(input[2]);
			 int n=1;
			 int m=1;
			 int ans=0;
			 int almostfill=0;
			 if(K<=4)
				 ans=K;
			 else{
				 if(N>2 && M>2){
					while(n*m+2*n+2*m<K){
					 	if(n>m && m<M-2)
						 	m++;
					 	else if(n>=m && n<N-2)
						 	n++;
					 	else if(m<M-2)
						 	m++;
					 	else{
					 		almostfill=1;
					 		break;
					 	}
				 	}
				 	if(almostfill==1){
					 	int j=0;
					 	while(n*m+2*n+2*m+j<K)
						 	j++;
					 	ans=2*m+2*n+j;
				 	}
				 	else if(K==(n-1)*(m-1)+2*(n-1)+2*(m-1)+1)
					 	ans=(n-1)*2+(m-1)*2+1;
				 	else
				 		ans=2*m+2*n;
				 }
				 else
					 ans=K;
			 }
			 
			 
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

}
