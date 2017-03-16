#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;
typedef unsigned long long ull;


int main()
{
    int T, N, S, p, score, result, num = 1;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        result = 0;
        cin >> N >> S >> p;
        int max[N][2];
        
        for(int j = 0; j < N; j++)
        {    
            cin >> score;
            max[j][0] = max[j][1] = 0;
            for(int k = 10; k >= 0; k--)
            {
                if( (k+k+k) == score || ( k != 0 && (k+k+k-1) == score )|| ( k != 0 && (k+k-1+k-1) == score) )
                    max[j][0] = max[j][0] > k ? max[j][0] : k;  
                
                if(k > 1)
                {    
                    if( (k+k+k-2) == score || (k+k-1+k-2) == score || (k+k-2+k-2) == score)
                        max[j][1] = max[j][1] > k ? max[j][1] : k;  
                }
            }
            
            //cout << max[j][0] << " " << max[j][1] << endl;
        }
        for(int j = 0; j < N; j++)
        {    
            if(max[j][0] >= p)
                result++;
            else if(max[j][1] >= p && S > 0)
                result++, S--;
        }
        cout << "Case #" << num++ << ": " << result << endl;
    }

    return 0;
}
