import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B {
	
	public static void main(String[] args){
		new B().run();
	}
	
	String c, j;
	
	void run(){
		Scanner sc = new Scanner(System.in);
		
		int testNum = sc.nextInt();
		for(int t=1;t<=testNum;t++){
			c = sc.next();
			j = sc.next();
			String ans = fnc();
			System.out.println("Case #" + t + ": " + ans);
		}
	}
	
	String fnc(){
		String ans = "";
		
		int dif = Integer.MAX_VALUE;
		String ans1 = "";
		String ans2 = "";
		
		
		int cnt = 0;
		for(int i=0;i<c.length();i++){
			char cc = c.charAt(i);
			if(cc=='?'){
				cnt++;
			}
		}
		for(int i=0;i<j.length();i++){
			char jj = j.charAt(i);
			if(jj=='?'){
				cnt++;
			}
		}
		
		if(cnt==6){
			ans = "000 000";
		}else{
		
			for(int x=0;x<10;x++){
				for(int y=0;y<10;y++){
					for(int z=0;z<10;z++){
						for(int v=0;v<10;v++){
							for(int u=0;u<10;u++){
								int[] a = new int[]{x, y, z, v, u};
								int cnt2 = 0;
								String s1 = "";
								for(int i=0;i<c.length();i++){
									char cc = c.charAt(i);
									if(cc=='?'){
										s1 += a[cnt2];
										cnt2++;
									}else{
										s1 += cc;
									}
								}
								String s2 = "";
								for(int i=0;i<j.length();i++){
									char jj = j.charAt(i);
									if(jj=='?'){
										s2 += a[cnt2];
										cnt2++;
									}else{
										s2 += jj;
									}
								}
								
								int d1 = Integer.valueOf(s1);
								int d2 = Integer.valueOf(s2);
								int d = Math.abs(d1-d2);
								
								if(d < dif){
									dif = d;
									ans1 = s1;
									ans2 = s2;
								}else if(d == dif){
									int d3 = Integer.valueOf(ans1);
									if(d2 < d3){
										ans1 = s1;
										ans2 = s2;
									}
								}
	
							}
						}
					}
				}
			}
			ans = ans1 + " " + ans2;
		}
		
		return ans;
	}
	
	
	
	
	/*
	String fnc(){
		String ans1 = "";
		String ans2 = "";
		
		for(int k=0;k<2;k++){
			int f = 0;
			for(int i=0;i<c.length();i++){
				char cc = c.charAt(i);
				char jj = j.charAt(i);
				
				if(cc=='?' && jj=='?'){
					if(f==0){
						ans1 += "0";
						ans2 += "0";
					}else if(f==1){
						ans1 += "0";
						ans2 += "9";
					}else if(f==2){
						ans1 += "9";
						ans2 += "0";
					}
				}else if(cc=='?' && jj!='?'){
					ans2 += jj;
					if(f==0){
						ans1 += jj;
					}else if(f==1){
						ans1 += "0";
					}else if(f==2){
						ans1 += "9";
					}
				}else if(cc!='?' && jj=='?'){
					ans1 += cc;
					if(f==0){
						ans2 += cc;
					}else if(f==1){
						ans2 += "9";
					}else if(f==2){
						ans2 += "0";
					}
				}else{
					ans1 += cc;
					ans2 += jj;
					if(f==0){
						if(cc>jj){
							f = 1;
						}else if(cc<jj){
							f = 2;
						}
					}
				}	
			}
		}
		
		return ans1 + " " + ans2;
	}
	*/

	
}
