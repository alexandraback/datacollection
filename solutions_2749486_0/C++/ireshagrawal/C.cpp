#include<iostream>
#include <fstream>
#include<map>
#include<set>
//#include<conio.h>
#define mp make_pair
using namespace std;
int X,Y;

 
map< pair<int,int> , int > M;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
map< int,char > F;
 

 
void PrinT(int nx,int ny,int moves)
{
    if((nx==0) && (ny==0))return;
   int I=M[mp(nx,ny)]-1;
 
   int px=(nx-(moves*dx[I]));
   int py=(ny-(moves*dy[I]));
    PrinT(px,py,moves-1);
    cout<<F[I];
}
 
void bfs()
{
    M.clear();
    M[mp(0,0)]=0;
    //queue < node > Q;
 
   // Q.push(start);
 
    set < pair<int,int> > S;
    S.insert(mp(0,0));
   int moves=1;
    while(1)
    {
         set < pair<int,int> > cur;
 
            for(set< pair<int,int> >::iterator it=S.begin();it!=S.end();it++)
            {
                int cur_x=it->first;
                int cur_y=it->second;
 
                    for(int dir=0;dir<4;dir++)
                    {
                        int nx=(cur_x+(moves*dx[dir]));
                        int ny=(cur_y+(moves*dy[dir]));
 
                        if(M[mp(nx,ny)])continue;
                        M[mp(nx,ny)]=(dir+1);
                        if(nx==X && ny==Y)
                        {PrinT(nx,ny,moves);return;}
                        cur.insert(mp(nx,ny));
                      //  cout<<nx<<" "<<ny<<endl;
 
                    }
 
            }
            moves++;
            S=cur;
            if(moves>500)break;
          //  cout<<endl<<endl;
 
 
    }
 
}
int main()
{ifstream fin;  
ofstream fout;
fin.open("C.in", ios::in);   
fout.open("ans.txt", ios::out);
   F[0]='E';
F[1]='N';
F[2]='W';
F[3]='S';
    int t;
    fin>>t;
    //scanf("%d",&t);
 
    for(int tt=0;tt<t;tt++)
    {cout<<"\nCase #"<<tt+1<<": ";
        fin>>X>>Y;
        //scanf("%d %d",&X,&Y);
      bfs();
      //cout<<endl;
      
    }
    system("pause>null");
    return 0;
}

