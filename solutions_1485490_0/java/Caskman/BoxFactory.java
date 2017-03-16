import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class BoxFactory {
	public static void main(String[] args) throws FileNotFoundException {
		try {
			new BoxFactory().go(args[0]);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	public void go(String filepath) throws IOException {
		Scanner input = new Scanner(new File(filepath));
		FileWriter fw = new FileWriter(new File("files/boxfactoryoutput.txt"));
		long tests = toInt(input.nextLine());
		String[] line;
		long n;
		long m;
		List<Prod> line1;
		List<Prod> line2;
		long num;
		Prod a;
		Prod b;
		BigInteger total;
		int depth1;
		int depth2;
		boolean proceed;
		BigInteger temp1;
		BigInteger temp2;
		long choice;
		
		
		for (int test = 0; test < tests; test++) {
			total = new BigInteger("0");
			line = input.nextLine().split(" ");
			n = toInt(line[0]);
			m = toInt(line[1]);
			line1 = new ArrayList<Prod>((int)n);
			line2 = new ArrayList<Prod>((int)m);
			
			line = input.nextLine().split(" ");
			for (int i = 0; i < n; i++) {
				line1.add(new Prod(new BigInteger(line[i*2]),toInt(line[i*2+1])));
			}
			
			line = input.nextLine().split(" ");
			for (int i = 0; i < m; i++) {
				line2.add(new Prod(new BigInteger(line[i*2]),toInt(line[i*2+1])));
			}
			
			while (!line1.isEmpty() && !line2.isEmpty()) {
				if (line1.get(0).type == line2.get(0).type) {// if heads are same type
					total = total.add(boxStuff(line1,line2));
					continue;
				}
				
				depth1 = depth(line2,line1.get(0).type);//depth of 1's head type in line2
				depth2 = depth(line1,line2.get(0).type);//depth of 2's head type in line1
				
				proceed = true;
				if (depth1 == -1) {// if line1's head type isn't in line 2, pop the head of line1
					line1.remove(0);
					proceed = false;
				} 
				if (depth2 == -1) {// same for line2
					line2.remove(0);
					proceed = false;
				} 
				
				if (!proceed)// if you had to pop any head, move onto next iteration
					continue;
				
				if (depth1 < depth2) { // pop line2 until you reach line1's head type
					
					for (int i = 0; i < depth1; i++)
						line2.remove(0);
					
					total = total.add(boxStuff(line1,line2));
					
				} else if (depth1 > depth2) { // pop line1 until you reach line2's head type
					for (int i = 0; i < depth2; i++)
						line1.remove(0);
					
					total = total.add(boxStuff(line1,line2));
				} else {// depths are equal
					temp1 = min(line1.get(0).amount,line2.get((int)depth1).amount);
					temp2 = min(line2.get(0).amount,line1.get((int)depth2).amount);
					
					if (temp1.compareTo(temp2) > 0) {// if line1 makes more, pop and box
						for (int i = 0; i < depth1; i++)
							line2.remove(0);
						
						total = total.add(boxStuff(line1,line2));
					} else if (temp1.compareTo(temp2) < 0) {
						for (int i = 0; i < depth2; i++)
							line1.remove(0);
						
						total = total.add(boxStuff(line1,line2));
					} else {// amounts they'd make are equal
						choice = stalemate(line1,line2,depth1,depth2);
						if (choice == 1) {
							for (int i = 0; i < depth1; i++)
								line2.remove(0);
							total = total.add(boxStuff(line1,line2));
						} else if (choice == 2) {
							for (int i = 0; i < depth2; i++)
								line1.remove(0);
							total = total.add(boxStuff(line1,line2));
						}
					}
				}
				
			}
			fw.write("Case #"+(test+1)+": "+total);
			if (test != tests-1)
				fw.write("\n");
			
		}
		fw.close();
	}
	
	
	int stalemate(List<Prod> line1, List<Prod> line2, int depth1,int depth2) {
		int depth11 = -1;
		int depth22 = -1;
		BigInteger temp1;
		BigInteger temp2;
		
		for (int i = depth1+1; i < line2.size(); i++)
			if (line2.get(i).type == line1.get(0).type) {
				depth11 = i;
				break;
			}
		if (depth11 == -1) // go with line 2
			return 2;
		
		for (int i = depth2+1; i < line1.size(); i++)
			if (line1.get(i).type == line2.get(0).type) {
				depth22 = i;
				break;
			}
		if (depth22 == -1) { // go with line 1
			return 1;
		}
		
		if (depth11 > depth22)
			return 2;
		else if (depth11 < depth22) {
			return 1;
		}
		
		temp1 = min(line1.get(0).amount,line2.get((int)depth1).amount);
		temp2 = min(line2.get(0).amount,line1.get((int)depth2).amount);
		
		if (temp1.compareTo(temp2) > 0) {// if line1 makes more, pop and box
			return 1;
		} else if (temp1.compareTo(temp2) < 0) {
			return 2;
		} else {// amounts they'd make are equal
//			choice = stalemate(line1,line2,depth1,depth2);
			return stalemate(line1,line2,depth11,depth22);
		}

	}

	BigInteger boxStuff(List<Prod> line1,List<Prod> line2) {
		//then remove min head and subtract amount from other head
		BigInteger total = null;
		if (line1.get(0).amount.compareTo(line2.get(0).amount) < 0) {
			total = line1.get(0).amount;
			line2.get(0).amount = line2.get(0).amount.subtract(line1.get(0).amount);
			line1.remove(0);
		} else if (line2.get(0).amount.compareTo(line1.get(0).amount) < 0) {
			total = line2.get(0).amount;
			line1.get(0).amount = line1.get(0).amount.subtract(line2.get(0).amount);
			line2.remove(0);
		} else {// if heads are equal, remove both
			total = line2.get(0).amount;
			line1.remove(0);
			line2.remove(0);
		}
		return total;
	}
	
	int depth(List<Prod> line,long type) {
		for (int i = 1; i < line.size(); i++) {
			if (line.get(i).type == type)
				return i;
		}
		return -1;
	}
	
	
	BigInteger min(BigInteger amount ,BigInteger amount2) {
		if (amount.compareTo(amount2) < 0)
			return amount;
		return amount2;
	}
	
	static long toInt(String s) {
		return Long.parseLong(s);
	}
	
	private class Prod {
		public BigInteger amount;
		public long type;
		public Prod(BigInteger amount,long type) {
			this.amount = amount;
			this.type = type;
		}
		
	}
}
