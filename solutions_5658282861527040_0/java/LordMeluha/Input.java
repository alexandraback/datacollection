package input;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Input {

	private String line;
	private int currentIndex;
	private BufferedReader br;
	private String[] arr;
	
	public Input(String fileName){
		File file = new File(fileName);
		try {
			FileInputStream fstream = new FileInputStream(file);

			DataInputStream in = new DataInputStream(fstream);
			br = new BufferedReader(new InputStreamReader(in));
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	public String nextLine(){
		try {
			line =  br.readLine();
			arr = line.split(" "); 
			currentIndex = 0;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return line;
	}
	
	public String next(){
		String N;
		if(currentIndex == 0 || currentIndex == arr.length){
			nextLine();
		}
		N = arr[currentIndex++];
		return N;
	}
	
	public int nextInt(){
		int N;
		N = Integer.parseInt(next());
		return N;
	}
	
	public long nextLong(){
		long N;
		N = Long.parseLong(next());
		return N;
	}
	
	public double nextDouble(){
		double N;
		N = Double.parseDouble(next());
		return N;
	}
	
	public float nextFloat(){
		float N;
		N = Float.parseFloat(next());
		return N;
	}
	
	public static ArrayList<Integer> GetIntList(String str){
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(String s : str.split(" ")){
			list.add(Integer.parseInt(s));
		}
		return list;
	}
	
	public static ArrayList<Long> GetLongList(String str){
		ArrayList<Long> list = new ArrayList<Long>();
		for(String s : str.split(" ")){
			list.add(Long.parseLong(s));
		}
		return list;
	}
	
	public static ArrayList<Float> GetFloatList(String str){
		ArrayList<Float> list = new ArrayList<Float>();
		for(String s : str.split(" ")){
			list.add(Float.parseFloat(s));
		}
		return list;
	}
	
	public static ArrayList<Double> GetDoubleList(String str){
		ArrayList<Double> list = new ArrayList<Double>();
		for(String s : str.split(" ")){
			list.add(Double.parseDouble(s));
		}
		return list;
	}
	
	public static ArrayList<String> GetList(String str){
		ArrayList<String> list = new ArrayList<String>();
		for(String s : str.split(" ")){
			list.add(s);
		}
		return list;
	}
}
