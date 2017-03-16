#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  vector<unsigned long long> data;
  data.push_back(1);
  data.push_back(4);
  data.push_back(9);
  data.push_back(121);
  data.push_back(484);
  data.push_back(10201);
  data.push_back(12321);
  data.push_back(14641);
  data.push_back(40804);
  data.push_back(44944);
  data.push_back(1002001);
  data.push_back(1234321);
  data.push_back(4008004);
  data.push_back(100020001);
  data.push_back(102030201);
  data.push_back(104060401);
  data.push_back(121242121);
  data.push_back(123454321);
  data.push_back(125686521);
  data.push_back(400080004);
  data.push_back(404090404);
  data.push_back(10000200001);
  data.push_back(10221412201);
  data.push_back(12102420121);
  data.push_back(12345654321);
  data.push_back(40000800004);
  data.push_back(1000002000001);
  data.push_back(1002003002001);
  data.push_back(1004006004001);
  data.push_back(1020304030201);
  data.push_back(1022325232201);
  data.push_back(1024348434201);
  data.push_back(1210024200121);
  data.push_back(1212225222121);
  data.push_back(1214428244121);
  data.push_back(1232346432321);
  data.push_back(1234567654321);
  data.push_back(4000008000004);
  data.push_back(4004009004004);
  FILE* f = fopen(argv[1], "r");
  int T;
  fscanf(f, "%d", &T);
  for(int t = 0; t < T; ++t) {
    unsigned long long A, B;
    fscanf(f, "%llu %llu", &A, &B);
    int res = 0;
    for(int i = 0; i < data.size(); ++i) {
      if(data[i] >= A && data[i] <= B) res++;
    }
    printf("Case #%d: %d\n", t + 1, res);
  }
}
