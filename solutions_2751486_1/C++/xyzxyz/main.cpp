#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")


using namespace std;
typedef long long ll;
typedef double db;
string readline() {
        int c = getchar();
        while (c < 33)
                c = getchar();
        string s = "";
        while (c > 32) {
                s += c;
                c = getchar();
        }
        return s;
}

bool alfa[27];
int t,le,ri,n,l,cnt;
ll sum;
string s;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    alfa['a'-'a']=1;
    alfa['e'-'a']=1;
    alfa['i'-'a']=1;
    alfa['o'-'a']=1;
    alfa['u'-'a']=1;

    
    
    cin>>t;
    for(int o=1;o<=t;o++){
        le=0;
        
        s=readline();
        cin>>n;
        l=s.size();
        cnt=0;
        sum=0;
       // cout<<l<<endl;
        for(int i=0;i<l;i++)
            {
                if(alfa[s[i]-'a']==0){//cout<<"mehe"<<endl;
                    cnt++;}
                else
                    cnt=0;
                
                if(cnt>=n){
                    //cout<<"xaxa"<<endl;
                    sum=sum+(ll)((i-n+1)-le+1)*((ll)(l-i));
                    
                    le=i-n+2;
                }
                
            }
        
        cout<<"Case #"<<o<<": "<<sum<<endl;
        
        }





    return 0;
}
