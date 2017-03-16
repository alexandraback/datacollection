    #include<bits/stdc++.h>
     #define cv adj[v][i].first
     #define cw adj[v][i].second
    #define lol 100000000000000
    typedef long int ll;
    using namespace std;
    vector<pair<int,ll> >adj[100002];
    ll co[100003];
    ll dis[100003];
    ll diss[100003],suc[100003],kak[100003],k,j,up[100003],upver[100003],the[100003];
    long  int dfs(int v)
    {
    co[v]=1;
    //printf("%d gajab\n",v);
    long int i,x=0,k1=0,THE=0;
    for(i=0;i<adj[v].size();i++)
    	{
    	if(co[cv]==0)
    		{
    		upver[cv]=v;
    		up[cv]=up[v]+cw;
    		k=dfs(cv)+cw;
    		if(k>=x){k1=x;x=k;suc[v]=cv;THE=the[cv];}//longest x wale child ka the tumhara the
    		else if(k>k1){k1=k;}
    		}
    		
    	}
    	the[v]=v;
    	dis[v]=diss[v]=x+k1;
    	i=v;
    	kak[v]=k1;
    	//printf(" %lld %lld %lld %lld %lld\n",i,sov[i],suc[i],diss[suc[i]],dis[i]);
    	//printf("              dis[%lld]=%lld   diss[%lld]=%lld x=%lld\n",v,dis[v],v,diss[v],x);
    	
    	
    	//mai my vertex per hu
    	//bete k answer wale node per jao
    	
    	//if(second largest of that node >= up[that node]-up[my]+second largest of my then ok i am copying answer)
    	//if not
    	// up in dfs while(up[the]-up[my]+second largest of mine >diss[the](the=up[the]))
	//edge distribution
	//if(up[the]-up[my]+second of my > diss[suc[the]])    that node is the, and div[v]=diss[the]
	//else
	//suc[the] is that node and dis[v]=sov[the]+    	
    	
    	
    	return x;
    }
    int main()
    {
    int samosa,jb;
    scanf("%d",&samosa);
    jb=samosa;
    while(samosa--)
    {
    int n,m,a,b,i,r,v,j,count=0,k=0;ll c,max=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    adj[i].clear();
     
    for(i=1;i<=n;i++)
    	{
    	scanf("%d",&b);
    	a=i;c=1;
    	adj[a].push_back(make_pair(b,c));
    	adj[b].push_back(make_pair(a,c));
    	}
    for(i=0;i<=n;i++) co[i]=0;
    for(i=0;i<=n;i++) dis[i]=0;
    for(i=0;i<=n;i++) diss[i]=0;
    for(i=0;i<=n;i++) suc[i]=0;
    for(i=0;i<=n;i++) up[i]=0;
    for(i=0;i<=n;i++)upver[i]=0;
    for(i=1;i<=n;i++)
  	  {
  	  if(co[i]==0)m=dfs(i);
     		if(dis[i]>max)max=dis[i];
     	  }
     	 printf("Case #%d: %ld\n",jb-samosa,max+1);
    }
    return 0;
    } 
