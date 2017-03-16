#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#include <fstream>
//#include <iostream>
using namespace std;

ifstream cin("/users/naginahas/Downloads/GCJ2015round1B/A-Large.in");
ofstream cout("/users/naginahas/Documents/Codeforces205/GCJ2015Round1BProbA/Asmallout.txt");





//special case if number ends with a 0; subtract 1 and do the work;AAAAAAAAAARGH

long long f(long long pw,long long j){//ozz and j have the same number of digits, j is not 0 terminated
    long long ozz = 1;
    for(int i=1;i<=pw;i++){
        ozz*= 10LL;
    }
    ostringstream oss;
    oss << j;
    long long best = j-ozz;
    string s = oss.str();
    //cout << "s= " <<  s << endl;
    
    string zzz = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    for(int i=1;i<=s.size();i++){
        string s2 = s.substr(0,i);
        
        //cout << "s2 = " <<s2 << endl;
        string zzz2 = zzz.substr(0,s.size()-i);
        
        if(zzz2.size() !=0) zzz2[zzz2.size()-1] = '1';
        
        string s3 = s2 + zzz2;
        //cout << "s3 = " << s3 << endl;
        reverse(s2.begin(),s2.end());
        istringstream iss2(s2);
        istringstream iss3(s3);
        
        long long x;
        iss2 >> x;
        long long y;
        iss3 >> y;
        y = j -y;
        best = min(best,x+y+1);
        
    }
    return best;
}

int main2(){
    for(int i=0;i<100;i++){
        long long x, y;
        cin >> x >> y;
        cout << f(x,y);
    }
    return 0;
}

int main(){
    int T;
    cin >> T;
    long long reach[100];
    long long creach[100];
    long long q = 1;
    for(long long i = 0;i<16;i++){
        
        reach[i] = f(i,q*10-1);
        q = q*10;
        if(i==0) creach[i] =  1;
        else creach[i] = creach[i-1]+reach[i-1]+1;
        
        
    }
    
    
    for(int t=0;t<T;t++){
        long long x;
        cin >> x;
        long long inc = 0;
        if(x%10 == 0){
            x--;
            inc++;
        }
        ostringstream xss;
        xss << x;
        long long pw = 1;
        for(int i=0;i<17;i++){
            if (i+1==xss.str().size()) break;
            pw=pw*10LL;
        }
        long long ans = f(xss.str().size()-1,x);
        ans = ans + creach[xss.str().size()-1];
        
        cout << "Case #" << t+1 << ": " << ans+inc << endl;
    }
    return 0;
}
