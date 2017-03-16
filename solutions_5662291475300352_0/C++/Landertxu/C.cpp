#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;

int main()
{
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++)
    {
        int N;
        cin >> N;
        VI deg, vel;
        fi (N)
        {
            int pd, pn, pv;
            cin >> pd >> pn >> pv;
            fj (pn)
            {
                deg.push_back(pd);
                vel.push_back(pv + j);
            }
        }
        int ans = 0;
        if (deg.size() == 2 and vel[0] != vel[1])
        {
            if (vel[0] > vel[1])
            {
                swap(vel[0],vel[1]);
                swap(deg[0],deg[1]);
            }
            VD tsal(2);
            fi(2) tsal[i] = vel[i] * (360. - deg[i]) / 360.;
            
            double vel0 = 360. / vel[0];
            double vel1 = 360. / vel[1];
            double dv = vel0 - vel1;
            double tp = 0;
//             cout << vel0 << " " << vel1 << " " << dv << endl;
            if (deg[0] <= deg[1])
            {
                tp = (360 + deg[1] - deg[0]) / dv;
            }
            else
                tp = (deg[1] - deg[0]) / dv;
            
//             cout << tp << " " << tsal[0] << " " << tsal[1] << endl;
            if (tp <= tsal[0] + eps or tp <= tsal[1] + eps)
                ans = 1;
        }
        cout << "Case #" << caso << ": " << ans << endl;
    }
}