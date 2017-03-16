#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

static const string _q = "B";

long get_dif(vector<int> & C_v, vector<int> & J_v)
{
    long dif = 0;
    long mult = 1;

    for (int i = C_v.size()-1; i >= 0; i--)
    {
        dif += (C_v[i] - J_v[i]) * mult;
        mult *= 10;
    }

    if (dif < 0) dif = -dif;
    return dif;
}

struct part_sol
{
    int depth;
    long C;
    long J;
    long dif;
};

long pow_10(int p)
{
    long ret = 1;
    for (int i = 0; i < p; i++)
    {
        ret *= 10;
    }
    return ret;
}

int N;

bool operator < (part_sol p1, part_sol p2)
{
    long p1_dif = p1.dif;
    long p2_dif = p2.dif;

    if (p1.depth < N)
    {
        if (pow_10(p1.depth) - p1_dif < p1_dif) p1_dif = pow_10(p1.depth) - p1_dif;
    }

    if (p2.depth < N)
    {
        if (pow_10(p2.depth) - p2_dif < p2_dif) p2_dif = pow_10(p2.depth) - p2_dif;
    }

    if (p1_dif == p2_dif)
    {
        if (p1.C == p2.C)
        {
            if (p1.J == p2.J)
            {
                return p1.depth < p2.depth;
            }
            return p1.J > p2.J;
        }
        return p1.C > p2.C;
    }

    //cout << "p1_dif: " << p1_dif << ", p2_dif: " << p2_dif << endl;

    return p1_dif > p2_dif;
}

void solve()
{
    string C, J;

    cin >> C >> J;

    priority_queue<part_sol> pq;
    part_sol p;
    p.depth = 0;
    p.C = 0;
    p.J = 0;
    p.dif = 0;

    N = C.size();

    long ans1, ans2 = 0;

    pq.push(p);
    while(!pq.empty())
    {
        p = pq.top(); pq.pop();
        //cout << "C: " << p.C << " J: " << p.J << endl;

        if (p.depth == C.size())
        {
            ans1 = p.C; ans2 = p.J;
            break;
        }

        int depth = p.depth;
        part_sol p2 = p;
        p2.depth = depth+1;

        if (C[N - depth - 1] == '?' && J[N - depth - 1] == '?')
        {
            p2.C = p.C;
            p2.J = p.J;
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            p2.C = p.C;         
            p2.J = p.J + pow_10(depth);
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            p2.C = p.C + pow_10(depth);         
            p2.J = p.J;
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);  
            p2.C = p.C;         
            p2.J = p.J + pow_10(depth) * 9;
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            p2.C = p.C + pow_10(depth) * 9;         
            p2.J = p.J;
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);     
        }

        if (C[N - depth - 1] == '?' && J[N - depth - 1] != '?')
        {
            if (J[N - depth - 1] != '0')
            {
            p2.C = p.C + pow_10(depth) * ( J[N - depth - 1] - '0' - 1);         
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            }
           
            p2.C = p.C + pow_10(depth) * (9);         
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            
            p2.C = p.C + pow_10(depth) * ( J[N - depth - 1] - '0'); 
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            if (J[N - depth - 1] != '9')
            {
            p2.C = p.C + pow_10(depth) * ( J[N - depth - 1] - '0' + 1);
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            }
          
            p2.C = p.C + pow_10(depth) * (0);
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);

        }   
    
        if (C[N - depth - 1] != '?' && J[N - depth - 1] == '?')
        {
            if (C[N - depth - 1] != '0')
            {
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');
            p2.J = p.J + pow_10(depth) * ( C[N - depth - 1] - '0' - 1);
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            }
        
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');
            p2.J = p.J + pow_10(depth) * (9);
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');
            p2.J = p.J + pow_10(depth) * ( C[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            if (C[N - depth - 1] != '9')
            {
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');  
            p2.J = p.J + pow_10(depth) * ( C[N - depth - 1] - '0' + 1);
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            }
        
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');  
            p2.J = p.J + pow_10(depth) * (0);
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
            
        }  

        if (C[N - depth - 1] != '?' && J[N - depth - 1] != '?')
        {
            p2.C = p.C + pow_10(depth) * ( C[N - depth - 1] - '0');
            p2.J = p.J + pow_10(depth) * ( J[N - depth - 1] - '0');
            p2.dif = abs(p2.J - p2.C);
            pq.push(p2);
        }
    }

    vector<int> op1(C.size(), 0);
    vector<int> op2(J.size(), 0);

    for (int i = 0; i < C.size(); i++)
    {
        op1[i] = ans1 / pow_10(C.size() - i - 1);
        ans1 %= pow_10(C.size() - i - 1);
        op2[i] = ans2 / pow_10(J.size() - i - 1);
        ans2 %= pow_10(C.size() - i - 1);
    }

    for (int i = 0; i < op1.size(); i++) cout << char(op1[i] + '0');
    cout << " ";
    for (int i = 0; i < op2.size(); i++) cout << char(op2[i] + '0');  

}

int main(void)
{
    ifstream in(_q + ".in");
    ofstream out(_q + ".out");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
