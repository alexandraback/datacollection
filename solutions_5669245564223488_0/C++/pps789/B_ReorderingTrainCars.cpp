#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;

char trains[111][111];

typedef long long ll;
const ll MOD = 1000000007;

int n;
int len[111];

ll fac[111];
ll mult_two[111];

bool must_connected[111][2];

// return <ret, must_connect>
pair<ll,int> query(char x){
	//bool visited[111]={false,};
	pair<ll,int> ret;
	int all=0, left=0, right=0, mid=0;

	for(int i=0; i<n; i++){
		bool all_x = true;
		bool only_left = true;
		bool only_right = true;
		bool only_mid = true;
		bool occured = false;

		// if occured?
		for(int j=0; j<len[i]; j++)
			if(trains[i][j] == x)
				occured = true;

		if(occured){
			// if all_x?
			int j;
			for(j=0; j<len[i]; j++)
				if(trains[i][j] != x)
					all_x = false;

			// if only_left?
			if(!all_x){
				j=0;
				while(j<len[i] && trains[i][j] == x) j++;

				if(j){
					for(;j<len[i];j++)
						if(trains[i][j] == x)
							only_left = false;
				}
				else only_left = false;

				// if only_right?
				if(!only_left){
					j=len[i]-1;
					for(;j>=0;j--)
						if(trains[i][j] != x) break;

					if(j<len[i]-1){
						for(;j>=0;j--)
							if(trains[i][j] == x)
								only_right = false;
					}

					// if valid_mid?
					if(!only_right){
						int l=0, r=len[i]-1;

						while(trains[i][l] != x && l<len[i]) l++;
						while(trains[i][r] != x && r>=0) r--;

						for(j=l; j<=r; j++)
							if(trains[i][j] != x)
								only_mid = false;

						if(!only_mid)
							return make_pair(-1, 0);
					}
				}
			}
		}

		if(occured){
			if(all_x) all++;
			else if(only_left){
				left++;
				if(must_connected[i][0])
					return make_pair(-1, 0);
				must_connected[i][0] = true;
			}
			else if(only_right) right++;
			else if(only_mid) mid++;
		}
	}

	if(left > 1 || right > 1)
		return make_pair(-1, 0);

	if(mid && (all || left || right))
		return make_pair(-1, 0);

	if(mid > 1)
		return make_pair(-1, 0);

	ret = make_pair(1, 0);

	if(left+right+mid+all == 0)
		return ret;

	if(mid) return ret;

	ret.second = all+left+right-1;

	ret.first *= fac[all];

	return ret;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("small.txt","w",stdout);


	fac[0] = 1;
	for(int i=1; i<=105; i++)
		fac[i] = (fac[i-1] * i)%MOD;

	mult_two[0] = 1;
	for(int i=1; i<=105; i++)
		mult_two[i] = (mult_two[i-1]*2)%MOD;

	int T;
	scanf("%d",&T);
	for(int tc=1; tc<=T; tc++){
		printf("Case #%d: ", tc);
		for(int i=0; i<111; i++)
			for(int j=0; j<2; j++)
				must_connected[i][j] = false;

		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%s", trains[i]);
		for(int i=0; i<n; i++)
			len[i] = strlen(trains[i]);

		bool isPossible = true;

		ll ans = 1;
		int connected = 0;

		for(char c = 'a'; c<='z'; c++){
			pair<ll, int> now = query(c);
			//printf("Queery : %c, %lld\n", c,  now.first);

			if(now.first < 0){
				isPossible = false; break;
			}

			ans *= now.first;
			ans %= MOD;
			connected += now.second;
			
		}

		int left = n-connected;
		ans *= fac[left];
		ans %= MOD;
		
		if(isPossible && left)
			printf("%lld\n", ans);
		else printf("0\n");
	}
}