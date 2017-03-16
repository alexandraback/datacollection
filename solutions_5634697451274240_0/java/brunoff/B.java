package gcj2016.qualification;

public class B {
	private String path = "/home/brunoff/data/dev/gcj/data/2016/qualification/";
	private int N; 
	private Case[] Cases;
	private class Case {
		public Case(char[] initialstack) { stack = initialstack; }
		public char[] stack; public int flips = -1;
	}
	
	//void main points here (new gcj2016.qualification.A().solve("B-large");)
	public void solve(String filename) throws Exception {
		readfile(filename);
		for(int casenumber=0;casenumber<N;casenumber++)
			solvecase(casenumber);
		writeresult(filename);
	}
	
	
	private boolean stackisfine(char[] stack) {
		for(int stackpos=0;stackpos<stack.length;stackpos++)
			if(stack[stackpos]!='+') return false;
		return true;
	}
	
	private char flip(char pancake) throws Exception {
		if(pancake=='+') return '-';
		else
		if(pancake=='-') return '+';
		else
		throw new Exception("bad pancake");
	}
	
	private char[] flip(char[] stack, int stackpos) throws Exception {
		stack[stackpos] = flip(stack[stackpos]);
		return stack;
	}
	
	private void solvecase(int casenumber) throws Exception {
		Case Case = Cases[casenumber];
		
		int flipcount=0;
		char flipto;
		for(;!stackisfine(Case.stack);flipcount++) {
			flipto = flip(Case.stack[0]);
			for(int stackpos=0;stackpos < Case.stack.length && Case.stack[stackpos]!=flipto;stackpos++) flip(Case.stack,stackpos);
		}
		Case.flips = flipcount;
		
		System.out.println("Case #"+(casenumber+1)+": "+caseresult(Cases[casenumber]));
	}
	
	private String caseresult(Case Case) {
		return String.valueOf(Case.flips);
	}
	
	private void writeresult(String filename) {
		try(java.io.Writer writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(new java.io.FileOutputStream(path+filename+".out")))) {
			for(int casenumber=0;casenumber<N;casenumber++)
				writer.write("Case #"+(casenumber+1)+": "+caseresult(Cases[casenumber])+System.lineSeparator());
		} catch (Exception ex) { ex.printStackTrace(); };
	}
	
	private void readfile(String filename) {
		try (java.io.BufferedReader reader = java.nio.file.Files.newBufferedReader(java.nio.file.Paths.get(path+filename+".in"))) {
			N = Integer.parseInt(reader.readLine());
			Cases = new Case[N];
			for(int casenumber=0;casenumber<N;casenumber++)
				Cases[casenumber] = new Case(reader.readLine().toCharArray());
		} catch (java.io.IOException ioex) {
			ioex.printStackTrace();
		}
	}
}