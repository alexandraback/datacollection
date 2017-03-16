#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

int main(){
  int i,j,k,l,m,n,o,p,t;
  int ok;
  vector<pair<int,int> > ZIP;
  map<pair<int,int>,int> spoj;
  stack<int> mam;
  
  scanf("%d",&t);
  
  for(l=1;l<=t;l++){
    scanf("%d",&n);
    scanf("%d",&m);
    
    ZIP.clear();
    ZIP.resize(n);
    
    for(i=0;i<n;i++){
      scanf("%d",&p);
      ZIP[i]=mp(p,i);
    }
    
    spoj.clear();
    
    for(i=0;i<m;i++){
      scanf("%d",&o);
      scanf("%d",&p);
      o--;p--;
      //spoj[o].push_back(p);
      //spoj[p].push_back(o);
      spoj[mp(o,p)]=1;
      spoj[mp(p,o)]=1;
    }
    
    sort(ZIP.begin(),ZIP.end());
    
    do{
      while(mam.size()>0){
	mam.pop();
      }
      /*printf("Trying:\n");
      for(i=0;i<ZIP.size();i++){
	printf("%d %d\n",ZIP[i].ff,ZIP[i].ss);
      }putchar('\n');*/
      
      ok=1;
      mam.push(ZIP[0].ss);
      for(i=1;i<n;i++){
	ok=0;
	while(mam.size()>0){
	  k=mam.top();
	  if(spoj.find(mp(ZIP[i].ss,k))!=spoj.end()){
	    ok=1;
	    break;
	  }
	  mam.pop();
	}
	mam.push(ZIP[i].ss);
	if(!ok){
	  break;
	}
      }
      if(ok){
	break;
      }
    }while(next_permutation(ZIP.begin(),ZIP.end()));
    
    printf("Case #%d: ",l);
    
    for(i=0;i<ZIP.size();i++){
      printf("%d",ZIP[i].ff);
    }putchar('\n');
    
  }
  
  return 0;
}
