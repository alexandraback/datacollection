package ProblemB;

import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

import utils.InputReader;

public class SolverB {
	public static void main(String[] args) throws IOException {
		LinkedList<String> input = InputReader.read("C:/Users/Danielle/Desktop/B-small-attempt2.in");
		int num = Integer.parseInt(input.removeFirst());
		int i = 1;
		while(i <= num && !input.isEmpty()) {
			if (i == 4){
				System.out.println();;
			}
			int sz = Integer.parseInt(input.removeFirst());
			ArrayList<int[]> levels = new ArrayList<int[]>(sz);
			for (int k = 0; k < sz; k++){
				String str = input.removeFirst();
				int[] cur = new int[3];
				String[] split = str.split(" ");
				cur[0] = Integer.parseInt(split[0]);
				cur[1] = Integer.parseInt(split[1]);
				cur[2] = 0;
				levels.add(cur);
			}
			int stars = 0;
			int plays = 0;
			while(!levels.isEmpty()){
				int[] cur = null;
				for (int[] js : levels) {
					if (js[1] <= stars){
						cur = js;
						break;
					}
					if ((cur == null || cur[1] < js[1]) && js[2] == 0 && js[0] <= stars){
						cur = js;
					}
				}
				if (cur == null){
					System.out.println("Case #"+(i++)+": Too Bad");
					break;
				}
				if (cur[1] <= stars){
					levels.remove(cur);
					stars += 2-cur[2];
					plays++;
				} else {
					cur[2] = 1;
					stars++;
					plays++;
				}
			}
			if (levels.isEmpty()) System.out.println("Case #"+(i++)+": "+plays);
		}
	}
}
