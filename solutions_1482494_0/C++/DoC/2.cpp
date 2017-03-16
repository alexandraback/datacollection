#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>


using namespace std;
int main()
{
    int T;
    cin >> T;
    int l1 [1000];
    int l2 [1000];
    bool dl1[1000];
    bool dl2[1000];
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        cerr << "Case " << t+1 << endl;
        for (int i = 0; i < N; i++)
        {
            cin >> l1[i] >> l2[i] ;
            dl1[i] = false;
            dl2[i] = false;
        }
        
        int s = 0;
        int steps = 0;
        while(s < 2*N)
        {
            cerr << "current stars: " <<  s << endl;
            ++steps;
            int n = -1;
            int adds = 0;
            for (int i = 0; i < N; i++)
            {
                if (s >= l2[i] && !dl2[i] && (adds < 2 * !dl1[i] + 1))
                {
                    n = i;
                    adds = 2 * !dl1[i] + 1;
                }
            }
            if (n!=-1)
            {
                dl2[n] = true;
                if(dl1[n])
                {
                    ++s;
                }
                else
                {
                    s+=2;
                }
                cerr << n << endl;
                cerr << "stars: " << 2 << endl;
                
            }
            else
            {
                int dist = 0;
                for (int i = 0; i < N; i++)
                {
                    if (s >= l1[i] && !dl1[i] && !dl2[i] && (dist < l2[i] - l1[i] ))
                    {
                        n=i;
                        dist = l2[i] - l1[i];
                    }
                    
                }
                if(n!=-1)
                {
                    ++s;
                    dl1[n] = true;
                    
                    cerr << n << endl;
                    cerr << "stars: " << 1 << endl;
                }
                else
                {
                    break;
                }
            }
            
        }
        
        cout << "Case #" << t+1 << ": " ;
        if(s==2*N)
        {
            cout << steps << endl;
        }
        else
        {
            cout << "Too Bad" << endl;
        }
    }
    
    return 0;
}
