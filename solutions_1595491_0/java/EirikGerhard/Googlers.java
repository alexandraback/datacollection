import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class Googlers {
public static void main(String[] args) throws Exception {
	String file="B-small-attempt3.in";
	String oFile="B-small-attempt3.out";
	BufferedReader br = new BufferedReader(new FileReader(file));
	BufferedWriter bw = new BufferedWriter(new FileWriter(oFile));
	int cases = Integer.parseInt(br.readLine());
	for(int i=1; i<=cases; i++)
	{
		bw.write("Case #"+i+": ");
		String line = br.readLine();
		String[] lineElems = line.split(" ");
		int N= Integer.parseInt(lineElems[0]);//Googlers
		int S= Integer.parseInt(lineElems[1]);//Surprising Scores
		int p= Integer.parseInt(lineElems[2]);//P score
		//here come the points
		int surprises=0;
		int goodlers=0;
		int lim = 3*(p-2)+1;
		for(int j=3; j< N+3; j++)
		{
			int score_i = Integer.parseInt(lineElems[j]);
			
			if(score_i>lim+2)
			{	
				goodlers++;
			}
			if(score_i<= lim+2 && score_i>lim && score_i>1)
			{
				surprises++;
			}
		}
		goodlers+=Math.min(S, surprises);
		bw.write(""+goodlers);
		bw.newLine();
	}
	br.close();
	bw.close();
}
}
