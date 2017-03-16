
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Pogo {
	final static String PROBLEM_NAME = "pogo";
	final static String WORK_DIR = "C:\\Gcj\\" + PROBLEM_NAME + "\\";
	int X,Y,jump,currentY,currentX;
	String result;

	static void preprocess() {
	}

	void checkNorth(){
		if(Math.abs(Y)==jump){
			if(Y>0){
				result+="N";
				currentY+=jump;
			}
			else{
				result+="S";
				currentY-=jump;
			}
			jump++;
		}
		if(Math.abs(X)==1){
			if(X<0)
				result+="EW";
			else
				result+="WE";
			currentX=X;
		}
	}
	
	void checkEast(){
		if(Math.abs(X)==jump){
			if(X>0){
				result+="E";
				currentX+=jump;
			}
			else{
				result+="W";
				currentX-=jump;
			}
			jump++;
		}
		if(Math.abs(Y)==1){
			if(Y<0)
				result+="NS";
			else
				result+="SN";
			currentY=Y;
		}
	}

	void solve(Scanner sc, PrintWriter pw) {
		result="";
		X = sc.nextInt();
		Y = sc.nextInt();
		currentX = 0;
		currentY = 0;
		jump = 1;

		if(Math.abs(X)>Math.abs(Y)){
			while(currentX!=X){
				if(X>0){
					checkNorth();
					if(currentX==X)
						break;
					result+="E";
					currentX+=jump;
					jump++;
					checkNorth();
					if(currentX==X)
						break;

					result+="W";
					currentX-=jump;
					jump++;
				}
				if(X<0){
					checkNorth();
					if(currentX==X)
						break;
					result+="W";
					currentX-=jump;
					jump++;
					checkNorth();
					if(currentX==X)
						break;
					result+="E";
					currentX+=jump;
					jump++;
				}
			}
		}
		else{
			while(currentY!=Y){
	

				if(Y>0){
					checkEast();
					if(currentY==Y)
						break;
					result+="N";
					currentY+=jump;
					jump++;
					checkEast();
					if(currentY==Y)
						break;
					result+="S";
					currentY-=jump;
					jump++;
				}
				if(Y<0){
					checkEast();
					if(currentY==Y)
						break;
					result+="S";
					currentY-=jump;
					jump++;
					checkEast();
					if(currentY==Y)
						break;
					result+="N";
					currentY+=jump;
					jump++;
				}
			}

		}

		System.out.println("Input : "+X+","+Y);
		System.out.println("Output : "+currentX+","+currentY);

		pw.println(result);
	}


	public static void main(String[] args) throws Exception {
		preprocess();
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=0; caseNum<caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum+1) + ": ");
			new Pogo().solve(sc, pw);
		}


		pw.flush();
		pw.close();
		sc.close();
	}
}
