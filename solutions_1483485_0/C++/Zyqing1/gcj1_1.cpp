#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<char,char> mp;
string data1[3]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",\
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",\
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string data2[3]={"our language is impossible to understand",\
                "there are twenty six factorial possibilities",\
                "so it is okay if you want to just give up"};
void init()
{
    bool flag[128];
    memset(flag,false,sizeof(flag));
    for(int i=0;i<3;i++){
        int sz=data1[i].size();
        for(int j=0;j<sz;j++){
            mp[data1[i][j]]=data2[i][j];
            flag[data2[i][j]]=true;
        }
    }
    mp[' ']=' ';
    mp['q']='z';
    mp['z']='q';
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    char ch;
    int t;
    cin>>t;
    init();
    ch=getchar();
    while(ch!='\n') ch=getchar();
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        ch=getchar();
        while(ch!='\n'){
            map<char,char>::iterator tmp;
            tmp=mp.find(ch);
            if(tmp!=mp.end()){
                putchar(tmp->second);
            }
            else{
                putchar(ch);
            }
            ch=getchar();
        }
        putchar(ch);
    }
}
