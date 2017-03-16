import java.util.Scanner;
import java.io.*;
import java.text.Format;
import java.text.NumberFormat;
import java.text.DecimalFormat;

public final class problemA {
	public static DecimalFormat df = new DecimalFormat("#.000000"); 
	static char[] res = new char[26]; 


	public static double compute(int A, int B, double[] arr){
		/**A descide how many time we should type backspace**/
		int remain = B - A; //how many char are remain
		double min;
		
		double tmpMin;
		
		
		/**just type without backspace**/
		double correct = 1.0;
		for(int i = 0 ; i < A ; i++){
			correct *= arr[i];
		}
		min = tmpMin = correct * (remain + 1) + (1 - correct) * (remain + 1 + B + 1);

		
		//System.out.println("======  " + df.format(tmpMin) + "  =====");
		correct = 1.0;
		
		
		/**how many times of backspace we need to type**/
		int total = A-1;
		
		int backspace = 1;
		
		while(total >= 0){
			
			for(int i = 0 ; i < total ; i++){
				correct *= arr[i];
			}
			
			tmpMin = correct * (backspace * 2 +  remain + 1) + (1 - correct) * (backspace * 2 +  remain + 1 + B + 1);
			//System.out.println("======  " + df.format(tmpMin) + "  =====");
			
			
			if(tmpMin < min)
				min = tmpMin;
			
			
			tmpMin = 0;
			correct = 1.0;
			backspace++;
			total--;
			
			
			
		}
		
		
		
		/**just type enter**/
		tmpMin = B + 2;
		//System.out.println("======  " + df.format(tmpMin) + "  =====");
		if(tmpMin < min)
			min = tmpMin;
		

		
		return min;
	}
	
	
	public static void main(String[] args){
		//Scanner sc = new Scanner(System.in);
		
		try{
			Scanner sc = new Scanner(new File("A-small-attempt0.in"));
			//Scanner sc = new Scanner(new File("test.txt"));
			FileWriter fw = new FileWriter("final.txt");
		
			String tmp = sc.nextLine();
			int step = Integer.valueOf(tmp);
			
			int counter = 1;
			
			int A, B;
			
			while(sc.hasNextLine()){
				//System.out.print("Case #" + counter + ": "); 
				String s = sc.nextLine();
				Scanner ss = new Scanner(s);
				A = ss.nextInt();
				B = ss.nextInt();
				//System.out.println(A + "  " + B);
				double[] tmpArr = new double[A];
				s = sc.nextLine();
				ss = new Scanner(s);
				for(int i = 0 ; i < A ; i ++){
					tmpArr[i] = ss.nextDouble();
					//System.out.print(tmpArr[i]+"  ");
				}
				//System.out.println();
				
				double res = compute(A, B, tmpArr);
				System.out.println("Case #" + counter + ": " + df.format(res)); 
				//System.out.println(df.format(res));
				fw.write("Case #" + counter + ": " + df.format(res));
				fw.write("\n");
				counter++;
				if(step < counter)
					break;
			}
			fw.close();
		}catch(Exception e){}
		
	}
	
}