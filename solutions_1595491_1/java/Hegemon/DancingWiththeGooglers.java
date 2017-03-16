import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DancingWiththeGooglers {
	BufferedReader reader;
	char [] charInput;
	String [] inputArray;
	int index;
	DancingWiththeGooglers()throws Exception{
		String input=null;
		reader = new BufferedReader(new InputStreamReader(System.in));
		while(reader.ready()){
			if (input==null){
				input =reader.readLine();
			}
			else{
				input =input+ " " + reader.readLine();
			}
		}
		inputArray=input.trim().split(" ");
		index=0;
	}
	String nextInput()throws Exception{
		if(index<inputArray.length){
			int temp=index;
			index++;
			return inputArray[temp];
		}
		else{
			return "\0";
		}
	}
	void start()throws Exception{
		int numCases=Integer.parseInt(nextInput());
		int googlers;
		int surprising;
		int best;
		int total;
		int maxBest=0;
		for(int i=0;i<numCases;i++){
			googlers=Integer.parseInt(nextInput());
			surprising=Integer.parseInt(nextInput());
			best=Integer.parseInt(nextInput());
			for(int j=0;j<googlers;j++){
				total=Integer.parseInt(nextInput());
				if(((double)total)/3>(best-1)){
					maxBest++;
				}
				else if(total%3!=1 && ((double)total)/3>(best-2) && total<28 && total>1){
					if (surprising>0){
						maxBest++;
						surprising--;
					}
				}
			}
			System.out.printf("Case #%d: %d", i+1,maxBest);
			if (i!=numCases-1){
				System.out.println();
			}
			maxBest=0;
		}
	}
}

