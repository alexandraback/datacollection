import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class pancakes {
	public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	}
	public static int maximum(int a[],int size){
		int max = a[0];
		for(int i=1;i<size;i++){
			if(max<a[i]){
				max=a[i];
			}
		}
		return max;
	}
	
	public static int sum(int arr[],int size,int z){
		int sum =0;
		for(int i=0;i<size;i++){
			sum+= (arr[i]-1)/z;
		}
		return sum;
	}
	
public static void main(String args[]){
		
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			int test = Integer.parseInt(br.readLine());
			int testcase= 1;
			while(test>= testcase)
			{
				int count = Integer.parseInt(br.readLine());
				
				String r[]= br.readLine().split(" ");
				int arr[] = new int[r.length];
				
				for(int i=0;i<r.length;i++){
					arr[i]=Integer.parseInt(r[i]);
				}
				int max = maximum(arr,r.length);
				
				int z =2;
				while(z<max)
				{
					max = min(max, sum(arr,r.length,z)+z);
					z+=1;
				}
				System.out.println("Case #"+testcase+": "+max);
				bw.write("Case #"+testcase+": "+max);
				//Case #1: 3
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
