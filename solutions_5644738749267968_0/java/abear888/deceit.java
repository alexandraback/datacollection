import java.io.*;
import java.util.*;

public class deceit {

	public static double[]reverse(double[]originalarray){
		for(int i = 0; i < originalarray.length/2; i++)
		{
		    double temp = originalarray[i];
		    originalarray[i] = originalarray[originalarray.length - i - 1];
		    originalarray[originalarray.length - i - 1] = temp;
		}
		return originalarray;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/alvin/My Documents/alvin/Computer Science/Code Jam/deceit.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("C:/Documents and Settings/alvin/My Documents/alvin/test.out.txt")));
		int numcases=Integer.parseInt(x.readLine());
		for (int a=1; a<=numcases; a++){
			int numblocks=Integer.parseInt(x.readLine());
			//initializing
			double []naomiblocks=new double[numblocks];
			double []kenblocks=new double[numblocks];
			StringTokenizer st=new StringTokenizer(x.readLine());
			for (int i=0; i<numblocks; i++){
				naomiblocks[i]=Double.parseDouble(st.nextToken());
			}
			StringTokenizer ab=new StringTokenizer(x.readLine());
			for (int i=0; i<numblocks; i++){
				kenblocks[i]=Double.parseDouble(ab.nextToken());
			}
			Arrays.sort(naomiblocks);
			Arrays.sort(kenblocks);
			double firstken=kenblocks[0];
			int deceitcounter=0;
			while (naomiblocks[deceitcounter]<firstken){
				deceitcounter++;
				if (deceitcounter==numblocks){
					break;
				}
			}
			naomiblocks=reverse(naomiblocks);
			kenblocks=reverse(kenblocks);
			double firstnaomi=naomiblocks[0];
			int tempcounter=0;
			while (kenblocks[tempcounter]>firstnaomi){
				tempcounter++;
				if (tempcounter==numblocks){
					break;
				}
			}
			int finaldeceit=numblocks-Math.max(tempcounter,deceitcounter);
			int kencounter=0;
			int regulartotal=0;
			for (int i=0; i<numblocks; i++){
				if (naomiblocks[i]>kenblocks[kencounter]){
					regulartotal++;
				}
				else{
					kencounter++;
				}
			}
			out.println("Case #"+a+": "+finaldeceit+" "+regulartotal);
		}
		out.close();
		System.exit(0);
	}

}
