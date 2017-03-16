#include <bits/stdc++.h>

using namespace std;

long long inf = 1e18;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        //CHECK if with or without endline!!!
        printf("Case #%d: ", kras);
        string coders, jammers;
        cin >> coders >> jammers;
        int C = coders.size();

        vector<long long> machten(20, 1);
        for(int i=1; i<20; i++)
        {
            machten[i] = machten[i-1]*10;
        }

        vector<string> biggest_coders(20, ""); //biggest starting at index i
        vector<string> smallest_coders(20, "");

        vector<string> biggest_jammers(20, "");
        vector<string> smallest_jammers(20, "");

        string bc="";
        for(int i=C-1; i>=0; i--)
        {
            if(coders[i] == '?')
            {
                reverse(bc.begin(), bc.end());
                bc += '9';
                reverse(bc.begin(), bc.end());
            }
            else
            {
                reverse(bc.begin(), bc.end());
                bc += coders[i];
                reverse(bc.begin(), bc.end());
            }
            biggest_coders[i]=bc;
        }

        string small_c="";
        for(int i=C-1; i>=0; i--)
        {
            if(coders[i] == '?')
            {
                reverse(small_c.begin(), small_c.end());
                small_c += '0';
                reverse(small_c.begin(), small_c.end());
            }
            else
            {
                reverse(small_c.begin(), small_c.end());
                small_c += coders[i];
                reverse(small_c.begin(), small_c.end());
            }
            smallest_coders[i]=small_c;
        }

        string bj="";
        for(int i=C-1; i>=0; i--)
        {
            if(jammers[i] == '?')
            {
                reverse(bj.begin(), bj.end());
                bj += '9';
                reverse(bj.begin(), bj.end());
            }
            else
            {
                reverse(bj.begin(), bj.end());
                bj += jammers[i];
                reverse(bj.begin(), bj.end());
            }
            biggest_jammers[i]=bj;
        }

        string small_j="";
        for(int i=C-1; i>=0; i--)
        {
            if(jammers[i] == '?')
            {
                reverse(small_j.begin(), small_j.end());
                small_j += '0';
                reverse(small_j.begin(), small_j.end());
            }
            else
            {
                reverse(small_j.begin(), small_j.end());
                small_j += jammers[i];
                reverse(small_j.begin(), small_j.end());
            }
            smallest_jammers[i]=small_j;
        }

        vector< pair<long long, pair<string, string> > > smallest_diff(20, make_pair(inf, make_pair("ABC", "DEF")));
        for(int i=C; i<20; i++)
        {
            smallest_diff[i] = make_pair(0, make_pair("", ""));
        }
        for(int i=C-1; i>=0; i--)
        {
            //getal, getal
            if(coders[i] != '?' && jammers[i] != '?')
            {
                if(coders[i] > jammers[i])
                {
                    string coder_minimize = "";
                    coder_minimize += coders[i];
                    coder_minimize += smallest_coders[i+1];

                    string jammer_maximize = "";
                    jammer_maximize += jammers[i];
                    jammer_maximize += biggest_jammers[i+1];

                    long long n1 = atoll(coder_minimize.c_str());
                    long long n2 = atoll(jammer_maximize.c_str());
                    smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                }
                else if(coders[i] == jammers[i])
                {
                    string coder_minimize = "";
                    coder_minimize += coders[i];
                    coder_minimize += smallest_diff[i+1].second.first;

                    string jammer_maximize = "";
                    jammer_maximize += jammers[i];
                    jammer_maximize += smallest_diff[i+1].second.second;

                    long long n1 = atoll(coder_minimize.c_str());
                    long long n2 = atoll(jammer_maximize.c_str());
                    smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                }
                else
                {
                    string coder_minimize = "";
                    coder_minimize += coders[i];
                    coder_minimize += biggest_coders[i+1];

                    string jammer_maximize = "";
                    jammer_maximize += jammers[i];
                    jammer_maximize += smallest_jammers[i+1];

                    long long n1 = atoll(coder_minimize.c_str());
                    long long n2 = atoll(jammer_maximize.c_str());
                    smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                }
            }
            //?, getal
            else if(coders[i] == '?' && jammers[i] != '?')
            {
                for(char probeer='0'; probeer<='9'; probeer++)
                {
                    coders[i] = probeer;

                    if(coders[i] > jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += biggest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else if(coders[i] == jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_diff[i+1].second.first;

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_diff[i+1].second.second;

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += biggest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }

                    coders[i] = '?';

                }
            }
            //getal, ?
            else if(coders[i] != '?' && jammers[i] == '?')
            {
                for(char probeer='0'; probeer<='9'; probeer++)
                {
                    jammers[i] = probeer;

                    if(coders[i] > jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += biggest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else if(coders[i] == jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_diff[i+1].second.first;

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_diff[i+1].second.second;

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += biggest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }

                    jammers[i] = '?';
                }
            }
            //?, ?
            else
            {
                for(char probeer1='0'; probeer1<='9'; probeer1++)
                {
                    for(char probeer2='0'; probeer2<='9'; probeer2++)
                    {
                        coders[i] = probeer1;
                        jammers[i] = probeer2;

                        if(coders[i] > jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += biggest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else if(coders[i] == jammers[i])
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += smallest_diff[i+1].second.first;

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_diff[i+1].second.second;

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }
                    else
                    {
                        string coder_minimize = "";
                        coder_minimize += coders[i];
                        coder_minimize += biggest_coders[i+1];

                        string jammer_maximize = "";
                        jammer_maximize += jammers[i];
                        jammer_maximize += smallest_jammers[i+1];

                        long long n1 = atoll(coder_minimize.c_str());
                        long long n2 = atoll(jammer_maximize.c_str());
                        smallest_diff[i] = min(smallest_diff[i], make_pair(abs(n1-n2), make_pair(coder_minimize, jammer_maximize)));
                    }

                        coders[i] = '?';
                        jammers[i] = '?';
                    }
                }
            }
        }
        cout << smallest_diff[0].second.first << " " << smallest_diff[0].second.second << endl;

    }
    return 0;
}
