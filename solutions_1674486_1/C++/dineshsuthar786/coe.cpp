#include<iostream>
#include<fstream>
using namespace std;
 int arr[1001][1001];
int main()
{
    ofstream ef;
    ef.open("a.txt");
    int t,l,a;
    int n,m,i,j,k;
    scanf("%d",&t);
    for(l=1;l<=t;l++){
                      int flag=0;
                        scanf("%d",&n);
                       for(i=0;i<n;i++)
                       for(j=0;j<n;j++)
                       arr[i][j]=0;
                        for(i=0;i<n;i++){
                                         scanf("%d",&m);
                                         for(j=0;j<m;j++){
                                                        scanf("%d",&a); 
                                                        arr[i][a-1]=1; 
                                         }
                        }
                        for(k=0;k<n;k++){
		                                for(i=0;i<n;i++){
			                                            for(j=0;j<n;j++){
				                                                        if(arr[i][k]+arr[k][j]>1)
				                                                                                  arr[i][j]++;
                                                                                                  if(arr[i][j]>=2){
                                                                                                                   flag=1;
                                                                                                                   break;
                                                                                                  }
                                                            }
                                                            if(flag==1)
                                                            break;
                                               }
                                               if(flag==1)
                                                          break;
                        }
                        if(flag==1)
                        ef<<"Case #"<<l<<": Yes\n";
                        else
                        ef<<"Case #"<<l<<": No\n";
    }
    ef.close();
    system("pause");
    return 0;
}
