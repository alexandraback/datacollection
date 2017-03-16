#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fii(a,b,c) for(int a=b; a<c; a++)


using namespace std;

int nlist, nl , _list[20], __list[20], ans;
string a[20], b[20];

int tcase, n;

int getbit(unsigned int x, int k)
{
    return (x >> k) & 1;
}


bool check() {
    fi(i, 1, nlist) {
        bool co1= 0, co2 = 0;
       // cout <<a[_list[i]]<<' '<<b[_list[i]]<<endl;
        fi(j, 1, nl)
            {
                if (a[_list[i]+1] == a[__list[j]+1]) co1 = 1;
                if (b[_list[i]+1] == b[__list[j]+1]) co2 = 1;
            }
        if (!co1 || !co2) return 0;
    }
    return 1;
}


int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> tcase;
    fi(t, 1, tcase)
    {
        ans = 0;
        cin >> n ;
        fi(i, 1, n) cin >> a[i] >> b[i];

     //  cout <<"xet"<<endl;


        unsigned int last = (1 << n) -1;
        for (unsigned int s = 0; s <= last ; s++) {


            nlist = nl  = 0;
            fii(i, 0, n) if (getbit(s, i)) {
                _list[++nlist] = i;
            } else {
                __list[++nl] = i;
            }
         //   cout <<nlist <<endl;

            if (check()) ans = max(ans, nlist);
        }

        printf("Case #%d: ", t);

        cout <<ans <<endl;
    }
}
