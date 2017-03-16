#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;
long long pot[55];

int main(){

    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int p,q,r,s;
        cin>>p>>q>>r>>s;
        int a[30],b[30],c[30];
        int cont=0;
        for(int i=1;i<=p;i++)
            for(int j=1;j<=q;j++)
                for(int k=1;k<=r;k++){
                    a[cont]=i;
                    b[cont]=j;
                    c[cont]=k;
                    cont++;
                }

        int maxi=0;int id=0;
        int val[30];
        
        int p1[32];int p2[32];int p3[32];
        for(int i=0;i<(1<<cont);i++){
            if(__builtin_popcount(i)<=maxi )continue;
            memset(p1,0,sizeof(p1));
            memset(p2,0,sizeof(p2));
            memset(p3,0,sizeof(p3));

            bool ok=1;
            int pos=0;
            for(int j=0;j<cont;j++)
                if( (i&(1<<j))!=0 ){
                    p1[a[j]*3+b[j]]++;
                    p2[a[j]*3+c[j]]++;
                    p3[b[j]*3+c[j]]++;

                    if(p1[a[j]*3+b[j]]>s){ok=0;break;}
                    if(p2[a[j]*3+c[j]]>s){ok=0;break;}
                    if(p3[b[j]*3+c[j]]>s){ok=0;break;}
                }
            if(ok){
                maxi=__builtin_popcount(i);
                id=i;
            }
        }


        cout<<maxi<<endl;
        for(int j=0;j<cont;j++)
            if( (id&(1<<j))!=0 )
                cout<<a[j]<<" "<<b[j]<<" "<<c[j]<<endl;
        
    }

    return 0;
}





