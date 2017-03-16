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

public class Pogo {
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
			int pointX = Integer.parseInt(str[0]);
			int pointY = Integer.parseInt(str[1]);
			String result = String.format("Case #%d: %s", i+1, getResult(pointX, pointY));
			mWrite.writeLine(result);
		}
	}
	
	static String getResult(int pointX, int pointY) {
		String rst = "";
		if (pointX < 0) {
			int tempX = -pointX;
			while (tempX-- > 0) {
				rst += "EW";
			}
		} else if (pointX > 0) {
			int tempX = pointX;
			while (tempX-- > 0) {
				rst += "WE";
			}
		}
		if (pointY < 0) {
			int tempY = -pointY;
			while (tempY-- > 0) {
				rst += "NS";
			}
		} else if (pointY > 0) {
			int tempY = pointY;
			while (tempY-- > 0) {
				rst += "SN";
			}
		}
		return rst;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReadIO read = new ReadIO("B-small-attempt1.in");
		WriteIO write = new WriteIO("output.txt");
		Pogo demo = new Pogo();
		demo.setIO(read, write);
		demo.process();
		read.close();
		write.close();
		demo.setIO(null, null);
	}

}
