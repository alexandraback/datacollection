
public class Main {
	public static void main(String[] args) throws java.io.FileNotFoundException,java.io.IOException{
		java.io.BufferedReader bRead=new java.io.BufferedReader(new java.io.FileReader("F:\\C-large-1.in"));
		java.io.BufferedWriter bWrite=new java.io.BufferedWriter(new java.io.FileWriter("F:\\C-large-1.out"));
		StringBuffer output=new StringBuffer();
		int noCases=Integer.parseInt(bRead.readLine());
		//All possible values in the given range
		long[] allValues={1L,4L,9L,121L,484L,10201L,12321L,14641L,40804L,44944L,1002001L,1234321L,4008004L,100020001L,102030201L,104060401L,121242121L,123454321L,125686521L,400080004L,404090404L,10000200001L,10221412201L,12102420121L,12345654321L,40000800004L,1000002000001L,1002003002001L,1004006004001L,1020304030201L,1022325232201L,1024348434201L,1210024200121L,1212225222121L,1214428244121L,1232346432321L,1234567654321L,4000008000004L,4004009004004L};
		long low,high;int count;String[] curLine;
		for(int i=0;i<noCases;i++){
			count=0;
			curLine=bRead.readLine().split(" ");
			low=Long.parseLong(curLine[0]);high=Long.parseLong(curLine[1]);
			
			for(int cur=0;cur<allValues.length;cur++)
				if(low<=allValues[cur] && allValues[cur]<=high){
					count++;
				}
			
			output.append("Case #"+(i+1)+": "+count+"\n");
		}
		bWrite.write(output.toString());
		bWrite.close();bRead.close();
	}
}
