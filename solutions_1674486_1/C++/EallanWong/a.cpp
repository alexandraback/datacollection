#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 1010
#define datat int
#define ansdatat int

int n;
int tot[maxn];
int mark[maxn][maxn], edge[maxn][maxn], flag[maxn];
int tmm = 0, tfl = 0;

struct tedge
{
	int a,b;
};

tedge ed_info[maxn*maxn];

void init_deal(){
		tmm++;
		memset(tot, 0, sizeof(tot));
}

int main(){
	
	int tttt;
	scanf("%d", &tttt);
	for(int ttt = 1;ttt<=tttt;ttt++){
		printf("Case #%d: ",ttt);
		init_deal();



		int nume = 0;
		scanf("%d", &n);
		for(int i = 1;i<=n;i++){
			int tote;
			scanf("%d", &tote);
			//tot[i] = tote;
			for(int j = 1;j<=tote;j++){
				int a;
				scanf("%d", &a);
				tot[a]++;
				edge[a][tot[a]] = i;
				nume++;
				mark[a][i] = nume;
				ed_info[nume].a = a;
				ed_info[nume].b = i;
			}

		}
//		cout<<"Done!"<<endl;

		bool res = false;
		for (int st = 1; st<=n; st++)
		{
			tfl ++;
			flag[st] = tfl;
			int head = 0, tail = 1;
			int qu[maxn];
			qu[1] = st;
			while(head<tail){
				head++;
				int now = qu[head];
				for(int i = 1;i<=tot[now];i++)
					if(flag[edge[now][i]] != tfl){
						tail++;
						qu[tail] = edge[now][i];
						flag[edge[now][i]] = tfl;
//						cout<<edge[now][i]<<endl;
					}
			}
//			cout<<"Done bfs1!    "<<st<<endl;
			for (int j = 1; j<=nume; j++)
			{

				tfl ++;
				flag[st] = tfl;
				int head1 = 0, tail1 = 1;
				int qu1[maxn];
				qu1[1] = st;
				while(head1<tail1){
					head1++;
					int now1 = qu1[head1];
					//cout<<"extend "<<now1<<endl;
					for(int i = 1;i<=tot[now1];i++)
						if(mark[now1][edge[now1][i]]!=j && 
						   flag[edge[now1][i]] != tfl){
							tail1++;
							qu1[tail1] = edge[now1][i];
							//cout<<"add "<<edge[now1][i];
							flag[edge[now1][i]] = tfl;
						}
				}
				for(int i = 2;i<=tail;i++)
					if(qu[i]>0){
						bool yes = false;
						for(int k = 2;k<=tail1;k++)
						if(qu[i] == qu1[k]){
							yes = true;
							break;
						}
						if(yes){

						}
						else{
							qu[i] = -1;
						}
					}

			}
//			cout<<"Done bfs2!"<<endl;
			for(int i = 2;i<=tail;i++)
				if(qu[i]>0){
					res = true;
					break;
				}
			if(res) break;
		}

		if(res)
			printf("Yes\n");
		else
			printf("No\n");




	}
	

	return 0;
};

