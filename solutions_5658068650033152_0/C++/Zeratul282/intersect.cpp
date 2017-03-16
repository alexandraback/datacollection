#include <iostream>

using namespace std;

int testy;
int n;
int m;
int k;
int a;
int n1;
int m1;
int wynik1;
int wynik2;
int wynik;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> testy;

    for(int i=1;i<=testy;i++)
    {
        cin >> n >> m >> k;

        if(n<m)
        {
            a=m;
            m=n;
            n=a;
        }

        if(m<=2)
        {
            cout << "Case #" << i << ": " << k << endl;
        }
        else
        {
            n1=n;
            m1=m;
            wynik1=n1;
            wynik2=m1;

            while(n1*m1-4>=k-1)
            {
                wynik1=n1;
                wynik2=m1;

                if(n1>=m1)
                {
                    n1--;
                }
                else
                {
                    m1--;
                }
            }

            wynik=2*wynik1+2*wynik2-8;

            if(wynik1==n && wynik2==m)
            {
                if(k-wynik1*wynik2+4>0)
                {
                    wynik=wynik+k-n1*m1+4;
                }
            }
            else if(wynik1*wynik2-4==k-1)
            {
                wynik++;
            }

            cout << "Case #" << i << ": " << wynik << endl;
        }
    }

    return 0;
}
