#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
#include <unordered_map>
#include <set>

using namespace std;
int t,a,b;
vector<char> m;
int ret;
void calc()
{
    m.clear();
    m.resize(10000001,'n');
    ret = 0;
    int n=1,j=a/10;
    while(j>0) {j/=10;n*=10;}
    //cout<<"n="<<n<<endl;
    for(int i=a;i<=b;i++) {
        if(m[i-a]=='y') continue;
        int k=i/10+(i%10)*n;
        int l=0;
        while(k!=i) {
            if(k>=a && k<=b) {
                m[k-a]='y';
                l++;
                //cout<<"k="<<k<<"m="<<m[i-a]<<endl;
            }
            k=k/10+(k%10)*n;
        }
        ret+=l*(l+1)/2;
    }
}
void input()
{
    cin>>a>>b;
}
void output(int ncase)
{
    cout<<"Case #"<<ncase<<":"<<" "<<ret<<endl;
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
