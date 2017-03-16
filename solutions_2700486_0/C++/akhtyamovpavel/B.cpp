#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define FILEIN "B.in"
#define FILEOUT "B.txt"
long double probc(int N,int a){
    long double pro=1;
    if(a>N){
        return (long double)0;
    }
    if(a<0)
        return (long double)0;
    for(int i=1;i<=a;++i){
        pro=pro*(N+1-i);
        pro=pro/(long double)(a+1-i);
        pro=pro/(long double)(2);
    }
    for(int i=1;i<=N-a;++i){
        pro=pro/(long double)(2);
    }
    return pro;
}
long double longprobc(int N,int y,int h){
    long double fpro=(long double)0;
    long double spro=(long double)0;
    for(int i=N-h;i<y;++i){
        fpro+=probc(N,i);
    }
    for(int i=N-h;i<=h;++i)
        spro+=probc(N,i);
    long double res=fpro/spro;
    return res;
}
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;++u){
        int N,x,y;
        cin>>N>>x>>y;
        if(x<0)
            x=-x;
        int h;
        for(int i=1;i<=10000;i+=2){
            if(i*(i+1)/2<=N)
                h=i;
        }
        h++;
        if(N==1){
            cout<<"Case #"<<u<<": ";
            if(x+y==0){

                cout<<1<<endl;
            }
            else{

                cout<<0<<endl;
            }
        }

        //cout<<h<<endl;
        else if(h>x+y)
        {
            cout<<"Case #"<<u<<": ";

                cout<<1<<endl;
        }
        else if (h<x+y){
            cout<<"Case #"<<u<<": ";

                cout<<0<<endl;
        }
        else{
            ++y;
            long double prob=(long double)1;
            int curn=N-(h)*(h-1)/2;
            //cout<<"curn"<<curn<<endl;
            //cout<<"y"<<y<<endl;

            if(curn>=h+y){
                cout<<"Case #"<<u<<": ";

                cout<<1<<endl;
            }
            else if(curn<y){
                cout<<"Case #"<<u<<": ";

                cout<<0<<endl;
            }
            else if(curn<=h){
                for(int i=0;i<y;++i){
                    prob-=probc(curn,i);
                    /*cout<<"cri";
                    cout<<curn<<" "<<i<<endl;
                    cout<<"PR"<<probc(curn,i)<<endl;*/

                }
                cout<<"Case #"<<u<<": ";
                cout<<fixed;
                cout<<setprecision(9);
                cout<<prob<<endl;
            }
            else {
                prob=(long double)1;
                prob-=longprobc(curn,y,h);
                cout<<"Case #"<<u<<": ";
                cout<<fixed;
                cout<<setprecision(9);
                cout<<prob<<endl;
            }
        }
    }
    return 0;
}
