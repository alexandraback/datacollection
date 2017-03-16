#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

bool isPrime[1000000];
vector<long long> prime;
void getPrime()
{
	for(long long i = 0; i < 1000000; i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for(long long i = 2; i < 1000000; i++)
	{
		if(isPrime[i] == true)
		{
			prime.push_back(i);
			long long test = i * 2;
			while(test < 1000000)
			{
				isPrime[test] = false;
				test += i;
			}
		}
	}

}

bool compare(int a, int b)
{
	return(a < b);
}

void compare_sample()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector (myints, myints+8);        
	vector<int>::iterator it;
	sort (myvector.begin()+4, myvector.end(), compare);
}
vector<vector<long long> > PT(502, vector<long long> (502, 1));

void create_pt()
{
	for(int i = 2; i <= 500; i++)
	{
		for(int j = 1; j < i; j++)
		{
			PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % 100003;
		}
	}
}

long long c_x_get_y(long long x, long long y)
{
	if(y == 0)
		return 1;
	long long ans = 1;
	for(int i = 0; i < y; i++)
	{
		ans *= (x - i);
		ans /= (i + 1);
	}
	return ans;
}
         int test( ll r, ll t, ll n)
         {
              if(2*n*n+2*n*r-n > t) return -1;
               ll next = n+1;
                if(2*next*next+2*next*r-next <= t) return 1;
                 return 0;

         }
int main()
{
	char c;
	int data_num, case_count = 1;
	cin >> data_num;
	while(data_num != 0)
	{
		cout << "Case #" << case_count << ": ";

        ll r, t;
        cin >> r >> t;
        ll ans;
         ll l=1,u,m;

                 u=1000000000<8000000000000000000LL/r ? 1000000000 : 8000000000000000000LL/r;

                         while(1)

                                     {

                                            m = (l+u)/2;

                                               ll res = test(r,t,m);

                                                  

                                                  if(res == 0)

                                                         {

                                                                 ans = m;

                                                                     break;

                                                                        }

                                                     res > 0 ? l = m : u = m;

                                                       }


                         cout << ans;
		cout << endl;
		data_num--;
		case_count++;
	}
	return 0;

}
