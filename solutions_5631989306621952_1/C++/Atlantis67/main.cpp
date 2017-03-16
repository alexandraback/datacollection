#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include <limits.h>
#include<cmath>
#include<map>
#include<queue>
#include<set>
using namespace std;

#define N 100005
#define M 100005
#define LL long long

//为自己加油O(∩_∩)O~

const long long  mod =1000000007;

int main()
{
    freopen("1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int t=T;
    while (T--){
        string z;
        cin>>z;
        string s1="",s2="",s="";
        for (int j=0;j<z.size();j++){
            if (s+z[j]>z[j]+s) s=s+z[j];else s=z[j]+s;
        }
        printf("Case #%d: ",t-T);
        cout<<s<<endl;
    }
    return 0;
}








