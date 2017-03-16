import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class A {

	public static void main(String[]args){
		
		try {
			BufferedReader reader = new BufferedReader(new FileReader(new File("A-large.in")));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out")));
			DecimalFormat format = new DecimalFormat("0.000000"); 
			
			int T = Integer.parseInt(reader.readLine());
			for(int i = 0;i<T;i++){
				
				
				String[] paras = reader.readLine().split(" ");
				String[] ps    = reader.readLine().split(" ");
				int A        = Integer.parseInt(paras[0]);
				int B		 = Integer.parseInt(paras[1]);
				float [] p   = new float[A];
				for(int j=0;j<A;j++){
					p[j] = Float.parseFloat(ps[j]);
					if(j>0){
						p[j] = p[j]*p[j-1];
					}
				}
				
				
				float Min    = Float.MAX_VALUE;
				float temp   = 0;
				
				Min = B + 2;
				
				for(int j = A-1;j>=0;j--){
					
					temp = p[j]*(B-A+2*(A-1-j)+1) + (1-p[j])*(B-A+2*(A-1-j)+1+B+1);
					if(Min>temp)
						Min = temp;
				}
				
				temp = A + B +1;
				if(Min > temp)
					Min = temp;
				  
				writer.write("Case #"+(i+1)+": "+format.format(Min)+"\n");
				writer.flush();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
