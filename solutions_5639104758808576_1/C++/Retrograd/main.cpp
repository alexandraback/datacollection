#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
typedef int var;

ifstream fin("debug.in");
ofstream fout("debug.out");

char str[100000];

int main() {

    var t;
    fin>>t;

    for(var tt=1; tt<=t; tt++) {
        var n, cur_no = 0, add = 0;
        fin>>n;
        fin>>str;

        for(var i=0; i<=n; i++) {
            if(cur_no < i) {
                add += i - cur_no;
                cur_no = i;
            }
            cur_no += str[i] - '0';
        }

        fout<<"Case #"<<tt<<": "<<add<<'\n';
    }

    return 0;
}
