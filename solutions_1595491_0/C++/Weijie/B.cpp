#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int getmax(int x){
    int ret = 0;
    int a = x / 3;
    ret = max(ret,a);
    x -= a;
    a = x / 2;
    ret = max(ret,a);
    a = x - a;
    ret = max(ret,a);
    return ret;    
}

int main()
{
    ifstream fin("test.in");
    ofstream fout("ans.out");
    int T;
    fin >> T;        
    for(int i = 1;i <= T;++i){
        int n,s,p;
        fin >> n >> s >> p;
        int ans = 0;
        int can = 0;
        for(int i = 1;i <= n;++i){
            int t;
            fin >> t;
            int temp = getmax(t);
            if(temp >= p)
                ++ans;
            else if(temp == p - 1 && (t % 3 == 2 || t % 3 == 0) && t != 0)
                ++can;
        }
        fout << "Case #" << i << ": " << ans + min(can,s) << endl;

    }
    system("pause");
    return 0;    
}
