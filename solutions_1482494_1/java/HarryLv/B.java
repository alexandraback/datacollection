import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class B {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new FileReader(new File("B-large.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out")));
		
		int T = Integer.parseInt(reader.readLine());
		
		for(int i =0;i<T;i++){
			int N   = Integer.parseInt(reader.readLine());
			int []a = new int[N];
			int []b = new int[N];
			int []p = new int[N];
			
			int stars = 0;
			int count = 0;
			
			for(int j=0;j<N;j++){
				String[] s = reader.readLine().split(" ");
				a[j] = Integer.parseInt(s[0]);
				b[j] = Integer.parseInt(s[1]);
				p[j] = 0;
			}
			
			while(true){
				int l = -1;
				int w = Integer.MAX_VALUE;
				for(int j =0;j<N;j++){
					if(b[j]<=stars&&p[j]<2&&w>b[j]){
						w = b[j];
						l = j;
					}
				}
				if(l>=0){
					stars += (2-p[l]);
					p[l]  = 2;
					count ++;
					continue;
				}
				
				l = -1;
				w = -1;
				for(int j=0;j<N;j++){
					if(a[j]<=stars&&p[j]==0&&w<b[j]){
						w = b[j];
						l = j;
					}
				}
				if(l>=0){
					stars++;
					p[l] = 1;
					count++;
					continue;
				}
				
				break;
			}
			
			boolean s = true;
			for(int j=0;j<N;j++){
				if(p[j]!=2){
					s = false;
					break;
				}
					
			}
			if(s){
				writer.write("Case #"+(i+1)+": "+count+"\n");
				writer.flush();
			}
			else{
				writer.write("Case #"+(i+1)+": Too Bad\n");
				writer.flush();
			}
		}
		
	}

}
