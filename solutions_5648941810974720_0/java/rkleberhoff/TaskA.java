

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class TaskA {
    
	int[] counts = new int[128];
    
    public TaskA(Scanner input) {
        String word = input.next();
        for (int i=0; i<word.length(); i++) {
        	counts[word.charAt(i)] ++;
        }
    }
    
    int countAndDelete(char ch, String word) {
    	int result = counts[ch];
    	for (int i=0; i<word.length(); i++) {
    		counts[word.charAt(i)] -= result;
    	}
    	return result;
    }
    
    StringBuilder repeat(char ch, int times) {
    	StringBuilder result = new StringBuilder();
    	for (int i=0; i<times; i++) {
    		result.append(ch);
    	}
    	return result;
    }
    
    
    public String solve() {
        StringBuilder zeroes = repeat('0', countAndDelete('Z', "ZERO"));
        StringBuilder twos = repeat('2', countAndDelete('W', "TWO"));
        StringBuilder fours = repeat('4', countAndDelete('U', "FOUR"));
        StringBuilder sixes = repeat('6', countAndDelete('X', "SIX"));
        StringBuilder eights = repeat('8', countAndDelete('G', "EIGHT"));

        StringBuilder ones = repeat('1', countAndDelete('O', "ONE"));
        StringBuilder threes = repeat('3', countAndDelete('R', "THREE"));
        StringBuilder fives = repeat('5', countAndDelete('F', "FIVE"));
        StringBuilder sevens = repeat('7', countAndDelete('S', "SEVEN"));
        StringBuilder nines = repeat('9', countAndDelete('I', "NINE"));
        
        String result = "" + zeroes + ones + twos + threes + fours + fives + sixes + sevens + eights + nines;
        return result;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("data/A.in"));
        PrintWriter writer = new PrintWriter("data/A.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            TaskA task = new TaskA(scanner);
            StringBuilder builder = new StringBuilder();
            String result = task.solve();
            builder.append("Case #" + i + ": ").append(result);
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
