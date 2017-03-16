import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	static String finalStr="";
	static boolean isFinished=false;
	static int count1=0;
	static int count2=0;
	static int count3=0;
	static int count4=0;
	public static String getNumOfMoves(int x, int y) {
		isFinished = false;
		int result = 0,altResult=0;
		int posX=0,posY=0;
		count1=0;
		count2=0;
		count3=0;
		count4=0;
		String resultStr = "";
		//int[] vMax = new int[w];
		//int[] hMax = new int[h];


		isSolveable(0,0,x,y,1,"",1,0);
		if(!isFinished)
		isSolveable(0,0,x,y,2,"",1,0);
		if(!isFinished)
			isSolveable(0,0,x,y,3,"",1,0);
		if(!isFinished)
			isSolveable(0,0,x,y,4,"",1,0);
		
		resultStr = finalStr;
		
		return resultStr;
	}

	public static boolean isSolveable(int posX, int posY,int x, int y,int direction,String str,int distance,int moves) {
		if (isFinished)
			return true;
		
		moves++;
		if(moves > 35)
        	return true;
		
		if (posX - x > 100 || x - posX > 100 || posY - y > 100 || y - posY > 100
				|| posX - x < -100 || x - posX < -100 || posY - y < -100 || y - posY < -100	)
			return false;
		
		if(direction == 1){
			count1++;
			zeroCounts(1);
			if(count1 > 2)
				return true;
		}else if(direction == 2){
			count2++;
			zeroCounts(2);
			 if(count2 > 2)
				return true;
		}else if(direction == 3){
			count3++;
			zeroCounts(3);
			if(count3 > 2)
				return true;
		}else if(direction == 4){
			count4++;
			zeroCounts(4);
			if(count4 > 2)
				return true;
		}
		
		
		

		
		if(direction == 1){
			posX+=distance;
			str = str+"E";
		}else if(direction == 2){
			posY+=distance;
			str = str+"N";
		}else if(direction == 3){
			posX-=distance;
			str = str+"W";
		}else if(direction == 4){
			posY-=distance;
			str = str+"S";
		}
		
		if(x == posX && y==posY){
			finalStr = str;
			isFinished = true;
			return true;
		}
		
		isSolveable(posX,posY,x,y,1,str,distance+1,moves);
		
		isSolveable(posX,posY,x,y,2,str,distance+1,moves);
		
		isSolveable(posX,posY,x,y,3,str,distance+1,moves);
		
		isSolveable(posX,posY,x,y,4,str,distance+1,moves);
		
		
		return true;
	}
	
	public static void zeroCounts(int direction){
		if(direction != 1)
		count1=0;
		if(direction != 2)
		count2=0;
		if(direction != 3)
		count3=0;
		if(direction != 4)
		count4=0;
	}
	
	public static void main(String args[]) {

		try {
			FileWriter foutstream = new FileWriter("A-small.out");
			BufferedWriter out = new BufferedWriter(foutstream);

			FileInputStream fstream = new FileInputStream("input.txt");
			DataInputStream in = new DataInputStream(fstream);
			Scanner sc = new Scanner(new File("input.txt"));

			int caseNumber = 1;
			int totalCaseNumber = sc.nextInt();
			int x = 0,y=0;
			String name="";
			//int[] motes;
			List<Integer> motes = new ArrayList<Integer>();
			while (caseNumber <= totalCaseNumber) {
				out.write("Case #");
				out.write(String.valueOf(caseNumber++));
				out.write(": ");
				
				x = sc.nextInt();
				y = sc.nextInt();

				out.write(""+getNumOfMoves(x,y));
				out.newLine();
			}
			in.close();
			sc.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
