#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int main(){
    freopen("bs.in","rt",stdin);
    freopen("out.txt","wt",stdout);

    int gt;
    cin>>gt;
    for(int run=1;run<=gt;run++){
        int sum=0;
        int a,b,k;
        cin>>a>>b>>k;

        for(int i=0;i<a;i++)
        for(int j=0;j<b;j++){
            if( (i&j)<k) sum++;
        }


        printf("Case #%d: ",run);
        cout<<sum<<"\n";
    }

	return 0;
}




