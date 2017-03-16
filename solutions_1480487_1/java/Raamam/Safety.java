import java.io.*;
import java.util.*;
import java.math.*;

public class Safety {
	
	class Case{
		int[] input;
		public Case(int[] input){
			this.input = input;
		}
		public double[] getResult(){
			long sum = 0;
			MathContext mc = new MathContext(8, RoundingMode.HALF_UP);
			for(int i=1; i<input.length; i++){
				sum = sum + input[i];
			}			

			double[] output = new double[input.length-1];
			for(int i=1; i<input.length; i++){				
//				if((2*sum) - (output.length*input[i]) < 0){
//					output[i-1] = 0.0;
//				}
//				else{
					output[i-1] = (double)((2*sum) - (output.length*input[i]))/(output.length * sum) ;				
//				}
			}
//			double percentSum = 0.0;
//			for(int i=0; i<output.length; i++){
//				percentSum = percentSum + output[i];
//			}
//			for(int i=0; i<output.length; i++){
//				output[i] = new BigDecimal(100 * output[i]/percentSum, mc).doubleValue();
//			}

			double maxnegative = 0.0;
			int countnegatives = 0;
			for(int i=0; i<output.length; i++){
				if(output[i] < 0){
					//maxnegative = output[i];
					countnegatives++;
				}
			}

			for(int i=0; i<output.length; i++){
				if(output[i] < 0){
					maxnegative = output[i];
					for(int j=0; j<output.length; j++){
						if(i == j){
							output[j] = 0.0;
						}
						else if( output[j] > 0){
							output[j] = output[j] + (maxnegative/(output.length - countnegatives));
						}
					}
				}
			}

			for(int i=0; i<output.length; i++){
				output[i] = new BigDecimal(100 * output[i], mc).doubleValue();
			}


			return output;
		}
	}

	public Safety(String file){
		BufferedReader in = null;
		PrintWriter out = null;

		try{
		    in = new BufferedReader(new InputStreamReader(new DataInputStream(new FileInputStream(file+"/input.txt"))));
			out = new PrintWriter(new BufferedWriter(new FileWriter(file+"/output.txt")), true);

			int caseId = 1;
			double result[] = null;
			String line = null;
			Case c = null;

			in.readLine(); //no of cases

			while ((line = in.readLine()) != null)   {
				c = new Case(getIntArray(line));
				result = c.getResult();
				System.out.print("Case #"+caseId+ ":");
				for(int i=0; i<result.length; i++){
					System.out.print(" "+result[i]);				
				}
				System.out.println();
				
				out.print("Case #"+caseId+ ":");
				for(int i=0; i<result.length; i++){
					out.print(" "+result[i]);				
				}
				out.println();
				
				caseId++;
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
		finally{
			try{ out.close(); } catch(Exception ignored){}
			try{ in.close(); } catch(Exception ignored){}
		}

	}

	public String[] getStringArray(String str){
		return str.split("\\s+");
	}

	public int[] getIntArray(String str){
		String[] sArray = getStringArray(str);
		int[] iArray = new int[sArray.length];
		for(int i=0; i<sArray.length; i++){
			iArray[i] = Integer.parseInt(sArray[i]);
		}

		return iArray;
	}

	public double[] getDoubleArray(String str){
		String[] sArray = getStringArray(str);
		double[] dArray = new double[sArray.length];
		for(int i=0; i<sArray.length; i++){
			dArray[i] = Double.parseDouble(sArray[i]);
		}

		return dArray;
	}
		
	public static void main(String args[]) throws Exception {
		Safety obj = new Safety(args[0]);
	}
	
}