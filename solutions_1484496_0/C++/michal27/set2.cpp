#include <cstdio>
#include <vector>
using namespace std;

int D[4000047];

int main()
{
  int t1;
  scanf("%d ",&t1);
  for(int i1=1; i1<=t1; i1++)
  {
    bool mam=false;
    int n;
    scanf("%d ",&n);
    vector<int> A; A.resize(n);
    for(int i=0; i<n; i++) scanf("%d ",&A[i]);
    for(int i=1; i<(1<<n); i++)
    {
      vector<int> B;
      vector<int> C;
      int suma=0;
      for(int j=0; j<n; j++)
      {
	if(i&(1<<j)) {suma+=A[j]; C.push_back(A[j]);}
	else B.push_back(A[j]);
      }
      for(int j=0; j<=suma; j++) D[j]=-1;
      D[0]=-2;
      for(int k=0; k<B.size(); k++){
      for(int j=suma; j>=0; j--)
      {
	if(D[j]!=-1 && j+B[k]<=suma && D[j+B[k]]==-1) D[j+B[k]]=j;
      }
      }
      if(D[suma]!=-1 && !mam)
      {
	int p=suma;
	vector<int> V;
	while(p!=0)
	{
	  V.push_back(p-D[p]);
	  p=D[p];
	}
	//printf("!\n");
	printf("Case #%d:\n",i1);
	printf("%d",C[0]);
	//printf("!\n");
	for(int k=1; k<C.size(); k++) printf(" %d",C[k]);
	printf("\n");
	//printf("!\n");
	printf("%d",V[0]);
	for(int k=1; k<V.size(); k++) printf(" %d",V[k]);
	printf("\n");
	mam=true; break;
      }
    }
    if(!mam) {printf("Case #%d: ",i1); printf("Impossible\n");}
  }
return 0;
}