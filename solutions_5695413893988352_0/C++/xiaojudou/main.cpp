#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<fstream>
#define eps 1e-5
#define mod 1000000007
using namespace std;
int t,n;
string j,c;
int main(){
    freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("b.out","w",stdout);
    cin>>t;
    for(int _=1;_<=t;++_){
        cin>>c>>j;
        
        int lt=(int)c.length();
        int ans=1000;
        int c0=0,j0=0;
        while((int)c.length()<3){
            c="0"+c;
            j="0"+j;
        }
        
        int tmpc=0,tmpj=0;
        for(int i1=0;i1<10;++i1)
            for(int i2=0;i2<10;++i2)
                for(int i3=0;i3<10;++i3)
                    for(int j1=0;j1<10;++j1)
                        for(int j2=0;j2<10;++j2)
                            for(int j3=0;j3<10;++j3)
                            {
                                if(c[0]=='?')tmpc=i1*100;
                                else tmpc=(c[0]-'0')*100;
                                
                                if(c[1]=='?')tmpc+=i2*10;
                                else tmpc+=(c[1]-'0')*10;
                                
                                if(c[2]=='?')tmpc+=i3*1;
                                else tmpc+=(c[2]-'0')*1;
                                
                                if(j[0]=='?')tmpj=j1*100;
                                else tmpj=(j[0]-'0')*100;
                                
                                if(j[1]=='?')tmpj+=j2*10;
                                else tmpj+=(j[1]-'0')*10;
                                
                                if(j[2]=='?')tmpj+=j3*1;
                                else tmpj+=(j[2]-'0')*1;
                                
                                if(abs(tmpc-tmpj)<ans){
                                    ans=abs(tmpc-tmpj);
                                    c0=tmpc;
                                    j0=tmpj;
                                }
                            }
            
        
        
        
        cout<<"Case #"<<_<<": ";
        cout.fill('0');
        cout.width(lt);
        cout<<c0<<" ";
        cout.fill('0');
        cout.width(lt);
        cout<<j0;
                cout<<endl;
    }
    return 0;
}