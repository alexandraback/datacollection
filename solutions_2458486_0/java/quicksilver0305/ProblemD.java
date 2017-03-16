package gcj2013;

import java.io.*;
import java.util.*;

public class ProblemD {
	BufferedReader br;
	BufferedWriter bw;
	
	public ProblemD(BufferedReader br, BufferedWriter bw) {
		this.br = br;
		this.bw = bw;
	}
	
	public void exec()
		throws IOException{	
		
		D_keys keys;
		
		BitSet remain;
		BitSet fail;
		BitSet trial;
		
		String[] strs, fkey;
		String   gain;
		String   answer;

		int numt, numk, numc, numg;
		int i,j,k;

		int    stage, ptr;
		int[]  pass;
		
		Boolean cant;
		
		// read 1st line (Number of Testcase)
		numt = Integer.parseInt(br.readLine());
		
		//read Each Testcase
		for(i=1; i<=numt; i++){
			
			keys   = new D_keys();
			remain = new BitSet(200);
			fail   = new BitSet(200);
			trial  = new BitSet(200);
			
			stage  = 0;
			ptr    = 0;
			pass   = new int[200];
			cant   = false;
			
			strs = br.readLine().split(" ");
			numk = Integer.parseInt(strs[0]);
			numc = Integer.parseInt(strs[1]);
			
			//set Chest
			remain.clear();
			remain.set(0, numc);
			fail.set(0,numc);
			
			//read StartKey Info
			fkey = br.readLine().split(" ");
			
			//read Chest Info
			for(j=0; j<numc; j++){
				strs = br.readLine().split(" ");
				keys.defKey(Integer.parseInt(strs[0])-1, j);
				keys.defNeed(j, Integer.parseInt(strs[0])-1);
				
				numg = Integer.parseInt(strs[1]);
				gain = String.valueOf(numg);
				for(k=0; k<numg; k++){
					gain += (" " + String.valueOf(Integer.parseInt(strs[2+k])-1));
				}
				keys.defGain(j, gain);
			}

			//set StartKey Info (after DefKey)
			for(j=0; j<numk; j++){
				keys.addKey(Integer.parseInt(fkey[j])-1, 1);
			}
			
			while(stage < numc){
				trial = (BitSet)remain.clone();
				trial.and(fail);
				
				ptr   = keys.findOpen(ptr, trial);
				
				//Found No Chest case
				if(ptr == -1){
					if(stage == 0){
						cant = true;
						break;
					}
					else{
						ptr = pass[stage-1] - 1;
						keys.addKey(keys.findNeed(ptr), 1);

						strs = keys.findGain(ptr).split(" ");
						numg = Integer.parseInt(strs[0]);
						for(j=0; j<numg; j++){
							keys.useKey(Integer.valueOf(strs[1+j]), 1);
						}
						fail.clear(ptr);
						
						remain.set(ptr);
						ptr++;
						stage--;
					}
				}
				//Found Next case
				else{
					keys.useKey(keys.findNeed(ptr), 1);
					
					strs = keys.findGain(ptr).split(" ");
					numg = Integer.parseInt(strs[0]);
					for(j=0; j<numg; j++){
						keys.addKey(Integer.valueOf(strs[1+j]), 1);
					}
					if(numg != 0){ fail.set(0, numc); }
					
					remain.clear(ptr);
					pass[stage] = ptr + 1;
					ptr = 0;
					stage++;
				}
			}
			
			if(cant){
				answer = "IMPOSSIBLE";
			}
			else{
				answer = "";
				for(j=0; j<numc-1; j++){
					answer += pass[j] + " ";
				}
				answer += pass[numc-1];
			}
			bw.write("Case #" + i + ": " + answer + "\n");
		}
		
		br.close();
		bw.close();		
	}
}
