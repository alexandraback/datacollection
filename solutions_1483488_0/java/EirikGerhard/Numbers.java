import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;
import java.util.Set;


public class Numbers {
public static void main(String[] args) throws Exception {
	String file="C-small-attempt0.in";
	String oFile="C-small-attempt0.out";
	BufferedReader br = new BufferedReader(new FileReader(file));
	BufferedWriter bw = new BufferedWriter(new FileWriter(oFile));
	int cases = Integer.parseInt(br.readLine());
	for(int i=1; i<=cases; i++)
	{
		bw.write("Case #"+i+": ");
		String line = br.readLine();
		String[] lineElems = line.split(" ");
		int A= Integer.parseInt(lineElems[0]);//Googlers
		int B= Integer.parseInt(lineElems[1]);//Surprising Scores
		int dig=lineElems[0].length();
		String n_j;
		int num_j;
		int cont=0;
		String code;
		for(int j=A; j<=B; j++)
		{
			n_j=""+j+""+j;
			ArrayList<String> As  = new ArrayList<String>();
			for(int k=1;k<=dig;k++)
			{
				num_j= Integer.parseInt(n_j.substring(k, k+dig));
				if (num_j>=A && num_j>j &&num_j<=B)
				{
					boolean found=false;
					for (String s: As)
					{
						if(s.compareTo(""+num_j)==0)
						{
							found=true;
							break;
						}
					}
					if(!found)
					{
						cont++;
						As.add(""+num_j);
					}
				}
				
			}
			As =null;
		}
		bw.write(""+cont);
		bw.newLine();
	}
	br.close();
	bw.close();
}
}
