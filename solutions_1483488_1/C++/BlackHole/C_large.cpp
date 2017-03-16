#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string Int2String(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}

int String2Int(string str)
{
   stringstream ss;
   int n;
   ss << str;
   ss >> n;
   return n;
}

int main () {
    int T,case_id;
    int A,B,xy,yx,len,i,j,count,uniq[10],u_c,u_m;
    string num1,num2;
    freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
    cin >> T;
    for (case_id=1;case_id<=T;case_id++) {
        cin >> A >> B;
        cout << "Case #" << case_id << ": ";
        count=0;
        for (xy=A;xy<=B;xy++) {
            num1=Int2String(xy);
            len=num1.size();
            u_c=0;
            for (i=1;i<=len-1;i++) {
                num2=num1.substr (len-i,i);
                num2+=num1.substr (0,len-i);
                yx=String2Int(num2);
                if ( num2[0]!='0' && xy<yx && yx>=A && yx<=B ) {
                    u_m=1;
                    for (j=0;j<u_c;j++) {
                        if (uniq[j]==yx) u_m=0;
                    }
                    if (u_m==1) {
                        uniq[u_c]=yx;
                        u_c++;
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
