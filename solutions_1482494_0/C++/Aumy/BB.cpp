# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>
# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <utility>
# include <string>
# include <queue>

using namespace std;

# define I(n)   scanf("%d",&(n))
# define read(x) freopen(x,"r",stdin)

int main()
{
	//read("in.txt");
    read("B-small-attempt2.in");
	freopen("B2.out","w",stdout);

	int T,N;
	int A[1001],B[1001];
	I(T);
	for(int cas=1;cas<=T;cas++)
	{
	    I(N);
	    vector<int> state(N,0);
        map<vector<int> , int > dist,point;

	    for(int i=0;i<N;i++)
	    {
	        I(A[i]); I(B[i]);
	    }

	    queue< vector<int> > q;
        dist[state] = 0;
        point[state] =0;
	    q.push(state);
        int ans = -1;

	    while( !q.empty() ){
	        vector<int> top = q.front();
	        q.pop();
	        int step = dist[top];
	        int p = point[top];

            bool f = true;
	        for(int i=0;i<top.size();i++)
	        {
	            if ( top[i] < 2 ) {
	                f=false;
	                break;
	            }
	        }
	        if ( f ){
	            ans = step;
				break;
	        }

	        for(int i=0;i<top.size();i++){
	            if ( top[i] == 2 ) continue;
	            if ( p >= B[i] ){
	                int temp = top[i];
	                top[i] = 2;

                    dist[top] = step + 1;
                    point[top] = p + 2 - temp;
                    q.push( top );

	                top[i] = temp;
	            }
	            if ( top[i] == 0 && p == A[i] ){
	                top[i] = 1;
                    if ( dist.count(top) == 0 ){
                        dist[top] = step + 1;
                        point[top] = p + 1;
                        q.push( top );
	                }
	                top[i] = 0;
	            }
	        }
	    }

		//cout<<ans<<endl;
	    if ( ans == -1 )
            printf("Case #%d: Too Bad\n",cas);
        else printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
