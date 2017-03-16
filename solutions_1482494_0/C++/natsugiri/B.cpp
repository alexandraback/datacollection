#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


int N, a[1000], b[1000];
int rate[1000];

int main(){
  int T;
  scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d%d", a+i, b+i);

    vector<pair<pair<int, int>, int> >v, w;
    
    for(int i=0; i<N; i++)
      v.push_back(make_pair(make_pair(b[i], a[i]), i));

    sort(v.begin(), v.end());

    memset(rate, 0, sizeof rate);

    int star=0, ans=0;
    for(int i=0; ;){
      if(i<N && v[i].first.first<=star){
	if(rate[v[i].second]<2){
	  star+=2-rate[v[i].second];
	  rate[v[i].second]++;
	  ans++;
	}
	i++;
      }else{
	int j;
	for(j=N-1; j>=0; j--){
	  if(v[j].first.second<=star && rate[v[j].second]==0){
	    star++;
	    rate[v[j].second]++;
	    ans++;
	    break;
	  }
	}
	if(j<0)break;
      }
    }
    
    printf("Case #%d: ", tc);
    if(star==2*N)printf("%d\n", ans);
    else puts("Too Bad");
  }
  return 0;
}
