import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int ten[]=new int[10];
		ten[1]=1;
		for(int i=2;i<10;ten[i]=ten[i-1]*10,i++);	
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			int A=Integer.parseInt(st.nextToken());
			int B=Integer.parseInt(st.nextToken());
			int n=(A+"").length();
			int ctr=0;
			boolean marked[]=new boolean[2000001];
			for(int a=A;a<=B;a++){
				if(marked[a])
					continue;
				int i=1;
				int b=a;
				for(int j=1;j<n;j++){
					b=b/10+(b%10)*ten[n];
					if(b>a&&b<=B&&!marked[b]){
						i++;
						marked[b]=true;
//						System.out.println(a+" "+b);
					}
				}
				ctr+=i*(i-1)/2;
//				System.out.println(">"+ctr);
			}
			System.out.println("Case #"+cn+": "+ctr);
		}
	}

}
