#include<bits/stdc++.h>
#define int long long
 using namespace std;

 int c[7],usd[7],i,zn,ans[7],ch[7],n,M,m,t,tt;
 int a[7][7],FLAG,ttt;

 void dfs(int v)
 {
     usd[v] = zn;
      c[v] = 1;
      for(int i=1;i<=n;++i)
         if(a[v][i])
         {
             if(c[i]==1 && usd[i]==zn)
             {
                 ttt=1;
                 return;
             }
             if(usd[i]<zn)
             {
                 dfs(i);
                 if(ttt) return;
             }
         }
      c[v] = 2;
 }

 int get(int v)
 {
     if(v==1) return 1;
     if(ch[v] == zn) return ans[v];
     ch[v] = zn;
      ans[v] = 0;
      for(int i=1;i<=n;++i)
        if(a[i][v]) ans[v]+=get(i);
        //cout<<v<<endl;
        return ans[v];
 }

  void f(int i,int j)
  {
      if(j==M)
      {
          j = 1;
          ++i;
          if(i == M)
          {

              ++zn;
            ttt = 0;
            for(i=1;i<=n;++i)
                if(usd[i] < zn){
                dfs(i);
                if(ttt) return;
                }

               if(get(n) == m)
               {
                   cout<<"POSSIBLE\n";
                   for(i=1;i<=n;++i)
                   {
                       for(j=1;j<=n;++j) cout<<a[i][j];
                       cout<<endl;
                   }
                   FLAG = 1;
                   return;
               }
            return;
          }
      }
      f(i,j+1);
      if(FLAG) return;
      if(i!=j && !a[j][i])
      {
          a[i][j] = 1;
          f(i,j+1);
          if(FLAG) return;
          a[i][j] = 0;
      }

  }

  //int
  main()
  {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

      cin>>t;
       for(tt=1;tt<=t;++tt)
       {
           cout<<"Case #"<<tt<<": ";
            cin>>n>>m;
            M = n + 1;
            memset(a,0,sizeof(a));
            FLAG = 0;
            f(1,1);
            if(!FLAG) cout<<"IMPOSSIBLE\n";
       }

    return 0;
  }
