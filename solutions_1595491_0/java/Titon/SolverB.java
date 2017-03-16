package problemB;

import java.io.IOException;
import java.util.LinkedList;

import utils.InputReader;

public class SolverB {

	public static void main(String[] args) throws IOException {
		LinkedList<String> input = InputReader.read("C:/Users/Danielle/Desktop/test.txt");
		int num = Integer.parseInt(input.removeFirst());
		int i = 1;
		for (String string : input) {
			if (i > num) {
				System.err.println(i+">"+num);
				break;
			}
			if (i == 3){
				System.out.print("");
			}
			String[] split = string.split(" ");
			int dancers = Integer.parseInt(split[0]);
			int supplies = Integer.parseInt(split[1]);
			int targetScore = Integer.parseInt(split[2]);

			boolean hasSupplies = supplies>0;

			int couldBeAbove = 0;

			for (int k = 3; k < dancers+3; k++){
				int total = Integer.parseInt(split[k]);
				if (total == 0 && targetScore > 0) continue;
				if (total > 27){
					if (targetScore < 11) couldBeAbove++;
					continue;
				}
				int avg = total/3;
				int lacking = targetScore-avg;
				if (lacking < 1) couldBeAbove++;
				else if (lacking > 2) continue;
				else {
					int rest = total%3;
					if (rest == 1){
						if (lacking == 1) couldBeAbove++;
					} else if (hasSupplies){
						switch(rest){
						case 2:
							switch (lacking) {
							case 1:
								couldBeAbove++;
								break;
							case 2:
								couldBeAbove++;
								hasSupplies = (--supplies)>0;
								break;
							}
							break;
						case 0:
							if (lacking == 1){
								couldBeAbove++;
								hasSupplies = (--supplies)>0;
							}
							break;
						}
					} else {
						if (rest == 2 && lacking == 1) couldBeAbove++;
					}
				}
			}
			System.out.println("Case #"+(i++)+": "+couldBeAbove);
		}
	}
}
