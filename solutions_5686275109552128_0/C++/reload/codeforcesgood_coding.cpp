#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}
long long int a[105],d,t;
int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        cin>>t;

        for (int i = 0; i < t; ++i)
        {
            cin>>d;

            for (int j= 0; j<d; ++j)
            {
                cin>>a[j];
            }
            long long int ans=0,fans=100000;
            for (int j = 1; j <=9; ++j)
            {
                queue< int > q;
                for (int k= 0; k<d ; ++k)
                {
                    q.push(a[k]);
                }
                ans=0;
                while(!q.empty())
                {
                    int x=q.front();
                    q.pop();
                    if(x>j)
                    {
                        q.push(x/2);
                        q.push((x+1)/2);
                        ans++;
                    }
                }
                fans=min(fans,ans+j);
            }
            cout<<"Case #"<<i+1<<": "<<fans<<endl;
        }

}
  


