import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;



public class exo3 {
	
	public static boolean analyse(String[] tab, int L, int X)
	{
		Quaternion a = new Quaternion(Symbol.I,1);
		Quaternion b=new Quaternion(Symbol.J,1);
		Quaternion c=new Quaternion(Symbol.K,1);
		Quaternion p=new Quaternion();
		int i=0;
		int j=0;
		Quaternion aux;
		while(!p.equals(a)&&j<X)
		{
			aux=new Quaternion(tab[i],1);
			p=Quaternion.product(p,aux);
			i++;
			if (i==L)
			{
				i=0;
				j++;
			}
		}
		p=new Quaternion();
		if (j==X)
		{
			return false;
		}
		while(!p.equals(b)&&j<X)
		{
			p=Quaternion.product(p,new Quaternion(tab[i],1));
			i++;
			if (i==L)
			{
				i=0;
				j++;
			}
		}
		if (j==X)
		{
			return false;
		}
		p=new Quaternion();
		while(j<X)
		{
			p=Quaternion.product(p,new Quaternion(tab[i],1));
			i++;
			if (i==L)
			{
				i=0;
				j++;
			}
		}
		if (p.equals(c))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	public static void main(String[] args) 
	{
		try
		{
			File f = new File ("output_exo3");
			FileWriter fw = new FileWriter (f);


			Scanner scan = new Scanner(System.in);
			try
			{
				scan = new Scanner(new FileReader("C-small-attempt0.in"));
			}
			catch(FileNotFoundException e)
			{
				e.printStackTrace();
				scan.close();
				return;
			}
			int T=scan.nextInt();
			int L,X;
			String mot;
			for (int test=1; test<=T; test++)
			{
				L=scan.nextInt();
				X=scan.nextInt();
				mot=scan.next();
				String[] tabaux=mot.split("");
				String[] tab=new String[tabaux.length-1];
				for (int l=1;l<tabaux.length;l++)
				{
					tab[l-1]=tabaux[l];
				}
				boolean sol=analyse(tab,L,X);
				if (sol)
				{
					fw.write("Case #"+test+": YES"+"\n");
				}
				else
				{
					fw.write("Case #"+test+": NO"+"\n");
				}

			}
			
			/*Quaternion a = new Quaternion(Symbol.I,1);
			Quaternion b=new Quaternion(Symbol.J,1);
			Quaternion c=new Quaternion(Symbol.K,1);
			Quaternion d=Quaternion.product(a,b);
			System.out.println(c.equals(d));
			Quaternion e=Quaternion.product(Quaternion.product(c,d),Quaternion.product(b,a));
			e.affiche();*/

			fw.close();
			System.out.println("FINI!! exo3");
		}catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("erreur écriture fichier solution");
		}

	}

}
