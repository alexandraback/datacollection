import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class Shyness {
	public static void main(String args[]){
		
		try {
			BufferedReader br = new BufferedReader(new FileReader("input0.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			int test = Integer.parseInt(br.readLine());
			int testcase= 1;
			while(test>= testcase)
			{
				String r[]= br.readLine().split(" ");
				int s_max = Integer.parseInt(r[0]);
				
				String str = r[1];
				int length = str.length();
				int arr[] = new int[s_max+1];
				int sum[] = new int[s_max+1];
				
				for(int i=0;i<s_max+1;i++){
					arr[i]= str.charAt(i)-'0';
				}
				int s = 0;
				sum[0] = 0;
				
				for(int i=1;i<s_max+1;i++){
					sum[i]= sum[i-1]+ arr[i-1];
				}
				int count =0;
				
				for(int i=1;i<s_max+1;i++){
					if(i- (sum[i]+count) >0){
						count ++;
					}
				}
				//System.out.println("Case #"+testcase+":"+count);
				bw.write("Case #"+testcase+": "+count);
				testcase++;
				if(testcase<=test){
					bw.write("\n");
				}
			}
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
