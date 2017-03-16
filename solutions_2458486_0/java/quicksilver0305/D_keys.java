package gcj2013;

import java.util.*;

public class D_keys {
	int[]    have;
	BitSet   open;
	BitSet[] keys;
	
	int[]    need;
	String[] gain;	
	
	public D_keys() {
		
		int i;
		
		this.have = new int[200];
		this.open = new BitSet(200);
		this.keys = new BitSet[200];
		
		this.need = new int[200];
		this.gain = new String[200];
		
		for(i=0; i<200; i++){
			have[i] = 0;
			keys[i] = new BitSet(200);
			keys[i].clear();

			need[i] = 0;
			gain[i] = "";
		}
		open.clear();
	}
	
	public void incOpen(int key){
		open.or(keys[key]);
	}	
	
	public void decOpen(int key){
		open.andNot(keys[key]);
	}	
	
	public void addKey(int key, int num){
		if(have[key]==0){
			incOpen(key);
		}
		have[key] += num;
	}

	public void useKey(int key, int num){
		have[key] -= num;
		if(have[key]==0){
			decOpen(key);
		}
	}
	
	public int findOpen(int sta, BitSet remain){
		int idx;
		BitSet trial;
		
		trial = (BitSet)open.clone();
		trial.and(remain);
		idx = trial.nextSetBit(sta);

		return idx;
	}	

	public int findNeed(int chest){
		return need[chest];
	}	

	public String findGain(int chest){
		return gain[chest];
	}	
	
	public void defKey(int key, int bit){
		keys[key].set(bit);
	}	
	
	public void defNeed(int chest, int key){
		need[chest] = key;
	}	
	
	public void defGain(int chest, String key){
		gain[chest] = key;
	}	

}
