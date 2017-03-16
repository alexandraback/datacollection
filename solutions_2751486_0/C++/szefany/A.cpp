#include "iostream"
#include "cstring"
#include "cstdio"
const int N = 3000010;
const int S = 3000010;
using namespace std;
int step[S], next[S][26], prev[S];
int last_node[N], roots[N], length[N], size;
int node_count, root;
void clear(int u) {
    step[u] = prev[u] = 0;
    memset(next[u], 0, sizeof(next[u]));
}

void copy_data(int v, int nv) {
    step[nv] = step[v];
    prev[nv] = prev[v];
    memcpy(next[nv], next[v], sizeof(next[v]));
}

int insert(int x, char key) {
    key = key - 'a';
    int u = ++ size, node;
    clear(u);
    step[u] = step[last_node[x]] + 1;
    for (node = last_node[x]; node && next[node][key] == 0; node = prev[node]) {
        next[node][key] = u;
    }
    if (node == 0) {
        prev[u] = roots[x];
    } else {
        int v = next[node][key];
        if (step[v] == step[node] + 1) {
            prev[u] = v;
        } else {
            int nv = ++ size;
            copy_data(v, nv);
            step[nv] = step[node] + 1;
            prev[u] = prev[v] = nv;
            for (; node && next[node][key] == v; node = prev[node]) {
                next[node][key] = nv;
            }            
        }
    }
    last_node[x] = u;
    length[x] ++;
    int value = length[x] - step[prev[u]];
    return value;
}
void initialise(int n) {
    for (int i = 0; i < n; ++ i) {
        int u = i + 1;
        roots[i] = u;
        last_node[i] = u;
        clear(u);
    }
    memset(length, 0, sizeof(length));
    size = n;
    node_count = 0;
}
int dp[N],l[N];
char s[N];
bool check(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
		return 0;
	}
	return 1;
}
int main(void)
{
	freopen("A-small-attempt0.in","r",stdin);
	int T,len,g=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s%d",s,&len);
		int n=strlen(s);
		dp[0]=0;
		l[0]=-1;
		initialise(1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int tmp=insert(1,s[i-1]);
			if(check(s[i-1])){
				dp[i]=dp[i-1]+1;
				if(dp[i]>=len){
					l[i]=i-len;
				}else{
					l[i]=l[i-1];
				}
			}else{
				dp[i]=0;
				l[i]=l[i-1];
			}
			ans+=min(l[i]+1,tmp+1);
		}
		printf("Case #%d: ",++g);
		cout<<ans<<endl;
	}
	return 0;
}