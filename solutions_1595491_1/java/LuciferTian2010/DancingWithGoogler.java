import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class DancingWithGoogler {

	private static FileReader freader;
	private static BufferedReader buffreader;
	private static FileWriter fwriter;
	private static BufferedWriter buffwriter;
	
	
	public static void main(String[] args) throws IOException {
		
		freader = new FileReader("B-large.in");
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
				int arrSize = Integer.parseInt(str.split(" ")[0]);
				int num = Integer.parseInt(str.split(" ")[1]);
				int p = Integer.parseInt(str.split(" ")[2]);
				int[] scores = new int[arrSize];
				for(int j=0; j<arrSize; j++){
					scores[j]= Integer.parseInt(str.split(" ")[j+3]);
				}
				int count = getMostNum(p,num,scores);
				String finalStr = "Case #"+Integer.toString(i-1)+": "+Integer.toString(count)+"\n";
				buffwriter.write(finalStr);
			}
			i++;
			
		}
		
		/*int num = 1;
		int p = 1;
		int[] scores = {8, 0};*/
		//System.out.println(getMostNum(p,num,scores));
		
		buffwriter.close();
		fwriter.close();
		buffreader.close();
		freader.close();

	}
	
	public static int getMostNum(int p, int num, int[] scores){
		if(p==0)
			return scores.length;
		else if(p==1){
			int val1 = 1;
			int count = 0;
			for(int i=0; i<scores.length; i++){
				if(scores[i]>=val1){
					count++;
				}
			}
			//System.out.println(num);
			return count;
		}
		else{
			int count=0;
			int val1 = 3*p-2;
			int val2 = 3*p-4;
			for(int i=0; i<scores.length; i++){
				if(scores[i]>=val1){
					count++;
				}
				else if(scores[i]<val1 && scores[i]>=val2){
					if(num>0){
						count++;
						num--;
					}
				}
			}
			return count;
		}
		
	}

}
