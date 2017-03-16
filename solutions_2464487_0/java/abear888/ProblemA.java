import java.io.*;
import java.util.*;


public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		//BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/ruth/My Documents/alvin/test.in.txt"));
		BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/ruth/My Documents/alvin/Computer Science/Code Jam/A-small-attempt0.in"));
		//BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/ruth/My Documents/alvin/Computer Science/Code Jam/A-large.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("C:/Documents and Settings/ruth/My Documents/alvin/test.out.txt")));
		int numcases=Integer.parseInt(x.readLine());
		for (int cases=1; cases<=numcases; cases++){
			StringTokenizer st=new StringTokenizer(x.readLine());
			long startradius=Long.parseLong(st.nextToken());
			long amountpaint=Long.parseLong(st.nextToken());
			long radius=startradius+1;
			long counter=0;
			while (amountpaint>0){
				long tobepainted=(radius*radius)-((radius-1)*(radius-1));
				if (amountpaint>=tobepainted){
					amountpaint=amountpaint-tobepainted;
					counter++;
				}
				else break;
				radius=radius+2;
			}
			out.println("Case #"+cases+": "+counter);
		}
		out.close();
		System.exit(0);
	}

}
