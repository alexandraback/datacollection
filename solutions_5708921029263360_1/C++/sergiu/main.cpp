#include <fstream>
#include <vector>

using namespace std;

struct OUTFIT
{
    int j, p, s;
    OUTFIT(int jj, int pp, int ss)
    {
        this->j = jj;
        this->p = pp;
        this->s = ss;
    }
};

int times_left_js[11][11];
int times_left_ps[11][11];
vector<OUTFIT> outfits;

void fill_times_left(int j, int p, int s, int k)
{
    for (int i = 1; i <= j; i++)
        for (int l = 1; l <= s; l++)
            times_left_js[i][l] = k;
    for (int i = 1; i <= p; i++)
        for (int l = 1; l <= s; l++)
            times_left_ps[i][l] = k;
}

void solve(int j, int p, int s, int k)
{
    fill_times_left(j, p, s, k);
    int jp = 0;
    int ps = 0;
    int ij, ip, is;
    int lastp = 1, lasts = 1;
    int oldp, olds;
    outfits.clear();
    for (ij = 1; ij <= j; ij++)
    {
        oldp = lastp - 1;
        for (ip = oldp + 1; ip <= p; ip++)
        {
            jp = 0;
            olds = lasts - 1;
            for (is = olds + 1; is <= s; is++)
            {
                if (times_left_js[ij][is] > 0 && times_left_ps[ip][is] > 0)
                {
                    jp++;
                    if (jp > k)
                        break;
                    times_left_js[ij][is]--;
                    times_left_ps[ip][is]--;
                    outfits.push_back(OUTFIT(ij, ip, is));
                    lastp = ip;
                    lasts = is;
                }
            }
            if (jp > k)
                continue;
            for (is = 1; is <= olds; is++)
            {
                if (times_left_js[ij][is] > 0 && times_left_ps[ip][is] > 0)
                {
                    jp++;
                    if (jp > k)
                        break;
                    times_left_js[ij][is]--;
                    times_left_ps[ip][is]--;
                    outfits.push_back(OUTFIT(ij, ip, is));
                    lastp = ip;
                    lasts = is;
                }
            }
        }
        for (ip = 1; ip <= oldp; ip++)
        {
            jp = 0;
            olds = lasts - 1;
            for (is = olds + 1; is <= s; is++)
            {
                if (times_left_js[ij][is] > 0 && times_left_ps[ip][is] > 0)
                {
                    jp++;
                    if (jp > k)
                        break;
                    times_left_js[ij][is]--;
                    times_left_ps[ip][is]--;
                    outfits.push_back(OUTFIT(ij, ip, is));
                    lastp = ip;
                    lasts = is;
                }
            }
            if (jp > k)
                continue;
            for (is = 1; is <= olds; is++)
            {
                if (times_left_js[ij][is] > 0 && times_left_ps[ip][is] > 0)
                {
                    jp++;
                    if (jp > k)
                        break;
                    times_left_js[ij][is]--;
                    times_left_ps[ip][is]--;
                    outfits.push_back(OUTFIT(ij, ip, is));
                    lastp = ip;
                    lasts = is;
                }
            }
        }
    }
}

int main()
{
    int t, ii;
    int j, p, s, k;
    int i;
    ifstream f("fashion.in");
    ofstream g("fashion.out");
    f >> t;
    for (ii = 1; ii <= t; ii++)
    {
        f >> j >> p >> s >> k;
        solve(j, p, s, k);
        g << "Case #" << ii << ": " << outfits.size() << '\n';
        for (i = 0; i < outfits.size(); i++)
            g << outfits[i].j << " " << outfits[i].p << " " << outfits[i].s << '\n';
    }
    f.close();
    g.close();
    return 0;
}
