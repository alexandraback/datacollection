package Codejamround1;

import java.util.Scanner;
import java.util.StringTokenizer;

class boxes {
	double number = 0;
	double type = 0;

	public boxes(double n, double t) {
		number = n;
		type = t;
	}
}

public class BoxFactory {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double testCases = Double.parseDouble(scan.nextLine());
		for (int i = 0; i < testCases; i++) {
			String t = scan.nextLine();
			StringTokenizer token = new StringTokenizer(t);
			double boxs = Double.parseDouble(token.nextToken());
			double toys = Double.parseDouble(token.nextToken());
			boxes[] box = new boxes[(int) boxs];
			boxes[] toy = new boxes[(int) toys];
			t = scan.nextLine();
			token = new StringTokenizer(t);
			for (int j = 0; j < box.length; j++) {
				box[j] = new boxes(Double.parseDouble(token.nextToken()),
						Double.parseDouble(token.nextToken()));
			}
			t = scan.nextLine();
			token = new StringTokenizer(t);
			for (int j = 0; j < toy.length; j++) {
				toy[j] = new boxes(Double.parseDouble(token.nextToken()),
						Double.parseDouble(token.nextToken()));
			}
			double max = 0;
			// try to empty the boxes
			int counter = 0;
			double sum = 0;
			for (int j = 0; j < toy.length; j++) {
				if (toy[j].type == box[counter].type) {
					sum += Math.min(toy[j].number, box[counter].number);
					counter++;
					if (counter >= box.length)
						break;
				}

			}
			if (sum > max)
				max = sum;
			counter = 0;
			sum = 0;
			for (int j = 0; j < box.length; j++) {
				if (box[j].type == toy[counter].type) {
					sum += Math.min(box[j].number, toy[counter].number);
					counter++;
					if (counter >= toy.length)
						break;
				}

			}
			if (sum > max)
				max = sum;

			System.out.println("Case #" + (i + 1) + ": " + max);

		}
	}
}
