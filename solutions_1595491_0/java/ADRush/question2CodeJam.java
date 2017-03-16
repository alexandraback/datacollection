import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;


public class question2CodeJam {
	public int N = 0;
	public int S = 0;
	public int P = 0;
	Vector<Integer> Scores = new Vector<Integer>();
	public int scoreValidCount=0; 
	public int computeAtLeastP(){
		
		for(int i=0;i<N;i++){
			
			int currentScore = Scores.get(i);
			if(currentScore%3==0){
				int minVal = currentScore/3;
				if(minVal>=P){
					scoreValidCount++;
					continue;
				}
				if(minVal == 0 && P == 0){
					scoreValidCount++;
					continue;
				} else if (minVal==0 && P!= 0){
					continue;
				}
				if((minVal+1) >= P && S > 0){
					//minVal + 1 would introduce 2 ka gap
					scoreValidCount++;
					S--;
					continue;
				}
			}
			if(currentScore%3==1){
				int minVal = currentScore/3;
				if(minVal>=P){
					scoreValidCount++;
					continue;
				}
				if((minVal+1) >= P){
					scoreValidCount++;
					continue;
				}
			}
			if(currentScore%3==2){
				int minVal = currentScore/3;
				if((minVal+1) >= P){
					scoreValidCount++;
					continue;
				}
				if(((minVal+2) >= P)&&(S>0)){
					S--;
					scoreValidCount++;
					continue;
				}
			}
			
		}
		return (int) scoreValidCount;
	}
	public static void main(String[] args){
		
	    try{
		    File file = new File(args[0]);
		    
		    FileWriter fstream = new FileWriter(args[1]);
		    BufferedWriter out = new BufferedWriter(fstream);
		    
		    BufferedReader in = new BufferedReader(new FileReader(file));
		    
		    String line = in.readLine();
		    //here line is the number of rounds
		    int counter=0;
		    int testCase = Integer.parseInt(line);
		    
		    while (counter<testCase) {
		    	question2CodeJam tmp = new question2CodeJam();
		    	String inline = in.readLine();
		    	String[] val = inline.split(" ");
		    	
		    	//initializing
		    	tmp.N = Integer.parseInt(val[0]);
		    	tmp.S = Integer.parseInt(val[1]);
		    	tmp.P = Integer.parseInt(val[2]);
		    	for(int i=3;i<val.length;i++){
		    		tmp.Scores.add(Integer.parseInt(val[i]));
		    	}
		    	
		    	++counter;
		    	//System.out.println("Case #" + counter + ": " + tmp.computeAtLeastP());
		    	//out.write(inline);
		    	out.write("Case #" + counter + ": " + tmp.computeAtLeastP());
		    	out.write("\n");
	    	}
		    out.close();
		    in.close();
	    }
	    catch(IOException e){
	    	
	    	System.out.println("IO Error");
	    }
	    catch (ArrayIndexOutOfBoundsException e){
	    	System.out.println("Array Error");
	    	e.printStackTrace();
	    }
		
	}

}
