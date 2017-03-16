#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int counter = 0;

double a[1000]; //NAOMI
double b[1000]; // KEN
int n;


bool WinsAll(vector<double> naomi, vector<double> ken) {
   
   for(int i = 0; i < naomi.size(); i++) {
      if(naomi.at(i) < ken.at(i)) {
         return false;
      }
   }
   return true;
}

int dwar() {
   std::sort(a, a+n);
   std::sort(b, b+n);
     
   
     
   vector<double> naomi;
   vector<double> ken;
   int gamepoints = 0;
   
   for(int i = 0; i < n; ++i)
   {
      naomi.push_back(a[i]);
      ken.push_back(b[i]);
   }

   for(int i = 0; i < n; i++) {
      
      if(WinsAll(naomi, ken)) {
         return n-i;
      } else {
         naomi.erase(naomi.begin());
         ken.pop_back();
      }
   }
   
      
   return gamepoints;
}

int war() {
   std::sort(a, a+n);
   std::sort(b, b+n);
   
      int gamepoints = 0;
      vector<double> naomi;
      vector<double> ken;
   
      for(int i = 0; i < n; ++i)
      {
         naomi.push_back(a[i]);
         ken.push_back(b[i]);
      }
      
       std::sort(ken.begin(), ken.end());
   
      /* printf("Naomi Playing: ");   
      for(int i =0; i < n; i++)
         printf("%lf ", naomi.at(i));
      printf("\n");*/
      
      for(int i = 0; i < n; i++) {
         double np = naomi.back();
         naomi.pop_back();
      
         vector<double>::iterator up;
         up = upper_bound(ken.begin(), ken.end(), np);
         double kp = *up;
      
         if(up == ken.end()) {
            kp = ken.front();
            ken.erase(ken.begin());
            gamepoints++;
         } else {
            ken.erase(up);
         }
         
      }
   return gamepoints;
}
void runCase() {
    printf("Case #%d: ", ++counter);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
       scanf("%lf", &a[i]);
    }
    
    for(int i = 0; i < n; ++i)
    {
       scanf("%lf", &b[i]);
    }
       
    int z = war();
    int y = dwar();
    
    printf("%d %d\n", y,z);
    
   
    return;
}


void preprocess() {
   
}
int main() {
   
   preprocess();
   
    int t; scanf("%d", &t);
    while(t--) {
        runCase();
    }
    return 0;
}


//  n, m, 2 numbers per line
//    int n, m; scanf("%d %d", &n, &m);


/* GRID - N x M  
int n, m; scanf("%d %d", &n, &m);
 for (int i=0; i<n; ++i) {
     for (int j=0; j<m; ++j) {
         scanf("%d", &t[i][j]);
     }
 }
 */