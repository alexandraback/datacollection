#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
#define PI acos(-1.0)
#define eps 1e-9
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
char ti[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                   "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                   "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char ta[3][100]={"our language is impossible to understand",
                 "there are twenty six factorial possibilities",
                 "so it is okay if you want to just give up"};
char hm[200];
char A[200];

void init(){
    int len,mp;
    for(int i=0;i<3;i++){
        len=strlen(ti[i]);
        for(int j=0;j<len;j++)hm[ti[i][j]]=ta[i][j];
    }
    for(int i='a';i<='z';i++){
        mp=0;
        for(int j='a';j<='z';j++)if(hm[j]==i)mp=1;
    }
    hm['q']='z'; hm['z']='q';
}

int main()
{
    int T,len;

    init();

    ifstream cin("A-small-attempt0.txt");
    ofstream cout("output.txt");

    cin>>T;
    cin.getline(A,200,'\n');

    for(int ts=1;ts<=T;ts++){
        cin.getline(A,200,'\n');

        len=strlen(A);
        cout<<"Case #"<<ts<<": ";
        for(int j=0;j<len;j++){
            if(isupper(A[j]))A[j]=tolower(A[j]);

            if(islower(A[j]))cout<<hm[A[j]];
            else cout<<' ';
        }
        cout<<endl;
    }
    cin.close(); cout.close();
    return 0;
}
