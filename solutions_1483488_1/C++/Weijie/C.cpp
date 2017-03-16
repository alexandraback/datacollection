#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

char str[100];
set<string> m_set;

string change(string s,int x){
    string ret = s;
    for(int i = 0;i + x < s.length();++i)
        ret[i] = s[i + x];
    for(int i = 0;i < x;++i)
        ret[s.length() - x + i] = s[i];
    //cout << x << " changing: " << s << " to " << ret << endl;
    if(ret[0] == '0')
        return "";
    return ret;
}

long long calc(int num,int up){
    m_set.clear();
    int ret = 0;
    sprintf(str,"%d",num);
    string s = string(str);
    sprintf(str,"%d",up);
    string ups = string(str);
    for(int i = 1;i < s.length();++i){
        string a = change(s,i);
        if(a.length() == s.length() && a > s && a <= ups){
            if(m_set.find(a) == m_set.end()){
                ++ret;
                m_set.insert(a);    
            }
        }
    }
    return ret;
}

int main()
{
    ifstream fin("test.in");
    ofstream fout("ans.out");
    int T;
    fin >> T;        
    for(int i = 1;i <= T;++i){
        int a,b;
        fin >> a >> b;
        long long ans = 0;
        for(int i = a;i < b;++i)
            ans += calc(i,b);
        fout << "Case #" << i << ": " << ans << endl;
    }
    system("pause");
    return 0;    
}
