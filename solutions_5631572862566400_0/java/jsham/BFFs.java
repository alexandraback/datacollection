import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
public class BFFs {
	public static void main(String[] args) {
		Scanner inputFile = null;

		PrintWriter fileWriter = null;
		try {
			fileWriter = new PrintWriter("C-small-attempt0-1.out");
			inputFile = new Scanner(new FileReader("C-small-attempt0-1.in"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int numberCases = inputFile.nextInt();
		inputFile.nextLine();
		
		for (int i = 0; i < numberCases; i++) {
			int numberOfNumbers = inputFile.nextInt();
			inputFile.nextLine();
			String line = inputFile.nextLine();
			Scanner lineScanner = new Scanner(line);
			
			int[] numberList = new int[numberOfNumbers];
			
			for (int j = 0; j < numberOfNumbers; j++) {
				numberList[j] = lineScanner.nextInt();
			}
			lineScanner.close();
			
			
			
			
			int best = 0;
			//for (int blah = 0; blah < numberOfNumbers; blah++) {
				ArrayList<Integer> list = new ArrayList<>();
				int index = 0;
				int[] tempList = new int[numberOfNumbers];
				
				for (int j = 0; j < numberList.length; j++) {
					tempList[j] = numberList[j];
				}
				
				while(index >= 0 && index < numberOfNumbers) {
					if (list.size() == 0) {
						list.add(index);
						int prev = index;
						index = tempList[index]-1;
						tempList[prev] = -1;
					} else {
						if (tempList[index] != -1) {
							list.add(index);
							int prev = index;
							index = tempList[index]-1;
							tempList[prev] = -1;
						} else {
							int prev = index;
							for (int j = 0; j < tempList.length; j++) {
								if (tempList[j] != -1) {
									/*if (tempList[j]-1 == list.get(0)) {
										list.add(0, j);
										prev = j;
										tempList[j] = -1;
										break;
									} else */
										if (tempList[j]-1 == list.get(list.size()-1)) {
										list.add(j);
										prev = j;
										tempList[j] = -1;
										break;
									}
								}
							}
							if (prev == index) {
								/*System.out.println("Case " + i);
								System.out.println("number list: " + Arrays.toString(numberList));
								System.out.println("list: " + list);
								System.out.println("temp list: " + Arrays.toString(tempList));
								
								while(true) {
									int lastNum = list.get(list.size()-1);
									System.out.println("last num: " +lastNum);
									boolean x = numberList[lastNum]-1 != list.get(0);
									boolean y =  numberList[lastNum]-1 != list.get(list.size()-2);
									if (!(( x || y ) && ! ( x && y ))) {
										System.out.println("here");
										if (list.size() > 2) {
											list.remove(list.size()-1);
										} else {
											break;
										}
										
									} else {
										break;
									}
								}*/
								
								int tempBest = list.size();
								
								if (best < tempBest) {
									best = tempBest;
									
								}
								break;
							}
						}
					}
				}
				
				
			//}
			fileWriter.println("Case #" + (i+1) + ": " + best);
		}
		inputFile.close();
		fileWriter.close();
	}
}
