#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
int arr[1001][1001];
int visit[1001];
bool flag=false;
void dfs(int node, int n)
{
   for(int i=0;i<n;i++)
   {
       if(arr[node][i]==1)
       {
           if(visit[i])
           {
               flag=true; 
           }
           else
           {
               dfs(i,n);
           }
       }
   }
   visit[node]=1;
}

int main()
{
	int t,t1=1;
	cin>>t;
	while(t1<=t)
	{
           for(int i=0;i<=1000;i++)
           {
               visit[i]=0;
	       for(int j=0;j<=1000;j++)
	           arr[i][j]=0;
            }
	    flag=false;

            int n, n1=0;
            cin>>n;
            for(n1=0;n1<n;n1++)
            {
                int mi;
                cin>>mi;
		for(int j=0;j<mi;j++)
 		{
		    int l;
		    cin>>l;
                    arr[n1][l-1]=1;
		}
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)visit[j]=0;
	        dfs(i,n);
                if(flag)break;
            }
            cout<<"Case #"<<t1<<": ";
            if(flag)
            	cout<<"Yes"<<endl;
	    else
		cout<<"No"<<endl;
            t1++;
	}
}
