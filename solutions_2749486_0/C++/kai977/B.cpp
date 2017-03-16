#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define SIZE 1000000

int T;
int X, Y;

set <vector <int> > used;
set <vector <int> >::iterator iter;

vector <int> v(3);

struct TP
{
  int x, y;
  int l;
} q[SIZE], p, np;

char dir[SIZE];
int prev[SIZE];
char sol[SIZE];
int len;

int start, last;

int main() {

  scanf("%d", &T);
  int c = 0;
  while (T--) {
    c++;
    
        
    scanf("%d %d", &X, &Y);
    
    printf("Case #%d: ", c);
    
    used.clear();
    
    p.x = 0; p.y = 0; p.l = 1;
    v[0] = p.x; v[1] = p.y; v[2] = p.l;
    used.insert(v);
    q[0] = p;
    start = 0; last = 1;
    prev[0] = -1;
    
    while (start < last) {
      if (last == SIZE-1) {printf("!!!!\n"); break;}
      p = q[start]; 
      
      if (p.x == X && p.y == Y) break;
            
      np.x = p.x + p.l; np.y = p.y; np.l = p.l+1;
      v[0] = np.x; v[1] = np.y; v[2] = np.l; 
      iter = used.find(v);
      if (iter == used.end()) {
        prev[last] = start;
        dir[last] = 'E';
        q[last] = np; last++;
	used.insert(v);
      }

      np.x = p.x - p.l; np.y = p.y; np.l = p.l+1;      
      v[0] = np.x; v[1] = np.y; v[2] = np.l; 
      iter = used.find(v);
      if (iter == used.end()) {      
        prev[last] = start;
        dir[last] = 'W';
        q[last] = np; last++;
	used.insert(v);
      }
      
      np.x = p.x; np.y = p.y + p.l; np.l = p.l+1;      
      v[0] = np.x; v[1] = np.y; v[2] = np.l; 
      iter = used.find(v);
      if (iter == used.end()) {      
        prev[last] = start;
        dir[last] = 'N';
        q[last] = np; last++;
	used.insert(v);
      }

      np.x = p.x; np.y = p.y - p.l; np.l = p.l+1;      
      v[0] = np.x; v[1] = np.y; v[2] = np.l; 
      iter = used.find(v);
      if (iter == used.end()) {      
        prev[last] = start;
        dir[last] = 'S';
        q[last] = np; last++;      
	used.insert(v);
      }      
      start++;
    }
    //printf("%d\n", last);
    
    int i = start;
    len = 0;
    while (i > 0) {
      //printf("%c", dir[i]);
      sol[len] = dir[i]; len++;
      i = prev[i];
    }
    
    for (i = len-1; i >=0; i--)
      printf("%c",sol[i]);
    printf("\n");
  }
  return 0;
}