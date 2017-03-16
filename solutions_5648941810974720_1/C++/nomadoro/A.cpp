#include <iostream>
#include <algorithm>
#include <string>

#define SET0(n,x) (N[n] = stat[x-'A'])
#define SET1(n,x,x1) (N[n] = stat[x-'A'] - N[x1])
#define SET2(n,x,x1,x2) (N[n] = stat[x-'A'] - N[x1] - N[x2])
#define SET3(n,x,x1,x2,x3) (N[n] = stat[x-'A'] - N[x1] - N[x2] - N[x3])

inline std::string gen(int dig, int cnt)
{
    return std::string(cnt, char(dig)+'0');
}

int main()
{
    int T;
    std::cin >> T;
    for(int t=1; t<=T; t++)
    {
        int stat[26] = {0};
        std::string S;
        std::cin >> S;
        for(int n=0; n<S.size(); n++)
            stat[S[n]-'A']++;
        int N[10];
        SET0(8,'G');
        SET1(3,'H',8);
        SET2(2,'T',3,8);
        SET0(4,'U');
        SET2(0,'R',3,4);
        SET3(1,'O',0,2,4);
        SET0(6,'X');
        SET1(7,'S',6);
        SET1(5,'V',7);
        SET3(9,'I',5,6,8);
        std::string sout = gen(0,N[0])+gen(1,N[1])+gen(2,N[2])+gen(3,N[3])+gen(4,N[4])
                          +gen(5,N[5])+gen(6,N[6])+gen(7,N[7])+gen(8,N[8])+gen(9,N[9]);
        std::cout << "Case #" << t << ": " << sout << std::endl;
    }
    return 0;
}
