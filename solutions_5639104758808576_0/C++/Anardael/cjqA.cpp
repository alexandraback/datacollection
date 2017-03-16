#include <fstream>
#include <string>
using namespace std;

int main(){
    int t;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>t;
    for (int tests=0;tests<t;tests++)
    {
        int smax=0;
        f>>smax;
        string s;
        f>>s;
        int count=0;
        int ans=0;
        for(int i=0;i<=smax;i++)
        {
            if(count<i){ans+=i-count;count+=i-count;}
            count+=s[i]-'0';
        }
        w<<"Case #"<<(tests+1)<<": "<<ans<<endl;
    }
    f.close();
    w.close();


    return 0;
}

