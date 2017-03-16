package c1;

import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		boolean[] vowels = new boolean[26];
		for(char i = 'a';i<='z';i++){
			if(i=='a' ||i=='e' ||i=='i' ||i=='o' ||i=='u')
				vowels[i-'a'] = true;
		}
		for(int t=1;t<=T;t++){
			char[] w = in.next().toCharArray();
			int N = in.nextInt();
			long nvalue = 0;
			for(int i=0;i<w.length;i++){
				int tmp=0;
				for(int j=i;j<w.length;j++){
					int cnt=0;
					for(int k=i;k<=j;k++){
						if(!vowels[w[k]-'a']){
							cnt++;
						}else{
							cnt=0;
						}
						if(cnt>=N){
							nvalue++;
							break;
							
						}
					
					}
					
				}
			}
			System.out.println("Case #" + t + ": " + nvalue);
		}


	}

}
