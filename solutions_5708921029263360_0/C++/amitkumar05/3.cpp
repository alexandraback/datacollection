#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<limits.h>
#include<deque>
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define sf(n) scanf("%f",&n)

#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n)
#define pf(n) printf("%f\n",n)

#define ll long long int
#define r0 return 0
#define INF INT_MAX
#define FR(i,a,b) for(i=a;i<b;i++)
#define decit int i,j,k
int M=1000000000+7;
using namespace std;

int main()
{
    int t,it;
    decit;
    si(t);
    FR(it,1,t+1)
    {
        ll ans=0;
        int x,y,z,K;
        ll count=0;
      	cout<<"Case #"<<it<<": ";
        cin>>x>>y>>z>>K;
        map< pair<int,int>,int > m1;
        map< pair<int,int>,int > m2;
        map< pair<int,int>,int > m3;
        FR(i,1,x+1)
        {
            FR(j,1,y+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m1[p]=K;
            }        

        }
        FR(i,1,x+1)
        {
            FR(j,1,z+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m2[p]=K;
            }        

        }
        
        FR(i,1,y+1)
        {
            FR(j,1,z+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m3[p]=K;
            }        
        }

        FR(i,1,x+1)
        {
            FR(j,1,y+1)
            {
               FR(k,1,z+1)
                {
                    pair<int,int> p1;
                    pair<int,int> p2;
                    pair<int,int> p3;
                    
        

                    p1.first=i;
                    p1.second=j;
         
                    p2.first=i;
                    p2.second=k;
                    

                    p3.first=j;
                    p3.second=k;
         
                   if(m1[p1]>0&&m2[p2]>0&&m3[p3]>0)
                    {
                        count++;
                    m1[p1]--;m2[p2]--;m3[p3]--;
                    }
                }     
            }
        }
        cout<<count<<endl;

        FR(i,1,x+1)
        {
            FR(j,1,y+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m1[p]=K;
            }        

        }
        FR(i,1,x+1)
        {
            FR(j,1,z+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m2[p]=K;
            }        

        }
        
        FR(i,1,y+1)
        {
            FR(j,1,z+1)
            {
                pair<int,int> p;
                p.first=i;
                p.second=j;
                m3[p]=K;
            }        
        }



        FR(i,1,x+1)
        {
            FR(j,1,y+1)
            {
               FR(k,1,z+1)
                {
                    pair<int,int> p1;
                    pair<int,int> p2;
                    pair<int,int> p3;
                    
        

                    p1.first=i;
                    p1.second=j;
         
                    p2.first=i;
                    p2.second=k;
                    

                    p3.first=j;
                    p3.second=k;
         
                   if(m1[p1]>0&&m2[p2]>0&&m3[p3]>0)
                    {
                        cout<<i<<" "<<j<<" "<<k<<endl;
                         m1[p1]--;m2[p2]--;m3[p3]--;
                    }
                }     
            }
        }
    }
    return 0;
}