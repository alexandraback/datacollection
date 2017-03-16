import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskC {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		out.println("Case #" + t + ": ");
		
		s1 = br.readLine();
		st = new StringTokenizer(s1);
		int r = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for ( int i = 0; i < r; i++){
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			int[] a = new int[6];
			int q = 0;
			for (int j = 0; j < k; j++){
				int x = Integer.parseInt(st.nextToken());
				if (x>1){
					if (x<=5){
						a[x]=1;
					} else {
						int p = 0;
						int a3=0;
						int a5=0;
						while (x%3 == 0){
							a3++;
							p++;
							x = x/3;
						}
						a[3] = Math.max(a[3], a3);
						while (x%5 == 0){
							a5++;
							x = x/5;
							p++;
						}
						a[5] = Math.max(a[5], a5);
						int a4=0;
						while(x%4==0){
							x = x/4;
							a4++;
						}
						int a2 = 0;
						while(x%2==0){
							x = x/2;
							a2++;
						}
						a[2]=Math.max(a2,a[2]);
						if (p+a4+a2==n){
							a[4]=a4;
							a[2]=a[2];
						} else {
							q = 1;
						}
						
					}
				}
			}
			int p = a[5]+a[3]+a[2]+a[4];
			if ((q ==1)&&(p<n)){
				if (p==2){
					a[4]++;
				} 
				if (p==1){
					a[2]+=2;
				} 
				if (p==0){
					a[2]+=2;
					a[4]++;
				} 
			}
			p = a[5]+a[3]+a[2]+a[4];
			if (p<n){
				a[5]++;
				p++;
			}
			if (p<n){
				a[3]++;
				p++;
			}
			if (p<n){
				a[2]++;
				p++;
			}
			for ( int j = 2; j <=5; j++){
				while (a[j]>0){
					a[j]--;
					out.print(j);
				}
			}
			out.println();
			
		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new TaskC().run();
	}

}