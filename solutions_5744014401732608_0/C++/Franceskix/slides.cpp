#include <fstream>
#include <vector>

using namespace std;

int main(){
    int t,b,m;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> t;
    vector<int> v;
    for(int i=0; i<t; i++) {
    v.assign(b,0);
    in >> b >> m;
    out << "Case #" << i+1 << ": ";
    if(m<=(1<<(b-2)))
    {
        out << "POSSIBLE" << endl;
        if(m==(1<<(b-2)))
        {
            out << "0";
            for(int k=1; k<b; k++)
                out << "1";
            out << endl;
        }
        else
        {
        int u = 0;
        while(m>0)
        {
            v[u++]=m%2;
            m/=2;
        }

        for(int k=b-2; k>=0; k--)
            out << v[k];
        out << "0" << endl;
        }
        for(int j=1; j<b; j++) {
            for(int k=0; k<=j; k++)
                out << "0";
            for(int k=j+1; k<b; k++)
                out << "1";
            out << endl;
        }
    }
    else
    {
        out << "IMPOSSIBLE" << endl;
    }
    }
    return 0;
}
