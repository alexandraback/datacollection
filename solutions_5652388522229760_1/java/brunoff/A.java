package gcj2016.qualification;

import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class A {
	private int MAX = 1000000;
	private String path = "/home/brunoff/data/dev/gcj/data/2016/qualification/";
	private int N; 
	private Case[] Cases;
	private class Case { public Case(long number) { firstnumber = number; } public long firstnumber; public long lastnumber; /*public List<Integer> numbers;*/ }
	
	//void main points here (new gcj2016.qualification.A().solve("A-large");)
	public void solve(String filename) {
		readfile(filename);
		for(int casenumber=0;casenumber<N;casenumber++)
			solvecase(casenumber);
		writeresult(filename);
	}
	
	
	private short markdigits(long number) {
		String str = Long.toString(number);
		short digits = 0b0000000000000000;
		for(int i=0;i<str.length();i++)
			switch(str.charAt(i)) {
				case '0': digits |= 0b0000000000000001; break;
				case '1': digits |= 0b0000000000000010; break;
				case '2': digits |= 0b0000000000000100; break;
				case '3': digits |= 0b0000000000001000; break;
				case '4': digits |= 0b0000000000010000; break;
				case '5': digits |= 0b0000000000100000; break;
				case '6': digits |= 0b0000000001000000; break;
				case '7': digits |= 0b0000000010000000; break;
				case '8': digits |= 0b0000000100000000; break;
				case '9': digits |= 0b0000001000000000; break;
				default: System.out.println("badigit"); break;
			}
		return digits;
	}
	
	private void solvecase(int casenumber) {
		Case Case = Cases[casenumber];
		//byte[] usedigits = new byte[10];
		short usedigits = 0b0000000000000000;
		int i=0;
		for(;usedigits!=0b0000001111111111 && i<MAX;)
			usedigits |= markdigits((++i)*Case.firstnumber);
		Case.lastnumber = i<MAX?i*Case.firstnumber:-1;
		
		System.out.println("Case #"+(casenumber+1)+": "+caseresult(Cases[casenumber]));
	}
	
	private String caseresult(Case Case) {
		return Case.lastnumber!=-1?String.valueOf(Case.lastnumber):"INSOMNIA";
	}
	
	private void writeresult(String filename) {
		try(java.io.Writer writer = new java.io.BufferedWriter(new java.io.OutputStreamWriter(new java.io.FileOutputStream(path+filename+".out")))) {
			for(int casenumber=0;casenumber<N;casenumber++)
				writer.write("Case #"+(casenumber+1)+": "+caseresult(Cases[casenumber])+System.lineSeparator());
		} catch (Exception ex) { ex.printStackTrace(); };
		for(int casenumber=0;casenumber<N;casenumber++);
	}
	
	private void readfile(String filename) {
		try (java.io.BufferedReader reader = java.nio.file.Files.newBufferedReader(java.nio.file.Paths.get(path+filename+".in"))) {
			String line = null;
			N = Integer.parseInt(reader.readLine());
			Cases = new Case[N];
			for(int casenumber=0;casenumber<N;casenumber++)
				Cases[casenumber] = new Case(Long.parseLong(reader.readLine()));
		} catch (java.io.IOException ioex) {
			ioex.printStackTrace();
		}
	}
}