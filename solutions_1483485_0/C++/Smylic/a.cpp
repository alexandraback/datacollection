#include <iostream>

using namespace std;

char s[] = "yhesocvxduiglbkrztnwjpfmaq";
char t[1024];

int main()
{
    int n;
    cin >> n;
    cin.getline(t, sizeof(t));

    for (int i=1; i<=n; i++)
    {
        cin.getline(t, sizeof(t));

        for (int j=0; t[j]; j++)
            if (t[j] != ' ')
                t[j] = s[t[j] - 'a'];

        cout << "Case #" << i << ": " << t << endl;
    }

    return 0;
}
