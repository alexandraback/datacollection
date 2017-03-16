import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class LawnMover {

	/**
	 * @param args
	 */
	static int [][] arr ;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			String res = "YES";
			int N = sc.nextInt() ; 
			int M = sc.nextInt() ;
			arr = new int[N][M];
			for(int j = 0; j < N ; j++)
			{
				for(int h = 0; h < M ; h++)
					arr[j][h] = sc.nextInt();
			} 
			while(!complete())
			{
				if(!undoLawnMover())
				{
					res = "NO";
					break; 
				} 
				//for(int j = 0; j < arr.length ; j++)
				//	System.out.println(Arrays.toString(arr[j]));
				//System.out.println();
			}
			System.out.println("Case #"+i+": "+res);
			out.write("Case #"+i+": "+res+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close();
	}
	private static boolean undoLawnMover() {
		int min = 100;
		for(int i = 0; i < arr.length ; i++)
			for(int j = 0; j < arr[0].length ; j++)
				if(arr[i][j]<min)
					min = arr[i][j];
		boolean [][] pp = new boolean [arr.length][arr[0].length];
		for(int i = 0; i < arr.length ; i++)
			for(int j = 0; j < arr[0].length ; j++)
				if(arr[i][j]==min)
					pp[i][j] = true;
		boolean [] allminy  = new boolean [arr.length];
		boolean [] allminx = new boolean [arr[0].length];
		for(int i = 0; i < arr.length ; i++)
		{
			boolean yes = pp[i][0];
			for(int j = 0; j < arr[0].length ; j++)
				yes&=pp[i][j];
			allminy[i] = yes;
		}	
		for(int i = 0; i < arr[0].length ; i++)
		{
			boolean yes = pp[0][i];
			for(int j = 0; j < arr.length ; j++)
				yes&=pp[j][i];
			allminx[i] = yes;
		}	
		for(int i = 0; i < allminy.length ; i++)
		{
			if(allminy[i])
				for(int j = 0;j <  arr[0].length ; j++)
					arr[i][j] ++;
		}
		for(int i = 0; i < allminx.length ; i++)
		{
			if(allminx[i])
				for(int j = 0;j <  arr .length ; j++)
					arr[j][i] ++;
		}
		
		for(int i = 0 ; i < allminx.length ; i++)
			for(int j = 0; j < allminy.length ; j++)
				if(allminx[i] && allminy [j])
					arr[j][i]--;
		int newmin =100;
		for(int i = 0; i < arr.length ; i++)
			for(int j = 0; j < arr[0].length ; j++)
				if(arr[i][j]<newmin)
					newmin = arr[i][j];
		if(newmin == min)
			return false;
		return true;
				
	}
	private static boolean complete() {
		for(int i = 0; i < arr.length ; i++)
			for(int j = 0; j < arr[0].length ; j++)
				if(arr[i][j]!= arr[0][0])
					return false;
		return true;
	}
} 

