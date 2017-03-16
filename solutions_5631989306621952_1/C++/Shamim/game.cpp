#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ans.txt","w",stdout);

    int test, kase = 1;
    cin>>test;
    char word[1001];
    while ( test--) {
        cin>>word;
        int len = strlen(word);
        string ans="";
        ans = ans + word[0];
        //cout<<ans<<endl;
        int i;
        for (i=1; i<len; i++)
            if ( word[i]>= ans[0])
                ans = word[i] + ans;
            else
                ans = ans + word[i];
        pf("Case #%d: ", kase++);
        cout<<ans<<endl;
    }
    return 0;
}
