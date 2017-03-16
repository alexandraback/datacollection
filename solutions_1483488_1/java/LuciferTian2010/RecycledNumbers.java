import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;


public class RecycledNumbers {


	private static FileReader freader;
	private static BufferedReader buffreader;
	private static FileWriter fwriter;
	private static BufferedWriter buffwriter;
	
	public static void main(String[] args) throws IOException {
		
		freader = new FileReader("C-large.in");
		buffreader = new BufferedReader(freader);
		fwriter= new FileWriter("result-large.txt");
		buffwriter = new BufferedWriter(fwriter);
		String str = null;
		int linenum = 0;
		int i=1;
		while((str=buffreader.readLine())!=null){
			if(i==1)
				linenum=Integer.parseInt(str);
			else{
				int start = Integer.parseInt(str.split(" ")[0]);
				int end = Integer.parseInt(str.split(" ")[1]);
				int num = calRecycleNum(start, end);
				String finalStr = "Case #"+Integer.toString(i-1)+": "+Integer.toString(num)+"\n";
				buffwriter.write(finalStr);
			}
			i++;
		}
		buffwriter.close();
		fwriter.close();
		buffreader.close();
		freader.close();

	}
	
	public static int calRecycleNum(int start, int end){
		int num = 0;
		for(int i=start; i<=end; i++){
			int len = Integer.toString(i).length();
			int recycleVal = i;
			HashSet<Integer> targetSet = new HashSet<Integer>();
			for(int j=1; j<len; j++){
				recycleVal = recycleOnce(recycleVal,len);
				if(recycleVal<=i)
					continue;
				else if(recycleVal<=end && recycleVal>=start){
					if(!targetSet.contains(recycleVal)){
						num++;
						//System.out.println(i+"\t"+recycleVal);
						targetSet.add(recycleVal);
					}
					/*else{
						System.out.println("Duplicate:"+recycleVal+"\t"+i);
					}*/

				}
				
			}
		}
		//System.out.println(num);
		return num;
	}
	
	public static int recycleOnce(int val, int length){
		return (int) (val%Math.pow(10, length-1)*10+val/Math.pow(10, length-1));
	}

}
