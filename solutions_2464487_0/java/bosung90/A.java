import java.util.Scanner;


public class A {

	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int caseNum = 0;
		while(testCases>0){
			testCases--;
			caseNum++;
			
			int r = scan.nextInt();
			int t = scan.nextInt();
			
			
			int count =(int) Math.floor( (-(2*r-1) + Math.sqrt( (2*r-1)*(2*r-1)+8*t )) /4);
			System.out.print("Case #"+(caseNum)+": ");
			System.out.println(count);
			
		}
		
//		System.out.println();
//		for(int a = 0; a<caseNum; a++){
//			System.out.print("Case #"+(a+1)+": ");
//			
//			
//			
//			System.out.println();
//		}
	}

}
