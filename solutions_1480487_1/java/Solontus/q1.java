import java.io.*;
import java.util.*;
public class q1{
    public static void main (String[] args) throws IOException 
    {
	BufferedReader input = new BufferedReader (new FileReader ("A-large.txt"));
	PrintWriter output = new PrintWriter (new FileWriter("test1Max.txt"));
	StringTokenizer st;
	
	int numlines = Integer.parseInt(input.readLine());
	for(int i = 0; i < numlines; i++){
	    st = new StringTokenizer(input.readLine());
	    int numOfScores = Integer.parseInt(st.nextToken());
	    int[] scores = new int[numOfScores];
	    double sumOfScores = 0;
	    for(int j = 0; j < numOfScores; j++){
		scores[j] = Integer.parseInt(st.nextToken());
		sumOfScores += (double)scores[j];
	    }
	    
	    double percentage[] = new double[numOfScores];
	    double sumOfLow = 0;
	    int numOfLow = 0;
	    double average = (double)(sumOfScores)/(double)(numOfScores);
	    double doubleavgOld = 2.0 *  average;
	    for(int j = 0; j < numOfScores; j++){
		double score = (double)scores[j];
		if(doubleavgOld > score){
		    sumOfLow += score;
		    numOfLow ++;
		}
	    }
	    average = (double)(sumOfLow)/(double)(numOfLow);
	    double doubleavg = average + (double)(sumOfScores)/(double)(numOfLow);
	    for(int j = 0; j < numOfScores; j++){
		double score = (double)scores[j];
		if(doubleavg > score){
		    percentage[j] = (doubleavg - score)/sumOfScores;
		    percentage[j] *= 100.0;
		}
		else{
		    percentage[j] = 0;
		}
	    }
	    output.print("Case #" + (i + 1) + ": ");
	    for(int j = 0; j < numOfScores - 1; j++){
		output.print(percentage[j] + " ");
	    }
	    output.print(percentage[numOfScores-1] + "\n");
	}
	output.close();
    }
}
