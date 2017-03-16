import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class King{
    static Scanner sc = new Scanner(System.in);
    
    public static void solve()
    {
	class lvl implements java.lang.Comparable {
	    int star;
	    int lvl;
	    int diff;

	    public int compareTo(Object other) { 
		int nombre1 = ((lvl) other).diff; 
		int nombre2 = this.diff; 
		if (nombre1 > nombre2)  return -1; 
		else if(nombre1 == nombre2) return 0; 
		else return 1; 
	    } 
	}


	boolean temp;
	int sold=0;
	int nb=0;
	int n=sc.nextInt();
	int[][] mat=new int[n][2];
	int[] tab=new int[n];
	int[] tab2=new int[n];
	int[] tab1=new int[n];

	int j,k;
	List<lvl> lvls=new ArrayList<lvl>();
	List<lvl> lvls1=new ArrayList<lvl>();
	List<lvl> lvls2=new ArrayList<lvl>();
	for(int i=0;i<n;i++)
	    tab[i]=0;
	for(int i=0;i<n;i++)
	    {
		mat[i][0]=sc.nextInt();
		mat[i][1]=sc.nextInt();
		tab1[i]=mat[i][0];
		tab2[i]=mat[i][1];
		lvl lvl=new lvl();
		lvl.star=1;
		lvl.lvl=i;
		lvl.diff=tab1[i];
		lvls.add(lvl);
		lvls1.add(lvl);
		lvl lvl2=new lvl();
		lvl2.star=2;
		lvl2.lvl=i;
		lvl2.diff=tab2[i];
		lvls.add(lvl2);
		lvls2.add(lvl2);
	    }	

	
	Collections.sort(lvls);
	Collections.sort(lvls1);
	Collections.sort(lvls2);
	j=0;
	k=0;
	while(j<n)
	    {temp=false;
		while(j<n && lvls2.get(j).diff<=sold )
		    {
			
			sold+=2-tab[lvls2.get(j).lvl];
			tab[lvls2.get(j).lvl]=2;
			nb++;
			j++;
			temp=true;
			// System.out.println("S "+sold);
			if(j==n)
			    {
				System.out.println(nb);
				return ;
			    }
		    }
		k=n-1;
		while(k>0 && (lvls1.get(lvls2.get(k).lvl).diff>sold || tab[lvls2.get(k).lvl]>0))
		    {
			k--;
		    }
		
		if(tab[lvls2.get(k).lvl]==0 && lvls1.get(lvls2.get(k).lvl).diff<=sold)
		    {
			nb++;
			sold++;
			tab[lvls2.get(k).lvl]=1;
			temp=true;
				// System.out.println("S "+sold);
		    }
		if(!temp){
		    System.out.println("Too Bad");
		    return;
		}
		
		    
	    }
	System.out.println(nb);
    }

    public static void main(String[] args)
    {
	int n=sc.nextInt();
	sc.nextLine();

	for(int i=0;i<n;i++)
	    {
		System.out.print("Case #"+(i+1)+": ");
		solve();
	    }
    }
    
}