import java.util.Scanner;
import java.util.Arrays;
class Mine
{
    private static int nmines,R,C,M,N,max_open,nopen;
    private static int[] mines,ivisited;

    private static void print_mines(){
	int num=0;
	for(int i=0;i<R;i++){
	    for(int j=0;j<C;j++){
		if(mines[num]==0)System.out.print('.'+" ");
		if(mines[num]==1)System.out.print('*'+" ");
		if(mines[num]==2)System.out.print('c'+" ");
		num++;
	    }
	    System.out.print("\n");
	}
	return;
    }

    private static int put_mine(int pos){

	int pos_curr=pos;
	//	System.out.println("Pos:"+pos+" nmines:"+nmines+" M:"+M);

	if(nmines==M){
	    //	    System.out.println("Calling chek_grid: "+nmines+" M:"+M);
	    int click=check_grid();
	    if(click>=0){
		//		System.out.println("nmines: "+nmines+" click"+click);
		mines[click]=2;
		print_mines();
		return 1;
		//		System.exit(1);
	    }
	    return 0;
	}
	if(pos+1>N)return 0;


	nmines++;	    
	mines[pos_curr]=1;
	//	System.out.println("Checking:");
	//	for(int i=0;i<N;i++)
	    //	    System.out.print(mines[i]+" ");
	//	System.out.print("\n");
	int mines_left=M-nmines;
	int spots_left=N-pos_curr+1;
	//	System.out.println("mines_left: "+mines_left+" spots:"+spots_left);
	if(mines_left>spots_left){
	    nmines--;
	    mines[pos_curr]=0;
	    return 0;
	}
	//	System.out.println("Calling:"+pos_curr);
	int res1=put_mine(pos_curr+1);
	if(res1==1)return 1;
	mines[pos_curr]=0;
	nmines--;
	res1=put_mine(pos_curr+1);
	return res1;
	
    }

    private static int check_grid(){  
	//	System.out.println("N:"+N+" R:"+R+" C:"+C);
	//	for(int i=0;i<N;i++)
	//  System.out.print(mines[i]+" ");
	//System.out.print("\n");
     	
	for(int click=0;click<N;click++){
	    if(mines[click]==1)continue;
	    //	    System.out.println("Trying Click: "+click+" max_open:"+max_open);
	    nopen=0;
	    for(int i=0;i<N;i++)
		ivisited[i]=0;
	    int irow=click/C;
	    int icol=click%C;
	    //	    System.out.println("irow: "+irow+" icol:"+icol);
	    isopen(irow,icol);
	    if(nopen==max_open)return click;	    
	}
	return -1;
    }

    private static int glob_num(int irow,int icol){
	return irow*C+icol;
    }

    private static void isopen(int irow,int icol){
	int num=irow*C+icol;
	//	System.out.println("irow:"+irow+" icol: "+icol+" inum:"+num+" mine:"+mines[num]);	
	if(mines[num]==1||ivisited[num]==1)return;
	ivisited[num]=1;
	nopen++;
	//	System.out.println("here1:");
	if(irow>0){
	    if(mines[glob_num(irow-1,icol)]==1){
		return;
	    }else{


	    }
	    if(icol>0)
		if(mines[glob_num(irow-1,icol-1)]==1)return;
	    if(icol<C-1)
		if(mines[glob_num(irow-1,icol+1)]==1)return;
	}
	//	System.out.println("here2:");
	if(irow<R-1){
	    if(mines[glob_num(irow+1,icol)]==1)return;
	    if(icol>0)
		if(mines[glob_num(irow+1,icol-1)]==1)return;
	    if(icol<C-1)
		if(mines[glob_num(irow+1,icol+1)]==1)return;
	}
	//	System.out.println("here3:");
	if(icol>0)
	    if(mines[glob_num(irow,icol-1)]==1)return;
	if(icol<C-1)
	if(mines[glob_num(irow,icol+1)]==1)return;
	//	System.out.println("here:");


	if(irow>0){

	    if(icol>0)
		isopen(irow-1,icol-1);
	    if(icol<C-1)
		isopen(irow-1,icol+1);
	}
	if(irow<R-1){
	    isopen(irow+1,icol);
	    if(icol>0)
		isopen(irow+1,icol-1);
	    if(icol<C-1)
		isopen(irow+1,icol+1);
	}
	if(icol>0)
	    isopen(irow,icol-1);
	if(icol<C-1)
	    isopen(irow,icol+1);
	return;
    }




    public static void main(String[] args)
    {
	Scanner in=new Scanner(System.in);
	int ncase=in.nextInt();	
	for(int icase=0;icase<ncase;icase++){
	    int icase1=icase+1;
	    System.out.println("Case #"+icase1+":");
	    R=in.nextInt();
	    C=in.nextInt();
	    M=in.nextInt();
	    N=R*C;
	    max_open=N-M;	    
	    mines=new int[R*C];
	    ivisited=new int[N];
	    for(int i=0;i<R*C;i++)
		mines[i]=0;
	    if(M==0){
		mines[0]=2;
		print_mines();
		continue;
	    }

	    nmines=0;
	    int ires=put_mine(0);
	    if(ires==0)
		System.out.println("Impossible");
	}

    }
}
