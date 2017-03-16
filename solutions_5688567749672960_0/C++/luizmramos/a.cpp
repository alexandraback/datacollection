#include <stdio.h>
#include <queue>
#include <utility>
#include <set>

std::queue<std::pair<int,int> > q;
std::set<int> visitado;

int reverse(int x) {
	int ans=0;
	while(x>0){
		ans*=10;
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main(){
	int n;
	int testes;
	scanf("%d",&testes);
	for(int xxx=0;xxx<testes;xxx++) {
		visitado.clear();
		scanf("%d",&n);
		q=std::queue<std::pair<int,int> >();
		q.push(std::make_pair(1,1));
		while(!q.empty()){
			std::pair<int,int> no = q.front();
			if(no.first == n) {
				printf("Case #%d: %d\n",xxx+1,no.second);
				break;
			}
			q.pop();
			if(visitado.count(no.first+1) == 0) {
				visitado.insert(no.first+1);
				q.push(std::make_pair(no.first+1,no.second+1));
			}
			int outro = reverse(no.first);
			if(visitado.count(outro) == 0) {
				visitado.insert(outro);
				q.push(std::make_pair(outro,no.second+1));
			}
		}
	}
}