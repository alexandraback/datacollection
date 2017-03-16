#include <bits/stdc++.h>

using namespace std;
string keyboard,tar;


int b(string str){
    int x= 0;
    int ctr=0;
    while(x<str.size()){
        x = (int)str.find(tar,x);
        if(x==-1)break;
        ctr++;
        x++;
    }
    return ctr;
}
int mx= 0, total = 0;

void calc(int sz, string str){
    if(sz==0){
        int tmp = b(str);
        mx = max(mx,tmp);
        total += tmp;
        return ;
    }

    for(int i=0;i<keyboard.size();i++){
       calc(sz-1, str+keyboard[i]);
    }
}
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t;
    cin>>t;
    for(int f=1 ; f<=t ;f++){
        int ksz, sz1,sz;
        cin>>ksz>>sz1>>sz;
        cin>>keyboard;
        cin>>tar;
        mx=0; total = 0;
        calc(sz,"");

        double avg = total / pow(ksz,sz);
        cout<< "Case #"<<f<<": "<<setprecision(8)<<fixed<<(double)mx-avg<<endl;
    }
    return 0;
}
