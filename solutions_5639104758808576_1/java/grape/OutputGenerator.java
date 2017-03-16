package util;

import java.io.File;

public class OutputGenerator {

	
	public static final File targetFile = new File("output/a.txt");
	
	int nextCaseId=1;
	StringBuilder output = new StringBuilder();
	
	
	public void oCase() {
		appendCaseNumber();
		output.append(LINE_SEP);
	}
	
	public void oCase(int x) {
		appendCaseNumber();
		o(x);
	}
	
	public void oCase(long x) {
		appendCaseNumber();
		o(x);
	}
	
	
	public void oCase(double x) {
		appendCaseNumber();
		o(x);
	}
	
	public void oCase(String x) {
		appendCaseNumber();
		o(x);
	}
	
	public void oCase(int[] x) {
		appendCaseNumber();
		o(x);
	}
	
	public void oCase(double[] x) {
		appendCaseNumber();
		o(x);
	}
	
	public void oCase(String[] x) {
		appendCaseNumber();
		o(x);
	}
	
	
	public void o(int x) {
		output.append(x);
		output.append(LINE_SEP);
	}
	
	public void o(long x) {
		output.append(x);
		output.append(LINE_SEP);
	}
	
	
	public void o(double x) {
		output.append(x);
		output.append(LINE_SEP);
	}
	
	public void o(String x) {
		output.append(x);
		output.append(LINE_SEP);
	}
	
	public void o(int[] x) {
		for(int y: x) {
			output.append(y);
			output.append(" ");
		}
		output.deleteCharAt(output.length()-1);
		output.append(LINE_SEP);
	}
	
	public void o(double[] x) {
		for(double y: x) {
			output.append(y);
			output.append(" ");
		}
		output.deleteCharAt(output.length()-1);
		output.append(LINE_SEP);
	}
	
	public void o(String[] x) {
		for(String y: x) {
			output.append(y);
			output.append(" ");
		}
		output.deleteCharAt(output.length()-1);
		output.append(LINE_SEP);
	}
	
	
	public void o(Object[] x) {
		for(Object y: x) {
			output.append(y);
			output.append(" ");
		}
		output.deleteCharAt(output.length()-1);
		output.append(LINE_SEP);
	}
	
	
	private void appendCaseNumber() {
		output.append("Case #" + nextCaseId++ + ": ");
	}
	
	
	public String get() {
		return output.toString();
	}
	
	public void wr() {
		FileAccess.write(output.toString(), targetFile);
	}
	
	public static final String toString(int[] a) {
		if(a==null)
			return null;
		StringBuilder sb = new StringBuilder();
		for(int i:a) {
			sb.append(i);
			sb.append(" ");
		}
		sb.deleteCharAt(sb.length()-1);
		return sb.toString().trim();
	}
	
	protected static final String LINE_SEP=System.getProperty("line.separator");
}
