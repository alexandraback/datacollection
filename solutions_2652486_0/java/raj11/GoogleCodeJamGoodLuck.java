import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class GoogleCodeJamGoodLuck {
	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream("/Users/ashwinjain/Desktop/good_in.txt")));
		int cases = Integer.parseInt(br.readLine());
		String temp2[] = br.readLine().split(" ");
		int R = Integer.parseInt(temp2[0]);
		System.out.println("Case #1:");
		for(int xx=0;xx<R;xx++){
			String temp[] = br.readLine().split(" ");
			int num[] = new int[temp.length];
			
			for(int i=0;i<temp.length;i++)
				num[i] = Integer.parseInt(temp[i]);
			
			int fi=0,th=0,t=0,fr=0;
			for(int i=0;i<num.length;i++){
				if(num[i]%5==0 && num[i]!=0){
					fi=1;
					num[i]=num[i]/5;
					if(num[i]%5==0 && num[i]!=0){
						fi=2;
						num[i]=num[i]/5;
						if(num[i]%5==0 && num[i]!=0){
							fi=3;
							num[i]=num[i]/5;
						}
					}
				}
				if(num[i]%3==0 && num[i]!=0){
					th=1;
					num[i]=num[i]/3;
					if(num[i]%3==0 && num[i]!=0){
						th=2;
						num[i]=num[i]/3;
						if(num[i]/3==0 && num[i]!=0){
							th=3;
							num[i]=num[i]/3;
						}
					}
				}
				if(num[i]%4==0 && num[i]!=0){
					fr=1;
					num[i]=num[i]/4;
					if(num[i]%4==0 && num[i]!=0){
						fr=2;
						num[i]=num[i]/4;
						if(num[i]%4==0 && num[i]!=0){
							fr=3;
							num[i]=num[i]/4;
						}
					}
				}
				if(num[i]%2==0 && num[i]%4!=0 && num[i]!=0)
					t=1;
				
				if(fi+th+t+fr>=3)
					break;
			}
			int printed = 0;
			if(fi+th+t+fr>=3){
				for(int i=0;i<fi;i++){
					if(printed==3) break;
					System.out.print("5");
					printed++;
				}
				for(int i=0;i<th;i++){
					if(printed==3) break;
					System.out.print("3");
					printed++;
				}
				for(int i=0;i<fr;i++){
					if(printed==3) break;
					System.out.print("4");
					printed++;
				}
				for(int i=0;i<t;i++){
					if(printed==3) break;
					System.out.print("2");
					printed++;
				}
			}else{
				t=fr*2;
				if(fi+th+t+fr>=3){
					for(int i=0;i<fi;i++){
						if(printed==3) break;
						System.out.print("5");
						printed++;
					}
					for(int i=0;i<th;i++){
						if(printed==3) break;
						System.out.print("3");
						printed++;
					}
					for(int i=0;i<fr;i++){
						if(printed==3) break;
						System.out.print("4");
						printed++;
					}
					for(int i=0;i<t;i++){
						if(printed==3) break;
						System.out.print("2");
						printed++;
					}
				}
			}
			System.out.println();
		}
	}
}
