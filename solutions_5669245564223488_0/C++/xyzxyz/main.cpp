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
#pragma comment(linker,"/STACK:116777216")
#define MAXN 100100

using namespace std;





int t,n,cnt,l;

int a[10];


string s,str[20],x1,x2;

int main(int argc, char *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&t);
    
    bool f,v[26];
    
    
    for(int o=1;o<=t;o++){
        cnt=0;
        for(int i=0;i<10;i++)
            a[i]=i;
        
        

        
        cin>>n;
        
        for(int i=0;i<n;i++)
            {
                cin>>str[i];
                
                //cout<<str[i]<<endl;
            }
        
        memset(v,0,sizeof(v));
        
        f=0;
        s="";
        for(int i=0;i<n;i++)
            s=s+str[i];
        //cout<<s<<endl;
        l=s.size();
        v[s[0]-'a']=1;
        for(int i=1;i<l;i++){
            if(s[i]!=s[i-1]){
                if(v[s[i]-'a']==1)
                    {
                        f=1;
                        break;
                    }
                else
                    v[s[i]-'a']=1;
                }
        //cout<<s[i];
        }
        //cout<<endl;
        if(f==0)
            cnt++;
        
        
        
        
        
        while(next_permutation(a,a+n)){
            memset(v,0,sizeof(v));
            f=0;
            s="";
            for(int i=0;i<n;i++)
                s=s+str[a[i]];
            //l=s.size();
            v[s[0]-'a']=1;
            for(int i=1;i<l;i++)
                if(s[i]!=s[i-1]){
                    if(v[s[i]-'a']==1)
                        {
                            f=1;
                            break;
                        }
                    else
                        v[s[i]-'a']=1;
                    }
            if(f==0)
                cnt++;
            }
        
        cout<<"Case #"<<o<<": ";
        cout<<cnt<<endl;
        
        
        memset(v,0,sizeof(v));
        }    
    
    
    
    
    //system("pause");
    return 0;
}
