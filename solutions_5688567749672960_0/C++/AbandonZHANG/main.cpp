#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long reverse_x(long long x){
	char s[20];
	sprintf(s, "%lld", x);
	long long res = 0;
	for(int i = strlen(s)-1; i >= 0; i --){
		res = res * 10;
        res += s[i]-'0';
	}
	return res;
}
long long find_little(long long x){
	char s[20];
	sprintf(s, "%lld", x);
    int len = (int)strlen(s);
    int i = len-1;
    bool ok = false;
    while(i > (len-1)/2){
		if(i == len-1){
            if(s[i] != '1'){
				s[i] = '1';
				break;
            }
            else{
                if(i == (len-1)/2+1){
					ok = true;
					break;
                }
                else{
					i --;
                }
            }
		}
        else{
			if(s[i] != '0'){
				s[i] = '0';
				break;
			}
			else{
                if(i == (len-1)/2+1){
					ok = true;
					break;
                }
                else{
					i --;
                }
			}
        }
    }
    long long res = 0;
    if(ok){
		len --;
		for(int i = 0; i < len - 1; i ++){
			res = res * 10;
			res += 9;
		}
		res = res * 10;
		res += 1;
    }
	else{
		for(int i = 0; i < len; i ++){
			res = res * 10;
			res += s[i]-'0';
		}
	}

	return res;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    //printf("%d\n",find_little(100001));
    int t;
    scanf("%d", &t);
	for(int ca = 1; ca <= t; ca ++){
        long long n;
        scanf("%lld", &n);
        long long ans = 0;
		long long tmpn = n;
        while(tmpn != 1){
            if(tmpn < 10){
				ans += tmpn-1;
                break;
            }
            else{
				int y = tmpn%10;
				// 先把个位变为1
				if(y == 0){
					ans += 9;
					tmpn = tmpn - 9;
				}
				else{
					ans += y - 1;
					tmpn = tmpn - (y - 1);
				}
				//
                if(reverse_x(tmpn)<tmpn){
                    tmpn = reverse_x(tmpn);
                    ans ++;
                }
                else{
					long long ne = find_little(tmpn);
					ans += tmpn - ne;
					tmpn = ne;
                }
            }
        }
        printf("Case #%d: %lld\n", ca, ans+1);
	}
	return 0;
}
