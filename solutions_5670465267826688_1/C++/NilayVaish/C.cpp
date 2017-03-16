#include <cassert>
#include <cstdio>

char S[40005];

void Multiply(char A1, bool B1, char A2, bool B2, char& A3, bool& B3)
{
  B3 = B1 xor B2;
  switch(A1)
  {
    case '1':
        if (A2 == '1') A3 = '1';
        else if (A2 == 'i') A3 = 'i';
        else if (A2 == 'j') A3 = 'j';
        else if (A2 == 'k') A3 = 'k';
        break;
    case 'i':
        if (A2 == '1') A3 = 'i';
        else if (A2 == 'i') { A3 = '1'; B3 = not B3; }
        else if (A2 == 'j') A3 = 'k';
        else if (A2 == 'k') { A3 = 'j'; B3 = not B3; }
        break;
    case 'j':
        if (A2 == '1') A3 = 'j';
        else if (A2 == 'i') { A3 = 'k'; B3 = not B3; }
        else if (A2 == 'j') { A3 = '1'; B3 = not B3; }
        else if (A2 == 'k') A3 = 'i';
        break;
    case 'k':
        if (A2 == '1') A3 = 'k';
        else if (A2 == 'i') A3 = 'j';
        else if (A2 == 'j') { A3 = 'i'; B3 = not B3; }
        else if (A2 == 'k') { A3 = '1'; B3 = not B3; }
        break;
    default:
        printf("What am I doing here!\n");
        assert(0);
        break;
  }

  //printf("%c %d X %c %d = %c %d\n", A1, B1, A2, B2, A3, B3);
}

int main()
{
  int T; scanf("%d\n", &T); for (int ii = 1; ii <= T; ++ii)
  {
    long long int X, L; scanf("%lld %lld\n%s\n", &L, &X, S);
    for (int i = 1; i < 4; ++i) for (int j = 0; j < L; ++j) S[i*L + j] = S[j];

    char M = '1'; bool R = false;
    for (int i = 0; i < L; ++i)
    {
      char A; bool B;
      Multiply(M, R, S[i], false, A, B);
      M = A; R = B;
    }

    char MX = '1'; bool RX = false;
    for (int i = 0; i < X % 4; ++i)
    {
      char A; bool B;
      Multiply(M, R, MX, RX, A, B);
      MX = A; RX = B;
    }
    M = MX, R = RX;

    //printf("%c %d\n", M, R);
    if (M == '1' && R == true)
    {
      M = '1'; R = false; long long int i; bool fi = false;
      for (i = 0; i < L*4; ++i)
      {
        char A; bool B;
        Multiply(M, R, S[i], false, A, B);
        if (A == 'i' && B == false)
        {
          fi = true;
          break;
        }
        M = A; R = B;
      }

      long long int k; M = '1', R = false; bool fk = false;
      for (k=L*4-1; k >= 0; --k)
      {
        char A; bool B;
        Multiply(S[k], false, M, R, A, B);
        if (A == 'k' && B == false)
        {
          fk = true;
          break;
        }
        M = A; R = B;
      }

      //int j; M = '1', R = false;
      //for (j = i + 1; j < k; ++j)
      //{
      //  char A; bool B;
      //  Multiply(M, R, S[j], false, A, B);
      //  M = A; R = B;
      //}

      k += (L * X - 4 * L);
      if (k - i >= 2 && fk && fi)
      {
        printf("Case #%d: YES\n", ii);
        //printf("M = %c, R = %d\n", M, R);
        //assert(M == 'j' && R == false);
      }
      else printf("Case #%d: NO\n", ii);
    }
    else printf("Case #%d: NO\n", ii);
  }
  return 0;
}
