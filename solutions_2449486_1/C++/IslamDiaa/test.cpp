#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int TEST;
int arr[105][105];
int N,M;
int max_row[105],max_col[105];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> TEST;
	for(int T = 1; T <= TEST; ++T)
	{
            bool ans = 1;
            memset(max_row,-1,sizeof max_row);
            memset(max_col,-1,sizeof max_col);
            cin >> N >> M;
            for(int i = 0 ; i < N; ++i)
                    for(int j = 0; j < M; ++j)
                    {
                            cin >> arr[i][j];
                            max_row[i] = max(max_row[i],arr[i][j]);
                            max_col[j] = max(max_col[j],arr[i][j]);
                    }
            
            for(int i = 0 ; i < N; ++i)
                    for(int j = 0; j < M; ++j)
                            if(arr[i][j] != max_row[i] && arr[i][j] != max_col[j])
                                         ans = 0;
            if(ans)
                   printf("Case #%d: YES\n",T);
            else
                   printf("Case #%d: NO\n",T);
	}
    return 0;
}
