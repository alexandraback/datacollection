//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>


using namespace std;

#define inf 1e8
long long powers[41];

long long gcd(long long a, long long b) {
    if(a<0 || b<0) return -1;
    return b ? gcd(b, a % b) : a;
}



int checkpower(long long a)
{
    for(int i=0;i<41;i++)
    {
        if(powers[i]==a) return i+1;
    }
    return 0;
}

int findans(long long a, long long b)
{
    int c1 = checkpower(b)-1;
    int c2 = -1;
    for(int j=c1;j>=0;j--)
    {
        if(powers[j]<=a)
        {
            c2 = j;
            break;
        }
    }
    return c1-c2;
}

int main()
{
    freopen("/Users/arkanathpathak/Downloads/A-small-attempt001.in","r",stdin);
    freopen("/Users/arkanathpathak/Downloads/A-small-output000","w",stdout);
    cout.precision(15);
    int test;
    cin >> test;
    vector<int> imp;
    int aaaa = 0;
    

    
    powers[0] = 1;
    for(int i=1;i<41;i++) powers[i] = powers[i-1]*2;
    
    
    
    for(int k=0;k<test;k++)
    {
        
        string s;
        cin >> s;
        string s1, s2;
        string delimiter = "/";
        s1 = s.substr(0, s.find(delimiter));
//        cout << s.find(delimiter)<< endl;
//        cout << s;
        s2 = s.substr(s.find(delimiter)+1,s.length()-s.find(delimiter)-1);
        stringstream ss;
        ss << s1;
        long long a,b;
        ss >> a;
        stringstream ss1;
        ss1 << s2;
        ss1 >> b;
//        cout << a << " "<< b << endl;
        long long g = gcd(a, b);
        
        a /= g;
        b /= g;
        int check = 1;
        if(a>b) check = -1;
        
        if(checkpower(b)==0) check = -1;
        
        if(a%2!=1) check = -1;
        
        if(check>0) cout << "Case #"<<k+1<<": "<< findans(a, b)<<endl;
        else cout << "Case #"<<k+1<<": impossible"<<endl;
        
    }
    return 0;
}
