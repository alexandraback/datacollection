#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define mp(a,b) make_pair(a,b)
#define xx first
#define yy second
using namespace std;
typedef long long LL;
typedef double db;
char s[2005];
int ne[30];
vector<int>g;
string c[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,N=0;
    cin>>t;
    while(t--){
        scanf("%s",s);
        int n=strlen(s);
        memset(ne,0,sizeof(ne));
        for(int i=0;i<n;i++){
            ne[s[i]-'A']++;
        }
        g.clear();
        int p=ne[25];
        for(int i=0;i<p;i++){//0
            g.push_back(0);
            for(int j=0;j<4;j++){
                ne[c[0][j]-'A']--;
            }
        }
        p=ne['X'-'A'];
        for(int i=0;i<p;i++){//6
            g.push_back(6);
            for(int j=0;j<3;j++){
                ne[c[6][j]-'A']--;
            }
        }
        p=ne['G'-'A'];
        for(int i=0;i<p;i++){//8
            g.push_back(8);
            for(int j=0;j<5;j++){
                ne[c[8][j]-'A']--;
            }
        }
        p=ne['U'-'A'];
        for(int i=0;i<p;i++){//4
            g.push_back(4);
            for(int j=0;j<4;j++){
                ne[c[4][j]-'A']--;
            }
        }
        p=ne['H'-'A'];
        for(int i=0;i<p;i++){//3
            g.push_back(3);
            for(int j=0;j<5;j++){
                ne[c[3][j]-'A']--;
            }
        }
        p=ne['S'-'A'];
        for(int i=0;i<p;i++){//7
            g.push_back(7);
            for(int j=0;j<5;j++){
                ne[c[7][j]-'A']--;
            }
        }
        p=ne['V'-'A'];
        for(int i=0;i<p;i++){//5
            g.push_back(5);
            for(int j=0;j<4;j++){
                ne[c[5][j]-'A']--;
            }
        }
        p=ne['T'-'A'];
        for(int i=0;i<p;i++){//2
            g.push_back(2);
            for(int j=0;j<3;j++){
                ne[c[2][j]-'A']--;
            }
        }
        p=ne['O'-'A'];
        for(int i=0;i<p;i++){//1
            g.push_back(1);
            for(int j=0;j<3;j++){
                ne[c[1][j]-'A']--;
            }
        }
        p=ne['E'-'A'];
        for(int i=0;i<p;i++){//9
            g.push_back(9);
            for(int j=0;j<4;j++){
                ne[c[9][j]-'A']--;
            }
        }
        sort(g.begin(),g.end());
        printf("Case #%d: ",++N);
        for(int v:g){
            printf("%d",v);
        }
        printf("\n");
    }
}