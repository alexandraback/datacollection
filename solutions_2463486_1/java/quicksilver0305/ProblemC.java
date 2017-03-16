package gcj2013;

import java.io.*;

public class ProblemC {
	BufferedReader br;
	BufferedWriter bw;
	
	public ProblemC(BufferedReader br, BufferedWriter bw) {
		this.br = br;
		this.bw = bw;
	}
	
	public void exec()
		throws IOException{

		String   str, sta, end;
		String[] strs;
		
		C_palindrome pal;
		
		int num, cnt;
		int i,j;
		
		Boolean sflag, eflag, hit;
		
		// read 1st line (Number of Testcase)
		num = Integer.parseInt(br.readLine());
		
		//read Each Testcase
		for(i=1; i<=num; i++){
			strs = br.readLine().split(" ");
			sta  = strs[0];
			end  = strs[1];
			
			pal   = new C_palindrome(strs[1].length()/2+1);
			sflag = false;
			eflag = false;
			cnt   = 0;
			
			while(!eflag){
				str = pal.square();
				if(!sflag){
					if     (str.length() > sta.length()){ sflag = true; }
					else if(str.length() < sta.length()){ }
					else   {
						for(j=0; j<str.length(); j++){
							if(Integer.parseInt(String.valueOf(str.charAt(j)))
									>= Integer.parseInt(String.valueOf(sta.charAt(j)))){
								sflag = true;
								break;
							}
						}
					}
				}

				if     (str.length() > end.length()){ eflag = true; break;}
				else if(str.length() < end.length()){ }
				else   {
					for(j=0; j<str.length(); j++){
						if(Integer.parseInt(String.valueOf(str.charAt(j)))
								> Integer.parseInt(String.valueOf(end.charAt(j)))){
							eflag = true;
							break;
						}	
					}
				}
				
				if(sflag && !eflag){
					hit = true;
					for(j=0; j<(str.length()); j++){
						if(!String.valueOf(str.charAt(j)).equals(String.valueOf(str.charAt(str.length()-1-j)))){
							hit = false;
						}
					}
					if(hit) { cnt++; }
				}
				pal.inc();
				str = pal.square();
				
			}
			
			bw.write("Case #" + i + ": " + cnt + "\n");
			
		}
		
		br.close();
		bw.close();		
		
	}
}
