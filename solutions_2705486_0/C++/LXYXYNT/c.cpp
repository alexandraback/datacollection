#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int dx[8]={1,0,-1,0,-1,-1,1,1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};
const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

vector<string> dict;
char s[4444];
int f[4444][5];

int main(){
    ifstream fin("dict.txt");
    dict.clear();
    string ss;
    while (fin>>ss) dict.push_back(ss);
    
    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        scanf("%s",s);
        int n=strlen(s);
        memset(f,100,sizeof(f));
        f[0][0]=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<5;++j){
                if (f[i][j]>9999) continue;
                for (int k=0;k<dict.size();++k){
                    if (dict[k].size()+i>n) continue;
                    int ret=0,warn=j;
                    for (int p=0;p<dict[k].size();++p){
                        if (dict[k][p]==s[i+p]){ 
                            warn=max(0,warn-1);                            
                            continue;
                        }
                        if (warn){
                            ret=-99999;
                            break;
                        }
                        ret++;
                        warn=4;
                    }
                    if (ret>-999)
                        f[i+dict[k].size()][warn]=min(f[i+dict[k].size()][warn],f[i][j]+ret);
                }
            }
        int ans=9999999;
        for (int i=0;i<5;++i)
            ans=min(ans,f[n][i]);
        printf("Case #%d: %d\n",++cas,ans);
    }   
    return 0;
}
