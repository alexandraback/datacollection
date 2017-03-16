package main;

import java.util.HashSet;

public class CountingSheep extends CodeJamBase {

	@Override
	public String doResolve(int count, String line, int lineNum) {
		int num = Integer.parseInt(line);
		if(num == 0) {
			return "INSOMNIA";
		}
		int lastNum = 0;
		int name;
		HashSet<String> set = new HashSet<String>();
		for(int i=1;i<Integer.MAX_VALUE;i++) {
			name = num*i;
			int div=10;
			while(name!=0) {
				int digit = name % 10;
				name /= 10;
				set.add(""+digit);
				if(set.size() == 10) {
					break;
				}
			}
			
			if(set.size() == 10) {
				lastNum = i*num;
				break;
			}
		}
		return ""+lastNum;
	}

	public static void main(String[] args) {
		CountingSheep test = new CountingSheep();
        test.start();
	}

}
