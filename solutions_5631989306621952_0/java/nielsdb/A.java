import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		boolean printToFile = true;
		try {
			if(printToFile){
				System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("out.txt")), true));
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		new A();
	}

	public A() {
		Scanner sc = new Scanner(System.in);
		int nbProblems = Integer.parseInt(sc.nextLine());
		for(int caseNb = 1; caseNb <= nbProblems; caseNb++){
			String str = sc.nextLine();
			String solution = "";
			for(int i = 0; i < str.length(); i++){
				if((solution + str.charAt(i)).compareTo(str.charAt(i) + solution) < 0){
					solution = str.charAt(i) + solution;
				}
				else{
					solution = solution + str.charAt(i);
				}
			}
			
			System.out.println("Case #" + caseNb + ": " + solution);
		}
	}
}
