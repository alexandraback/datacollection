package com.google.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;

class ReadIO {
	private FileReader fileReader;
	private BufferedReader bufferedReader;
	public ReadIO(String filepath) {
		try {
			File file = new File(filepath);
			fileReader = new FileReader(file);
			bufferedReader = new BufferedReader(fileReader);
		} catch (Exception ex) {
			
		}
	}
	
	public String readLine() {
		try {
			return bufferedReader.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public void close() {
		if (bufferedReader != null) {
			try {
				bufferedReader.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			bufferedReader = null;
		}
		if (fileReader != null) {
			try {
				fileReader.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			fileReader = null;
		}
	}
}

class WriteIO {
	private FileOutputStream fos;
	private OutputStreamWriter writer;
	public WriteIO(String filepath) {
		try {
			File file = new File(filepath);
			file.createNewFile();
			fos = new FileOutputStream(file);
			writer = new OutputStreamWriter(fos);
		} catch (Exception ex) {
			
		}
	}
	
	public void writeLine(String str) {
		try {
			writer.write(str+ System.getProperty("line.separator"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void close() {
		if (writer != null) {
			try {
				writer.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				writer.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			writer = null;
		}
		if (fos != null) {
			try {
				fos.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			fos = null;
		}
	}
}

public class Consonants {
	private ReadIO mRead;
	private WriteIO mWrite;
	public void setIO(ReadIO read, WriteIO write) {
		mRead = read;
		mWrite = write;
	}
	
	public void process() {
		int caseCount = Integer.parseInt(mRead.readLine());
		for (int i = 0; i<caseCount; ++i) {
			String[] str = mRead.readLine().split(" ");
			String name = str[0].toLowerCase();
			int N = Integer.parseInt(str[1]);
			String result = String.format("Case #%d: %d", i+1, getResult(name, N));
			mWrite.writeLine(result);
		}
	}
	
	static int getResult(String name, int N) {
		int length = name.length();
		if (N > length) {
			return 0;
		}
		int count = 0;
		for (int i = 0; i<length-N+1; ++i) {
			for (int j = i + N; j<=length; ++j) {
				String subString = name.substring(i, j);
				int num = 0;
				int subLength = subString.length();
				for (int k = 0; k<subLength; ++k) {
					if (subString.charAt(k) != 'a'
						&& subString.charAt(k) != 'e'
				        && subString.charAt(k) != 'i'
				        && subString.charAt(k) != 'o'
				        && subString.charAt(k) != 'u') {
						num++;
						if (num >= N) {
							count++;
							break;
						}
					} else {
						num = 0;
					}
				}
			}
		}
		return count;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReadIO read = new ReadIO("A-small-attempt0.in");
		WriteIO write = new WriteIO("output.txt");
		Consonants demo = new Consonants();
		demo.setIO(read, write);
		demo.process();
		read.close();
		write.close();
		demo.setIO(null, null);
	}

}
