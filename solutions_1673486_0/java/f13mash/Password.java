import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Password {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int cases=Integer.parseInt(br.readLine().trim());
		
		for(int t=1;t<=cases;t++){
			String ln=br.readLine().trim();
			String[] splts=ln.split(" ");
			
			int typed=Integer.parseInt(splts[0]);
			int size=Integer.parseInt(splts[1]);
			double[] prob=new double[typed];
			
			ln=br.readLine().trim();
			ln.split(" ");
			splts=ln.split(" ");
			
			for(int i=0;i<typed;i++){
				prob[i]=Double.parseDouble(splts[i]);
			}
			
			double[] backspace=new double[typed+1];
			double[] rightProb=new double[typed];
			//double[] rightProbSum=new double[typed];
			
			double prev=1;
			for(int i=0;i<typed;i++){
				rightProb[i]=prev*prob[i];
				prev=rightProb[i];
			}
			
			double min=Double.MAX_VALUE;
			for(int bk=1;bk<=typed;bk++){
				double p;
				if(typed==bk){
					p=1;
				}
				else{
					p=rightProb[typed-bk-1];
				}
				
				int keys=0;
				
				
				if(typed==bk){
					keys=bk+size+1;
				}
				else{
					keys=size-typed+1+2*bk;
					backspace[bk]+=(1-p)*(keys+size+1);
				}
				
				backspace[bk]+=(p*keys);
				if(backspace[bk]<min)
					min=backspace[bk];
				//System.out.println("bk : "+bk+" : "+backspace[bk]+" : "+p+" : "+keys);
			}
			//System.out.println("min : "+min);
			double kes0=0;
			double p1=rightProb[typed-1];
			
			kes0+=(p1*(size-typed+1));
			kes0+=((1-p1)*(2*size+2-typed));
			
			double kes1=0;
			kes1=1*(2+size);

			min=Math.min(min, kes0);
			min=Math.min(min, kes1);
			System.out.println("Case #"+t+": "+min);
		}
	}

}
