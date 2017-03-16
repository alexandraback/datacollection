import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class Main_Dance {
	public static void main(String[] args)throws Exception {
		File _=new File("dance.in");
		BufferedReader br=_.exists()? new BufferedReader(new FileReader(_)):new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine().trim());
		int n,s,p;
		ArrayList<Integer> scores;
		StringTokenizer st;
		int k,surprising,total;
		
		for (int i = 1; i <= t; i++) {
			scores=new ArrayList<Integer>();
			st=new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			s=Integer.parseInt(st.nextToken());
			p=Integer.parseInt(st.nextToken());
			k=p+2*Math.max(0, p-2);
			
			
			for (int j = 0; j < n; j++) {
				scores.add(Integer.parseInt(st.nextToken()));
			}
			total=0;
			surprising=0;
			Collections.sort(scores);
			for (int j = 0; j < scores.size(); j++) {
				if(scores.get(j)>=k)
					total++;
				if((p!=1&&p!=0)&&(scores.get(j)==p+2*(p-2)||scores.get(j)==p+2*(p-2)+1))
					surprising++;
			}
			
			if(surprising>s)
				total-=surprising-s;
			
			
			System.out.println("Case #"+i+": "+total);
		}
		
	}
}
