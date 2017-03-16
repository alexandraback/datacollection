import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Round1AA2 {

	/**
	 * @param args
	 */
	
	static int t =0;
	//static ArrayList<ArrayList<String>> table = new ArrayList<ArrayList<String>>();	

		public static void inputF() throws FileNotFoundException{
			
			File inputFile = new File("A-large.in");
			Scanner in = new Scanner(inputFile);
			File outputFile = new File("A-large.out");
			PrintWriter out = new PrintWriter(outputFile);
			String result="";
			String input ="";
			
			int t,a,b=0;
			double[] list;
			
			t = in.nextInt();
			//System.out.println(n);
			input = in.nextLine();
			for (int i=1; i<=t; i++) {
				a = in.nextInt();
				b = in.nextInt();
				
				list = new double[a];
				for (int j=0; j<a; j++) {
					list[j]=in.nextDouble();
				}
				
				//System.out.println("length of the list: "+list.length);
				//result = "Case #"+i+ ": "+ count(a,b,list);
				//out.(result);
				out.format("Case #%d: %.6f%n",i, count(a,b,list));
				//System.out.format("%.3f%n", pi)
			}
			in.close();
			out.close();
		}



	private static Double count(int a, int b, double[] list) {
			double result=b+2;
			//double[] matrix = new double[];
			ArrayList<Double> matrix = new ArrayList<Double>(); 
			double[] pos = new double[a+1];
			
			if (a==1){
				result=Math.min(2*b+1-list[0]-b*list[0], b+2);
			} else {
				
				pos[0]=list[0];
				
				for (int i=1;i<a;i++) {
					pos[i]=pos[i-1]*list[i];
				//	System.out.println(pos[i]);
				}
	
				
				for (int i=0; i<a; i++) {
				//	System.out.println((b-a+i*2+1)*pos[a-1-i]);
				   matrix.add((b-a+i*2+1)*pos[a-1-i]+(2*b-a+(1+i)*2)*(1-pos[a-1-i]));
				 //  System.out.println(i+": "+matrix.get(i));
				   if (result>matrix.get(i)) {
					   result=matrix.get(i);
				   }
				}
				if (result>(a+b+1)){
					result = a+b+1;
				}
			}
			return result;
		}



	public static void main(String[] args) throws FileNotFoundException {
		inputF();

	}

}