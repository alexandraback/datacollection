package G2015;



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Q1 {

	public static void main(String[] args) throws IOException {
		String path="I:\\google\\2015\\q1\\A-small-attempt0.in";
		String path1="I:\\google\\2015\\q1\\A-small-attempt0.out";
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



	private static void solution(int max, int[] people, int k) {
		int cur=0;
		int aaa=0;
		for (int i=0;i<=max;i++){
			if (cur>=i){
				cur+=people[i];
			}else{
				aaa+=i-cur;
				cur=i;
				cur+=people[i];
			}
		}
		ans[k]=Integer.toString(aaa);
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
				String[] temp=rec.split(" ");
				int max=Integer.parseInt(temp[0]);
				int[] people=new int[max+1];
				for (int i=0;i<=max;i++){
					people[i]=temp[1].charAt(i)-'0';
				}
				solution(max,people,k++);
			}
		}catch(Exception e){
			
		}
	}
	
	
}
