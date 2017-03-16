#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define uint unsigned int

int c,d,n;
vector<int> v;
vector<int> u;


bool fn(int x,int a[])
{
    if(x==0)return true;
    if(x<0) return false;
    bool ret=false;

    for(int i=0;(i<v.size())&&!ret;i++)
    {
        if(a[i]<c)
        {
            a[i]++;
            ret= ret|fn((x-v[i]),a);
            a[i]--;
        }
    }

    
return ret;
}


inline void func()
{
    int temp;
    cin>>c>>d>>n;
    for(int i=0;i<d;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    int a[30]={0};
    for(int i=1;i<=n;i++)
    {
        if(!fn(i,a))
        {
        
            v.push_back(i);
        }
    }
    
   
    cout<< v.size() - d <<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int tc=0;tc<T;tc++)
    {
        cout<<"Case #"<<tc+1<<": ";
        v.clear();
        u.clear();
        func();
    }
}
