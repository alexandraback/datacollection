#include<iostream>
using namespace std;
long long int t,n,m,toy[100][2],box[100][2],maxval,k;

void calculate(long long int x,long long int y,long long int val)
{
    // cout<<x<<" "<<y<<" "<<val<<" "<<box[x][1]<<" "<<toy[y][1]<<"\n";
     //cin>>k;
    if(x>=n||y>=m)
    {
                  if(maxval<val)
                           maxval=val;
                           return;
}
    if(box[x][1]==toy[y][1])
    {
                            if(box[x][0]>toy[y][0])
                            {
                                                   val=val+toy[y][0];
                                                   box[x][0]-=toy[y][0];
                                                   calculate(x,y+1,val);
                                                    box[x][0]+=toy[y][0];
                            }
                            else
                            {
                                val+=box[x][0];
                                toy[y][0]-=box[x][0];
                                calculate(x+1,y,val);
                                toy[y][0]+=box[x][0];
                            }
    }
    else
    {calculate(x+1,y,val);
    calculate(x,y+1,val);}
}

int main()
{
    long long int i,j,k;
    cin>>t;
    
    for(i=0;i<t;i++)
    {
                    maxval=0;
                    cin>>n>>m;
                    
                    for(j=0;j<n;j++)
                    cin>>box[j][0]>>box[j][1];
                    
                    for(j=0;j<m;j++)
                    cin>>toy[j][0]>>toy[j][1];
                    
    calculate(0,0,0);
                    cout<<"Case #"<<i+1<<": "<<maxval<<"\n";
    }
                    
    return 0;
}
