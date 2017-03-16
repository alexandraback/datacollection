#include <iostream>

int main(int argc, char **argv)
{
    int T, c, D, m, i, n, z, zi, zh, zhh;
    int P[3000];

    std::cin >> T;

    for(c=1; c<=T; c++)
      {
        std::cin >> D;
        m = 0;
        for(i=0; i<D; i++)
          {
            std::cin >> P[i]; 
            if(P[i]>m)
                m = P[i];
          }
        n = 0;
        z = m;
        while(n<=m)
          {
            z = -99;
            zi = -99;
            for(i=0; i<D; i++)
              {
                if(P[i]>z)
                  {
                    z = P[i];
                    zi = i;
                  }
              }
            if(n+z < m)
                m = n+z;
            if(z<=2)
                break;
            zh = z/2;
            zhh = z - zh;
            P[zi] = zh;
            P[D++] = zhh;
            n++;
          }
        std::cout << "Case #" << c << ": " << m << "\n";
      }
}
