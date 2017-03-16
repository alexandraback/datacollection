/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define MEM(x,val) memset((x),val,sizeof(x))
#define scan(x) scanf("%d",&(x))
#define scan2(x,y) scanf("%d%d",&(x),&(y))
#define scan3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan4(x,y,z,k) scanf("%d%d%d%d",&(x),&(y),&(z),&(k))
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define fuck(x) cout<<#x<<" - "<<x<<endl
int mk(int& tmp, char C[],int len){
    int cc = 0;
    for(int i = 0; i < len; i++)
    {
        if(C[i] == '?')
        {
            cc = cc * 10 + tmp % 10;
            tmp /= 10;
        }else {
            cc = cc * 10 + C[i] - '0';
        }
    }
    return cc;
}
void get(int& tmp, char C[], int len){
    for(int i = 0; i < len; i++)
    {
        if(C[i] == '?')
        {
            C[i] = tmp % 10 + '0';
            tmp /= 10;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("B-small-attempt2.in","r",stdin);
    //freopen("B-small-attempt2.out","w",stdout);
    char C[222], J[222];
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        scanf("%s%s", C, J);
        int len = strlen(C);
        int num = 0;
        int dif = 0x3f3f3f3f, mic, mij, sol;
        for(int i = 0; i < len; i++){
            if(C[i] == '?') num++;
            if(J[i] == '?') num++;
        }

        int up = 1;
        for(int i=0;i<num;i++) up*=10;
        for(int s = 0; s < up; s++)
        {
            int tmp = s;
            int cc = mk(tmp, C, len);
            int jj = mk(tmp, J, len);
            if(dif > abs(cc-jj)) {
                dif = abs(cc-jj);
                mic = cc, mij = jj;
                sol = s;
            }else if(dif == abs(cc-jj) && cc < mic) {
                mic = cc;
                mij = jj;
                sol = s;
            }else if(dif == abs(cc-jj) && cc == mic && jj < mij) {
                mij = jj;
                sol = s;
            }
        }
        int tmp = sol;
        get(tmp,C,len);
        get(tmp,J,len);
        printf("Case #%d: ", cas++);
        printf("%s %s\n", C, J);
    }
    return 0;
}
