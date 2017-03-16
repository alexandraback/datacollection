#include <bits/stdc++.h>
using namespace std;

char S[105];

char get_comp(char x)
{
    if(x=='-')
        return '+';

    return '-';
}

int solve(string X, int flag)
{
    if(X.size()==0)
        return 0;

    if(X.size()==1)
    {
        if(X[0]=='+')
        {
            if(flag==0)
                return 0;
            return 1;
        }
        else
        {
            if(flag==0)
                return 1;
            return 0;
        }
    }

    if(!flag)
    {
        int x;
        string Y;

        if(X[0]=='-')
        {
            for(x=0; x<X.size() && X[x]=='-'; x++);

            for(int i=X.size()-1; i>=x; i--)
                Y.push_back(get_comp(X[i]));

            return 1 + solve(Y, 0);
        }
        else
        {
            for(x=X.size()-1; x>=0 && X[x]=='-'; x--);

            for(int i=x; i>=0; i--)
                Y.push_back(get_comp(X[i]));

            X = Y;
            Y.clear();

            for(x=X.size()-1; x>=0 && X[x]=='-'; x--);

            for(int i=0; i<=x; i++)
                Y.push_back(X[i]);

            return 2 + solve(Y, 1);
        }
    }
    else
    {
        int x;
        string Y;

        if(X[0]=='+')
        {
            for(x=0; x<X.size() && X[x]=='+'; x++);

            for(int i=X.size()-1; i>=x; i--)
                Y.push_back(get_comp(X[i]));

            return 1 + solve(Y, 1);
        }
        else
        {
            for(x=X.size()-1; x>=0 && X[x]=='+'; x--);

            for(int i=x; i>=0; i--)
                Y.push_back(get_comp(X[i]));

            X = Y;
            Y.clear();

            for(x=X.size()-1; x>=0 && X[x]=='+'; x--);

            for(int i=0; i<=x; i++)
                Y.push_back(X[i]);

            return 2 + solve(Y, 0);
        }
    }
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out2_large.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int test=1; test<=T; test++)
    {
        scanf(" %s", S);

        string X;

        int N = strlen(S), x;

        for(x=N-1; x>=0; x--)
            if(S[x]=='-')
                break;

        for(int i=0; i<=x; i++)
            X.push_back(S[i]);

        printf("Case #%d: %d\n", test, solve(X, 0));
    }

    fclose(stdout);
    fclose(stdout);

    return 0;
}
