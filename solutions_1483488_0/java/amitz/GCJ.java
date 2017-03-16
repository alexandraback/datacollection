package com.google.code;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public abstract class GCJ {

	private BufferedReader input;
	private BufferedWriter output;
	String inputLine;
	String[] brokenUpInputLine;
	public static final String FOLDER = "/tmp/";
	
	
	protected GCJ() throws IOException {
		String subclass = this.getClass().getSimpleName();		
		input = new BufferedReader(new FileReader(new File(FOLDER, subclass+".in")));
		output = new BufferedWriter(new FileWriter(new File(FOLDER, subclass+".out")));
	}

	public void run() throws NumberFormatException, IOException {
		int loop = Integer.valueOf(input.readLine());
		for (int i = 0; i < loop; i++)
			answering(i+1);
		output.flush();
	}

	protected void write(String s) throws IOException {
		System.out.print(s);
		output.write(s);
	}
	protected void writeln(String s) throws IOException {
		System.out.println(s);
		output.write(s+"\n");
	}
	protected void writeln() throws IOException {
		System.out.println();
		output.write("\n");
	}
	protected void write(int s) throws IOException {
		System.out.print(String.valueOf(s));
		output.write(String.valueOf(s));
	}
	protected void writeln(int s) throws IOException {
		System.out.println(String.valueOf(s));
		output.write(String.valueOf(s)+"\n");
	}
	
	protected void readLine() throws IOException {
		inputLine = input.readLine();
		brokenUpInputLine = inputLine.split(" ");
	}
	
	protected String getStringInput(int i) {
		return brokenUpInputLine[i];
	}
	
	protected int getIntInput(int i) {
		return Integer.parseInt(brokenUpInputLine[i]);
	}
	
	protected long getLongInput(int i) {
		return Long.parseLong(brokenUpInputLine[i]);
	}
	
	protected double getDoubleInput(int i) {
		return Double.parseDouble(brokenUpInputLine[i]);
	}

	private void answering(int ordinalityOfProblem) throws IOException {
		writeOrdinalityOfAnswer(ordinalityOfProblem);
		code(ordinalityOfProblem);
	}
	private void writeOrdinalityOfAnswer(int ordinalityOfProblem) throws IOException {
		write("Case #"+ordinalityOfProblem+": ");
	}
	
	protected abstract void code(int count) throws IOException;

}
