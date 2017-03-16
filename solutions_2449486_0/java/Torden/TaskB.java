import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskB {
	
	int N;
	int M;
	int[][] field;
	int[] rowsMax;
	int[] colsMax;
	boolean possible;
	
	public void parseCase(Scanner input) {
		N=input.nextInt();
		M=input.nextInt();
		field=new int[N][M];
		rowsMax=new int[N];
		colsMax=new int[M];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				field[i][j]=input.nextInt();
				if(field[i][j]>rowsMax[i])
					rowsMax[i]=field[i][j];
				if(field[i][j]>colsMax[j])
					colsMax[j]=field[i][j];
			}
	}
	
	public void solveCase() {
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(field[i][j]<rowsMax[i]&&field[i][j]<colsMax[j])
				{
					possible=false;
					return;
				}
		possible=true;
	}

	public String getSolution() {
		return possible?"YES":"NO";
	}

	public void runTask(String[] args) {
		if(args.length<1)
		{
			System.out.println("Not enough parameters");
			return;
		}
		try{
			Scanner in=new Scanner(new File(args[0]));
			PrintWriter out=new PrintWriter(new File(args[1]));
			runCases(in,out);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void runCases(Scanner in, PrintWriter out){
		int numOfCases=in.nextInt();
		in.nextLine();
		for(int i=1;i<=numOfCases;i++){
			parseCase(in);
			solveCase();
			out.println("Case #"+i+": "+getSolution());
			out.flush();
			System.out.println("Case #"+i+": "+getSolution());
		}
		
	}

	public static void main(String[] args) {
		new TaskB().runTask(args);

	}

}
