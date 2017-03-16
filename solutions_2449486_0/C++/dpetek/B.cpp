#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool loan(vector<vector<int> > v, int m)
{
    int dim = max(v.size() , v[0].size());
    for (int h=1;h<=m;++h) {
        vector<vector<int> > copy = v;
        for (int i=0;i<dim;++i) {
            bool ok1 = true, ok2 = true;

            if (i < v.size() && ok1) {
                for (int j=0;j<v[0].size();++j) {
                    if (v[i][j] != h) {ok1 = false;break;}
                }
            } else ok1 = false;

            if (i<v[0].size() && ok2) {
                for (int j=0;j<v.size();++j) {
                    if (v[j][i] != h ) {ok2 = false; break;}
                }
            } else ok2 = false;

            if (ok1) {
                for (int j=0;j<v[0].size();++j) {
                    copy[i][j] = h + 1;
                }
            }

            if (ok2) {
                for (int j=0;j<v.size();++j) {
                    copy[j][i] = h + 1;
                }
            }
        }
        v = copy;
    }

    bool ok = true;
    for (int i=0;i<v.size();++i) {
        for (int j=0;j<v[i].size();++j) {
            if ( v[i][j] != m + 1) return false;
        }
    }
    return true;
}

int main(void)
{
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int t;
    scanf ("%d", &t);
    vector<vector<int> > field;
    for (int _test=1;_test<=t;++_test) {
        int n, m, a, maxy = -1;
        vector<int> tmp;
        field.clear();

        scanf ("%d %d", &n, &m);
        for (int i=0;i<n;++i) {
            tmp.clear();
            for (int j=0;j<m;++j) {
                scanf ("%d", &a);
                maxy = max(maxy, a );
                tmp.push_back(a);
            }
            field.push_back(tmp);
        }
        bool resp = loan(field, maxy);
        printf ("Case #%d: %s\n", _test, resp ? "YES" : "NO");
    }

    return 0;
}
