import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskA {
	
	String[] board=new String[4];
	int[] rowsX;
	int[] rowsO;
	int[] colsX;
	int[] colsO;
	int[] diagsX;
	int[] diagsO;
	int Xs,Os,Ts;
	public void parseCase(Scanner input) {
		for(int i=0;i<4;i++)
			board[i]=input.nextLine();
		input.nextLine();
		rowsX=new int[4];
		rowsO=new int[4];
		colsX=new int[4];
		colsO=new int[4];
		diagsX=new int[4];
		diagsO=new int[4];
		Xs=Os=Ts=0;
	}
	
	public void solveCase() {
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			switch(board[i].charAt(j)){
			case 'X':
				Xs++;
				rowsX[i]++;
				colsX[j]++;
				if(i==j)
					diagsX[0]++;
				if(i+j==3)
					diagsX[1]++;
				break;
			case 'O':
				Os++;
				rowsO[i]++;
				colsO[j]++;
				if(i==j)
					diagsO[0]++;
				if(i+j==3)
					diagsO[1]++;
				break;
			case 'T':
				Ts++;
				rowsX[i]++;
				colsX[j]++;
				rowsO[i]++;
				colsO[j]++;
				if(i==j)
				{
					diagsX[0]++;
					diagsO[0]++;
				}
				if(i+j==3)
				{
					diagsX[1]++;
					diagsO[1]++;
				}
				break;

			}
	}

	public String getSolution() {
		if(Xs==Os&&fourExist(rowsO,colsO,diagsO))
			return "O won";
		else if(fourExist(rowsX,colsX,diagsX))
			return "X won";
		else if(Xs+Os+Ts==16)
			return "Draw";
		else
			return "Game has not completed";
	}
	
	boolean fourExist(int[]... arrays){
		for(int[] array:arrays)
			for(int value:array)
				if(value==4){
					return true;
				}
		return false;
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
		new TaskA().runTask(args);

	}

}
