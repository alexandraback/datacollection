#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<iostream>
#include<sstream>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

bool Valid(vector<string> cars, vector<int> orders)
{
    string bigStr=cars[orders[0]];
    int i;
    for(i=1;i<orders.size();i++)
        bigStr += cars[ orders[i] ];
    //cout<<bigStr<<endl;
    bool flagged[26];
    fill(flagged, flagged+26, false);
    for(i=0;i<bigStr.size();i++)
    {
        if ( flagged[bigStr[i] - 'a'])
            return false;
        flagged[ bigStr[i] - 'a' ] = true;
        i++;
        while ( i< bigStr.size() && bigStr[i] == bigStr[i-1] )
            i++;
        i--;
    }
    return true;
}

int main()
{
    //freopen("sample.txt","r",stdin);
    freopen("B.in","r",stdin);
    freopen("ans.txt","w",stdout);
    int t;
    cin>>t;
    int kase = 1;
    while ( t--)
    {
        pf("Case #%d: ",kase++);
        int n;
        cin>>n;
        vector<string> cars;
        cars.clear();
        int i;
        for(i=0;i<n;i++)
        {
            char word[1001];
            cin>>word;
            cars.pb(word);
        }
        //sort(cars.begin(),cars.end());
        vector<int> orders;
        for(i=0;i<n;i++)
            orders.pb(i);
        long long counter = 0;
            do
            {
                if ( Valid(cars, orders))
                    counter++;
            }while( next_permutation(orders.begin(),orders.end() ) );
        counter = counter % 1000000007;
        cout<<counter<<endl;
    }
return 0;
}
