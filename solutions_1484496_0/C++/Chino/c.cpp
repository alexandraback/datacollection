#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

	
int N;
int numbers[1000];
map<int, vector<int> > m;
map<int, vector<int> >::iterator it;

void differents(vector<int> v, int &a, int &b){
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N;j++){
			if(!(v[i] & v[j])){
				a=v[i];
				b=v[j];
				return;
			}
		}
	}
	a=-1;
	b=-1;
	return;
}

void imprime(int a){
	int first=0;
	//printf("---->%d\n",a);
	for(int i=0; i<N;i++){
		if(a%2){
			if(first){
				printf(" ");
			}else{
				first++;
			}
			printf("%d",numbers[i]);
		}
		a/=2;
	}
	printf("\n");
	//printf("---->%d\n",a);
}

int main(){
	int T,cases;
	int i,j,k;
		
	scanf("%d\n",&T);
	cases = 0;
	while(cases < T){
		scanf("%d\n", &N);
		for(i=0; i<N; i++){
			scanf("%d\n",&numbers[i]);
		}
		
		for(i=1;i<1024*1024; i++){
			int sum=0;
			int d=i;
			for(j=0;j<20;j++){
				if(d%2){
					sum+= numbers[j];
				}
				d/=2;
			}
			m[sum].push_back(i);
		}
		int a=-1,b=-1;
		for(it=m.begin(); it!=m.end()  && a==-1 && b==-1; it++){
			if(it->second.size()>=2){
				//printf("%d\n",it->first);
				//for(i=0;i<it->second.size(); i++){
				//	printf("%d ",it->second[i]);
				//}
				//printf("\n");
				differents(it->second, a, b);

				//printf("%d %d\n",a,b);
			}
		}
		m.clear();
		printf("Case #%d:\n",++cases );
		if(a!=-1){
			imprime(a);
			imprime(b);
		}else{
			printf("Impossible\n");
		}
	}
}
