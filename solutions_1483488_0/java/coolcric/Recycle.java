
import java.io.*;
import java.util.*;

class C{}

public class Recycle {
	static Scanner scan;
	static PrintWriter writer;
	
	
	public static void readProcessOutput() throws Exception{
	
		String outputStr = ""; String result = "";
		int index = 1;	
		
		int testCases = Integer.parseInt(scan.nextLine());
		//-------
		
		
		
		//-------
		
		while(index <= testCases ){	//runs testCases number of times
			
			System.out.println("Running testcase : " + index);
			int count = 0;
			//-----------
			Scanner temp = new Scanner(scan.nextLine());
			int A = temp.nextInt();
			int B = temp.nextInt();
			boolean mark[] = new boolean[B+1];
			int c[] = new int[B+1];
			
			for(int i = A; i <=B; i++){
				//if(!mark[i]) {

					int j = i;
					int k = i;
					String s = "" + j;
					
					do{
						//j = (j%div)*10 + (j/div);
						s = s.substring(1) + s.charAt(0);
						j = Integer.parseInt(s);
						if(j >= A && j <= B && j > i && ("" +j).length() == s.length()){
							count++;
							mark[i] = true;
							mark[j] = true;
							c[i]++;
						}
					
					}while(j != k);
					
//					if(!mark[i])
//						System.out.println(i);
//				}
				
			}
//			int f =0;
//			for(int m : c)
//				f += m;
//			System.out.println("count:"+ f);

			//------------
			
			
			outputStr = "Case #" + index + ": " + 			count;
			
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
		String className = C.class.getSimpleName() ;
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
				readProcessOutput();
				System.out.println("Solved successfully!\n"); 
				break;
			case 2 :
				scan = new Scanner(new File(className + "-large-practice.in"));
				writer = new PrintWriter(new BufferedWriter(new FileWriter(new File(className +"large.txt"))));
				readProcessOutput();
				System.out.println("Solved successfully!\n"); 
				break;
		}
		
		
		}while (choice != 0);
		
		System.out.println("Program finished!");
		
	}

}
