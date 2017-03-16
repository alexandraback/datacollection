#include<bits/stdc++.h>
#define pb push_back
 using namespace std;

 string S[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
 int pos[] = {0,2,6,8,7,5,4,1,3,9};
 vector<int> ans;
 string s;
 int cnt[100],t,t_,tt,i,j,n,jj;

  int main()
  {

//      freopen("output.txt","w",stdout);

    cin>>t;
     for(t_=1;t_<=t;++t_)
     {
        cin>>s;
         memset(cnt,0,sizeof(cnt));
         ans.clear();
         n = (int)s.size();

          for(i=0;i<n;++i)
                ++cnt[s[i]-'A'];

          i=0;
          while(i<10)
          {
            tt = 1;
            for(j=0;j<(int)S[pos[i]].size();++j)
            if(cnt[S[pos[i]][j]-'A']==0)
            {
             tt=0;
             for(jj=0;jj<j;++jj)
                ++cnt[S[pos[i]][jj]-'A'];
             break;
            } else --cnt[S[pos[i]][j]-'A'];
            if(tt){
            ans.pb(pos[i]);
            } else ++i;
          }

          cout<<"Case #"<<t_<<": ";
          sort(ans.begin(),ans.end());
          for(i=0;i<(int)ans.size();++i) cout<<ans[i];
          cout<<endl;

     }

  }
