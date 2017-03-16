#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <sys/time.h>

using namespace std;

int keys[256];
int keysNeed[256];
int keysHave[256];
struct SChest
{
    int ktype;
    vector<int> ky;
    char used;
};
vector<SChest> chest;

vector<int> order;
vector<int> border;
bool solved;

int N;

double get_time()
{
    int              i;
    struct timeval   tp;
    struct timezone  tzp;

    i = gettimeofday(&tp,&tzp);
    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}
double dstart;
int same[256][256];
int got[256][256];
int selfi[256];
char *cache;

void rec(int p, int bits)
{
    if (solved) return;
    if (p==order.size())
    {
        border = order;
        solved = true;
        return;
    }

    char notry[256] = {0};
    for (int c=0;c<N;c++) if (!chest[c].used)
    {
        int ktype = chest[c].ktype;
        if (keys[ktype]>0 && notry[c]==0)
        {
            keys[ktype]--;
            keysNeed[ktype]--;
            chest[c].used = 1;
            bits = bits + (1<<c);
            for (int j=0;j<chest[c].ky.size();j++)
            {
                keys[chest[c].ky[j]]++;
            }
            order[p] = c;
            for (int cc=c+1;cc<N;cc++)
                if (same[c][cc]) notry[cc] = 1;

            if (cache[bits]==0)
                rec(p+1, bits);

            if (solved) return;
            cache[bits] = 1;
            bits = bits - (1<<c);
            for (int j=0;j<chest[c].ky.size();j++)
            {
                keys[chest[c].ky[j]]--;
            }
            chest[c].used = 0;
            keys[ktype]++;
            keysNeed[ktype]++;
        }
    }

}

void solve()
{
    cache = new char[(1<<20)+1];
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        int K;
        cin >> K >> N;
        memset(keys, 0, sizeof(keys));
        memset(selfi, 0, sizeof(selfi));
        memset(keysNeed, 0, sizeof(keysNeed));
        memset(keysHave, 0, sizeof(keysHave));
         memset(got, 0, sizeof(got));
         memset(cache, 0, (1<<20)+1);
       // memset(same, 0, sizeof(same));
        //cerr << "case " << t << endl;
        for (int i=0;i<K;i++)
        {
            int kk;
            cin >> kk;
            keys[kk]++;
            keysHave[kk]++;
     //       cerr << kk << " ";
        }
       // cerr << endl;
        chest.resize(N);
        for (int i=0;i<N;i++)
        {
            chest[i].used = 0;
            cin >> chest[i].ktype;
            keysNeed[chest[i].ktype]++;
           // cerr << chest[i].ktype << " : ";
            int nky;
            cin >> nky;
            chest[i].ky.resize(nky);
            for (int j=0;j<nky;j++)
            {
                cin >> chest[i].ky[j];
           //     cerr << chest[i].ky[j] << " ";
//                keysHave[chest[i].ky[j]]++;
            }
         //   cerr << endl;
            sort(chest[i].ky.begin(), chest[i].ky.end());
        }
        solved = false;
        order.resize(N);

        for (int i=0;i<N;i++)
        {
            vector<int> nw;
            for (int j=0;j<chest[i].ky.size();j++)
            {
                if (keysNeed[chest[i].ky[j]]>0)
                {
                    nw.push_back(chest[i].ky[j]);
                    keysHave[chest[i].ky[j]]++;
                    got[i][chest[i].ky[j]]++;
                    if (chest[i].ky[j]==chest[i].ktype) selfi[i] = 1;
                }

            }
            chest[i].ky = nw;
        }

        for (int i=0;i<N;i++)
            for (int j=i+1;j<N;j++)
            {
                same[i][j] = 0;
                same[j][i] = 0;
                if (chest[i].ktype==chest[j].ktype)
                {
                    if (chest[i].ky.size()==chest[j].ky.size())
                    {
                        bool bsame = true;
                        for (int z=0;z<chest[i].ky.size();z++)
                            if (chest[i].ky[z]!=chest[j].ky[z])
                            {
                                bsame = false;
                                break;
                            }
                        if (bsame)
                        {
                            same[i][j] = 1;
                            same[j][i] = 1;
                        }
                    }
                }
            }
        bool bImp = false;
        for (int i=0;i<256;i++)
        {
            if (keysNeed[i]>keysHave[i])
            {
                bImp = true;
                break;
            }
        }
        dstart = get_time();

        if (!bImp) rec(0, 0);

        if (solved)
        {
            cout << "Case #" << (t+1) << ": " << (border[0]+1);
            for (int i=1;i<N;i++)
            {
                cout << " " << (border[i]+1);
            }
            cout << endl;
        } else
        {
            cout << "Case #" << (t+1) << ": IMPOSSIBLE" << endl;
        }
    }
}


int main(int argc,char *argv[])
{
  solve();

  return 0;
}
