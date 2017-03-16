#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int score[10000];

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ifstream cin("jam2.rc");
    ofstream cout("jam2.out");
    int N;    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
            cout << "Case #" << i+1 << ": ";
            
            int n, s, p;
            cin >> n >> s >> p;
            
            for(int j = 0; j < n; j++)
            {
                    cin >> score[j];
            }
            
            sort(score, score + n, cmp);
            
            int ans = 0;
//            cout << n << endl;
            for(int j = 0; j < n; j++)
            {
                    if(score[j] >= 3 * p - 2) ans++;
                    else
                    if(s > 0 && score[j] >= 3 * p - 4 &&  score[j] >= p) 
                    {
                         ans++;
                         s--;
                    }
                    else break;
            }
            
            cout << ans << endl;
    }
    getchar();
}
