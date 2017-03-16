import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class exo1 {
	
	public static int INT(String s)
	{
		return Integer.parseInt(s);
	}

	public static int[] INT(String[] tab)
	{
		int l=tab.length;
		int rep[]=new int[l-1];
		for (int i=1; i<l; i++)
		{
			rep[i-1]=INT(tab[i]);
		}
		return rep;
	}
	
	public static int somme_tab(int[] tab)
	{
		int rep=0;
		for (int i=0; i<tab.length;i++)
		{
			rep+=tab[i];
		}
		return rep;
	}

	public static void main(String[] args) 
	{
		//fichier solution
		try{
		File f = new File ("output_exo1_large");
		FileWriter fw = new FileWriter (f);
		
		
		Scanner scan = new Scanner(System.in);
		try
		{
			scan = new Scanner(new FileReader("A-large.in"));
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
			scan.close();
			return;
		}
		int T=scan.nextInt();
		int max_shy;
		String distrib;
		int rep; //solution
		int people;
		int standup;
		int ajout;
		for (int i=1; i<=T; i++)
		{
			rep=0;
			standup=0;
			max_shy=scan.nextInt();
			distrib=scan.next();
			int[] tab=INT(distrib.split(""));
			people=somme_tab(tab);
			for (int k=0; k<=max_shy;k++)
			{
				if (standup>=k)
				{
					standup+=tab[k];
				}
				else
				{
					ajout=(k-standup);
					rep+=ajout;
					standup+=ajout;
					standup+=tab[k];
				}
			}
			if (standup!=people+rep)
			{
				System.out.println("erreur!! pour "+i+" "+standup+" "+people);
			}
			fw.write("Case #"+i+": "+rep+"\n");
		}
		fw.close();
		System.out.println("FINI");
		
		}catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("erreur écriture solution");
		}

	}

}
