#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;

int main(){
    long long int t,l=1,c,r,w,hit;
    cin>>t;
    while(t){
        t-=1;
        cin>>r>>c>>w;
        if(c%w!=0)
            hit=1;
        else
            hit=0;
        hit=hit+((c/w)*r);
        hit+=w-1;
                cout<<"Case #"<<l<<": "<<hit<<endl;
        l++;
    }
}


