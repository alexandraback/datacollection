import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class BullsEye {

	private long r;
	private long t;



	public BullsEye() throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int numberOfCases=Integer.parseInt(sc.nextLine());

		for(int i=0; i<numberOfCases; i++){
			readData(sc);

			System.out.println("Case #"+ (i+1) +": "+solve());
		}

		sc.close();
	}


	private int solve() {
		
		long paint=t;
		
		double nextSquare;
		double previousSquare;
		
		int counter=0;
		
		do{
			nextSquare=Math.pow(r, 2);
			previousSquare=Math.pow(r-1, 2);
			
			paint-=nextSquare-previousSquare;
			r+=2;
			
			if (paint>=0) {
				counter++;	
			}
			
		}while(paint>=0);
		
		
		return counter;
	}

	private void readData(Scanner sc){

		StringTokenizer token=new StringTokenizer(sc.nextLine());
		r=Long.parseLong(token.nextToken()) + 1;
		t=Long.parseLong(token.nextToken());
	}

	public static void main(String[] args) {
		try {
			new BullsEye();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}