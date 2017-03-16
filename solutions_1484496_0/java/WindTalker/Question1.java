import java.io.DataInputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.HashSet;


public class Question1 {

	static boolean Choose(boolean [] IsChooseA, boolean [] IsChooseB, Integer [] NumSet){
		for (int i=0;i<IsChooseA.length;i++){
			IsChooseA[i] = false;
			IsChooseB[i] = false;
		}
		
		for (int i=1;i<1048576;i++){
			for (int j=1;j<1048576;j++){
				if ( (i&j)==0 ){
					int2boolean(IsChooseA,i);
					int2boolean(IsChooseB,j);
					if (isEqual(IsChooseA,IsChooseB,NumSet)){
						return true; 
					}
				}
			}
		}
		return false;
	}
	
	static void int2boolean(boolean [] IsChoose, int i){
		int temp = i;
		for (int j=0;j<IsChoose.length;j++){
			IsChoose[j] = (temp%2 == 1);
			temp = temp/2;
		}
	}
	
	static boolean isEqual(boolean [] IsChooseA, boolean [] IsChooseB, Integer [] NumSet){
		int sumA = 0;
		int sumB = 0;
		for (int i=0;i<IsChooseA.length;i++){
			if (IsChooseA[i]){
				sumA += NumSet[i];
			}
		}
		for (int i=0;i<IsChooseB.length;i++){
			if (IsChooseB[i]){
				sumB += NumSet[i];
			}
		}
		
		return (sumA==sumB);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		
		try{
			FileInputStream infile = new FileInputStream("in");
			DataInputStream datain = new DataInputStream(infile);
			//Reader reader = new InputStreamReader(new FileInputStream(infile));
			FileWriter writer = new FileWriter("out", false);
			String s = datain.readLine();
			Integer k = new Integer(s);
			int N = 20;
			
			for (int i=1;i<=k;i++){
				s = datain.readLine();
				String [] StringSet = s.split(" ");
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
			
		}catch(EOFException e){

		}catch (Exception e) {
			//infile.close();
            e.printStackTrace();
        }
	}
/*				
				Integer A = new Integer(ABstring[0]);
				Integer B = new Integer(ABstring[1]);				
//				int numShift = ABstring[0].length()-1;
//				int numRecycledNum = 0;

				for (int n=A;n<B;n++)
				{
					HashSet<String> nSet = new HashSet<String>();
					int roundShift = 1;
					String stringN = Integer.toString(n);
					stringN = stringN.substring(1) + stringN.charAt(0);
					//nSet.add(stringN);
					
					while (roundShift<=numShift){
						Integer shiftedNum = new Integer(stringN);

						if (n<shiftedNum && shiftedNum<=B && !nSet.contains(stringN)){
							nSet.add(stringN);
							numRecycledNum++;
							//System.out.println(numRecycledNum+": "+n+","+shiftedNum);
						}
						roundShift++;
						stringN = stringN.substring(1) + stringN.charAt(0);
					}
					
				}
				
				writer.append("Case #"+i+": "+numRecycledNum+"\n");
				
				
				
			}
			infile.close();
			datain.close();
			writer.close();
			
			
/*			System.out.print(i);
			writer.append("Case #1"+": ");
			int k = 2;
			while(datain.available()!=0){
				char c = (char) datain.readByte();
				if (c=='\n' && k<=i){
					writer.append('\n');
					writer.append("Case #"+k+": ");
					k++;
				}else{
					char d = mapChar(c);
					writer.append(d);
					//System.out.print(d);
				}
			}
//			writer.flush();
			infile.close();
			datain.close();
			writer.close();
		
			
		}catch(EOFException e){

		}catch (Exception e) {
			//infile.close();
            e.printStackTrace();
        }

	}
*/	
}
