# include <string> 
# include <vector> 
# include <iostream> 
# include <sstream> 
# include <cstdio> 
# include <cstdlib> 
# include <cmath> 
# include <cctype> 
# include <cstring> 
# include <map> 
# include <queue> 
# include <deque> 
# include <set> 
# include <algorithm> 
# include <utility> 
# include <functional> 
# include <stack> 
# include <bitset> 
# include <complex> 
# include <cassert> 
# include <ctime> 
# include <list> 
# include <valarray> 
#include <unordered_set>
using namespace std;

vector<string> first, second;
int N;
 
void work()
{
    int maxi = 0;
    for(int comb = 0; comb < (1 << N); comb++)
    {
        unordered_set<string> ff;
        unordered_set<string> ss;
        
        for(int i = 0; i < N; i++)
        {
            if(((1 << i) & comb) != 0)
            {
                ff.emplace(first[i]);
                ss.emplace(second[i]);
            }
        }
        
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            if(((1 << i) & comb) == 0)
            {
                count++;
                
                if(ff.find(first[i]) == ff.end()  || ss.find(second[i]) == ss.end())
                {
                    count = -100;
                    break;
                }
            }
        }
        
        maxi = max(count, maxi);
    }
    
    cout << maxi << endl;
}

int main()
{
	int T;
    cin >> T;
    
    for(int i = 1; i <= T; i++)
    {
        cin >> N;
        first = vector<string>();
        second = vector<string>();
        
        for(int i = 0; i < N; i++)
        {
            string a, b;
            cin >> a >> b;
            first.push_back(a);
            second.push_back(b);
            
        }
        cout << "Case #" << i << ": "; 
        work();
    }
	return 0;
}

