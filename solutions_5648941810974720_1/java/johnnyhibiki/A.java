import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args){
		new A().run();
	}
	
	String org;
	
	void run(){
		Scanner sc = new Scanner(System.in);
		
		int testNum = sc.nextInt();
		for(int t=1;t<=testNum;t++){
			org = sc.next();
			String ans = fnc();
			System.out.println("Case #" + t + ": " + ans);
		}
	}
	
	String fnc(){
		int[] ans = new int[10];
		
		int[] cnt = new int[26];
		for(int i=0;i<org.length();i++){
			int p = org.codePointAt(i)-65;
			cnt[p]++;
		}
		
		//zero
		ans[0] = cnt[25]; //z
		cnt[4] -= cnt[25]; //e
		cnt[17] -= cnt[25]; //r
		cnt[14] -= cnt[25]; //o
		cnt[25] = 0;
		
		//two
		ans[2] = cnt[22]; //w
		cnt[19] -= cnt[22]; //t
		cnt[14] -= cnt[22]; //o
		cnt[22] = 0;
		
		//four
		ans[4] = cnt[20]; //u
		cnt[5] -= cnt[20]; //f
		cnt[14] -= cnt[20]; //o
		cnt[17] -= cnt[20]; //r
		cnt[20] = 0;
				
		//six
		ans[6] = cnt[23]; //x
		cnt[18] -= cnt[23]; //s
		cnt[8] -= cnt[23]; //i
		cnt[23] = 0;
		
		//five
		ans[5] = cnt[5];//f
		cnt[8] -= cnt[5];//i
		cnt[21] -= cnt[5];//v
		cnt[4] -= cnt[5];//e
		cnt[5] = 0;
		
		//seven
		ans[7] = cnt[21]; //v
		cnt[18] -= cnt[21]; //s
		cnt[4] -= cnt[21]*2;//ee
		cnt[13] -= cnt[21];//n
		cnt[21] = 0;
		
		//three
		ans[3] = cnt[17];//r
		cnt[4] -= cnt[17]*2;//ee
		cnt[19] -= cnt[17];//t
		cnt[7] -= cnt[17];//h
		cnt[17] = 0;
		
		//one
		ans[1] = cnt[14];//o
		cnt[13] -= cnt[14];//n
		cnt[4] -= cnt[14];//e
		cnt[14] = 0;
		
		//eight
		ans[8] = cnt[7];//h
		cnt[4] -= cnt[7];//e
		cnt[8] -= cnt[7];//i
		cnt[6] -= cnt[7];//g
		cnt[19] -= cnt[7];//t
		cnt[7] = 0;
		
		//nine
		ans[9] = cnt[8];
		
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<10;i++){
			for(int j=0;j<ans[i];j++){
				sb.append(i);
			}
		}
		
		return sb.toString();
	}


	
}
