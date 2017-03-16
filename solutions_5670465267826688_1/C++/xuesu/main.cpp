#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxl=2.5e5+10;
int l;
ll x;
char str[maxl];
int val[maxl],rv[maxl];

int subcalc[255][255];
void initcalc(){
    subcalc[1][1]=1;
    subcalc[1][(int)'i']=(int)'i';
    subcalc[1][(int)'j']=(int)'j';
    subcalc[1][(int)'k']=(int)'k';
    subcalc[(int)'i'][1]=(int)'i';
    subcalc[(int)'j'][1]=(int)'j';
    subcalc[(int)'k'][1]=(int)'k';
    subcalc[(int)'i'][(int)'j']=(int)'k';
    subcalc[(int)'j'][(int)'i']=-(int)'k';
    subcalc[(int)'i'][(int)'k']=-(int)'j';
    subcalc[(int)'k'][(int)'i']=(int)'j';
    subcalc[(int)'j'][(int)'k']=(int)'i';
    subcalc[(int)'k'][(int)'j']=-(int)'i';
    subcalc[(int)'i'][(int)'i']=-1;
    subcalc[(int)'j'][(int)'j']=-1;
    subcalc[(int)'k'][(int)'k']=-1;
}
int calc(int a,int b){
    int sign=a*b/abs(a)/abs(b);
    a=abs(a);
    b=abs(b);
    return sign*(subcalc[a][b]);
}
int indi,indk;
void calvalue(){
    val[0]=(int)str[0];
    if(val[0]==(int)'i')indi=0;
    else indi=0x7ffffff;
    indk=-1;
    for(int i=1;i<l;i++){
        val[i]=calc(val[i-1],(int)str[i]);
        if(val[i]==(int)'i'){
            indi=min(indi,i);
        }
    }
    rv[l]=1;
    for(int i=l-1;i>=0;i--){
        rv[i]=calc((int)str[i],rv[i+1]);
        if(rv[i]==(int)'k'){
            indk=max(indk,i);
        }
    }
}

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    initcalc();
    int T;
    cin>>T;
    for(int ti=1;ti<=T;ti++){
        cin>>l>>x>>str;
        //printf("%d %I64d %s\n",l,x,str);
        if(x>12){
            x=x%12+8;
        }
        for(int i=1;i<x;i++){
            for(int j=i*l;j<i*l+l;j++){
                str[j]=str[j-i*l];
            }
        }
        l*=x;
        str[l]=0;
        calvalue();
        int fl=val[l-1];
        if(fl!=-1||indi>=indk){
            cout<<"Case #"<<ti<<": NO"<<endl;
        }
        else {
            cout<<"Case #"<<ti<<": YES"<<endl;
        }
    }
    return 0;
}
