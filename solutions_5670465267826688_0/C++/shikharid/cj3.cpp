#include<bits/stdc++.h>
using namespace std;

int a[][5]={{0,1,2,3,4},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
map<char,int> mean;
int bpow(int r,long long n){

    int res=0;
    while(n){

        if(n&1){
             if(res>=0){
                if(r>0){
                    res=a[res][r];
                }
                else res=-a[res][(-r)];
            }
            else{
                if(r>0){
                    res=-a[(-res)][(r)];
                }
                else res=a[(-res)][(-r)];
            }
        }
        if(r>0){
            r=a[r][r];
        }
        else r=a[(-r)][(-r)];
        n>>=1;
    }
    return res;

}
int main(){
    int t,d;
    //ifstream cin("C-small-attempt1.in");
   //ofstream cout("ans31.txt");
    mean['i']=2,mean['j']=3,mean['k']=4;
    cin>>t;
    long long l,x;
    string s;
    for(int tt=1;tt<=t;tt++){
        cin>>l>>x;
        cin>>s;
        string y=s;
        int fr=0,ba=0,fi=0,fj=0;
        for(int i=2;i<=x;i++)s+=y;
        l=l*x;
        for(int i=0;i<l;i++){
            if(fr>=0){
                fr=a[fr][mean[s[i]]];
            }
            else{
                fr=-a[(-fr)][mean[s[i]]];
            }
            if(fr==2){
                fi=1;
            }
            if(fr==(4)&&fi==1){
                fj=1;
            }
        }
        if(fr==-1&&fi==1&&fj==1)
            cout<<"Case #"<<tt<<": YES"<<endl;
        else cout<<"Case #"<<tt<<": NO"<<endl;

    }
    return 0;
}
