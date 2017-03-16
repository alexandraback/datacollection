// Template By Fendy Kosnatha (Seraph)
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
int arr[40];
int main()
{
    int count=1;
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>arr[i];
        map<int, int> m;
        int sampe=1;
        for (int i=0;i<n;i++) sampe*=2;
        vector<int> a1,a2;
        int ada=0;
        for (int i=0;i<sampe;i++)
        {
            int temp=0;
            for (int j=0;j<n;j++)
                if ((i&(1<<j))>0) temp+=arr[j];
            m[temp]++;
            if (m[temp]==2)
            {
                for (int j=0;j<n;j++)
                    if ((i&(1<<j))>0) a1.push_back(arr[j]);
                ada=temp;break;
            }
            //cout<<temp<<endl;
        }
        cout<<"Case #"<<count++<<":"<<endl;
        if (ada>0)
        {
            for (int i=0;i<sampe;i++)
            {
                int temp=0;
                for (int j=0;j<n;j++)
                    if ((i&(1<<j))>0) temp+=arr[j];
                //m[temp]++;
                if (m[temp]==2)
                {
                    for (int j=0;j<n;j++)
                        if ((i&(1<<j))>0) a2.push_back(arr[j]);
                    break;
                }
            }
            sort(a1.begin(), a1.end());
            sort(a2.begin(), a2.end());
            for (int i=0;i<a1.size();i++)
            {
                for (int j=0;j<a2.size();j++)
                {
                    if (a1[i]==a2[j]){a1[i]=0;a2[j]=0;break;}
                }
            }
            int ad=0;
            for (int i=0;i<a1.size();i++)
            {
                if (a1[i]>0)
                {
                    if (ad>0) cout<<" "; 
                    cout<<a1[i];
                    ad=1;
                }
            }
            ad=0;
            cout<<endl;
            for (int i=0;i<a2.size();i++)
            {
                if (a2[i]>0)
                {
                    if (ad>0) cout<<" ";  
                    cout<<a2[i];
                    ad=1;
                }
            }
            cout<<endl;
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
