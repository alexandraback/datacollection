#include<bits/stdc++.h>


using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));

vector<string>vs;
void foo(string key,int pos, int s,string tem)
{
    if(pos==s)
    {
       vs.pb(tem);
       return;
    }
    int i=0;
    for(i=0;i<key.size();i++)
    {
      string nu=tem+key[i];
      foo(key,pos+1,s,nu);
    }
    return ;
}
int main()
{
   //ios_base::sync_with_stdio(0);
  freopen("int","r",stdin);
  freopen("out","w",stdout);
  int CASES ;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    vs.clear();
   int i ,j,k,lim,val,l,s;
   double n;
   cin>>k>>l>>s;
   string key,tar;
   cin>>key>>tar;
   foo(key,0,s,"");
   n=vs.size();
   double ans=0,maxi=0;
   vector<double>vd;
   for(k=0;k<n;k++)
   {
    string tem=vs[k];
   // cout <<tem<<" ";
    double te=0;
    for(i=0;i<s;i++)
    {
      j=0;
      int p=i;
      while(tem[i]==tar[j] )
      {
        i++;
        j++;
        if(i==tem.size() || j==tar.size())break;
      }
      if(j==tar.size())te++;
      i=p;
    }
    maxi=max(te,maxi);
    vd.pb(te);
   }
   for(i=0;i<vd.size();i++){
    ans+=(maxi-vd[i]);
    //cout<<vs[i]<<" "<<vd[i]<<"\n";
  }
   printf("Case #%d: ", CASE);
    //cout<<ans<<" "<<n<<" "<<
    cout<<setprecision(9)<<(double)ans/n<<"\n";
  }

  return 0;
}