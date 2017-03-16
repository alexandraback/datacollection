#include <bits/stdc++.h>

using namespace std;

#define LL long long

int main(int argc,char *argv[])
{
    int T;
    cin >> T;
    LL* dt = new LL[10000001];
    for (int t=0;t<T;t++)
    {
        LL N;
        LL ans = 1;
        cin >> N;

        for (LL i=1;i<=N;i++) dt[i] = (LL)(1)<<62;
        dt[1] = 1;
        for (LL i=1;i<N;i++)
        {
            //cerr << i << " " << dt[i] << endl;
            if (dt[i]+(LL)1 < dt[i+1])
                dt[i+1] = dt[i] + (LL)1;
            stringstream ss2;
            ss2 << i;
            string s = ss2.str();
            reverse(s.begin(), s.end());
            if (s[0]!='0')
            {
                LL NN = 0;
                for (int j=0;j<s.length();j++)
                    NN = NN*(LL)(10) + (LL)(s[j]-'0');
                if (NN>1 && NN<=N)
                {
                    if (dt[i]+(LL)1 < dt[NN]) dt[NN] = dt[i]+(LL)1;
                }
            }
        }
        ans = dt[N];
//        while (N!=1)
//        {
//           // cerr << N << " " << ans << endl;
//            LL d = N%(LL)(10);
//            stringstream ss;
//            ss << N;
//            LL f = ss.str()[0] - '0';
//            if (d==0 || (d==1 && f==1) || ss.str().length()==1)
//            {
//                N--;
//                ans++;
//            } else
//            {
//                while (d>1)
//                {
//                    N--;
//                    ans++;
//                    d--;
//                }
//                if (f!=1)
//                {
//                    stringstream ss2;
//                    ss2 << N;
//                    string s = ss2.str();
//                    reverse(s.begin(), s.end());
//                    N = 0;
//                    for (int i=0;i<s.length();i++)
//                        N = N*(LL)(10) + (LL)(s[i]-'0');
//                    ans++;
//                }
//            }
//        }
        cout << "Case #" << t+1 << ": " << ans << endl;
    }

  return 0;
}
