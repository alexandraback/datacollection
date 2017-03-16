package jamra2p1;

import java.io.*;
import java.util.*;

public class main {
    static boolean debugging = false;
    
    public static void main(String[] args) {
	Scanner in = null;
	if (debugging) {
	    try {
		in = new Scanner(new File("A-small-attempt1.in"));
	    } catch (FileNotFoundException ex) {}
	} else {
	    in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	}
	int testCases = in.nextInt();
	in.nextLine();
	for (int t = 0; t < testCases; t++) {
	    System.out.print("Case #" + (t+1) + ": ");
	    String s = in.nextLine();
	    NumberDictionary nd = new NumberDictionary();
	    nd.add(s);
	    int[] numbers = new int[10];
	    while (nd.getWordCount("six") > 0) {
		nd.sub("six");
		numbers[6]++;
	    }
	    while (nd.getWordCount("two") > 0) {
		nd.sub("two");
		numbers[2]++;
	    }
	    while (nd.getWordCount("four") > 0) {
		nd.sub("four");
		numbers[4]++;
	    }
	    while (nd.getWordCount("five") > 0) {
		nd.sub("five");
		numbers[5]++;
	    }
	    while (nd.getWordCount("zero") > 0) {
		nd.sub("zero");
		numbers[0]++;
	    }
	    while (nd.getWordCount("one") > 0) {
		nd.sub("one");
		numbers[1]++;
	    }
	    while (nd.getWordCount("eight") > 0) {
		nd.sub("eight");
		numbers[8]++;
	    }
	    while (nd.getWordCount("nine") > 0) {
		nd.sub("nine");
		numbers[9]++;
	    }
	    while (nd.getWordCount("seven") > 0) {
		nd.sub("seven");
		numbers[7]++;
	    }
	    while (nd.getWordCount("three") > 0) {
		nd.sub("three");
		numbers[3]++;
	    }
	    for (int n = 0; n < numbers.length; n++) {
		for (int i = 0; i < numbers[n]; i++)
		    System.out.print(n);
	    }
	    if (nd.getRemainder() > 0)
		System.out.println(" error");
	    else
		System.out.println();
	}
    }
}

class NumberDictionary {
    int[] letters;

    NumberDictionary() {
	letters = new int[15];
    }

    public void add(String s) {
	for (char c : s.toLowerCase().toCharArray()) {
	    letters[getIndex(c)]++;
	}
    }

    public void sub(String s) {
	for (char c : s.toCharArray()) {
	    int idx = getIndex(c);
	    if (letters[idx] > 0)
		letters[idx]--;
	    else {
		
	    }
	}
    }
    
    public int getCount(char c) {
	return letters[getIndex(c)];
    }
    
    public int getWordCount(String s) {
	int count = Integer.MAX_VALUE;
	for (char c : s.toCharArray()) {
	    count = Math.min(count, getCount(c) / getCharCount(s, c));
	}
	return count;
    }

    public static int getCharCount(String s, char c) {
	int count = 0;
	for (char cins : s.toCharArray()) {
	    if (cins == c)
		count++;
	}
	return count;
    }
    
    public int getRemainder() {
	int count = 0;
	for (int i = 0; i < letters.length; i++) {
	    count += letters[i];
	}
	return count;
    }
    
    public int getIndex(char c) {
	switch(c) {
	    case 'e':
		return 0;
	    case 'f':
		return 1;
	    case 'g':
		return 2;
	    case 'h':
		return 3;
	    case 'i':
		return 4;
	    case 'n':
		return 5;
	    case 'r':
		return 6;
	    case 'o':
		return 7;
	    case 's':
		return 8;
	    case 't':
		return 9;
	    case 'v':
		return 10;
	    case 'u':
		return 11;
	    case 'w':
		return 12;
	    case 'x':
		return 13;
	    case 'z':
		return 14;
	    default:
		return -1;
	}
    }
}