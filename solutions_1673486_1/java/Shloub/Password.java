import java.util.Scanner;

class Password{
    static Scanner sc = new Scanner(System.in);
    
    public static void solve()
    {
	double probaOk=1;
	double espeOk;
	double espeNew;
	double min;
	double temp;
	int n=sc.nextInt();
	int N=sc.nextInt();
	double[] tab= new double[n];
	double[] prod=new double[n];
	double prodt=1;
	for(int i=0;i<n;i++)
	    {
		
		tab[i]=sc.nextDouble();
		
		probaOk*=tab[i];
		prod[i]=probaOk;
	    }	
	espeNew=(N+2);
	min=espeNew;
	for(int i=1;i<n;i++)
	    {
		temp=prod[n-i-1]*(N-n+1+2*i)+((1-prod[n-i-1])*(2*N-n+2+2*i));
		if(temp<min)
		    min=temp;
	    }
	
	espeOk=probaOk*(N-n+1)+(1-probaOk)*(2*N-n+2);
	System.out.println(Math.min(Math.min(espeOk,espeNew),min));
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