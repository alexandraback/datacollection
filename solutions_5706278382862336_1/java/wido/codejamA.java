import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class codejamA {

	
	public static void main(String[] args) throws IOException {
     
		Scanner x = new Scanner(new File("A.txt"));
	//	Scanner x = new Scanner(System.in);
		
			PrintWriter out = new PrintWriter(new FileWriter("resA.txt"));
		   int cou=1;
		int t=x.nextInt();
		
		int counter=0;
		while(t--!=0){
			counter=0;
			String str=x.next();
			
			String[] arr=str.split("/");
			
			double p=Double.parseDouble(arr[0]);					
			double q=Double.parseDouble(arr[1]);
			
			double res=(p/q);
			
			double b;
			boolean first=false;
			int count=0;

			boolean f=false;
			
			
			
			if((p/q)*2 >=1){
				counter++;
				 b=(p/q)*2-1;	
				 count=counter;
				 f=true;
			}
			else{ b=(p/q)*2;	}	
			
			counter++;
			
			for(int i=0;;i++){
				
				if(b==0||b==1){break;}
				if(counter>40){f=true;break;}
				counter++;
				if(2*b>=1){
					b=2*b-1;					
					if(f==false){count=counter;}
					f=true;
				}else{				
				b*=2;				
				}
			}			
			
		//	System.out.println(counter);
			
			if(counter!=41){	
			
				out.println("Case #"+cou+": "+count);}
			
	else{out.println("Case #"+cou+": impossible");}
			
			cou++;
		}	
		
		
		
		//System.out.println(counter);
		//	out.println(p);			
				out.close();
		
	}

	
}
