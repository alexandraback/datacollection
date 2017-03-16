import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;


public class ProblemB {
	static FileWriter writer;
	public static void main(String[] args) throws IOException {
		writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/output.txt");
		BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/input.txt"));
		String line = br.readLine();
		int numCases = Integer.parseInt(line);
		for(int caseNum = 1; caseNum <= numCases; caseNum++){
			line = br.readLine();
			int d = Integer.parseInt(line);
			line = br.readLine();
			Scanner s = new Scanner(line);
			ArrayList<Integer> pancakes = new ArrayList<Integer>();
			while(s.hasNext()){
				pancakes.add(Integer.parseInt(s.next()));
			}
			Collections.sort(pancakes);
			write("" + brute3(pancakes), caseNum);
		}
		writer.close();
		br.close();

	}
	
	public static int brute3(ArrayList<Integer> p){
		int min = p.get(p.size() - 1);
		for(int wait = 1; wait < min; wait++){
			int splits = 0;
			for(int i = 0; i < p.size(); i++){
				splits += Math.ceil((double)p.get(i)/wait) - 1;
			}
			if(splits + wait < min){
				min = splits + wait;
			}
		}
		return min;
	}

	public static int brute2(ArrayList<Integer> p){
		if(p.size() == 0) return 0;
		if(p.get(p.size() - 1) < 4) return p.get(p.size() - 1);
		ArrayList<Integer> next = new ArrayList<Integer>();
		for(int i = 0; i < p.size(); i++){
			if(p.get(i) != 1){
				int value = p.get(i) - 1;
				next.add(value);
			}
		}
		int max = p.remove(p.size() - 1);
		if(max == 9){
			ArrayList<Integer> copy = new ArrayList<Integer>();
			for(int i = 0; i < p.size(); i++){
				copy.add(p.get(i));
			}
			p.add(3);
			p.add(6);
			copy.add(4);
			copy.add(5);
			Collections.sort(p);
			Collections.sort(copy);
			return Math.min(Math.min(brute2(p), brute2(next)), brute2(copy)) + 1;
		} else {
			int part1 = max/2;
			int part2 = max - part1;
			p.add(part1);
			p.add(part2);
			Collections.sort(p);
			return (Math.min(brute2(p), brute2(next)) + 1);
		}
	}
	
	public static int brute(ArrayList<Integer> p, int base, int current){
		//if(current == 1) System.out.println(p);
		if(p.size() == 0) return base;
		if(p.get(p.size() - 1) <= 3) return Math.min(current + p.get(p.size() - 1), base);
		if(current + 3 >= base) return base;
		ArrayList<Integer> next = new ArrayList<Integer>();
		for(int i = 0 ; i < p.size(); i++){
			int nextNumber = p.get(i);
			if(nextNumber != 1){
				next.add(nextNumber - 1);
			}
		}
		int baseLine = brute(next, base, current + 1);
		for(int i = 0; i < p.size(); i++){ // pick one to split
			int target = p.get(i);
			if(target < 4) continue;
			if(i != 0 && target == p.get(i - 1)) continue;
			for(int add = 1; add < target; add++){ //pick value of split
				int left = target - add;
				for(int toAddTo = 0; toAddTo < p.size(); toAddTo++){ //pick plate to add to
					if(toAddTo != i && p.get(toAddTo) + add >= target) continue;
					next = new ArrayList<Integer>();
					next.add(left);
					if(toAddTo == i){
						for(int j = 0; j < p.size(); j++){
							if(j != i && j != toAddTo){
								int nextNumber = p.get(j);
								next.add(nextNumber);
							} else if(j == i){
								next.add(add);
							}
						}
					} else {
						for(int j = 0; j < p.size(); j++){
							if(j != i && j != toAddTo){
								int nextNumber = p.get(j);
								next.add(nextNumber);
							} else if(j == toAddTo){
								int nextNumber = p.get(j) + add;
								next.add(nextNumber);
							}
						}
					}
					Collections.sort(next);
					//System.out.println(next);
					int value = brute(next, baseLine, current + 1);
					if(value < baseLine){
						System.out.println(value + " " + next);
						baseLine = value;
					}
				}
			}
			
		}
		return baseLine;
	}
	public static void write(String line, int caseNum) throws IOException{
		writer.write("Case #" + caseNum + ": " + line + "\n");
	}
}
