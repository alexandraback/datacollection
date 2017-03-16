#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool fix(vector<string> *, int);

int main(){

int T, N, i, j, max_length, res;
vector<string> word;
string str;

cin >> T;
for(int caso=1;caso<=T;caso++)
{
    cout << "Case #" << caso << ": ";
    cin >> N;
    word.clear();
    max_length = 0;
    for(i=0;i<N;i++)
    {
        cin >> str;
        max_length = str.size() > max_length ? str.size() : max_length;
        word.push_back(str);
    }

    if( !fix(&word, max_length) )
    {
        cout << "Fegla Won" << endl;
        continue;
    }

    for(res=i=0;i<word[0].size();i++)
    {
        int count = 0;
        for(j=0;j<N;j++)
            if( word[j].at(i) == '-' )
                count++;
        count = N-count < count ? N-count : count;
        res += count;
    }
    cout << res << endl;
}

return 0;
}

bool fix(vector<string> *w, int m)
{
    int i, j, idx, max;
    char c;
    int count[100];
    for(idx=0;idx<m;idx++)
    {
        if( w->at(0).size() <= idx )
            return false;
        c = w->at(0).at(idx);
        for(max=i=0;i<w->size();i++)
        {
            for(j=idx;j < w->at(i).size() && w->at(i).at(j) == c;j++);
            if( j == idx )
                return false;
            count[i] = j-idx;
            max = (j-idx) > max ? (j-idx) : max;
        }
        for(i=0;i<w->size();i++)
        {
            w->at(i).insert(idx+count[i], max-count[i], '-');
            m = w->at(i).size() > m ? w->at(i).size() : m;
        }
        idx += (max-1);
    }

    return true;
}

