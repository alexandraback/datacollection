// adijimmy
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
vector<int> vec;
int check[5][5];
void pre(){
 check[1][1] = 1;
 check[1][2] = 2;
 check[1][3] = 3;
 check[1][4] = 4;

 check[2][1] = 2;
 check[2][2] = -1;
 check[2][3] = 4;
 check[2][4] = -3;

 check[3][1] = 3;
 check[3][2] = -4;
 check[3][3] = -1;
 check[3][4] = 2;

 check[4][1] = 4;
 check[4][2] = 3;
 check[4][3] = -2;
 check[4][4] = -1;
}
int dp[10005][10005];
int main(){
 pre();
 freopen("C-small-attempt1.in","r",stdin);
 freopen("ans.txt","w",stdout);
 int t;
 ll L,X;
 string p,s;
 scanf("%d",&t);
 for(int cas=1;cas<=t;cas++){
	printf("Case #%d: ",cas);
	scanf("%lld %lld",&L,&X);
   cin >> p;
   s = "";
   for(int i=0;i<X;i++) s += p;
   int n = L*X;
   vec.clear();
   for(int i=0;i<n;i++){
		if(s[i] == '1'){
			dp[i][i] = 1;
		   vec.push_back(1);
		}
		else if(s[i] == 'i'){
			dp[i][i] = 2;
		   vec.push_back(2);
		}
		else if(s[i] == 'j'){
			dp[i][i] = 3;
		   vec.push_back(3);
		}
		else if(s[i] == 'k'){
			dp[i][i] = 4;
		   vec.push_back(4);
		}
   }
   for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x = dp[i][j-1];
			int y = vec[j];
			if(x<0){
				x = abs(x);
				dp[i][j] = (-1)*check[x][y];
			}else{
			  dp[i][j] = check[x][y];
			}
		}
   }
   bool flag = false;
   for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			if(dp[0][i]==2 && dp[i+1][j]==3 && dp[j+1][n-1]==4){
				flag = true;
				break;
			}
		}
   }
   if(flag) puts("YES");
   else puts("NO");
 }
 return 0;
}
