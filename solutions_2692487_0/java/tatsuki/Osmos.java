package com.google.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;

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

public class Osmos {
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
			int initSize = Integer.parseInt(str[0]);
			int motoNumber = Integer.parseInt(str[1]);
			String[] str2 = mRead.readLine().split(" ");
			int[] motoSizes = new int[motoNumber];
			for (int j = 0; j<motoSizes.length; ++j) {
				motoSizes[j] = Integer.parseInt(str2[j]);
			}
			String result = String.format("Case #%d: %d", i+1, getResult(initSize, motoSizes));
			mWrite.writeLine(result);
		}
	}
	
	static int getResult(long initSize, int[] motoSizes) {
		Arrays.sort(motoSizes);
		long currentSize = initSize;
		int operation = 0;
		int maxOperation = -1;
		for (int i = 0; i<motoSizes.length; ++i) {
			if (currentSize > motoSizes[i]) {
				currentSize += motoSizes[i];
			} else {
				int needRemove = motoSizes.length - i;
				int needAdd = 0;
				long currentTemp = currentSize;
				if (currentTemp != 1) {
					while(currentTemp <= motoSizes[i]) {
						currentTemp += (currentTemp-1);
						needAdd++;
					}
				} else {
					needAdd = needRemove + 1;
				}
				if (maxOperation == -1) {
					maxOperation = operation + needRemove;
				} else {
					if (operation + needRemove < maxOperation) {
						maxOperation = operation + needRemove;
					}
				}
				if (needRemove < needAdd) {
					operation += needRemove;
					if (operation > maxOperation && maxOperation != -1) {
						return maxOperation;
					}
					return operation;
				} else {
					operation += needAdd;
					currentSize = currentTemp + motoSizes[i];
					if (operation > maxOperation && maxOperation != -1) {
						return maxOperation;
					}
				}
				
			}
		}
		if (operation > maxOperation && maxOperation != -1) {
			return maxOperation;
		}
		return operation;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReadIO read = new ReadIO("A-small-attempt1.in");
		WriteIO write = new WriteIO("output.txt");
		Osmos demo = new Osmos();
		demo.setIO(read, write);
		demo.process();
		read.close();
		write.close();
		demo.setIO(null, null);
	}

}
