#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numnoremove(int a, const int* begin, const int* end)
{
    int resp = 0;
    for(const int* p=begin;p!=end;++p)
    {
        if(a > *p)
        {
            a += *p;
        }
        else
        {
            while(a <= *p)
            {
                a += a-1;
                ++resp;
            }
            
            a += *p;
        }
    }
    
    return resp;
}

int calc(int a, const vector<int>& motes)
{
    if (a == 1)
    {
        return motes.size();
    }
    
    int resp = motes.size();
    for(int i=0;i<=motes.size();++i)
    {
        resp = min(resp, i + numnoremove(a, &motes[0], &motes[motes.size() - i]));
    }
    
    return resp;
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int a, n;
        cin >> a >> n;
        vector<int> motes(n);
        for(int& x : motes)
        {
            cin >> x;
        }
        
        sort(motes.begin(), motes.end());
        auto resp = calc(a, motes);
        cout << "Case #" << lp << ": " << resp << "\n";
    }
    
    return 0;
}