import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main_Recycled {
	static int a,b;
	public static void main(String[] args)throws Exception {
		File _=new File("recycled.in");
		BufferedReader br=_.exists()? new BufferedReader(new FileReader(_)):new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine().trim());
		StringTokenizer st;
		
		boolean visited[];
		int size,total;
		int temp;
		for (int i = 1; i <= t; i++) {
			total=0;
			st=new StringTokenizer(br.readLine());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			visited=new boolean[b+1];
			for (int j = a; j <= b; j++) {
				size=0;
				temp=j;
				while(!visited[temp]){
					visited[temp]=true;
					size++;
					temp=next(temp);
				}
				total+=size*(size-1)/2;
				
				
			}
			System.out.println("Case #"+i+": "+total);
		}
	}

	private static int next(int temp) {
		String str=""+temp;
		do{
			str=str.substring(1,str.length())+str.charAt(0);
		}
		while(Integer.parseInt(str)<a||Integer.parseInt(str)>b);
		return Integer.parseInt(str);
	}
}
