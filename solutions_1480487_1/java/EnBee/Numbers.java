package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Numbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<String> input=new ArrayList<String>();
		List<String> output=new ArrayList<String>();
		try{
			  // Open the file that is the first 
			  // command line parameter
			  FileInputStream fstream = new FileInputStream("c:/input/x.in");
			  // Get the object of DataInputStream
			  DataInputStream in = new DataInputStream(fstream);
			  BufferedReader br = new BufferedReader(new InputStreamReader(in));
			  String strLine;
			  //Read File Line By Line
			  br.readLine();
			  while ((strLine = br.readLine()) != null)   {
			  // Print the content on the console
				//  System.out.println(strLine);
			  input.add(strLine);
			  }
			  //Close the input stream
			  in.close();
			    }catch (Exception e){//Catch exception if any
			  System.err.println("Error: " + e.getMessage());
			  }
		//input done
		//int n[]={20,10};
		for(int j=0;j<input.size();j++){
			String a=input.get(j);
			String b[]=a.split(" ");
			int tn=Integer.parseInt(b[0]);
			int n[]=new int[tn];
			for(int i=0;i<tn;i++){
				n[i]=Integer.parseInt(b[i+1]);
			}
		int nsum=0;
		int rsum=0;
		for(int i=0;i<n.length;i++){
			nsum+=n[i];
			
		}
	//System.out.println(nsum+"$$$$$$$$$$$$$$$$$$$$ "+n.length+" "+n[0]);
		double o[]=new double[n.length];
		String s="";
		int div=n.length;
		for(int i=0;i<o.length;i++){
			if(n[i]>(2*nsum)/n.length){
				div--;
				rsum+=n[i];
			}
		}
		for(int i=0;i<o.length;i++){
			if(n[i]<(2*nsum)/n.length){
				o[i]=(100)*((((2*nsum-rsum)/(double)(div))-n[i])/(double)nsum);
			}
			else{
				o[i]=0;
			}
			 DecimalFormat twoDForm = new DecimalFormat("#.######");
			 s+=Double.valueOf(twoDForm.format(o[i]))+" ";
			
		}
		output.add(s);
		}
		try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(new File("C:/output/Num.out"), true));
            for(int i=0;i<output.size();i++){
            	bw.write("Case #"+(i+1)+": "+output.get(i));
            	bw.newLine();
            }
            bw.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}

}