#include <iostream>

using namespace std;

bool allTrue(bool a[], int n)
{
    for(int i=0; i<=n; i++)
        if(!a[i])
            return false;
    return true;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        int c, d, v;
        cin >> c >> d >> v;
        int a[d];
        for(int i=0; i<d; i++)
            cin >> a[i];

        bool canBe[v+1];
        for(int i=0; i<=v; i++) canBe[i] = false;
        canBe[0] = true;

        for(int i=0; i<d; i++)
            for(int j=v; j-a[i] >= 0; j--)
                if(canBe[j-a[i]]) canBe[j] = true;

        int res = 0;
        while(!allTrue(canBe, v))
        {
            int nom;
            for(int i=1; i<=v; i++)
                if(!canBe[i])
                {
                    nom = i;
                    break;
                }
            for(int j=v; j-nom >=0; j--)
                if(canBe[j-nom]) canBe[j] = true;

            res++;
        }

        cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}


