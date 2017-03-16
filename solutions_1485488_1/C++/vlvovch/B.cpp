#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
int H,N,M;
vector< vector<int> > fl;
vector< vector<int> > ce;
vector< vector<int> > wrk;
vector< vector<double> > tms;

int main()
{
    fstream fin("B-large.in",ifstream::in);
    fstream fout("B-large.out",ofstream::out);
    fin >> T;
    for(int j=1;j<=T;j++)
    {
		cout << j << "\n";
		fin >> H >> N >> M;
		fl.resize(N);
		ce.resize(N);
		tms.resize(N);
		wrk.resize(N);
		rep(i,N)
		{
			fl[i].resize(M);
			ce[i].resize(M);
			tms[i].resize(M);
			wrk[i].resize(M);
			rep(k,M)
			{
				tms[i][k] = 1.e10;
				wrk[i][k] = 0;
			}
		}
		rep(i,N)
			rep(k,M)
				fin >> ce[i][k];
		rep(i,N)
			rep(k,M)
				fin >> fl[i][k];
		tms[0][0] = 0.;
		
		while (1)
		{
			//bool fl = 0;
			int ci = -1, ck = -1;
			rep(i, N)
				rep(k, M)
			{
				if (wrk[i][k]==0 && tms[i][k]<0.9e10)
				{
					if (ci==-1 || tms[i][k]<tms[ci][ck])
					{
						ci = i;
						ck = k;
					}
				}
			}
			if (ci==-1) break;

			wrk[ci][ck] = 1;
			//cout << ci << "\t" << ck << "\t" << tms[ci][ck] << "\n";
			if (ci>0)
			{
				int cni = ci-1;
				int cki = ck;
				if (ce[cni][cki]-fl[cni][cki]>=50 && ce[cni][cki]-fl[ci][ck]>=50 && ce[ci][ck]-fl[cni][cki]>=50)
				{
					double ct = tms[ci][ck];
					double CH = H - ct*10.;
					if (CH<0.) CH = 0.;
					double ct1 = 0., ct2 = 0., minCH = CH;
					if (ce[cni][cki]-max((double)fl[ci][ck],CH)>=50) ct1 = 0.;
					else 
					{
						ct1 = (CH - (ce[cni][cki] - 50.)) / 10.;
						minCH = min(minCH, (ce[cni][cki] - 50.));
					}

					/*if (ce[ci][ck]-max((double)fl[cni][cki],CH)>=50) ct2 = 0.;
					else 
					{
						ct2 = (CH - (ce[ci][ck] - 50.)) / 10.;
						minCH = min(minCH, (ce[ci][ck] - 50.));
					}*/

					if (fabs(ct1)<1e-8 && fabs(ct2)<1e-8 && fabs(ct)<1e-8)
					{
						tms[cni][cki] = 0.;
					}
					else
					{
						if (minCH-fl[ci][ck]>=20.) tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 1.);
						else tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 10.);
					}
				}
			}

			if (ci<N-1)
			{
				int cni = ci+1;
				int cki = ck;
				if (ce[cni][cki]-fl[cni][cki]>=50 && ce[cni][cki]-fl[ci][ck]>=50 && ce[ci][ck]-fl[cni][cki]>=50)
				{
					double ct = tms[ci][ck];
					double CH = H - ct*10.;
					if (CH<0.) CH = 0.;
					double ct1 = 0., ct2 = 0., minCH = CH;
					if (ce[cni][cki]-max((double)fl[ci][ck],CH)>=50) ct1 = 0.;
					else 
					{
						ct1 = (CH - (ce[cni][cki] - 50.)) / 10.;
						minCH = min(minCH, (ce[cni][cki] - 50.));
					}

					/*if (ce[ci][ck]-max((double)fl[cni][cki],CH)>=50) ct2 = 0.;
					else 
					{
						ct2 = (CH - (ce[ci][ck] - 50.)) / 10.;
						minCH = min(minCH, (ce[ci][ck] - 50.));
					}*/

					if (fabs(ct1)<1e-8 && fabs(ct2)<1e-8 && fabs(ct)<1e-8)
					{
						tms[cni][cki] = 0.;
					}
					else
					{
						if (minCH-fl[ci][ck]>=20.) tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 1.);
						else tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 10.);
					}
				}
			}

			if (ck>0)
			{
				int cni = ci;
				int cki = ck-1;
				if (ce[cni][cki]-fl[cni][cki]>=50 && ce[cni][cki]-fl[ci][ck]>=50 && ce[ci][ck]-fl[cni][cki]>=50)
				{
					double ct = tms[ci][ck];
					double CH = H - ct*10.;
					if (CH<0.) CH = 0.;
					double ct1 = 0., ct2 = 0., minCH = CH;
					if (ce[cni][cki]-max((double)fl[ci][ck],CH)>=50) ct1 = 0.;
					else 
					{
						ct1 = (CH - (ce[cni][cki] - 50.)) / 10.;
						minCH = min(minCH, (ce[cni][cki] - 50.));
					}

					/*if (ce[ci][ck]-max((double)fl[cni][cki],CH)>=50) ct2 = 0.;
					else 
					{
						ct2 = (CH - (ce[ci][ck] - 50.)) / 10.;
						minCH = min(minCH, (ce[ci][ck] - 50.));
					}*/

					if (fabs(ct1)<1e-8 && fabs(ct2)<1e-8 && fabs(ct)<1e-8)
					{
						tms[cni][cki] = 0.;
					}
					else
					{
						if (minCH-fl[ci][ck]>=20.) tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 1.);
						else tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 10.);
					}
				}
			}

			if (ck<M-1)
			{
				int cni = ci;
				int cki = ck+1;
				if (ce[cni][cki]-fl[cni][cki]>=50 && ce[cni][cki]-fl[ci][ck]>=50 && ce[ci][ck]-fl[cni][cki]>=50)
				{
					double ct = tms[ci][ck];
					double CH = H - ct*10.;
					if (CH<0.) CH = 0.;
					double ct1 = 0., ct2 = 0., minCH = CH;
					if (ce[cni][cki]-max((double)fl[ci][ck],CH)>=50) ct1 = 0.;
					else 
					{
						ct1 = (CH - (ce[cni][cki] - 50.)) / 10.;
						minCH = min(minCH, (ce[cni][cki] - 50.));
					}

					/*if (ce[ci][ck]-max((double)fl[cni][cki],CH)>=50) ct2 = 0.;
					else 
					{
						ct2 = (CH - (ce[ci][ck] - 50.)) / 10.;
						minCH = min(minCH, (ce[ci][ck] - 50.));
					}*/

					if (fabs(ct1)<1e-8 && fabs(ct2)<1e-8 && fabs(ct)<1e-8)
					{
						tms[cni][cki] = 0.;
					}
					else
					{
						if (minCH-fl[ci][ck]>=20.) tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 1.);
						else tms[cni][cki] = min(tms[cni][cki], ct + max(ct1,ct2) + 10.);
					}
				}
			}

		}

        fout << "Case #" << j << ": " << tms[N-1][M-1] << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC;
    system("PAUSE");
    return 0;
}
