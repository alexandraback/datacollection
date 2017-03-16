#include<cstdio>
#include<vector>


using namespace std;

int main(){
  int T; scanf("%d", &T);
  for (int tc=1; tc<=T; ++tc){
    int N, M; scanf("%d %d", &N, &M);
    vector<vector<int> > a(N,vector<int>(M,0));
    for (int i=0; i<N; ++i)
      for (int j=0; j<M; ++j)
	scanf("%d", &a[i][j]);
    vector<int> row(N,0);
    vector<int> col(M,0);
    for (int i=0; i<N; ++i)
      for (int j=0; j<M; ++j){
	if (a[i][j]>row[i]) row[i]=a[i][j];
	if (a[i][j]>col[j]) col[j]=a[i][j];
      }
    bool ja=true;
    for (int i=0; ja && i<N; ++i)
      for (int j=0; ja && j<M; ++j)
	if (a[i][j]<col[j] && a[i][j]<row[i])
	  ja=false;
    printf("Case #%d: ", tc);
    if (ja)
      printf("YES\n");
    else
      printf("NO\n");
    
	
  }
  return 0;
}
