#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int d[110][55];
bool rem[110];
int main(){
   
      freopen("b.in","r",stdin);
      freopen("b.out","w",stdout);
      
   int t,n;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      multiset<int>dans;
      scanf("%d",&n);
      for(int i=0;i<n+n-1;i++)
         for(int j=0;j<n;j++)
            scanf("%d",&d[i][j]); 

      memset(rem,false,sizeof rem);
      for(int i=0;i<n;i++){
         vector<pair<int,int> >a;
         dans.clear();
         for(int j=0;j<n+n-1;j++)if(!rem[j]){
            a.push_back(make_pair(d[j][i],j));
            dans.insert(d[j][i]);
         }
         sort(a.begin(),a.end());

         if(a.size()==1 || a[0].first!=a[1].first){
            int idx=a[0].second;
            for(int j=i+1;j<n;j++)dans.erase(dans.find(d[idx][j]));
            break;
         }
         else{
            rem[a[0].second]=true;
            rem[a[1].second]=true;
         }
      }
      multiset<int>uans;
      memset(rem,false,sizeof rem);
      for(int i=n-1;i>=0;i--){
         vector<pair<int,int> >a;
         uans.clear();
         for(int j=0;j<n+n-1;j++)if(!rem[j]){
            a.push_back(make_pair(d[j][i],j));
            uans.insert(d[j][i]);
         }
         sort(a.begin(),a.end(),greater<pair<int,int> >());

         if(a.size()==1 || a[0].first!=a[1].first){
            int idx=a[0].second;
            for(int j=i;j>=0;j--)uans.erase(uans.find(d[idx][j]));
            break;
         }
         else{
            rem[a[0].second]=true;
            rem[a[1].second]=true;
         }
      }

      multiset<int>::iterator it;
      for(it=uans.begin();it!=uans.end();it++)dans.insert(*it);

      printf("Case #%d:",tt);
      for(it=dans.begin();it!=dans.end();it++)printf(" %d",*it);
      printf("\n");
   }
   return 0;
}
