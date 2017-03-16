#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_EL = 823543;

string possibleOutcomes[MAX_EL];
string K, L;

string currentOutcome("Blablablabla");
int it = 0;

void generateOutcomes(int currLetter, int len)
{
    if(currLetter == len)
    {
        possibleOutcomes[it++] = currentOutcome.substr(0, len);
    }
    else
        for(int i=0; i<K.length(); i++)
        {
            currentOutcome[currLetter] = K[i];
            generateOutcomes(currLetter+1, len);
        }
}

void pref(string s, vector <int> &p)
{
        p.resize(s.length());
        int x = 0;
        p[0] = 0;

        for(int i=1; i<s.length(); i++)
        {
            while(x > 0 && s[i] != s[x])
                x = p[x-1];
            x = p[i] = x + (s[i] == s[x]);
        }
}

int countInstances(string w, string s)
{
    vector <int> p;
    string tmp = w+"#"+s;
    pref(tmp, p);

    int res = 0;
    for(int i=0; i<p.size(); i++)
        if(p[i] == w.length())
            res++;

    return res;
}

int main()
{
    cout.unsetf ( ios::floatfield );
    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        int k, l, s;
        cin >> k >> l >> s;
        cin >> K >> L;

        it = 0;
        generateOutcomes(0, s);

        double maxInstances = 0;
        double sumInstances = 0;

        for(int i=0; i<it; i++)
        {
            double tmp = countInstances(L, possibleOutcomes[i]);
            sumInstances += tmp;
            maxInstances = max(maxInstances, tmp);
        }

        std::cout.precision(10);
        cout << "Case #" << t << ": " << (maxInstances-(sumInstances/it)) << "\n";
    }

    return 0;
}
