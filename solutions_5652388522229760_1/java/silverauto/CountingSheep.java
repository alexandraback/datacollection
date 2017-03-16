package main;

import java.util.HashSet;

public class CountingSheep extends CodeJamBase {

	@Override
	public String doResolve(int count, String line, int lineNum) {
		long num = Integer.parseInt(line);
		if(num == 0) {
			return "INSOMNIA";
		}
		long lastNum = 0;
		long name;
		HashSet<String> set = new HashSet<String>();
		for(long i=1;i<Long.MAX_VALUE;i++) {
			name = num*i;
			boolean inla=false;
			while(name!=0) {
				long digit = name % 10;
				name /= 10;
				boolean sucess = set.add(""+digit);
//				if(sucess) {
//					System.out.print(digit+" ");
//					inla = true;
//				}
				if(set.size() == 10) {
					break;
				}
			}
			
//			if(inla) {
//				System.out.println("");
//				System.out.println(num*i+" ====== ");
//			}
			
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
