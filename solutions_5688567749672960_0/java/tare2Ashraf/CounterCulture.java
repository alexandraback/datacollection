import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class CounterCulture {
	
	public static long reverse(long n){
		
		String a=n+"";
		
		String b="";
		
		for(int i=a.length()-1;i>=0;i--){
			b+=a.charAt(i);
		}
		
		return Long.parseLong(b);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new FileReader("in.txt"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("out.txt"));
		
		int t=Integer.parseInt(br.readLine());

		for(int tt=0;tt<t;tt++){
			
			long n=Long.parseLong(br.readLine());
			
			
			long ans=0;
			
			if(n%10==0){
				ans++;
				n--;
			}
			
			while(n>10){
				
				String a=n+"";
				
				if(a.charAt(0)==a.charAt(a.length()-1)){
					ans+=(a.charAt(0)-'0')*Math.pow(10, a.length()-1);
					a=a.substring(1);
					
					n=Long.parseLong(a);
				}else{
				
					ans+=(n%10);
					
					n=n/10;
					n*=10;
					n++;
				}
				n=reverse(n);
			}
			
			bw.append("Case #"+(tt+1)+": "+(ans+n)+"\n");
			System.out.println(ans+n);
		}
		bw.close();
		
	}
}
