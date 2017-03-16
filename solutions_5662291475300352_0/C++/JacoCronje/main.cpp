#include <bits/stdc++.h>

using namespace std;

struct SHike
{
    double p;
    double spd;
    SHike(double _p, double _spd) : p(_p), spd(_spd) {}
};
vector<double> spds;
vector<SHike> hike;
int ans;
#define EPS 0.000000000001
void rec(double p, double spd, int enc)
{
    if (enc>=ans) return;
    double ETA = (360.0 - p) / spd;
   // cerr << p << " " << ETA << endl;
    double T = ETA;
    bool benc = false;
    int bcnt = 0;
    vector<double> tenc;
    for (int i=0;i<hike.size();i++)
    {
        double sdiff = (spd - hike[i].spd);
        if (fabs(sdiff)<EPS)
        {
            if (fabs(hike[i].p - p)<EPS)
            {
               // benc = true;
                return;
            }
            continue;
        }
//        double t = (hike[i].p - p) / (sdiff);
//        if (t>0 && t<ETA)
//        {
//            if (t<T) T = t;
//            benc = true;
//        }
        double t = fmod(hike[i].p - p, 360.0) / (sdiff);
        double t2 = fmod(hike[i].p+360.0 - p, 360.0) / (sdiff);
        if (t<0)
            t = fmod(hike[i].p+360.0, 360.0) - p / (sdiff);
        if (t>0 && t2>0)
            t = min(t,t2);
      //  cerr << "h" << i << " " << hike[i].p << " " << hike[i].spd << " = " << t << endl;
        if (t>=0 && t<=ETA)
        {
            if (t<T) T = t;
            tenc.push_back(t);
            benc = true;
        }
    }
    if (benc)
    {
        for (int i=0;i<tenc.size();i++)
            if (fabs(tenc[i]-T)<EPS)
                enc++;
    }

    if (T<=EPS || p>=360.0)
    {
        if (enc<ans) ans = enc;
        return;
    }

    vector<SHike> hk = hike;
    for (int i=0;i<hike.size();i++)
    {
        hike[i].p = hike[i].p + hike[i].spd * T;
        hike[i].p = fmod(hike[i].p, 360.0);
    }
    for (int j=0;j<spds.size();j++)
    {
        rec(p + spd * T, spds[j], enc);
    }

    hike = hk;
}

int main(int argc,char *argv[])
{
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        int N;
        cin >> N;
        hike.clear();
        spds.clear();
        for (int j=0;j<N;j++)
        {
            int D, H, M;
            cin >> D >> H >> M;
            for (int i=0;i<H;i++)
            {
                hike.push_back(SHike(D, 360.0 / (M-i)));
                spds.push_back(360.0 / (M-i));
                spds.push_back(180.0 / (M-i));
                spds.push_back(0.95*360.0 / (M-i));
                spds.push_back(0.9*360.0 / (M-i));
                spds.push_back(0.99*360.0 / (M-i));
            }
        }
        sort(spds.begin(), spds.end());
        int ii = spds.size();
        for (int i=0;i<ii-1;i++)
            spds.push_back((spds[i]+spds[i+1])*0.5);
        sort(spds.begin(), spds.end());
        ans = 1<<30;
        for (int i=0;i<spds.size();i++)
        {
          //  cerr << i << ":" << spds[i] << endl;
            rec(0, spds[i], 0);
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }

  return 0;
}
