#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

void ispos(int arr[5][5],int visited[5][5],int x,int y,int r,int c)
{
        visited[x][y]=1;
        int sum=0;
        if(x>0&&y>0&&arr[x-1][y-1])    //a
                sum++;
        if(x>0&&arr[x-1][y]==1)             //d
                sum++;
        if(x>0&&y<c-1&&arr[x-1][y+1]==1)  //g
                sum++;
        if(y>0&&arr[x][y-1]==1)             //b
                sum++;
        if(y<c-1&&arr[x][y+1]==1)           //h
                sum++;
        if(x<r-1&&y>0&&arr[x+1][y-1]==1)  //c  
                sum++;
        if(x<r-1&&arr[x+1][y]==1)           //f
                sum++;
        if(x<r-1&&y<c-1&&arr[x+1][y+1]==1)//i
                sum++;
        if(sum==0)
        {
                if(x>0&&y>0&&arr[x-1][y-1]==0&&visited[x-1][y-1]==0)    //a
                        ispos(arr,visited,x-1,y-1,r,c);
                if(x>0&&arr[x-1][y]==0&&visited[x-1][y]==0)             //d
                        ispos(arr,visited,x-1,y,r,c);
                if(x>0&&y<c-1&&arr[x-1][y+1]==0&&visited[x-1][y+1]==0)  //g
                        ispos(arr,visited,x-1,y+1,r,c);
                if(y>0&&arr[x][y-1]==0&&visited[x][y-1]==0)             //b
                        ispos(arr,visited,x,y-1,r,c);
                if(y<c-1&&arr[x][y+1]==0&&visited[x][y+1]==0)           //h
                        ispos(arr,visited,x,y+1,r,c);
                if(x<r-1&&y>0&&arr[x+1][y-1]==0&&visited[x+1][y-1]==0)  //c  
                        ispos(arr,visited,x+1,y-1,r,c);
                if(x<r-1&&arr[x+1][y]==0&&visited[x+1][y]==0)           //f
                        ispos(arr,visited,x+1,y,r,c);
                if(x<r-1&&y<c-1&&arr[x+1][y+1]==0&&visited[x+1][y+1]==0)//i
                        ispos(arr,visited,x+1,y+1,r,c);
        } 
               
}

int main()
{
        freopen ("C-small-attempt0.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
                int r,c,m;
                cin>>r>>c>>m;
                cout<<"Case #"<<test<<":\n";
               //cout<<r<<" "<<c<<" "<<m<<" ";
                int arr[25]={0};
                for(int i=0;i<m;i++)
                        arr[i]=1;
                int flag=0;
                do{
                        int mine[5][5];
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        mine[i][j]=arr[i*c+j];
                                        //cout<<mine[i][j]<<" ";
                                }
                                //cout<<endl;
                        }
                        
                        for(int i=0;i<r*c;i++)
                        {
                                int visited[5][5]={{0}};
                                int x=i/c;
                                int y=i%c;
                                if(mine[x][y]==0&&flag==0)
                                {
                                        ispos(mine,visited,x,y,r,c);
                                        int ct=0;
                                        for(int i=0;i<5;i++)
                                                for(int j=0;j<5;j++)
                                                        if(visited[i][j])
                                                                ct++;
                                        if(ct==(r*c-m))
                                        {
                                                flag=1;
                                                //cout<<"Possible\n";
                                                for(int k=0;k<r;k++)
                                                {
                                                        for(int l=0;l<c;l++)
                                                        {
                                                                if(k==x&&l==y)
                                                                cout<<"c";
                                                                else if(mine[k][l])
                                                                cout<<"*";
                                                                else
                                                                cout<<".";
                                                        }
                                                        cout<<endl;
                                                }
                                        }
                                }
                                if(flag)
                                break;
                        }
                        //cout<<endl;
                        if(flag)
                        break;
                }while(prev_permutation(arr,arr+r*c));
                if(!flag)
                {
                        cout<<"Impossible\n";
                }
        }
        return 0;
}
