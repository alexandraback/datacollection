#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;


struct Pr
{
    long num;
    int type;

    Pr(long n, int t) : num(n), type(t) {}
    Pr(const Pr & p0)
    {
        num = p0.num;
        type = p0.type;
    }
};


struct State
{
    int na_main;
    int nb_main;
    long na_offset;
    long nb_offset;
    long current_sum;
    
    State(int nam, int nbm, int nao, int nbo, int s)
    : na_main(nam), nb_main(nbm), na_offset(nao), nb_offset(nbo), current_sum(s)
    {}
    State(const State & s0)
    {
        na_main = s0.na_main;
        nb_main = s0.nb_main;
        na_offset = s0.na_offset;
        nb_offset = s0.nb_offset;
        current_sum = s0.current_sum;
    }
};


long render(int len_a, int len_b, const deque< Pr > & line_a, const deque< Pr > & line_b)
{
    long nmax = 0;
    vector< State > stack;
    stack.push_back(State(0, 0, 0, 0, 0));
    while(stack.size())
    {
        State s = stack.back();
        stack.pop_back();
        if(line_a[s.na_main].type == line_b[s.nb_main].type)
        {
            long xa = line_a[s.na_main].num - s.na_offset;
            long xb = line_b[s.nb_main].num - s.nb_offset;
            long xmin = min(xa, xb);
            s.na_offset += xmin;
            s.nb_offset += xmin;
            if(s.na_offset == line_a[s.na_main].num)
            {
                s.na_main ++;
                s.na_offset = 0;
            }
            if(s.nb_offset == line_b[s.nb_main].num)
            {
                s.nb_main ++;
                s.nb_offset = 0;
            }
            s.current_sum += xmin;
            if(s.na_main == len_a || s.nb_main == len_b)
            {
                nmax = max(nmax, s.current_sum);
            }
            else
            {
                stack.push_back(s);
            }
        }
        else
        {
            State sa(s), sb(s);
            sa.na_main ++;
            sa.na_offset = 0;
            if(sa.na_main == len_a)
            {
                nmax = max(nmax, sa.current_sum);
            }
            else
            {
                stack.push_back(sa);
            }
            sb.nb_main ++;
            sb.nb_offset = 0;
            if(sb.nb_main == len_b)
            {
                nmax = max(nmax, sb.current_sum);
            }
            else
            {
                stack.push_back(sb);
            }
        }
    }
    return nmax;
}


int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        deque< Pr > line_a, line_b;
        int N, M;
        cin >> N >> M;
        for(int i = 0; i < N; i++)
        {
            long a;
            int A;
            cin >> a >> A;
            line_a.push_back(Pr(a, A));
        }
        for(int i = 0; i < M; i++)
        {
            long b;
            int B;
            cin >> b >> B;
            line_b.push_back(Pr(b, B));
        }
        
        cout << "Case #" << k << ": " << render(line_a.size(), line_b.size(), line_a, line_b) << endl;
    }
    return 0;
}



