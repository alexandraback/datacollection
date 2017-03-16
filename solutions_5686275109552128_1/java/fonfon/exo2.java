import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class exo2 {

	public static int MAX(ArrayList<Integer> tab)
	{
		int rep=0;
		for (int i=0; i<tab.size();i++)
		{
			if (rep<tab.get(i))
			{
				rep=tab.get(i);
			}
		}
		return rep;
	}
	
	public static int MIN(ArrayList<Integer> tab)
	{
		int rep=tab.get(0);
		for (int i=0; i<tab.size();i++)
		{
			if (rep>tab.get(i))
			{
				rep=tab.get(i);
			}
		}
		return rep;
	}
	
	public static void affiche(ArrayList<Integer> tab)
	{
		for (int i=0; i<tab.size();i++)
		{
			System.out.print(tab.get(i)+" ");
		}
		System.out.println();
	}
	
	//compte le nombre d'éléments strictements supérieurs au seuil
	public static int SUP(ArrayList<Integer> tab, int seuil)
	{
		int rep=0;
		for (int i=0; i<tab.size();i++)
		{
			if (tab.get(i)>seuil)
			{
				rep++;
			}
		}
		return rep;
	}
	
	
	public static void MOINSUN(ArrayList<Integer> tab)
	{
		for (int i=0; i<tab.size();i++)
		{
			tab.set(i, Math.max(0, tab.get(i)-1));
		}
	}
	
	public static int MAX_INDICE(ArrayList<Integer> tab)
	{
		int rep=0;
		int indice=0;
		for (int i=0; i<tab.size();i++)
		{
			if (rep<tab.get(i))
			{
				rep=tab.get(i);
				indice=i;
			}
		}
		return indice;
	}
	
	public static ArrayList<Integer> decr(ArrayList<Integer> tab)
	{
		ArrayList<Integer> rep=new ArrayList<Integer>();
		for (int i=0; i<tab.size();i++)
		{
			if (tab.get(i)>=1)
			{
				rep.add(tab.get(i)-1);
			}
		}
		return rep;
	}
	
	public static ArrayList<Integer> decoupe(ArrayList<Integer> tab)
	{
		ArrayList<Integer> rep=new ArrayList<Integer>();
		int indice=MAX_INDICE(tab);
		int max=MAX(tab);
		for (int i=0; i<tab.size();i++)
		{
			if (i!=indice)
			{
				rep.add(i, tab.get(i));
			}
			else
			{
				rep.add(i,PES(max));
			}
		}
		rep.add(max-PES(max));
		return rep;
	}
	
	public static ArrayList<Integer> bouge(ArrayList<Integer> tab, int nb)
	{
		ArrayList<Integer> rep=new ArrayList<Integer>();
		int indice=MAX_INDICE(tab);
		int max=MAX(tab);
		for (int i=0; i<tab.size();i++)
		{
			if (i!=indice)
			{
				rep.add(i, tab.get(i));
			}
			else
			{
				rep.add(i,max-nb);
			}
		}
		rep.add(nb);
		return rep;
	}
	
	public static int mange(ArrayList<Integer> tab)
	{
		int max=MAX(tab);
		if (max<=0)
		{
			return 0;
		}
		else
		{
			if (max<=3){return max;}
			else
			{
				ArrayList<Integer> aux=new ArrayList<Integer>();
				for(int j=2; j<=PES(max);j++)
				{
					aux.add(mange(bouge(tab,j)));
				}
				aux.add(mange(decr(tab)));
				return 1+MIN(aux);
			}
			
		}
	}
	
	
	
	//partie entiere superieure de x/2
	public static int PES(int x)
	{
		if (2*(x/2)==x)
		{
			return x/2;
		}
		else
		{
			return 1+x/2;
		}
	}
	
	public static void main(String[] args) 
	{
		
		try
		{
			//fichier solution
			File f = new File ("output_exo2_large");
			FileWriter fw = new FileWriter (f);
			
			Scanner scan = new Scanner(System.in);
			try
			{
				scan = new Scanner(new FileReader("B-large.in"));
			}
			catch(FileNotFoundException e)
			{
				e.printStackTrace();
				scan.close();
				return;
			}
			int T=scan.nextInt();
			int D;
			int aux;
			int temps;
			int max;
			int indice;
			boolean fini;
			for (int test=1; test<=T; test++)
			{
				//System.out.println("round "+test);
				D=scan.nextInt();
				ArrayList<Integer> tab=new ArrayList<Integer>();
				for (int j=0; j<D; j++)
				{
					tab.add(j,scan.nextInt());
				}
				temps=0;
				fini=false;
				//affiche(tab);
				while (!fini)
				{
					max=MAX(tab);
					indice=MAX_INDICE(tab);
					if (PES(max)+SUP(tab,PES(max))<max)
					{
						tab.remove(indice);
						tab.add(max-PES(max));
						tab.add(PES(max));
					}
					else
					{
						MOINSUN(tab);
					}
					//affiche(tab);
					temps++;
					fini=(MAX(tab)==0);
				}
				//temps=mange(tab);
				fw.write("Case #"+test+": "+temps+"\n");
				
			}
			
			
			
			
			
			
			//FIN
			fw.close();
			System.out.println("FINI!! exo2");
			
		}catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("erreur écriture solution");
		}

	}

}
