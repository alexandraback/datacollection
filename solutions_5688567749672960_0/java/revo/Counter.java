import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


public class Counter {
	int arr[];
public int counter(int n){
	
	if(n<21) return n;
	int c,rev;
	
	arr=new int[n+1];
	
	for(int i=1;i<21;i++)
		arr[i]=i;
	
	for(int i=21;i<=n;i++){
	
		rev=reverse(i);
		c=arr[i-1];
		
		if(rev<i && rev>9 && (i%10!=0) && arr[rev]<c) {arr[i]=arr[rev]+1;}
		else {arr[i]=c+1;}
	}
	
	return arr[n];
	
}

public int reverse(int n){
	int temp=0, revn=0;
	while(n>0){
        temp = n%10;
        
        revn = revn * 10 + temp;
        n = n/10;
	}
	return revn;	
}
}

class Test3{
	public static void main(String args[]){
		File file;
		int ntests;
		BufferedReader br;
		BufferedWriter bw;
		String[] results;
		String line1;
		file = new File (args[0]); 
		Counter Cnt=new Counter();
		
 
try {
			br = new BufferedReader(new FileReader(file));
			ntests = Integer.parseInt(br.readLine());
			results = new String[ntests];

			for (int i = 0; i < ntests; i++) {
				
				line1= br.readLine();
				results[i]=Integer.toString(Cnt.counter(Integer.parseInt(line1)));
			//	System.out.println(results[i]);
			}
			br.close();
			System.out.println("Done. Writing now");
	
			bw = new BufferedWriter(new FileWriter(args[1])); 
			for (int i = 0; i < ntests; i++) {

				if (i < ntests - 1)
					bw.write("Case #" + (1 + i) + ": " + results[i] + "\n");
				else
					bw.write("Case #" + (1 + i) + ": " + results[i]);
			}
			bw.close();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
