#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
long long int n,a[10001];
long long int min(long long int x,long long int y)
{
    if(x>y) return y;
    return x;
    }
long long int fun(long long int i,long long int s,long long int ans)
{
    if(s==1 ) return n-i;
    if(i==n-1 && s>a[i]) return ans;
    if(i==n-1 && s<a[i]) return ans+1; 
    if(s>a[i]) {return fun(i+1,s+a[i],ans);}
    else {ans+=min(1+fun(i,(2*s)-1,0),n-i);return ans;}
    
    }
int main()
{
    ifstream gh;
    ofstream ghj;
    ghj.open("ans.txt");
    gh.open("1.txt");
    int test,jk=1;
    gh>>test;
    while(test--)
    {
                 long long int s;
                 gh>>s>>n;
                 for(int i=0;i<n;i++)
                 gh>>a[i];
                 sort(a,a+n);
                 long long int i=fun(0,s,0);
                 ghj<<"Case #"<<jk<<": "<<i<<endl; 
                 jk++;   
                 }
    return 0;
}
