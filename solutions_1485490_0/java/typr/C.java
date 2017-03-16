package a3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class C {
	static long[] tn;
	static int[] tt;
	static long[] bn;
	static int[] bt;
	
	static class State{
		int curT = -1;
		int curB = -1;
		long countT = 0;
		long countB = 0;
		long count = 0;
		State() {}
		State(State s){
			curT = s.curT;
			curB = s.curB;
			countT = s.countT;
			countB = s.countB;
			count = s.count;
		}
		
		void produce(List<State> states, List<State> fin){
			if (tt[curT] == bt[curB]) {
				// same types
				long min = Math.min(countT, countB);
				count += min;
				countT -= min;
				countB -= min;
				process(states, fin);
			} else {
				// add 3 states
				State skipT = new State(this);
				skipT.countT = 0;
				skipT.process(states, fin);
				
				State skipB = new State(this);
				skipB.countB = 0;
				skipB.process(states, fin);
				
				State skipBoth = new State(this);
				skipBoth.countT = 0;
				skipBoth.countB = 0;
				skipBoth.process(states, fin);
			}
				
		}
		
		void process(List<State> states, List<State> fin){
			if (countT == 0){
				if (curT < tn.length-1) curT++; else {
					fin.add(this);
					return;
				}
				countT = tn[curT];
			}
			if (countB == 0){
				if (curB < bn.length-1) curB++; else {
					fin.add(this);
					return ;
				}
				countB = bn[curB];
			}
			states.add(this);
		}
		public String toString(){
			String s = curT + ":" + curB + " " + countT + ":" + countB + " " + count;
			return s;
		}
	}
	public static void main(String[] args) throws Exception{
		String in_file = "a3/cs.in";
		String out_file = in_file.replace(".in", ".out");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++){
			String s = in.readLine();
			String[] tmp = s.split(" ");
			int nToy = Integer.parseInt(tmp[0]);
			int nBox = Integer.parseInt(tmp[1]);
			tn = new long[nToy];
			tt = new int[nToy];
			s = in.readLine();
			tmp = s.split(" ");
			for (int j = 0; j < nToy; j++){
				tn[j] = Long.parseLong(tmp[j*2]);
				tt[j] = Integer.parseInt(tmp[j*2 + 1]);
			}
					
			bn = new long[nBox];
			bt = new int[nBox];
			s = in.readLine();
			tmp = s.split(" ");
			for (int j = 0; j < nBox; j++){
				bn[j] = Long.parseLong(tmp[j*2]);
				bt[j] = Integer.parseInt(tmp[j*2 + 1]);
			}
					
			List<State> states = new ArrayList<State>();
			List<State> fin = new ArrayList<State>();
			new State().process(states, fin);
			while (states.size() > 0){
				State st = states.remove(states.size() - 1);
				st.produce(states, fin);
			}
			
			long m = 0;
			for (State st : fin){
				if (st.count > m) m = st.count;
			}
			out.write("Case #" + i + ": " + m + "\n");
			
		}
		
		
		in.close();
		out.close();
		
	}
}
