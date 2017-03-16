#include<iostream>
#include<string>
#include<vector>
using namespace std;

void allSubstr(string sss, int z, vector<string>& ret)
{
    
    for(int i=0; i<sss.length()-z+1; ++i)
    {
        ret.push_back(sss.substr(i, z));
    }
}
bool verifyCCstr(const string& ss, int n)
{
    int cc = 0;
    for(int i=0; i<ss.length(); ++i)
    {
        if(ss[i]=='a' || ss[i]=='e' || ss[i]=='i' || ss[i]=='o' || ss[i]=='u')
        {
            cc = 0;
        }
        else
        {
            ++cc;
            if(cc>=n) return true;
        }
    }
    return false;
}
int verifyCC(const vector<string>& svc, int n)
{
    int tot = 0;
    for(int i=0; i<svc.size(); ++i)
    {
        string s = svc[i];
        if(verifyCCstr(s, n)) ++tot;
    }
    return tot;
}
void main()
{
    vector<string> tmp;
    int T;
    cin >> T;
    for(int TC=0; TC<T; ++TC)
    {
        string sss;
        int n;
        cin >> sss;
        cin >> n;
        int total = 0;
        for(int i=n; i<=sss.length(); ++i)
        {
            tmp.clear();
            allSubstr(sss, i, tmp);
            total += verifyCC(tmp, n);
        }
        printf("Case #%d: %d\n", TC+1, total);
    }
}