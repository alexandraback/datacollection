#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void exe();
int main(void)
{	
	int T;	cin >> T;
	for(int caseNum=1; caseNum<=T ; ++caseNum){
		cout << "Case #" << caseNum << ": ";
		exe();	
	}
	return 0;
}

int b, m;
bool p[6][6];
void f(int x){
	if(x==b-1){
		--m; return;
	}
	else{
		for(int i=b-1;i>x;--i){
			if(m>0){
				p[x][i] = true;
				f(i);
			}
		}
	}
	return;
}

void exe()
{
	cin >> b >> m;
	if(m > 1<<(b-2)) cout << "IMPOSSIBLE"<< endl;
	else{
		cout << "POSSIBLE" << endl;
		for(int i=0;i<b;++i)for(int j=0;j<b;++j)p[i][j]=false;
		f(0);
		for(int i=0;i<b;++i){
			for(int j=0;j<b;++j){
				if(p[i][j]) cout << '1';
				else cout <<'0';
			}
			cout << endl;
		}
	}
}
