#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

string test(int x, int y)
{
    set<pair<int, int>> ps;
    pair<int, int> currP(0, 0);
    queue<pair<int, int>> cQ;
    cQ.push(currP);
    string result="";
    queue<string> resQ;
    resQ.push(result);        
    string fr = "";
    ps.insert(currP);
    while(true)
    {
        pair<int, int> cp = cQ.front();
        cQ.pop();
        string cr = resQ.front();
        resQ.pop();
        int jump = cr.size()+1;
        if(cp.first == x && cp.second == y)
        {
            fr = cr;
            break;
        }
        {
            pair<int, int> nt = cp;
            nt.second+=jump;
            if(ps.find(nt)==ps.end()){
                ps.insert(nt);
                cQ.push(nt);
                resQ.push(cr+"N");
            }
        }
        {
            pair<int, int> nt = cp;
            nt.second-=jump;
            if(ps.find(nt)==ps.end()){
                ps.insert(nt);
                cQ.push(nt);
                resQ.push(cr+"S");
            }
        }
        {
            pair<int, int> nt = cp;
            nt.first+=jump;
            if(ps.find(nt)==ps.end()){
                ps.insert(nt);
                cQ.push(nt);
                resQ.push(cr+"E");
            }
        }
        {
            pair<int, int> nt = cp;
            nt.first-=jump;
            if(ps.find(nt)==ps.end()){
                ps.insert(nt);
                cQ.push(nt);
                resQ.push(cr+"W");
            }
        }            
    }
    return fr;
}

void main()
{
    vector<string> tmp;
    int T;
    cin >> T;
    for(int TC=0; TC<T; ++TC)
    {
        int x, y;
        cin >> x >> y;
        string fr = test(x, y);
        printf("Case #%d: %s\n", TC+1, fr.c_str());
    }
}