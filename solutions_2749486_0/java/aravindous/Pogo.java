import java.awt.List;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.SortedSet;

import javax.naming.NameParser;

public class Pogo{

    final static String PROBLEM_NAME = "diamond";
    final static String WORK_DIR = "C:\\Users\\aravinda\\workspace\\gcj2k13\\src\\inputs\\fair.in" ;
    int X;
    int Y;
    
    
    public static void main(String[] args) throws Exception {
    	Scanner sc = new Scanner(new FileReader(WORK_DIR));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.print("Case #" + (caseNum+1) + ": ");
            new Pogo().solve(sc);
        }
        sc.close();
    }

	private void solve(Scanner sc) {
        X = sc.nextInt();
        Y = sc.nextInt();
        int ans = 0;
        go(X,Y);
        System.out.println();
	}

	private void go(int x, int y) {
		int steps = 1;
		if(x > 0){
			int tempX = 0;
			while(tempX + steps <= x){
				tempX = tempX + steps;
				steps++;
				System.out.print("E");
			}
			if(tempX+steps == x)
				System.out.print("E");
			int mod = 0;
			while(tempX != x){
				if(mod % 2  == 0){
					tempX = tempX + steps*-1;
					System.out.print("W");
				}
				else{
					tempX = tempX + steps;
					System.out.print("E");
				}
				mod++; steps++;
			}
			//System.out.println("Found tempX ");
		}
		
		if(x < 0){
			int tempX = 0;
			while(tempX + steps*-1 >= x){
				tempX = tempX + steps*-1;
				steps++;
				System.out.print("W");
			}
			if(tempX+steps*-1 == x)
				System.out.print("W");
			int mod = 0;
			while(tempX != x){
				if(mod % 2  == 0){
					tempX = tempX + steps;
					System.out.print("E");
				}
				else{					
					tempX = tempX + steps*-1;
					System.out.print("W");
				}
				mod++; steps++;
			}
			//System.out.println("Found tempX ");
		}
		
		if(y > 0){
			int tempY = 0; 
			while(tempY + steps <= y){
				tempY = tempY + steps;
				steps++;
				System.out.print("N");
			}
			if(tempY+steps == y)
				System.out.print("N");
			int mod = 0;
			while(tempY != y){
				if(mod % 2  == 0){
					tempY = tempY + steps*-1;
					System.out.print("S");
				}
				else{
					tempY = tempY + steps;
					System.out.print("N");
				}
				mod++; steps++;
			}
			//System.out.println("Found tempY");
		}
		//System.out.println("the steps countis " + steps);
		if(y < 0){
			int tempY = 0; 
			while(tempY + steps*-1 >= y){
				tempY = tempY + steps*-1;
				steps++;
				System.out.print("S");
			}
			if(tempY+steps*-1 == y)
				System.out.print("S");
			int mod = 0;
			while(tempY != y){
				if(mod % 2  == 0){
					tempY = tempY + steps;
					System.out.print("N");
				}
				else{
					tempY = tempY + steps*-1;
					System.out.print("S");
				}
				mod++; steps++;
				//System.out.println("the steps countis " + steps);
			}
			//System.out.println("Found tempY");
		}
		
	}

}