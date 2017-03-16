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
string week[10]={  "ONE",  "NINE"};
int cha[30],ans[10];
int t,n;
string s;
int main(){
    freopen("A-small-attempt0.in.txt","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    for(int _=1;_<=t;++_){
        cin>>s;
        
        memset(cha,0,sizeof(cha));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<(int)s.length();++i)
            cha[s[i]-'A']++;
        
        //0
        n=(int)('Z'-'A');
        if(cha[n]>0)//0
        {
            ans[0]=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[(int)('R'-'A')]-=cha[n];
            cha[(int)('O'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //6
        n=(int)('X'-'A');
        if(cha[n]>0)
        {
            ans[6]=cha[n];
            cha[(int)('S'-'A')]-=cha[n];
            cha[(int)('I'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //8
        n=(int)('G'-'A');
        if(cha[n]>0)
        {
            ans[8]=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[(int)('I'-'A')]-=cha[n];
             cha[(int)('H'-'A')]-=cha[n];
             cha[(int)('T'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //7
        n=(int)('S'-'A');
        if(cha[n]>0)
        {
            ans[7]=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[(int)('V'-'A')]-=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[(int)('N'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //4
        n=(int)('U'-'A');
        if(cha[n]>0)
        {
            ans[4]=cha[n];
            cha[(int)('F'-'A')]-=cha[n];
            cha[(int)('O'-'A')]-=cha[n];
            cha[(int)('R'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //5
        n=(int)('V'-'A');
        if(cha[n]>0)
        {
            ans[5]=cha[n];
            cha[(int)('F'-'A')]-=cha[n];
            cha[(int)('I'-'A')]-=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //3
        n=(int)('R'-'A');
        if(cha[n]>0)
        {
            ans[3]=cha[n];
            cha[(int)('T'-'A')]-=cha[n];
            cha[(int)('H'-'A')]-=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //2
        n=(int)('T'-'A');
        if(cha[n]>0)
        {
            ans[2]=cha[n];
            cha[(int)('W'-'A')]-=cha[n];
            cha[(int)('O'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //9
        n=(int)('I'-'A');
        if(cha[n]>0)
        {
            ans[9]=cha[n];
            cha[(int)('N'-'A')]-=2*cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        //1
        n=(int)('O'-'A');
        if(cha[n]>0)
        {
            ans[1]=cha[n];
            cha[(int)('N'-'A')]-=cha[n];
            cha[(int)('E'-'A')]-=cha[n];
            cha[n]=0;
        }
        
        
        cout<<"Case #"<<_<<": ";
        for(int i=0;i<10;++i)
            if(ans[i]){
                for(int j=0;j<ans[i];++j)
                    cout<<(char)('0'+i);
            }
        cout<<endl;
    }
    return 0;
}