
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;



public class EqualSum {
	static int numbers;
	static StringBuffer s = new StringBuffer("");
	public static void main(String[] args) throws IOException 
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-small-attempt1.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("EqualSum.txt"));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=1; i <= cases; i++)
		{
			String[] data = reader.readLine().split(" ");
			numbers = Integer.parseInt(data[0]);
			array = new int[numbers];
			map  = new HashMap<Integer,  ArrayList<Integer>>();
			for(int j=1;j<=numbers;j++) {
				array[j-1] = Integer.parseInt(data[j]);
			}
			s.append("Case #" + i + ":\n");
			if(!recursion(0, 0, new ArrayList<Integer>()))
				s.append("Impossible\n");
			out.write(s.toString());
			//System.out.println(s);
			s = new StringBuffer("");
			//System.out.print("Case #" + i+ ":" + s+"\n");
			//out.write("Case #" + i+ ":" + s+"\n");
		}
		out.close();
	}
	static int[] array;
	static HashMap<Integer, ArrayList<Integer>> map;
	public static boolean recursion(int index, int sum, ArrayList<Integer> list) throws IOException {
		for(int i = index; i < array.length; i++) {
			ArrayList<Integer> newList = new ArrayList<Integer>(list);
			newList.add(i);
			int newSum = sum+array[i];
			if(map.containsKey(newSum) && doesNotContainSameIndex(newList, map.get(newSum))) {
				display(newList);
				display(map.get(newSum));
				return true;
			}
			else
				map.put(newSum, newList);
			if(recursion(i+1, newSum, newList)) return true;
		}
		return false;
	}
	private static boolean doesNotContainSameIndex(ArrayList<Integer> newList, ArrayList<Integer> arrayList) {
		boolean[] array = new boolean[numbers];
		for(int i =0; i<newList.size(); i++)
			array[newList.get(i)] = true;
		for(int i =0; i<arrayList.size(); i++)
			if(array[arrayList.get(i)]) return false;
		return true;
	}
	public static void display(ArrayList<Integer> list) throws IOException {
		s.append(array[list.get(0)]);
		for(int i =1; i< list.size(); i++) {
			s.append(" " + array[list.get(i)]);
		}
		s.append("\n");
	}
}