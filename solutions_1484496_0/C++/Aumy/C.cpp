/**
 *@author A B M Faisal
 */

# include <iostream>
# include <sstream>

# include <vector>
# include <string>
# include <map>
# include <stack>
# include <queue>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>

# include <utility>
# include <assert.h>

# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>

using namespace std;
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
#define S(x) ((x)*(x))
#define I(n)   scanf("%d",&(n))
const double pi = acos(-1.0);
typedef long long LL;

vector<int> arr;
vector<int> result;
map<pair<int,int>,bool > mem;
int N,data[20];
bool dp(int sum,int index)
{
        if ( mem.count(make_pair(sum,index)) ) return mem[make_pair(sum,index)];

        if ( sum == 0 ) {
                return true;
        }
        if ( index >= arr.size() ) return false;

        if ( arr[index] <= sum ) {
                if (dp(sum-arr[index],index+1)) {
                        result.push_back(arr[index]);
                        return mem[make_pair(sum,index)] = true;
                } else if ( dp(sum,index+1) ) {
                        return mem[make_pair(sum,index)] = true;
                }
        }
        return mem[make_pair(sum,index)] = false;
}



void func()
{


        for(int i=1; i<(1<<N)-1; i++) {
                int sum =0 ;
				arr.clear();
				vector<int> another;
                for(int j=0; j<N; j++) {
                        if ( i & (1<<j) ) {
                                sum += data[j];
                                another.push_back(data[j]);
                        } else arr.push_back(data[j]);
                }

                result.clear();
                //mem.clear();

                if ( dp( sum , 0 ) ) {
                        for(int i=0; i<another.size()-1; i++) {
                                cout<<another[i]<<" ";
                        }
                        cout<<another.back()<<endl;

                        for(int i=0; i<result.size()-1; i++) {
                                cout<<result[i]<<" ";
                        }
                        cout<<result.back()<<endl;
                        return;
                }
        }
        cout<<"Impossible"<<endl;
}

int main()
{
        freopen("C-small-attempt0.in","r",stdin);
        freopen("out.txt","w",stdout);

        int T;
        I(T);
        for(int cas=1; cas<=T; cas++) {
                I(N);
                for(int i=0; i<N; i++) {
                        I(data[i]);
                }

                sort(data,data+N);


                printf("Case #%d: \n",cas);
                func();
        }
        return 0;
}
