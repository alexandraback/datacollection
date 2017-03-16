#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include<string.h>
#define MAX 3050
using namespace std;


int main()
{
      ifstream cin ("output.out");
      ofstream cout ("output.txt");
    int t,r=1;
      cin>>t;
      while(t--)
      {
            cout<<"Case #"<<r++<<": ";
            string s;
            int n;
            cin>>s>>n;
            int l=s.length();
            int ans=0;
            for(int i=0;i<l;i++)
            {
                  int cur=0,pos=0;
                  for(int j=i;j<l;j++)
                  {
                        if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u')
                        pos=0;
                        else
                        pos++;
                        cur=max(cur,pos);
                        if(cur>=n)
                        ans++;
                  }
            }
            cout<<ans<<endl;            
      }
      return 0;
}
