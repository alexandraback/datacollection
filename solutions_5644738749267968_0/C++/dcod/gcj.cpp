#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    freopen("file.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int t;
    int cas = 0;
    cin>>t;
    while(t--)
    {
         int n;
         cas++;
         double a;
         vector<double> nao , ken;
         cin>>n;
         for(int i = 0 ; i < n; i++)
         {
             cin>>a;
             nao.push_back(a);
         }
         for(int i = 0 ; i < n; i++)
         {
             cin>>a;
             ken.push_back(a);
         }
         int s1=0,s2=0;
         sort(nao.begin() , nao.end());
         sort(ken.begin() , ken.end());
         int naoe = n-1 , kenb=0 , kene = n-1 , times = n;
         while(times--)
         {
             if(nao[naoe] > ken[kene] )
             {
                 s1++;
                 naoe--;
             }
             kene--;
         }
         for(int i = 0; i < n; i++)
         {
             vector<double>::iterator it = lower_bound(ken.begin() , ken.end() , nao[i]);
             if(it != ken.end())
             {
                 s2++;
                 int idx = it-ken.begin();
                 ken.erase(ken.begin() + idx);
             }
         }
         cout<<"Case #"<<cas<<": "<<s1<<" "<<n-s2<<endl;
    }
}