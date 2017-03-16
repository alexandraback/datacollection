#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen ("file_name3.X","w",stdout);
    int n , m , k, t , d, sum = 0, tem1 , tem2;
    long long ans = 1e9;
    string s , c;

    cin >> t ;
    int i = 1;

    while(i <= t){

        cin >> n;
        ans = 1e9;

        if(n <= 20){
            ans = n;

        } else {
            for(long long j = n, m = 0; j >= 21; j-- ,m++){

                stringstream ss;
                ss << j;
                string str = ss.str();

                 for(int h = 0, k = str.length() - 1; h < str.length() / 2; h++, k--){
                    char temp = str[h];
                    str[h] = str[k];
                    str[k] = temp;

                }
                long long co = atoi(str.c_str());
                if(co < j && co > 11){
                    if(ans > (co + 1 + m) ){
                        ans = co + 1 + m;
                    }


                }

            }
        }

            cout << "Case #" << i <<": " << ans << endl;
            i++;
    }

    return 0;
}
