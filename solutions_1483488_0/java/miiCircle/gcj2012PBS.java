import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;


public class gcj2012PBS {
	
	
	
	public String recycle(String num, int cycle) {
		if (cycle == 0) {
			return num;
		}
		
		
		String s = String.valueOf(num);
		int len = s.length();
		String temp = s.substring(len-1,len);
		
		
		
		String temp2 = s.substring(0,len-1);
		
		String result = temp+ temp2;
		
		
		
		
		return recycle(result, cycle-1);
		
		
	}

	
	
	public static void main(String[] args) {
		
		gcj2012PBS gc = new gcj2012PBS();
		
		
		String filenameIn = "C-small-attempt0.in";
		String filenameOut = "C-small-attempt0.out";
		FileIn fi = new FileIn(filenameIn);
		String s = fi.getString();
		String ss[] = s.split("\n");
		StringBuilder sb = new StringBuilder();
		int z = Integer.valueOf(ss[0]);
		boolean flag[] = new boolean[2000000];
		
		
		
		
		
		for (int i = 1; i <= z; i++) {
			Arrays.fill(flag, false);
			String tt[] = ss[i].split(" ");
			
			int a = Integer.valueOf(tt[0]);
			int b = Integer.valueOf(tt[1]);
			int answer = 0;
			
			
			String A = "";
			String B = "";
			A = String.valueOf(a);
			//桁数の取得
			int keta = A.length();
			if (keta == 1) {
				sb.append("Case #");
				sb.append(i);
				sb.append(": ");
				sb.append(answer);
				sb.append("\n");
				continue;
				
			}
			String ppp;
			String ooo;
			
			for(int x = a; x <= b; x ++) {
				boolean aaaaa=false;
				ppp = String.valueOf(x);
				ooo = ppp.substring(0, 1);
				for (int ok = 1; ok < keta ; ok++) {
					if(!ooo.equals(ppp.substring(ok,ok+1))) {
						aaaaa = true;
						break;
					}
				}
				
				if(!aaaaa) {
					flag[x] = true;
				}
			}
			
			for (int x = a; x <= b; x++) {
				ArrayList<Integer> list = new ArrayList<Integer>();
				
				
				
				for(int k = 1; k < keta; k++) {
					int result = Integer.valueOf(gc.recycle(String.valueOf(x), k));
					
//					if(result == 1212) {
//						int aa=1;
//					}
					
					if (!flag[result]){
					
						if(x >= a && result <= b && x < result) {
							
														
							if(list.indexOf(result) != -1) {
								continue;
							}
							list.add(result);
						
							answer++;
							
//							if(i == 4) {
//								System.out.println(x + " : " + result);
//							}
							//flag[x] = true;
							//flag[result]=true;
//							for(int k2 = 1; k2 < keta; k2++) {
//								result = Integer.valueOf(gc.recycle(String.valueOf(x), k2));
//								if(result >= a && result <= b && x < result) {
//									flag[result] = true;
//								}
//							}
							
						}
					}
				}
						
			
			
			
			
			
			
				
			
			
			
			}
			
			sb.append("Case #");
			sb.append(i);
			sb.append(": ");
			sb.append(answer);
			sb.append("\n");
		
			
		}
	
		
		
		
		
		
		
		new FileOut(filenameOut, sb.toString());
		
	
	}
	
	
}
