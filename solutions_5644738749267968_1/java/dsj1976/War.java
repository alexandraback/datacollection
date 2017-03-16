import java.util.Scanner;
import java.util.Arrays;
class War
{

    private static int Deceit(int N,double[] Nval,double[] Kval,int[] Nburn,int[] Kburn){
	int score=0;
	double dscore=Optim(N,Nval,Kval,Nburn,Kburn);;

	for(int igame=0;igame<N;igame++){
	    double Nchosen=0.0,Kchosen=0.0;
	    int jloc;
	    for(int i=N-1;i>=0;i--){
		if(Nburn[i]==0){
		    jloc=-1;
		    Nchosen=Nval[i];
		    for(int j=N-1;j>=0;j--){
			if(Kburn[j]==0){
			    Kchosen=Kval[j];
			    jloc=j;
			    break;
			}
		    }
		    if(Kchosen>Nchosen){
			Kburn[jloc]=1;
			break;
		    }
		    igame++;
		    score++;
		    Nburn[i]=1;
		    Kburn[jloc]=1;
		}
	    }



	    for(int i=0;i<N;i++){
		if(Nburn[i]==0){
		    Nchosen=Nval[i];
		    Nburn[i]=1;
		    break;
		}
	    }


	}
	return score;
    }

    private static int Optim(int N,double[] Nval,double[] Kval,int[] Nburn1,int[] Kburn1){

	int []Nburn=new int[N];
	int []Kburn=new int[N];
	for(int i=0;i<N;i++){
	    Nburn[i]=Nburn1[i];
	    Kburn[i]=Kburn1[i];
	}

	int score=0;
	for(int igame=0;igame<N;igame++){
	    double Nchosen=0.0,Kchosen;
	    
	    for(int i=N-1;i>=0;i--){
		if(Nburn[i]==0){
		    Nchosen=Nval[i];
		    Nburn[i]=1;
		    break;
		}
	    }
	    int Kfound=0;
	    int imin=-1;
	    for(int i=0;i<N;i++){
		if(Kburn[i]==0){
		    if(imin<0)imin=i;
		    if(Kval[i]>Nchosen){
			Kchosen=Kval[i];
			Kburn[i]=1;
			Kfound=1;
			break;
		    }
		}
	    }
	    if(imin<0)break;

	    if(Kfound==0){
		Kchosen=Kval[imin];
		Kburn[imin]=1;
		score++;
	    }


	}
	return score;
    }

    public static void main(String[] args)
    {
	Scanner in=new Scanner(System.in);
	int ncase=in.nextInt();
	
	for(int icase=0;icase<ncase;icase++){
	    int icase1=icase+1;
	    int N=in.nextInt();
	    double[] Nval=new double[N];
	    double[] Kval=new double[N];
	    int[] Nburn=new int[N];
	    int[] Kburn=new int[N];
	    for(int i=0;i<N;i++){
		Nval[i]=in.nextDouble();
		Nburn[i]=0;
	    }
	    Arrays.sort(Nval);
	    for(int i=0;i<N;i++){
		Kval[i]=in.nextDouble();
		Kburn[i]=0;
	    }
	    Arrays.sort(Kval);

	    int optim_score=Optim(N,Nval,Kval,Nburn,Kburn);

	    int deceit_score=Deceit(N,Nval,Kval,Nburn,Kburn);
		    
	    System.out.println("Case #"+icase1+":"+" "+deceit_score+" "+optim_score);

	}
    }
}
