package G2015;



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Q2 {

	public static void main(String[] args) throws IOException {
		String path="I:\\google\\2015\\q1\\B-small-attempt7.in";
		String path1="I:\\google\\2015\\q1\\B-small-attempt7.out";
		readData(path);
		writeData(path1);
		
		
	}
	
	
	
	private static void writeData(String path) throws IOException {
		
		OutputStreamWriter fr = new OutputStreamWriter(new FileOutputStream(path));
		BufferedWriter br = new BufferedWriter(fr);
		for (int i=1;i<=ans.length;i++){
			String s="";
			s="Case #"+Integer.toString(i)+": "+ans[i-1];
			br.write(s);
			br.newLine();
		}
		br.close();
		
	}


	static int count=0;
	private static void solution(int d, int[] c, int k) {
		count=1000;
		int t=0;
		for (int i=1;i<=1000;i++){
			t=i;
			for (int j=0;j<d;j++){
				t+=(c[j]-1)/i;
			}
			count=Math.min(count, t);
		}
		
		ans[k]=Integer.toString(count);
	}


	


	static String[] ans;
	private static void readData(String path) throws IOException {
		InputStreamReader fr = new InputStreamReader(new FileInputStream(path));
		BufferedReader br = new BufferedReader(fr);
		String rec = br.readLine();
		ans=new String[Integer.parseInt(rec)];
		int k=0;
		try {
			while ((rec = br.readLine()) != null) {
				int d=Integer.parseInt(rec);
				rec = br.readLine();
				String[] temp=rec.split(" ");
				int c[]=new int[d];
				for (int i=0;i<d;i++){
					c[i]=Integer.parseInt(temp[i]);
				}
				Arrays.sort(c);
				
				
				solution(d, c, k++);
			}
		}catch(Exception e){
			
		}
	}
	
	
}
