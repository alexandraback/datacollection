import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class SafetyNumber {

	private static FileReader freader;
	private static BufferedReader buffreader;
	private static FileWriter fwriter;
	private static BufferedWriter buffwriter;
	
	public static void main(String[] args) throws IOException {
		freader = new FileReader("A-small-attempt1.in");
		buffreader = new BufferedReader(freader);
		fwriter= new FileWriter("result.txt");
		buffwriter = new BufferedWriter(fwriter);
		String str = null;
		int linenum = 0;
		int i=1;
		while((str=buffreader.readLine())!=null){
			if(i==1)
				linenum=Integer.parseInt(str);
			else{
				int contNum = Integer.parseInt(str.split(" ")[0]);
				int[] votes = new int[contNum];
				float[] prob = new float[contNum];
				for(int j=0; j<contNum; j++){
					votes[j] = Integer.parseInt(str.split(" ")[j+1]);
					prob[j] = 0f;
					calSafetyNum(contNum, votes, prob);

				}
				String finalStr = "Case #"+Integer.toString(i-1)+":";
				for(int j=0; j<contNum; j++)
					finalStr +=" "+Float.toString(prob[j]);
				finalStr += "\n";
				buffwriter.write(finalStr);
			}
			i++;
		}
		
		buffwriter.close();
		fwriter.close();
		buffreader.close();
		freader.close();
		/*int contNum = 6;
		int[] votes = {0,0,0,81,0,0};
		float[] prob = new float[contNum];
		calSafetyNum(contNum, votes, prob);
		String finalStr = "Case #:"+Integer.toString(0);
		for(int j=0; j<contNum; j++)
			finalStr +=" "+Float.toString(prob[j]);
		finalStr += "\n";
		System.out.println(finalStr);*/

	}
	
	public static void calSafetyNum(int num, int[] votes, float[] prob){
		int total = 0;
		int flag = 1;
		int sum = 0;
		for(int vote: votes){
			total += vote;
			sum += vote;
		}
		float aver = 0;
		int size = num;
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int[] flagarr = new int[num];
		Arrays.fill(flagarr, 0);
		while(flag==1){
			flag = 0;
			aver = (float)(sum+total)/size;
			arr.clear();
			for(int i=0; i<num; i++){
				if(flagarr[i]==0){
					if(votes[i]>aver){
						total-= votes[i];
						size--;
						flag = 1;
						prob[i] = 0f;
						flagarr[i] = 1;
					}
					else{
						arr.add(i);
					}
				}
			}
		}
		//System.out.println(total);
		//System.out.println(size);
		aver = (float)(sum+total)/size;
		for(int idx: arr){
			prob[idx] = (aver-votes[idx])*100f/sum;			
		}
		
	}

}
