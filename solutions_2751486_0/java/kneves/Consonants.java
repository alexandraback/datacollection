
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;


public class Consonants {
	final static String PROBLEM_NAME = "consonants";
	final static String WORK_DIR = "C:\\Gcj\\" + PROBLEM_NAME + "\\";

	ArrayList<String> allString = new ArrayList<String>();
	ArrayList<String> consonants = new ArrayList<String>();
	int result;
	int plus;

	static void preprocess() {
	}

	ArrayList<String> computeString(String name){
		ArrayList<String> s = new ArrayList<String>();
		for (int i = 0; i <= name.length(); i++) {
			for (int j = i + 1; j <= name.length(); j++) {
				allString.add(name.substring(i,j));
				s.add(name.substring(i,j));
				//System.out.println(name.substring(i,j));
			}
		}
		return s;
	}


	void solveAux(String s,int n,int sens){
		if(s.length()==n){
			if(!(s.contains("a") || s.contains("e") || s.contains("i") || s.contains("o") || s.contains("u"))){
				result+=plus;
			}
		}
		else if(s.length()>n){
			if(sens==0){
				solveAux(s.substring(0,s.length()-1),n,0);
				solveAux(s.substring(1,s.length()),n,1);
			}
			else
				solveAux(s.substring(1,s.length()),n,1);
		}
	}


	void solve(Scanner sc, PrintWriter pw) {
		result=0;
		String  name = sc.next();
		int n = sc.nextInt();
		int L = name.length();
		 plus = L-n;
		solveAux(name.substring(0,L-1),n,0);
		solveAux(name.substring(1,L),n,1);
		if(result>0)
			result++;
		pw.println(""+result);
	}

	public static void main(String[] args) throws Exception {
		preprocess();
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=0; caseNum<caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum+1) + ": ");
			new Consonants().solve(sc, pw);
		}


		pw.flush();
		pw.close();
		sc.close();
	}
}
