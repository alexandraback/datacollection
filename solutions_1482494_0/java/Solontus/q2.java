import java.io.*;
import java.util.*;
public class q2{
    public static void main (String[] args) throws IOException 
    {
	BufferedReader input = new BufferedReader (new FileReader ("B-small-attempt3.txt"));
	PrintWriter output = new PrintWriter (new FileWriter("test2Max.txt"));
	StringTokenizer st;
	
	int numlines = Integer.parseInt(input.readLine());
	for(int i = 0; i < numlines; i++){
	    int levels = Integer.parseInt(input.readLine());
	    int[][] level = new int[levels][2];
	    for(int j = 0; j < levels; j++){
		st = new StringTokenizer(input.readLine());
		level[j][0] = Integer.parseInt(st.nextToken());
		level[j][1] = Integer.parseInt(st.nextToken());
	    }
	    boolean [][] finished = new boolean[levels][2];
	    for(int j = 0; j < levels; j++){
		finished[j][0] = false;
		finished[j][1] = false;
	    }
	    int stars = 0;
	    boolean beatGame = false;
	    boolean impossible = false;
	    int counter = 0;
	    int starsGained;
	    boolean found;
	    while(!beatGame){
		starsGained = 0;
		found = false;
		for(int j = 0; j < levels; j++){
		    if(!finished[j][0] && !finished[j][1] && stars >= level[j][1]){
			starsGained = 2;
			finished[j][1] = true;
			found = true;
			break;
		    }
		}
		if(!found){
		    for(int j = 0; j < levels; j++){
			if(finished[j][0] && !finished[j][1] && stars >= level[j][1]){
			    starsGained = 1;
			    finished[j][1] = true;
			    found = true;
			    break;
			 }
		     }
		 }
		if(!found){
		    int bestToFinish = 0;
		    for(int j = 0; j < levels; j++){
			if(!finished[j][0] && !finished[j][1] && stars >= level[j][0] && stars < level[j][1]){
			    if(level[bestToFinish][1] < level[j][1])
				bestToFinish = j;
			    starsGained = 1;
			    found = true;
			}
		    }
		    if(found)
		    finished[bestToFinish][0] = true;
		 }
		 if(starsGained == 0){
		    impossible = true;
		    break;
		 }
		 stars += starsGained;
		 counter++;
		 beatGame = true;
		 for(int j = 0; j < levels; j++){
		    if(!finished[j][1]){
			beatGame = false;
			break;
		    }
		 }
	     }
	     if(impossible)
		output.println("Case #" + (i + 1) + ": Too Bad");
	     else
		output.println("Case #" + (i + 1) + ": " + counter);
	}
	output.close();
    }
}
	      
