import java.io.DataInputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileWriter;


public class Ex1 {

	/*
	public static void main(String[] args) {
		System.out.println("Hello World");
		System.out.println( (23&23) );
		int [] a = new int [3];
		double [] b;
		int n = 3;
		a[0] = 24;
		a[1] = 30;
		a[2] = 21;
		//a[3] = 25;
		b = minimum(n,a);
		for (int j=0;j<n;j++){
			System.out.println( b[j]+" " );
		}
		
	}
	*/
	
	
	public static void main(String[] args) {

		
		try{
			FileInputStream infile = new FileInputStream("in");
			DataInputStream datain = new DataInputStream(infile);
			//Reader reader = new InputStreamReader(new FileInputStream(infile));
			FileWriter writer = new FileWriter("out", false);
			String s = datain.readLine();
			Integer k = new Integer(s);

			
			for (int i=1;i<=k;i++){
				s = datain.readLine();
				String [] StringSet = s.split(" ");
				Integer num = new Integer(StringSet[0]);
				int [] points = new int[num];
				
				for (int j=0;j<num;j++){
					points[j] = Integer.parseInt(StringSet[j+1]);
				}
				
				double [] necessary = minimum(num,points);
				
				writer.append("Case #"+i+": ");

				for( int ib=0;ib<num;ib++){
					writer.append(""+necessary[ib]);
					if (ib!=num-1){
						writer.append(" ");
					}
				}
				writer.append("\n");
			}
			infile.close();
			datain.close();
			writer.close();
				
				
				
				
/*				
				Integer [] NumSet = new Integer[N];
				boolean [] IsChooseA = new boolean[N];
				boolean [] IsChooseB = new boolean[N];			
				
				for (int j=0;j<N;j++){
					NumSet[j] = new Integer(StringSet[j+1]);
				}
	
				if (Choose(IsChooseA,IsChooseB,NumSet)){
					for( int ia=0;ia<N;ia++){
						if (IsChooseA[ia])
							System.out.print(NumSet[ia]+" ");
					}
					System.out.println();
					for( int ib=0;ib<N;ib++){
						if (IsChooseB[ib])
							System.out.print(NumSet[ib]+" ");
					}
					System.out.println();
				}
				
				writer.append("Case #"+i+":"+"\n");
				for( int ia=0;ia<N;ia++){
					if (IsChooseA[ia])
						writer.append(NumSet[ia]+" ");
				}
				writer.append("\n");
				for( int ib=0;ib<N;ib++){
					if (IsChooseB[ib])
						writer.append(NumSet[ib]+" ");
				}
				writer.append("\n");
			}
			infile.close();
			datain.close();
			writer.close();
*/			
		}catch(EOFException e){

		}catch (Exception e) {
			//infile.close();
            e.printStackTrace();
        }
	}
	
	static double[] minimum (int n, int[] value){
		int m = n ;
		double X=0 ;
		double remains=0 ;
		double[] necessary  = new double[n];
		boolean modified = true ;
		boolean[] won = new boolean[n] ;
		for(int i=0 ; i<n ; i++){
			X=X+(double)value[i]; won[i]=true;
		}
		remains = 2*X;
		while(modified){
			modified = false;
			for(int j=0 ; j<n ; j++){
				if (won[j]&&((double)value[j]>=remains/(double)m)){
					won[j]=false; modified=true;m--;
					remains = remains-(double)value[j];
				}
			}
		}
		for(int i=0 ; i<n ; i++){
			if(!won[i]){
				necessary[i]=0;
			}
			else{
				necessary[i]=100*(remains/(double)m - (double)value[i]) / (double)X;
			}

		}
		return necessary;
	}
}

