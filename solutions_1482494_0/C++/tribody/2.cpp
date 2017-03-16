#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream in("small.in");
    ofstream out("small.out");
    int tt,n,m,s,max,p,f;
    int o[10000],t[10000];
    char c;
    in>>tt;
    for(int w=0;w<tt;w++){
        in>>n;
        for(int i=0;i<n;i++)
            in>>o[i]>>t[i];
        m=0;s=0;p=0;
        while(m<2001&&s<n){
            max=-1;
            f=1;
            for(int i=0;i<n;i++){
                if(t[i]<=m){
                m++;s++;p++;t[i]=10000;
                if(o[i]!=10000)m++;
                o[i]=10000;
                f=0;
                }
                else if((o[i]<=m)&&(max==-1||t[max]<t[i]))max=i;
                };
            if(f){
                if(max==-1)m=2002;else
                {m++;p++;o[max]=10000;};
                };
            }
        if (m==2002)out<<"Case #"<<w+1<<": Too Bad\n";
        else out<<"Case #"<<w+1<<": "<<p<<endl;
        }
}
