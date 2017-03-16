package common;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class FileTranslatorBasis {

	private int numOfCase;
	private File file;
	Queue<String> dataList = new LinkedList<String>();

	
	
	public static FileTranslatorBasis getInstance(String fname){
		if(fname ==null){
			throw new IllegalArgumentException();
		}
		return new FileTranslatorBasis(new File(fname));
	}
	
	private FileTranslatorBasis(File file) {
		this.file = file;
		read();
	}
	
	private void read(){
		try{
			FileReader fr = new FileReader(this.file);
			BufferedReader br = new BufferedReader(fr);
		
			String line;
			while((line = br.readLine())!=null){
				dataList.add(line);
			}
		}catch(IOException e){
			e.printStackTrace();
		}
		numOfCase = Integer.parseInt(dataList.poll());
	}

	public int getNumOfCase(){
		return numOfCase;
	}
	
	public int getIntData(){
		return Integer.parseInt(dataList.poll());
	}
	
	public int[] getIntDataArray(){
		String[] tmp = getStrDataArray();
		int[] data = new int[tmp.length];
		int i = 0;
		for(String t: tmp){
			data[i++] = Integer.parseInt(t);
		}
		return data;
	}
	
	
	public long getLongData(){
		return Long.parseLong(dataList.poll());
	}
	
	public long[] getLongDataArray(){
		String[] tmp = getStrDataArray();
		long[] data = new long[tmp.length];
		int i = 0;
		for(String t: tmp){
			data[i++] = Long.parseLong(t);
		}
		return data;
	}
	public String getStrData(){
		return dataList.poll();
	}
	
	public String[] getStrDataArray(){
		return dataList.poll().split(" ");
	}

	
	
}
