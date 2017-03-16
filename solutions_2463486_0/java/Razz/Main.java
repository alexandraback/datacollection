
public class Main {
	public static void main(String[] args) throws java.io.FileNotFoundException,java.io.IOException{
		java.io.BufferedReader bRead=new java.io.BufferedReader(new java.io.FileReader("F:\\C-small-attempt0.in"));
		java.io.BufferedWriter bWrite=new java.io.BufferedWriter(new java.io.FileWriter("F:\\C-small-attempt0.out"));
		StringBuffer output=new StringBuffer();
		int noCases=Integer.parseInt(bRead.readLine());
		
		int low,high,count;String[] curLine;
		for(int i=0;i<noCases;i++){
			count=0;
			curLine=bRead.readLine().split(" ");
			low=Integer.parseInt(curLine[0]);high=Integer.parseInt(curLine[1]);
			
			//only 5 values are there in the range 1-1000
			if(low<=1 && 1<=high)count++;
			if(low<=4 && 4<=high)count++;
			if(low<=9 && 9<=high)count++;
			if(low<=121 && 121<=high)count++;
			if(low<=484 && 484<=high)count++;
			
			output.append("Case #"+(i+1)+": "+count+"\n");
		}
		bWrite.write(output.toString());
		bWrite.close();bRead.close();
	}
}
