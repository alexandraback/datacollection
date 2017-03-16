#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10000 + 10;
int len,x;
int sum[maxn];
int mul[10][10];
void prepare(){
	mul[1][1] = 1; mul[1][2] = 2; mul[1][3] = 3; mul[1][4] =4;
	mul[2][1] = 2; mul[2][2] = -1; mul[2][3] = 4; mul[2][4] = -3;
	mul[3][1] = 3; mul[3][2] = -4; mul[3][3] = -1; mul[3][4] = 2;
	mul[4][1] = 4; mul[4][2] = 3; mul[4][3] = -2; mul[4][4] = -1;
}
inline int h(char c){
	if (c == '1') return 1;
	else if (c == 'i') return 2;
	else if (c == 'j') return 3;
	else if (c == 'k') return 4;
}
inline int calc(int x,int y){
	int ret;
	if (x == 0){
		ret = -sum[y];
	}else{
		ret = mul[abs(sum[x - 1])][abs(sum[y])];
		if (sum[x - 1] * sum[y] < 0) ret = -ret;
	}
	return -1 * ret;
}
int main()
{

	freopen("c.in","r",stdin); 
	freopen("c.out","w",stdout);
	int T; cin>>T; prepare();
	for (int ii = 1;ii <= T;ii++){
		string A,B;
		scanf("%d%d",&len,&x); cin >> A; B = A;
		for (int i = 1;i < x;i++) A += B;
		len *= x; int flag = 0; string tt;
		sum[0] = h(A[0]);
		for (int i = 1;i < len;i++){
			sum[i] = mul[abs(sum[i - 1])][h(A[i])];
			if (sum[i - 1] < 0) sum[i] = -sum[i];
		}
		for (int i = 0;i < len - 2;i++){
			if (flag) break; 
			int t1 = calc(0,i);
			if (abs(t1) != 2) continue; 
			for (int j = i + 1;j < len - 1;j++){
				int t2 = calc(i + 1,j); if (abs(t2) != 3) continue;
				int t3 = calc(j + 1,len - 1); if (abs(t3) != 4) continue;
				if (t1 * t2 * t3 > 0){
					flag = 1; break;
				}
			}
		}
		cout<<"Case #"<<ii<<": ";
		if (flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
	return 0;
}
