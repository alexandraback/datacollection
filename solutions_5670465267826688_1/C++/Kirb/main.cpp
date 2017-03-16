#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

#define I 2
#define J 3
#define K 4

int main(int p_Argc, char  **p_Argv)
{
    int T;
    string s;
	fstream input("C-large.in");
	ofstream output("enfin2.txt");
	input >> T;
	string Lo;

	int prod[4][4] = {{1,I,J,K},{I,-1,K,-J},{J,-K,-1,I},{K,J,-I,-1}};

    for (int l=0;l<T;l++){
            long long int X,L;
            input >> L >> X >> s;

            long long int rep;
            if (X > 20) rep = 20+(X%4);
            else rep = X;
            Lo.clear();
            for (int pp=0;pp<rep;pp++){
                Lo.append(s);
            }

            int cumul = 1;
            int signe = 1;
            int iExiste, jExiste, kExiste;
            iExiste=0;
            jExiste=0;
            kExiste=0;

            for (int u=0;u<Lo.length();u++)
            {
                int pos;
                switch (Lo[u])
                {
                case '1' : pos = 1; break;
                case 'j' : pos = J; break;
                case 'k' : pos = K; break;
                case 'i' : pos = I; break;
                }
                cumul = signe * prod[cumul-1][pos-1];
                signe = (cumul > 0 ? 1 : -1);
                cumul = abs(cumul);
                if (signe > 0 && cumul == I && !iExiste) {iExiste = 1; cumul=1;}
                if (signe > 0 && cumul == J && iExiste && !jExiste) {jExiste = 1; cumul = 1;}
                if (signe > 0 && cumul == K && (u == Lo.length()-1) && iExiste && jExiste && !kExiste) kExiste = 1;
            }

           output << "Case #" << l+1 << ": " << (kExiste ? "YES" : "NO") << endl;
    }


    return 0;

}





