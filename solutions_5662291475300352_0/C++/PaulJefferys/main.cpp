#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>
#include <queue>


using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");

bool cmp(pair<long long,long long> a, pair<long long,long long> b)
{
    return (a.first<b.first);
}

long long encode(long long x)
{
    return 1000000000000000000LL-x;
}

long long decode(long long x)
{
    return encode(x);
}

int main(void)
{
    int ttt;
    fin >> ttt;
    int ct = 0;
    string s;
    
    cout.precision(9);
    fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
    
    while(ttt>0)
    {
        ct++;
        ttt--;
        
        
        
        int i,j,k,ans;
        
        priority_queue<long long> q;
        
        vector<pair<long long,long long> > ids;
        
        map<long long, int> lookup;
        
        vector<vector<int> > nexts;
        
        vector<int> empt;
        
        nexts.push_back(empt);
        
        int n;
        
        fin >> n;
        
        long long p,r;
        
        for(int a=0; a<n; a++)
        {
            fin >> p >> k >> r;
            for(i=0; i<k; i++)
            {
                ids.push_back(make_pair((360LL-p)*(r+i),360LL*(r+i)));
            }
        }
        
        sort(ids.begin(),ids.end(),cmp);
        
        ans = ids.size()-1;
        
        int passes = 0;
        
        for(k=0; k<ids.size(); k++)
        {
            if(passes>=ans)
                break;
            long long tm  = ids[k].first;
            
           // cout << ans << " " << tm << " " << k << " " << q.size() << " ";
            
//            if(q.size()>0)
//                cout << decode(q.top());
//            cout << endl;
            
            while(q.size()>0 && decode(q.top())<=tm)
            {
                long long a = decode(q.top());
                j = lookup[a];
                for(i=0; i<nexts[j].size(); i++)
                {
                    r = tm + ids[nexts[j][i]].second;
                    int xx = lookup[r];
                    
                    if(xx==0)
                    {
                        q.push(encode(r));
                        
                        int l = nexts.size();
                        lookup[r]=l;
                        nexts.push_back(empt);
                        nexts[l].push_back(nexts[j][i]);
                    }
                    else{
                        nexts[xx].push_back(nexts[j][i]);
                    }
                    passes++;
                }
                q.pop();
            }
            
            r = tm + ids[k].second;
            
            int xx = lookup[r];
            
            if(xx==0)
            {
                q.push(encode(r));
                
                int l = nexts.size();
                lookup[r]=l;
                nexts.push_back(empt);
                nexts[l].push_back(k);
            }
            else{
                nexts[xx].push_back(k);
            }
            
            if(ans > passes + ids.size()-1-k)
                ans = passes+ids.size()-1-k;
        }
        
        ids.clear();
        lookup.clear();
        nexts.clear();
        
        
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        
        
        cout << ans;
        fout << ans;
        
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

