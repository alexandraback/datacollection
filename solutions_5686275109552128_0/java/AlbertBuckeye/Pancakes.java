package Qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class Pancakes {
	public static void main(String[] args) throws NumberFormatException, IOException {
		File inFile = new File("input.txt");
		File outFile = new File("output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		PrintWriter pw = new PrintWriter(outFile);
		int numTest = Integer.parseInt(reader.readLine().trim());
		for(int i=1; i<=numTest; i++){
			int num = Integer.parseInt(reader.readLine().trim());
			String strSplit[] = reader.readLine().trim().split(" ");
			int arr[] = new int[strSplit.length];
			for(int j=0; j<arr.length; j++)
				arr[j] = Integer.parseInt(strSplit[j]);
			pw.println("Case #"+i+": "+getMinTime(num, arr));
		}
		pw.flush();
		pw.close();
		reader.close();
		System.out.println("******************************");
		System.out.println(getMinTime(1, new int[]{3}));
	}
	public static int getMinTime(int num, int arr[]){
		int time = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int ele:arr){
			list.add(ele);
		}
		Collections.sort(list);
//		System.out.println(list.get(0));
		int curIdx = list.size()-1;
		int special = 0;
		time = list.get(curIdx);
		while(list.get(curIdx) != 1){//all elements are 1
			//split
			int part1 = list.get(curIdx)/2, part2 = (list.get(curIdx)+1)/2;
			assert part1+part2 == list.get(curIdx);
			insert(list, part1, part2);
			list.remove(curIdx+2);//remove last element
			special += 1;
			curIdx = list.size()-1;
			if(special+list.get(curIdx).intValue() > time)//splitting the element will increase the time.
				;
			else
				time = special+list.get(curIdx).intValue();
		}
		return time;
	}
	public static void insert(ArrayList<Integer> list, int part1, int part2){
//		for(int i=0; i<list.size(); i++)	System.out.print(list.get(i)+" ");
//		System.out.println("\nAdd "+part1+" "+part2);
		int idx = Math.abs(Collections.binarySearch(list, part1)+1);
		list.add(idx, part1);
		for(int i=idx; i<list.size(); i++){
			if(part2 <= list.get(i).intValue()){
				list.add(i, part2);
				break;
			}
		}
//		for(int i=0; i<list.size(); i++)	System.out.print(list.get(i)+" ");
//		System.out.println("");
		
	}
}
