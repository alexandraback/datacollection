#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
 
#define fi first
#define sc second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define ll long long
#define dl double
#define ison(a,b) (a&(1<<b))
#define bitcnt __builtin_popcount
#define MOD 1000000007 
#define INF 1000000000
 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> wadj;


int main(int argc, char const *argv[])
{
//freopen("inp.txt","r",stdin);
 //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        printf("Case #%d: ",x);
        string s;
        cin>>s;
        int fre[200],fre1[10];
        memset(fre,0,sizeof(fre));
        memset(fre1,0,sizeof(fre1));
        for(int i=0;i<s.size();i++)
            fre[s[i]]++;
    string v[10];
    v[0]="ZERO";
    v[1]="ONE";
    v[2]="TWO";
    v[3]="THREE";
    v[4]="FOUR";
    v[5]="FIVE";
    v[6]="SIX";
    v[7]="SEVEN";
    v[8]="EIGHT";
    v[9]="NINE";
    if(fre['Z'])
    {
    fre1[0]=fre['Z'];
    fre['Z']=0;
    fre['E']-=fre1[0];
    fre['R']-=fre1[0];
    fre['O']-=fre1[0];

    }
    if(fre['W'])
    {
        fre1[2]=fre['W'];
    fre['W']=0;
    fre['T']-=fre1[2];
    fre['O']-=fre1[2];
    }
    if(fre['G'])
    {
        fre1[8]=fre['G'];
        fre['G']=0;
    fre['H']-=fre1[8];
    fre['I']-=fre1[8];
    fre['E']-=fre1[8];
    fre['T']-=fre1[8];
    }
    if(fre['H'])
    {
        fre1[3]=fre['H'];
        fre['H']=0;
    fre['T']-=fre1[3];
    fre['R']-=fre1[3];
    fre['E']-=2*fre1[3];
    }
    if(fre['X'])
    {
        fre1[6]=fre['X'];
    fre['X']=0;
    fre['I']-=fre1[6];
    fre['S']-=fre1[6];
    }
    if(fre['U'])
    {
        fre1[4]=fre['U'];
        fre['U']=0;
    fre['O']-=fre1[4];
    fre['R']-=fre1[4];
    fre['F']-=fre1[4];
    }
    if(fre['O'])
    {
          fre1[1]=fre['O'];
    fre['O']=0;
    fre['N']-=fre1[1];
    fre['E']-=fre1[1];
    }
    if(fre['S'])
    {
        fre1[7]=fre['S'];
        fre['S']=0;
        fre['E']-=fre1[7];
        fre['V']-=fre1[7];
        fre['E']-=fre1[7];
        fre['N']-=fre1[7];
    }
    if(fre['V'])
    {
        fre1[5]=fre['V'];
    fre['V']=0;
    fre['I']-=fre1[5];
    fre['F']-=fre1[5];
    fre['E']-=fre1[5];
    }
    if(fre['I'])
    {
        fre1[9]=fre['I'];
    fre['I']=0;
    fre['N']-=2*fre1[9];
    fre['E']-=fre1[9];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<fre1[i];j++)
            printf("%d",i);
    }
    printf("\n");
}
    
    return 0;
}
 