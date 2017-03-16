import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

import practice.template.A;


public class Googlerese {
	
	static char[] g2e = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	
	static Scanner scan;
	static PrintWriter writer;
	
	
	public static void solve() throws Exception{
	
		String outputStr = ""; String result = "";
		int index = 1;	
		
		int testCases = Integer.parseInt(scan.nextLine());
		//-------
		
		
		
		//-------
		
		while(index <= testCases ){	//runs testCases number of times
			
			System.out.println("Running testcase : " + index);
			int count = 0;
			//-----------
			String str = scan.nextLine();
			char [] arr = str.toCharArray();
			
			for(int i = 0; i < arr.length; i++){
				if(Character.isLetter(arr[i])){
					//System.out.println(" print" + arr[i] + (arr[i] - 97));
					arr[i] = g2e[arr[i] - 97];
				}
			}
			
			result = new String(arr);
			//------------
			
			
			outputStr = "Case #" + index + ": " + 			result;
			
			writer.println(outputStr);
			
			result = "";
			outputStr = "";
			index++;
			
		}

		scan.close();
		writer.close();
		
	}
	

	
	public static void main(String[] args) throws Exception {
		
		Scanner in = new Scanner(System.in);
		String className = A.class.getSimpleName() ;
		int choice = 0;
		
		do{
				
			System.out.println("Enter your choice :");
			System.out.println("1) Solve small");
			System.out.println("2) Solve large");
			System.out.print("Choice : ");
			choice = in.nextInt();
			
		switch(choice){
			case 1 :
				scan = new Scanner(new File(className + "-small-practice.in"));
				writer = new PrintWriter(new BufferedWriter(new FileWriter(new File(className +"small.txt"))));
				solve();
				System.out.println("Solved successfully!\n"); 
				break;
			case 2 :
				scan = new Scanner(new File(className + "-large-practice.in"));
				writer = new PrintWriter(new BufferedWriter(new FileWriter(new File(className +"large.txt"))));
				solve();
				System.out.println("Solved successfully!\n"); 
				break;
		}
		
		
		}while (choice != 0);
		
		System.out.println("Program finished!");
		
	}
}
