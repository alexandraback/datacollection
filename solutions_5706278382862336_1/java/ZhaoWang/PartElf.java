import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class PartElf {
	private final double p;
	private final double q;
	private final static int max = Integer.MAX_VALUE;
	
	public PartElf(double p, double q) {
		this.p = p;
		this.q = q;
	}
	
	public int numOfGen() {
		int[] num = new int[1];
		num[0] = max;
		numOfGen(p, q, num, 0);
		return num[0];
	}
	
	public void numOfGen(double p, double q, int[] num,int lev) {
		if (lev > 40) {
			num[0] = max;
			return;
		}
		if (p == q || p == 0) {
			num[0] = Math.min(lev, num[0]);
			return;
		}
		if (q % 2 == 1) {
			num[0] = max;
			return;
		}
		if ((p / q) >= 0.5) {
			num[0] = Math.min((lev+1), num[0]);
			numOfGen(2*p - q, q, num, lev+1);
		}
		else {
			numOfGen(2*p, q, num, lev+1);
		}
	}
	
	public static void main(String[] args) {
		File file = new File(args[0]);
		Scanner in = null;
		BufferedWriter fw = null;
		File file2 = new File("C:/Users/wang/Desktop/result.txt");
		try {
			in = new Scanner(file);
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			fw = new BufferedWriter(new FileWriter(file2));			
		} 
		catch (IOException e) {
			e.printStackTrace();
		}
		int loop = 1;
		if (in.hasNext()) loop = in.nextInt();
		for (int i = 0; i < loop; i++) {
			String s = in.next();
			String[] num = s.split("/");
			double p = Double.parseDouble(num[0]);
			double q = Double.parseDouble(num[1]);
			PartElf elf = new PartElf(p, q);
			int g = elf.numOfGen();
			try {
				if (i > 0) {
					fw.newLine();
				}
				if (g > 40) {
					fw.append("Case #"+Integer.toString(i+1)+": impossible");
/*					System.out.println("Case #"+Integer.toString(i+1)+": impossible");*/
				}
				else {
					fw.append("Case #"+Integer.toString(i+1)+": "+ Integer.toString(g));
/*					System.out.println("Case #"+Integer.toString(i+1)+": "+ Integer.toString(g));*/
				}
			}
			catch (IOException e){
				e.printStackTrace();
			}
		}
		try {
			fw.close();
		}
		catch (IOException e) {
			
		}
		in.close();
		
	}

}
