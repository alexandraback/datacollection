#include<iostream>
#include<fstream>
using namespace std;
int a[1100][1100];
int cp[1100][1100];
int main(){
    int t;
    cin>>t;
    ofstream out("Q3.out");
    int temp,max;
    int i,j,k,n,i1,j1,k1;
    for (i=0;i<t;i++){
        cin>>n;
        for (j=1;j<=n;j++)
            for (k=1;k<=n;k++){
                cp[j][k]=0;
                a[j][k]=0;
            }
        for (j=1;j<=n;j++){
            cin>>temp;
            a[j][temp]=1;
            if (a[temp][j]==1){
               cp[j][temp]=1;
               cp[temp][j]=1;
            }
            cp[j][temp]=2;
        }
        for (i1=1;i1<=n;i1++){
            for (j1=1;j1<=n;j1++){
                if (cp[i1][j1]==1) continue;
                if (i1==j1) continue;
                for (k1=1;k1<=n;k1++){
                    if (a[i1][k1]==0) continue;
                    if (a[k1][j1]==0) continue;
                    if (a[i1][j1]<a[i1][k1]+a[k1][j1]) a[i1][j1]=a[i1][k1]+a[k1][j1];
                }
            }
        }
        max=0;
        for (j=1;j<=n;j++){
            for (k=j+1;k<=n;k++){
                if (cp[j][k]==1){
                   for (i1=1;i1<=n;i1++)
                       for (j1=1;j1<=n;j1++){
                           if (i1==j) continue;
                           if (j1==j) continue;
                           if (i1==k) continue;
                           if (j1==k) continue;
                           if (a[i1][j]+a[j1][k]>max) max=a[i1][j]+a[j1][k];
                       }
                }
            }
        }
        for (j=1;j<=n;j++)
            for (k=1;k<=n;k++){
                if (cp[j][k]==1) continue;
                if (a[j][k]+1>max && cp[k][j]==2) max=a[j][k]+1;
            }
        out<<"Case #"<<i+1<<": "<<max<<endl;
    }
}
