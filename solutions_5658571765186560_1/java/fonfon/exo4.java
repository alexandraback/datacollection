import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class exo4 {

	public static boolean solution(int X, int R, int C)
	{
		if (X==1) {return true;}
		if (X>=7) {return false;}
		if (X==2)
		{
			if ((R*C)%2==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (X==3)
		{
			if (R==1 || C==1)
			{
				return false;
			}
			if ((R*C)%3==0)
			{
				return true;
			}
			return false;
		}
		if (X==4)
		{
			if (R<=2 || C<=2)
			{
				return false;
			}
			if ((R*C)%4==0)
			{
				return true;
			}
			return false;
		}
		if (X==5 || X==6)
		{
			if (R<=3 || C<=3)
			{
				return false;
			}
			if ((R*C)%X==0)
			{
				if ((R*C)/X>=X-1)
				{
					if (R*C==36 && R!=6)
					{
						return false;
					}
					return true;
				}
				return false;
			}
			return false;
		}
		System.out.println("bug");
		return true;
	}

	public static void main(String[] args) 
	{
		try{
			File f = new File ("output_exo4_large");
			FileWriter fw = new FileWriter (f);


			Scanner scan = new Scanner(System.in);
			try
			{
				scan = new Scanner(new FileReader("D-large.in"));
			}
			catch(FileNotFoundException e)
			{
				e.printStackTrace();
				scan.close();
				return;
			}
			int T=scan.nextInt();
			int R,C,X;
			boolean rep;

			for(int test=1; test<=T; test++)
			{
				X=scan.nextInt();
				R=scan.nextInt();
				C=scan.nextInt();
				rep=solution(X,R,C);
				if (rep)
				{
					fw.write("Case #"+test+": "+"GABRIEL"+"\n");
				}
				else
				{
					fw.write("Case #"+test+": "+"RICHARD"+"\n");
				}
			}




			fw.close();
			System.out.println("FINI!! exo4");
		}catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("erreur écriture fichier solution");
		}

	}

}
