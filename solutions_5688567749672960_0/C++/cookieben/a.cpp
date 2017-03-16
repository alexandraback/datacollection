#include<fstream>
#include<iostream>
#include<cstdio>
#include<map>
#include<string>

using namespace std;

#define FL(i, a, b) for(int i = a; i < b; i++)
#define MIN(a, b) ((a > b)? b : a)
#define MAX(a, b) ((a > b)? a : b)

long long upper_lower_sum(long long num) {
  int digit = 0;
  string num_string = "";
  while (num > 0) {
    num_string.insert(0,1,'0'+num%10);
    digit++;
    num/=10;
  }

  int half = digit /2;
  long long upper = 0;
  long long lower = 0;
  FL(i,half,num_string.size()) {
    lower = lower * 10 + (num_string[i] - '0');
  }
  for (int i=half-1; i>=0; i--) {
    upper = upper * 10 + (num_string[i] - '0');
  }

  return lower + upper;
}

long long count_final(long long num, long long lower, long long upper) {
  if (upper == 1) {
    upper = 0;
  }

  long long temp_ans = 0;
  long long step = 1;
  while (num >= 10) {
    step *= 10;
    long long sum = upper_lower_sum(step-1);
//printf("num: %lld, step: %lld, sum: %lld, temp: %lld\n", num,step,sum, temp_ans);
    temp_ans += sum + 1;
    num/=10;
  }

//printf("temp: %lld, lower: %lld, upper: %lld\n", temp_ans, lower, upper);

  return temp_ans + lower + upper;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("file input\n");
    return -1;
  }

  ifstream fin(argv[1]);
						
  int T;
  fin>>T;
  FL(t,0,T) {
    long long num = 0;
    string num_string;
    fin>>num_string;
    FL(i,0,num_string.size()) {
      num = num * 10 + (num_string[i] - '0');
    }
//printf("%lld\n", num);

    long long ans = 0;
    if (num <= 20) {
      ans = num;
    } else {
      int half = num_string.size() / 2;
      long long upper = 0;
      long long lower = 0;
      FL(i,half,num_string.size()) {
        lower = lower * 10 + (num_string[i] - '0');
      }
      for (int i=half-1; i>=0; i--) {
        upper = upper * 10 + (num_string[i] - '0');
      }
      
//printf("%lld, %lld\n", lower, upper);

      if (lower == 0) {
        num--;
        long long temp = num;
        num_string = "";
        while (temp > 0) {
          num_string.insert(0,1,'0'+temp%10);
          temp/=10;
        }

//printf("%s\n", num_string.c_str());

        upper = 0;
        lower = 0;
        FL(i,half,num_string.size()) {
          lower = lower * 10 + (num_string[i] - '0');
        }
        for (int i=half-1; i>=0; i--) {
          upper = upper * 10 + (num_string[i] - '0');
        }

        ans = 1;
        ans += count_final(num, lower, upper);

      } else {
        ans += count_final(num, lower, upper);
      }

    }

    printf("Case #%d: %lld\n",t + 1,ans);
  }
  return 0;
}

