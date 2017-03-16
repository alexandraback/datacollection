#include<iostream>
using namespace std;

int dist[1000][1000],n;
int floyd_warshall() {
	int i, j, k;
	for (k = 0; k < n; ++k) {
		
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				
				if ((dist[i][k] * dist[k][j] != 0) && (i != j))
					
					if ((dist[i][j] == 0))
						dist[i][j] = dist[i][k] + dist[k][j];
					else
					return 1;
	}
	return 0;
	
}

int main()
{
    int t,i,j,k,n2,x,y;
    
    cin>>t;
    
    for(i=0;i<t;i++)
    {
                    for(j=0;j<1000;j++)
                    for(k=0;k<1000;k++)
                    dist[j][k]=0;
                    
                    
                    cin>>n;
                    
                    for(j=0;j<n;j++)
                    {
                                    cin>>n2;
                                    
                                    for(k=0;k<n2;k++)
                                    {
                                                     cin>>x;
                                                     dist[j][x-1]=1;;
                                    }
                    }
                    
                                    cout<<"Case #"<<i+1<<": ";
                    
                                             if(floyd_warshall()==0)
                                             cout<<"No\n";
                                             else
                                             cout<<"Yes\n";       
                    
    }
    
    return 0;
}
                                                     
                                    
