import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Dijkstra {
	
	private class struct {
		
		public long sign;
		
		public char val;
		
		public struct(long sign, char val) {
			
			this.sign = sign;
			this.val = val;
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Dijkstra dijInstance = new Dijkstra();
		/*String test = "jiiikijjkiiij";
		seqLength = test.length();
		struct ss = dijInstance.calcPieceRst(test);*/
		Scanner scanner = new Scanner(new File("C-small-attempt1.in"));
		PrintWriter pw = new PrintWriter("C-small-attempt1-out.txt");
		numCase = scanner.nextLong();
		System.out.println(numCase);
		for (int c = 1; c <= numCase; c++) {
			
			 boolean flag = false;
			 seqLength = scanner.nextLong();
			 repeatTime = scanner.nextLong();
			 String seq = scanner.next();
			 struct finalRst = dijInstance.calcFinalRst(seq, repeatTime);
			 if (finalRst.sign != -1 || finalRst.val != '1') {
				 
				 flag = false;
			 }
			 else {
				 
				 int leftNum = dijInstance.calcLeftmostI(seq);
				 int rightNum = dijInstance.calcRightmostK(seq);
				 if (leftNum == -1 || rightNum == -1) {
					 
					 flag = false;
				 }
				 else {
					 
					 if (leftNum + rightNum >= seqLength * repeatTime) {
						 
						 flag = false;
					 }
					 else {
						 
						 flag = true;
					 }
				 }
			 }
			 
			 pw.println("Case #" + c + ": " + (flag? "YES": "NO"));
		}
		pw.flush();
		pw.close();
		scanner.close();
	}
	
	private static long numCase = 0;
	private static long seqLength = 0;
	private static long repeatTime = 0;

	private struct calcFinalRst(String seq, long repeatTime) {
		
		struct pieceRst = calcPieceRst(seq);
		struct finalRst = new struct(1, '1');
		for (int i = 0; i < repeatTime % 4; i++) {
			
			finalRst = rule(finalRst, pieceRst);
		}
		
		return finalRst;
	}
	
	private struct calcPieceRst(String str) {
		
		struct init = new struct(1, '1');
		for (int i = 0; i < seqLength; i++) {
			
			init = rule(init, new struct(1, str.charAt((int) (i % seqLength))));
			System.out.println(init.sign + " " + init.val);
		}
		
		return init;
	}
	
	private int calcLeftmostI(String str) {
		
		struct init = new struct(1, '1');
		for (int i = 0; i < 4 * seqLength; i++) {
			
			init = rule(init, new struct(1, str.charAt((int) (i % seqLength))));
			if (init.sign == 1 && init.val == 'i') {
				
				return i + 1;
			}
		}
		
		return -1;
	}
	
	private int calcRightmostK(String str) {
		
		struct init = new struct(1, '1');
		for (int i = (int) (4 * seqLength - 1); i >= 0; i--) {
			
			init = rule(new struct(1, str.charAt((int) (i % seqLength))), init);
			if (init.sign == 1 && init.val == 'k') {
				
				return (int) (4 * seqLength - i);
			}
		}
		
		return -1;
	}
	
	private struct rule(struct x, struct y) {
		
		struct tmpRst = rule(x.val, y.val);
		return new struct(x.sign * y.sign * tmpRst.sign, tmpRst.val);
	}
	
	private struct rule(char x, char y) {
		
		if (x == '1') {
			
			return new struct(1, y);
		}
		else if (y == '1') {
			
			return new struct(1, x);
		}
		else if (x == y) {
			
			return new struct(-1, '1');
		}
		else if (x == 'i') {
			
			if (y == 'j') {
				
				return new struct(1, 'k');
			}
			else {
				
				return new struct(-1, 'j');
			}
		}
		else if (x == 'j') {
			
			if (y == 'i') {
				
				return new struct(-1, 'k');
			}
			else {
				
				return new struct(1, 'i');
			}
		}
		else {
			
			if (y == 'i') {
				
				return new struct(1, 'j');
			}
			else {
				
				return new struct(-1, 'i');
			}
		}
	}
}