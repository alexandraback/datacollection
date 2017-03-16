import java.util.*;
import java.io.*;

public class digits {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	String toss = in.nextLine();
	for (int l = 0; l < count; l++) {

	    String s = in.nextLine();
	    int[] set = new int[26];
	    for (int i = 0; i < 26; i++)
		set[i] = 0;
	    for (int i = 0; i < s.length(); i++) {
		int value = (int)s.charAt(i);
		set[value-((int)'A')]++;
	    }

	    int[] nums = new int[10];
	    for (int i = 0; i < 10; i++)
		nums[i] = 0;

	    nums[0] = set[25];
	    set = remove(set, "zero", 'z');
	    
	    nums[8] = set['g'-'a'];
	    set = remove(set, "eight", 'g');

	    nums[6] = set['x'-'a'];
	    set = remove(set, "six", 'x');

	    nums[7] = set['s'-'a'];
	    set = remove(set, "seven", 's');
	 
	    nums[5] = set['v'-'a'];
	    set = remove(set, "five", 'v');

	    nums[9] = set['i'-'a'];
	    set = remove(set, "nine", 'i');

	    nums[4] = set['u'-'a'];
	    set = remove(set, "four", 'u');

	    nums[3] = set['r'-'a'];
	    set = remove(set, "three", 'r');

	    nums[2] = set['w'-'a'];
	    set = remove(set, "two", 'w');

	    nums[1] = set['o'-'a'];
	    set = remove(set, "one", 'o');
		
	    System.out.print("Case #" + (l+1) + ": ");
	    for (int i = 0; i < 10; i++) {
		for (int j = 0; j < nums[i]; j++) {
		    System.out.print(i);
		}
	    }
	    System.out.println();

	}

    }

    public static int[] remove (int[] list, String s, char c) {
	int count = list[c - 'a'];
	for (int i = 0; i < s.length(); i++) {
	    list[s.charAt(i) - 'a'] -= count;
	}
	return list;
    }

}
