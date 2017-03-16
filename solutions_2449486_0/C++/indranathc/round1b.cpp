#include <iostream>
#include <string>
#include <map>

using namespace std;

class Lawn
{
public:
    int n,m;
    int **_v;

    Lawn(istream& is)
    {
        is >> n >> m;
        _v = new int*[n];
        for (int i=0; i<n; ++i)
        {
            _v[i]=new int[m];
            for (int j=0; j<m; ++j)
            {
                is >> _v[i][j];
                //cout << _v[i][j] << " ";
            }
            //cout << endl;
        }
    }
    
    ~Lawn()
    {
        for(int i=0; i<n; ++i) 
        {
            delete[] _v[i];
        }
        delete[] _v;
    }
    
    bool possibleone(int u, int v)
    {
        bool lhigh = false;
        for (int i=0; i<u; ++i) {
            if (_v[i][v]>_v[u][v]) {
                lhigh = true;
                break;
            }
        }
        bool rhigh = false;
        for (int i=u+1; i<n; ++i) {
            if (_v[i][v]>_v[u][v]) {
                rhigh = true;
                break;
            }
        }
        bool uhigh = false;
        for (int j=0; j<v; ++j) {
            if (_v[u][j]>_v[u][v]) {
                uhigh = true;
                break;
            }
        }
        bool dhigh = false;
        for (int j=v+1; j<m; ++j) {
            if (_v[u][j]>_v[u][v]) {
                dhigh = true;
                break;
            }
        }
        
        if ( (lhigh || rhigh) && (uhigh || dhigh) )
            return false;
        return true;
    }
    
    bool possible()
    {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!possibleone(i,j))
                    return false;
            }
        }
        return true;
    }
};

void readfile(istream& is)
{
    int num_tests;
    is >> num_tests;
    for (int i=1; i<=num_tests; ++i)
    {
        Lawn l(is);
        cout << "Case #" << i << ": " << (l.possible()?"YES":"NO") << endl;
    }
}

int main()
{
    readfile(cin);
    return 0;
}
