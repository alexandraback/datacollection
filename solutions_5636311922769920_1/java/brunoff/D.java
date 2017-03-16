package gcj2016.qualification;

public class D {
	private String path = "/home/brunoff/data/dev/gcj/data/2016/qualification/";
	private int N; 
	private Case[] Cases;
	private class Case {
		public Case(String[] strarr) {
			k = Integer.parseInt(strarr[0]);
			c = Integer.parseInt(strarr[1]);
			s = Integer.parseInt(strarr[2]);
		}
		public int k, c, s;
		public String answer;
	}
	
	//void main points here (new gcj2016.qualification.D().solve("D-large");)
	public void solve(String filename) throws Exception {
		readfile(filename);
		for(int casenumber=0;casenumber<N;casenumber++)
			solvecase(casenumber);
		writeresult(filename);
	}
	
	private String stringbuild(long from, int positions) {
		String output = "";
		for(int i=0;i <= positions;i++)
			output += " "+(from + i + 1);
		return output;
	}
	
	private void solvecase(int casenumber) throws Exception {
		Case Case = Cases[casenumber];
		if(Case.k<1)
			throw new Exception("zero length artwork");
		else
		if(Case.k==1)
			Case.answer = (Case.s>=1)?" 1":" IMPOSSIBLE";
		else
		if(Case.s < (1+Case.k-Case.c) )
			Case.answer = " IMPOSSIBLE";
		else {
			long initialpos = Math.min(Case.c,Case.k) - 1;
			int i=1;
			while(i<Math.min(Case.c,Case.k)-1) {
			//while(i<Case.k-Case.c-1) {
				initialpos += i*Math.pow(Case.k,(Math.min(Case.c,Case.k)-i-1));
				i++;
			}
			Case.answer = stringbuild(initialpos,Math.max(Case.k-Case.c,0));
		}
		
		System.out.println("Case #"+(casenumber+1)+":"+caseresult(Cases[casenumber]));
	}
	
	private String caseresult(Case Case) {
		//return Case.k + " " + Case.c + " " + Case.s + " =>" + Case.answer;
		return Case.answer;
	}
	
	private void writeresult(String filename) {
		try(java.io.Writer writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(new java.io.FileOutputStream(path+filename+".out")))) {
			for(int casenumber=0;casenumber<N;casenumber++)
				writer.write("Case #"+(casenumber+1)+":"+caseresult(Cases[casenumber])+System.lineSeparator());
		} catch (Exception ex) { ex.printStackTrace(); };
	}
	
	private void readfile(String filename) {
		try (java.io.BufferedReader reader = java.nio.file.Files.newBufferedReader(java.nio.file.Paths.get(path+filename+".in"))) {
			N = Integer.parseInt(reader.readLine());
			Cases = new Case[N];
			for(int casenumber=0;casenumber<N;casenumber++)
				Cases[casenumber] = new Case(reader.readLine().split(" ",3));
		} catch (java.io.IOException ioex) {
			ioex.printStackTrace();
		}
	}

}
