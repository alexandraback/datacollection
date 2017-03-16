import java.io.*;
class Elf{
	public static void main(String args[]) throws IOException{
		long pow2[] = new long[41];
		pow2[0]=1;
		for(int i=1;i<=40;i++){
			pow2[i] = pow2[i-1]*2;
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(br.readLine());
		for(int t = 1; t <= tests; t++){
			System.out.print("Case #"+t+": ");
			String ip[] = br.readLine().split("/");
			long n = Long.parseLong(ip[0]);
			long d = Long.parseLong(ip[1]);
			int c = 0, flag = 0;
			if(d%2==1){
				System.out.println("impossible");
			}
			else{
				while(d>1){
					if(d%2==1){
						flag=1;
						break;
					}
					else{
						c++;
						d/=2;
					}
				}
				if(flag==0){
					if(n==1)
						System.out.println(c);
					else{
						int i;
						for(i=0;i<41;i++){
							if(n<pow2[i]){
								break;
							}
						}
						System.out.println(c-i+1);
					}
				}
				else{
					System.out.println("impossible");
				}
			}
		}
	}
}