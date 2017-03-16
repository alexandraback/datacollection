#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int i)
{
    return i>0?i:-i;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int i,j,k,m,n,t,c,x,y;
    cin>>t;
    for(c=1;c<=t;++c){
        cin>>x>>y;


        printf("Case #%d: ",c);
        int ll=abs(x);
        for(i=0;i<ll;i++){

            if(x>0){
                printf("WE");
            }else{
                printf("EW");
            }
        }
        ll=abs(y);
        for(i=0;i<ll;i++){

            if(y>0){
                printf("SN");
            }else{
                printf("NS");
            }

        }
        cout<<endl;


    }
    return 0;
}

