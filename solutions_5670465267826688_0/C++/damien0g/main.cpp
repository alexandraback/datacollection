#include <iostream>
#include <cstdio>

using namespace std;

int s[4][4] = {{1,1,1,1},{1,-1,1,-1}, {1,-1,-1,1}, {1,1,-1,-1}};
int p[4][4] = {{0,1,2,3},{1,0,3,2}, {2,3,0,1}, {3,2,1,0}};

char chartoid[256];

struct Quat
{
    int sign;
    int id;

    Quat() {};
    Quat(int _sign, int _id): sign(_sign), id(_id) {};

    const Quat operator* (const Quat& a) const
    {
        return Quat(sign*a.sign*s[id][a.id], p[id][a.id]);
    }

    const Quat operator*= (const Quat& a)
    {
        sign *= a.sign*s[id][a.id];
        id = p[id][a.id];
        return *this;
    }

    bool operator== (const Quat& a) const
    {
        return((sign == a.sign) && (id == a.id));
    }
};

int main()
{
    chartoid['i'] = 1;
    chartoid['j'] = 2;
    chartoid['k'] = 3;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int ct = 1; ct <= T; ct++)
    {
        int L, X;
        scanf("%d%d", &L, &X);

        string ch;
        cin >> ch;

        Quat P(1, 0);    //unité
        for(int i = 0; i < L; i++)
            P *= Quat(1, chartoid[(int)ch[i]]);

        printf("Case #%d: ", ct);
        if(((P.sign == -1) && (P.id == 0) && (X%2)) || ((P.id != 0) && (X%4 == 2)))    //si le produit vaut -1
        {
            //On sait que P^4 = 1, on peut donc se contenter de répéter 8x la chaîne pour trouver le i du début et le k de fin
            string nouv;
            for(int i = 0; i < min(8, X); i++)
                nouv += ch;

            int pos_i = -1, pos_k = -1;
            //On n'a qu'à regarder jusqu'à 4 itérations pour voir si on a trouvé un i

            P = Quat(1, 0); //on remet le produit à 1
            for(int i = 0; i < (int)nouv.size(); i++)
            {
                P *= Quat(1, chartoid[(int)nouv[i]]);
                if(P == Quat(1, 1)) //si ça vaut i
                {
                    pos_i = i;
                    break;
                }
            }

            P = Quat(1, 0); //on remet le produit à 1
            for(int i = nouv.size()-1; i >= 0; i--)
            {
                P = Quat(1, chartoid[(int)nouv[i]])*P;
                if(P == Quat(1, 3)) //si ça vaut k
                {
                    pos_k = i;
                    break;
                }
            }

            if((pos_i != -1) && (pos_k != -1) && (pos_k - pos_i >= 2))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else    //si le produit vaut 1
            printf("NO\n");
    }

    return 0;
}
