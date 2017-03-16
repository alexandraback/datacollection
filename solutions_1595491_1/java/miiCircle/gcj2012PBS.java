
public class gcj2012PBS {
	
	
	public static void main(String[] args) {
		
		
		String filenameIn = "B-large.in";
		String filenameOut = "B-large.out";
		FileIn fi = new FileIn(filenameIn);
		String s = fi.getString();
		String ss[] = s.split("\n");
		StringBuilder sb = new StringBuilder();
		int z = Integer.valueOf(ss[0]);
		
		
		
		for (int i = 1; i <= z; i++) {
			String tt[] = ss[i].split(" ");
			int [] score = new int[100];
			int google = Integer.valueOf(tt[0]);
			int igai = Integer.valueOf(tt[1]);
			int saitei = Integer.valueOf(tt[2]);
			int answer = 0;
			
			for (int x = 0; x < google; x++) {
				score[x] = Integer.valueOf(tt[x+3]);
				
				int a = score[x];
				
				if(a < saitei) {
					continue;
				}
				
							
				
				if (saitei * 3 <= a) {
					answer++;
					continue;
				}
				
				
				if (saitei * 3 == a) {
					answer++;
					continue;
				}
				
				int hhh=0;
				int ttt=0;
				
				for (int t = 0; t <=10; t++) {
					if (t * 3 >= a) {
						ttt = t;
						hhh = t*3;
						break;
					}
				}
				
						
				if (a <= saitei + 1 + saitei + 1 + saitei + 1 && a >= saitei + saitei - 1 + saitei - 1  
						)	{
					answer++;
					continue;
				}
						
						
				
				int b =  hhh - a;
				
				
				if( igai > 0 && a >= saitei + saitei - 2 + saitei - 2) {
					igai--;
					answer++;
					continue;
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
