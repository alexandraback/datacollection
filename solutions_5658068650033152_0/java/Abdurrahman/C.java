import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class C {
	public static void main(String[] args) throws IOException {
			
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("C-small.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int i = 1; i<=cases; i++){
			String[] inp = br.readLine().split(" ");
			int n = Integer.parseInt(inp[0]);
			int m = Integer.parseInt(inp[1]);
			int k = Integer.parseInt(inp[2]);
			
			int a = Math.max(m, n);
			int b = Math.min(m, n);
			
			int min = k;
			
			for(int t1 = 1; t1<k; t1++){
				for(int t2 = t1; t2<k; t2++){
					if(2*t1+2*t2+t1*t2>=k)
					if(Math.min(t1, t2)<=b+2 && Math.max(t1, t2)<=a+2){
						min = Math.min(min, 2*t1+2*t2);
					}
				}
			}
			
			bw.write("Case #"+i+": "+min+"\r\n");
			
		}
		bw.close();
	}
}
