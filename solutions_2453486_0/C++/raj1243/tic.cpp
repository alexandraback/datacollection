#include <iostream>

using namespace std;

int main()
{ int i,j,t,k,countx,counto,countt,countdot,wonx,wono;
 char a[4][4];
 cin>>t;
 k=1;
 while(t--)
 {  wonx=wono=0;
   
    countx=counto=countt=countdot=0;
    int flag=0;
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    cin>>a[i][j];
    //checking along row
    for(i=0;i<4;i++)
    { if(flag==0)
       {countx=0;counto=0;countt=0;
       for(j=0;j<4;j++)
       {
           if(a[i][j]=='X')
           countx++;
           if(a[i][j]=='O')
           counto++;
           if(a[i][j]=='T')
           countt++;
           if(a[i][j]=='.')
           countdot++;

       }
       if((countx==3&&countt==1)||countx==4)
       {wonx=1;flag=1;}
       if((counto==3&&countt==1)||counto==4)
       {wono=1;flag=1;}
    }
    }
       //cj=hecking along coloumn
    if(flag==0)
       {
        for(i=0;i<4;i++)
      { if(flag==0)
       {countx=0;counto=0;countt=0;
       for(j=0;j<4;j++)
       {
           if(a[j][i]=='X')
           countx++;
           if(a[j][i]=='O')
           counto++;
           if(a[j][i]=='T')
           countt++;
           if(a[j][i]=='.')
           countdot++;

       }
       if((countx==3&&countt==1)||countx==4)
       {wonx=1;flag=1;}
       if((counto==3&&countt==1)||counto==4)
       {wono=1;flag=1;}
       }
       }
       }



    //checking along rite diagonal
        if(flag==0)
        {countx=0;counto=0;countt=0;
       for(j=0;j<4;j++)
       {
           if(a[j][j]=='X')
           countx++;
           if(a[j][j]=='O')
           counto++;
           if(a[j][j]=='T')
           countt++;
           if(a[j][j]=='.')
           countdot++;

       }
       if((countx==3&&countt==1)||countx==4)
       {wonx=1;flag=1;}
       if((counto==3&&countt==1)||counto==4)
       {wono=1;flag=1;}

      }

      //checking along left diagonal

    if(flag==0)
    {
       countx=0;counto=0;countt=0;
       for(j=0;j<4;j++)
       {
           if(a[3-j][j]=='X')
           countx++;
           if(a[3-j][j]=='O')
           counto++;
           if(a[3-j][j]=='T')
           countt++;
           if(a[3-j][j]=='.')
           countdot++;

       }
       if((countx==3&&countt==1)||countx==4)
       {wonx=1;flag=1;}
       if((counto==3&&countt==1)||counto==4)
       {wono=1;flag=1;}

 }

    if(wonx)
    cout<<"Case #"<<k<<": X won\n";
    else
    if(wono)
    cout<<"Case #"<<k<<": O won\n";
    else
    if(countdot)
    cout<<"Case #"<<k<<": Game has not completed\n";
    else
    cout<<"Case #"<<k<<": Draw\n";
k++;
cout<<endl;
}
    return 0;
}
