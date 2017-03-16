#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int i,cases,c1;
    long long pi,pk,l,x;
    string s;
    int cuaternios[8][8] = {
        {0,1,2,3,4,5,6,7},
        {1,4,3,6,5,0,7,2},
        {2,7,4,1,6,3,0,5},
        {3,2,5,4,7,6,1,0},
        {4,5,6,7,0,1,2,3},
        {5,0,7,2,1,4,3,6},
        {6,3,0,5,2,7,4,1},
        {7,6,1,0,3,2,5,4},
    };
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        cin>>l>>x;
        int ade[4*l],atr[4*l];
        cin>>s;
        pi=-1;
        if(s[0]=='i'){
            pi=0LL;
            ade[0]=1;
        }
        if(s[0]=='j')ade[0]=2;
        if(s[0]=='k')ade[0]=3;
        for(i=1;i<4*l;i++){
            if(s[i%l]=='i')ade[i]=cuaternios[ade[i-1]][1];
            if(s[i%l]=='j')ade[i]=cuaternios[ade[i-1]][2];
            if(s[i%l]=='k')ade[i]=cuaternios[ade[i-1]][3];
            if(ade[i]==1&&pi==-1)pi=i;
        }
        cout<<"Case #"<<c1<<": ";
        if(ade[l-1]==0){
            cout<<"NO"<<endl;
            continue;
        }
        if((ade[l-1]==4)&&(x%2==0)){
            cout<<"NO"<<endl;
            continue;
        }
        if((ade[l-1]%4!=0)&&(x%4!=2)){
            cout<<"NO"<<endl;
            continue;
        }
        pk=-1;
        if(s[l-1]=='i')atr[4*l-1]=1;
        if(s[l-1]=='j')atr[4*l-1]=2;
        if(s[l-1]=='k'){
            pk=0LL;
            atr[4*l-1]=3;
        }
        for(i=4*l-2;i>=0;i--){
            if(s[i%l]=='i')atr[i]=cuaternios[1][atr[i+1]];
            if(s[i%l]=='j')atr[i]=cuaternios[2][atr[i+1]];
            if(s[i%l]=='k')atr[i]=cuaternios[3][atr[i+1]];
            if(atr[i]==3&&pk==-1)pk=4LL*l-1-i;
        }
        if((pi!=-1)&&(pk!=-1)&&(pi+pk)<l*x){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
