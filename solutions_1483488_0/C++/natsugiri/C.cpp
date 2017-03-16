#include<cstdio>
#include<set>
using namespace std;


int A, B;

int main(){
  int T;
  scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    scanf("%d%d", &A, &B);

    int ans=0;
    int y=1;
    for(; y<=B; y*=10);
    
    for(int i=A; i<B; i++){
      set<int>se;

      for(int x=10; x<=i; x*=10){
	int h=i/x+i%x*(y/x);
	if(i<h && h<=B)se.insert(h);
      }
      ans+=se.size();
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
