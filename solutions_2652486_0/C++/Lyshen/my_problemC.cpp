#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> p[220];

int d[220][3], in = 0;
int a[10];

bool is(int l,int K)
{
        int len = p[l].size();

        for (int j = 0; j < K; j++)
        {
                bool flag = false;
                for (int i = 0; i < len; i++)
                        if (a[j] == p[l][i])
                        {
                                flag = true;
                                break;
                        }
                if (!flag) return false;
        }
        return true;
}


void init()
{

        for (int i = 2; i <= 5; ++i)
                for (int j = i; j <= 5; j++)
                        for (int k = j; k <= 5; k++)
                        {
                               d[in][0] = i;
                               d[in][1] = j;
                               d[in][2] = k;
                               in++;
                              // cout << i << " " << j << " " << k << endl;
                        }
        for (int l = 0; l < in; ++l)
        {
                for (int i = 0; i < (1 << 3); i++)
                {
                        int t = 1;
                        for (int j = 0; j < 3; j++)
                                if (i & (1 << j))
                                        t *= d[l][j];
                        p[l].push_back(t);
                }
        }
}



int main()
{

      ifstream cin("C-small-1-attempt0.in");
     ofstream cout("cc.txt");


        int T;
        cin >> T;
        init();
        for(int tt=1; tt<=T; tt++)
        {
                int R, N, M, K;
                cout << "Case #" << tt << ":"<< endl;
                cin >> R >> N >> M >> K;
                for (int i = 0; i < R; ++i)
                {
                        for (int j = 0; j < K; j++)
                        {
                                cin >> a[j];
                        }
                        for (int l = 0; l < in; ++l)
                        {
                                if (is(l,K))
                                {
                                        cout << d[l][0] << d[l][1] << d[l][2] << endl;
                                        break;
                                }
                        }
                }

        }
        return 0;
}
