import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class judges {



	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(
				"C:\\Users\\Alex\\workspace\\chapter1\\prob.in.txt"));
		PrintWriter output = new PrintWriter(new BufferedWriter(new FileWriter(
				"C:\\Users\\Alex\\workspace\\chapter1\\prob.out.txt")));
		int num=Integer.parseInt(reader.readLine());
		for(int test=1;test<=num;test++){
			StringTokenizer st=new StringTokenizer(reader.readLine());
			output.print("Case #"+test+": ");
			int n=Integer.parseInt(st.nextToken());
			int[] scores=new int[n];
			int sum=0;
			for(int i=0;i<n;i++){
				scores[i]=Integer.parseInt(st.nextToken());
				sum+=scores[i];
			}
			
			int[] arr=new int[n];
			for(int i=0;i<n;i++){
				arr[i]=scores[i];
			}
			
			Arrays.sort(arr);
			int fill=sum;
			double level=arr[0];
			for(int i=1;i<n;i++){
				int area=(arr[i]-arr[i-1])*i;
				if(area<fill){
					fill-=area;
					level=arr[i];
				}else{
					level+=1.0*fill/i;
					fill=0;
					break;
				}
			}
			level+=1.0*fill/n;
			
			for(int i=0;i<n;i++){
				double s=level-scores[i];
				s*=100.0/sum;
				if(s<0){
					s=0;
				}
				output.print(s+" ");
			}
			
			output.println();
		}
		output.close();
	}

}
