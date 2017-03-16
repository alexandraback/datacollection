package com.ovation;

public class Ovation {
	private int smax;
	private int shne[];
	
	public Ovation(String line) {
		String tokens[] = line.split(" ");
		smax = Integer.parseInt(tokens[0]);
		shne = new int[smax + 1];
		for (int i = 0; i <= smax; i++) {
			shne[i] = tokens[1].charAt(i)-48;
		}
	}
	
	public int getNumFriendsToInvite(){
		int add = 0;
		int sum = 0;
		for(int i=0;i<=smax;i++){
			if(sum>=i){
				sum+= shne[i];
				continue;
			}else{
				int newFriends = i-sum;
				add += newFriends;
				sum += shne[i] + newFriends;
			}
		}
		return add;
	}
}
