#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int a,b,c,k;
        cin>>a>>b>>c>>k;
        cout<<"Case #"<<tc<<": ";
        int arr1[11][11]={0},arr2[11][11]={0},arr3[11][11]={0};
        vector<int>v,v1,v2;
        for(int f=0;f<a;f++)
        {
            for(int f1=0;f1<b;f1++)
            {
                for(int f2=0;f2<c;f2++)
                {
                    if(arr1[f][f1]<k&&arr2[f1][f2]<k&&arr3[f][f2]<k)
                    {
                        v.push_back(f+1);
                        v1.push_back(f1+1);
                        v2.push_back(f2+1);
                        arr1[f][f1]++;
                        arr2[f1][f2]++;
                        arr3[f][f2]++;
                    }
                }
            }
        }
        cout<<v.size()<<endl;
        for(int f=0;f<v.size();f++)
            cout<<v[f]<<" "<<v1[f]<<" "<<v2[f]<<endl;
    }
    return 0;
}
