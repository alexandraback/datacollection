import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class DancingWiththeGooglers {
	
	enum Type{
		A{
			@Override
			public int getNoSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value+1)/3;
			}

			@Override
			public int getSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value+1)/3+1;
			}
		},
		B{
			@Override
			public int getNoSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value)/3;
			}

			@Override
			public int getSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value)/3+1;
			}
		},
		C{
		
			@Override
			public int getNoSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value-1)/3+1;
			}

			@Override
			public int getSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return (value-1)/3+1;
			}
		},
		ZERO{
			
			@Override
			public int getNoSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return 0;
			}

			@Override
			public int getSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return 0;
			}
		},
		ONE{
			@Override
			public int getNoSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return 1;
			}

			@Override
			public int getSurpiseHigh(int value) {
				// TODO Auto-generated method stub
				return 1;
			}
		};
		public static Type valueOf(int value){
			switch (value){
			case 0: return Type.ZERO;
			case 1: return Type.ONE;
			default: 
				switch (value%3){
				case 0: return B;
				case 1: return C;
				case 2: return A;
				default: return null;
				}
			}
			
		}
		int value;
		public abstract int getSurpiseHigh(int value);
		public abstract int getNoSurpiseHigh(int value);
	}

	
	public static void main(String args[]) throws FileNotFoundException{
		//System.setOut(new PrintStream(new File("DancingWiththeGooglers.txt")));
		
		Scanner scanner = new Scanner(System.in);
		int testcasenum = Integer.valueOf(scanner.next());
		scanner.nextLine();
		for (int testcase = 0;testcase < testcasenum;testcase++){
			int googlersnum = scanner.nextInt();
			int surpisesnum = scanner.nextInt();
			int atleast = scanner.nextInt();
			//int totals[] = new int[googlersnum];
			int maximum = 0;
			for (int index = 0;index < googlersnum;index++){
				int total = scanner.nextInt();
				Type type = Type.valueOf(total);
				//System.out.println(type);
				//System.out.println(type.getNoSurpiseHigh(total));
				if (type != Type.ZERO && type != Type.ONE && type != Type.C && type.getSurpiseHigh(total) == atleast && surpisesnum > 0){
					maximum++;
					surpisesnum--;
				}else if (type.getNoSurpiseHigh(total) >= atleast){
					maximum++;
				}
			}
			
			System.out.print("Case #");
			System.out.print(testcase+1);
			System.out.print(": ");
			System.out.println(maximum);
		}
	}
}
