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

int counter[2500+10];

int main()
{

    freopen("B-small-attempt0.in","r",stdin);
    freopen("ans.txt","w",stdout);

    int test;
    int N;
    int kase = 1;
    cin>>test;
    while ( test--) {
        cin>>N;
        int i;
        fill (counter, counter+2500+5,0);
        for (i=0;i<2*N-1;i++) {
            int j;
            for (j=0; j< N;j++) {
                int ht;
                cin>>ht;
                counter[ht]++;
            }
        }
    vector<int> ans;
    ans.clear();

    for (i=1;i<=2500;i++)
        if ( counter[i] > 0 && (counter[i]%2 == 1) )
            ans.pb(i);
    sort (ans.begin(), ans.end());
    pf("Case #%d:", kase++);
    for (i=0; i< ans.size(); i++)
        cout<<" "<<ans[i];
    cout<<endl;

    }
    return 0;
}
