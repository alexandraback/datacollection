import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class RecycledNumbers {
	BufferedReader reader;
	char [] charInput;
	String [] inputArray;
	int index;
	RecycledNumbers()throws Exception{
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
		LinkedList<Integer> prevMatches=new LinkedList<Integer>();
		int numCases=Integer.parseInt(nextInput());
		int A;
		int B;
		int numRecycledPairs=0;
		int [] numArray;
		int digits;
		int testNum=0;
		boolean prevExists=false;
		for(int i=0;i<numCases;i++){
			A=Integer.parseInt(nextInput());
			B=Integer.parseInt(nextInput());
			digits=numDigits(A);
			numRecycledPairs=0;
			for(int j=A;j<=B;j++){
				prevMatches.clear();
				numArray=new int[digits*2-1];
				testNum=j;
				for (int k=numArray.length-1;k>=0;k--){
					testNum=testNum/10;
					if(k==digits-1){
						testNum=j;
					}
					numArray[k]=testNum%10;
				}
				for (int k=1;k<digits;k++){
					testNum=0;
					for (int l=k;l<digits+k;l++){
						testNum=testNum*10;
						testNum=testNum+numArray[l];
					}
					if (prevMatches.size()==0){
						prevExists=false;
					}
					else{
						for (Integer m: prevMatches){
							if (m.intValue()==testNum){
								prevExists=true;
								break;
							}
							else{
								prevExists=false;
							}
						}
					}
					if (testNum>=A && testNum<=B && testNum>j && prevExists==false){
						numRecycledPairs++;
						prevMatches.add(new Integer(testNum));
					}
				}
			}
			System.out.printf("Case #%d: %d", i+1,numRecycledPairs);
			if (i!=numCases-1){
				System.out.println();
			}
		}
	}


	//credit to Marian	
	//http://stackoverflow.com/questions/1306727/way-to-get-number-of-digits-in-an-int
	int numDigits(int n){
		if (n < 100000)
		{
			// 5 or less
			if (n < 100)
			{
				// 1 or 2
				if (n < 10)
					return 1;
				else
					return 2;
			}
			else
			{
				// 3 or 4 or 5
				if (n < 1000)
					return 3;
				else
				{
					// 4 or 5
					if (n < 10000)
						return 4;
					else
						return 5;
				}
			}
		}
		else
		{
			// 6 or more
			if (n < 10000000)
			{
				// 6 or 7
				if (n < 1000000)
					return 6;
				else
					return 7;
			}
			else
			{
				// 8 to 10
				if (n < 100000000)
					return 8;
				else
				{
					// 9 or 10
					if (n < 1000000000)
						return 9;
					else
						return 10;
				}
			}
		}
	}
}

