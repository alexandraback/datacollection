#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;


int R, M, N, K;
int a[100];

int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");

    int TestCase;
    infile>>TestCase;

    outfile<<"Case #1:"<<endl;
    infile>>R>>N>>M>>K;

    for (int testcase = 0; testcase < R; testcase++) {
        for (int i=0; i<K; i++)
            infile>>a[i];

        int three = 0;
        int five = 0;
        int two = 0;
        bool odd = false;

        for (int i=0; i<K; i++) {
            int count = 0;
            while(a[i]%3==0) {
                count++;
                a[i] /= 3;
            }
            three = max(three, count);

            count = 0;
            while(a[i]%5==0) {
                count++;
                a[i] /= 5;
            }
            five = max(five, count);

            count = 0;
            while(a[i]%2==0) {
                count++;
                a[i] /= 2;
            }
            if (count%2==1)
                odd = true;
            two = max(two, count);
        }

        string ret="";
        for (int i=0; i<three; i++)
            ret += "3";
        for (int i=0; i<five; i++)
            ret += "5";
        if(odd) {
            ret += "2";
            if (two%2==1)
                two--;
        }
        two /= 2;
        for (int i=0; i<two; i++)
            ret += "4";

        while(ret.length()<3)
            ret += "1";

        ret = ret.substr(0,3);

        outfile<<ret<<endl;
    }
}
