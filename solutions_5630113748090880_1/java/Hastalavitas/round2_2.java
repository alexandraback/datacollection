package CodeJam2016;

import java.util.Scanner;
import java.util.TreeSet;

public class round2_2 {

	public static void solution(Scanner in, int k){
		TreeSet<Integer> set = new TreeSet<>();
		int n = in.nextInt();
		in.nextLine();
		for(int j=0;j<2*n-1;++j){
			String[] cur = in.nextLine().split(" ");
			for(String s:cur){
				int tmp = Integer.valueOf(s);
				if(set.contains(tmp)){
					set.remove(tmp);
				}
				else{
					set.add(tmp);
				}
			}	
		}
		StringBuilder sBuilder = new StringBuilder();
		for(Integer i:set){
			sBuilder.append(i+" ");
		}
		System.out.println("CASE #" + (k+1+": ") + sBuilder.toString());
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int m = in.nextInt();
		in.nextLine();
		
		for(int i=0;i<=m;++i){
			solution(in,i);
		}
		in.close();
	}

}
