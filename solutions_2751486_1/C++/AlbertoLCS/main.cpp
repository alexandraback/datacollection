#include <iostream>
#include <fstream>

using namespace std;

bool isNotVowel(char x)
{
    if(x == 'a')
        return false;
    if(x == 'e')
        return false;
    if(x == 'i')
        return false;
    if(x == 'o')
        return false;
    if(x == 'u')
        return false;
    return true;
}

long long albertoAlgorithm (string name, long long l, long long n)
{
	long long maxEnding = 0, total = 0, a0 = 0, b0 = n-1, a1, b1;
	for(long long i = 0; i < l; i++){
	    if(isNotVowel(name[i]))
            maxEnding++;
	    else{
            if(maxEnding >= n){
                a1 = i - maxEnding;
                b1 = maxEnding;
                long long start, end;
                start = a1 - (a0 + b0) + n;
                end = l - a1 - n + 1;
                total += start*end;
                for(long long m = 1; m <= b1 - n; m++)
                    total += --end;
                a0 = a1;
                b0 = b1;
            }
            maxEnding = 0;
	    }
    }
    if(maxEnding >= n){
        a1 = l - maxEnding;
        b1 = maxEnding;
        long long start, end;
        start = a1 - (a0 + b0) + n;
        end = l - a1 - n + 1;
        total += start*end;
        for(long long m = 1; m <= b1 - n; m++)
            total += --end;
    }
    return total;
}

int main()
{
    ifstream ent;
    ofstream sal;
    ent.open("input.txt");
    sal.open("output_R1C_A.txt");
    long long casos, n;
    string name;
    ent >> casos;
    for(long long i = 0; i < casos; i++){
        ent >> name >> n;
        sal << "Case #" << i+1 << ": " << albertoAlgorithm(name, name.length(), n) << endl;
    }
    ent.close();
    sal.close();
    return 0;
}
