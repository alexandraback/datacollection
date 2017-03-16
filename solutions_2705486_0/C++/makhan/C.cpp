#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char buf[4001];

struct node {
  node* son[26];
  bool end;
  node() {
    for (char i='a'; i <= 'z'; i++) {
      son[i] = NULL;
    }
    end = false;
  }
};

map< pair<node*, char*>, int > *mapa;

node *root;

int bound = 4000;


int run(node* v, char* ptr, int cost) {
  if (cost >= bound)
    return bound;

  //  pair<unsigned long long int,unsigned long long int> h = make_pair((unsigned long long int)(v), (unsigned long long int)(ptr));
  pair<node*,char*> h = make_pair(v,ptr);
  if ((*mapa)[h] && (*mapa)[h] <= cost)
    return bound;
  else
    (*mapa)[h] = cost;

  if (*ptr == 0) {
    return bound = (v->end ? cost : bound);
  }

  if (v->end) {
    bound = min(bound, run(root, ptr, cost));
  }
  
  int l = (*ptr)-'a';

  if (v->son[l] != NULL)
    bound = min(bound, run(v->son[l], ptr+1, cost));

  for (int i=0; i<=l-5; i++)
    if (v->son[i] != NULL)
      bound = min(bound, run(v->son[i], ptr+1, cost+1));
  for (int i=l+5; i<26; i++)
    if (v->son[i] != NULL)
      bound = min(bound, run(v->son[i], ptr+1, cost+1));

  return bound;
}

void add(node* v, char *ptr) {
  if (*ptr == 0) {
    v->end = true;
    return;
  }

  int l = (*ptr)-'a';

  if (v->son[l] == NULL)
    v->son[l] = new node();

  add(v->son[l], ptr+1);
}

void prepare() {
  root = new node();

  FILE *f = fopen("garbled_email_dictionary.txt", "r");

  while ( fscanf(f,"%s",buf) > 0 ) {
    add(root, buf);
  }

}

int main() {
  int T;

  prepare();

  scanf("%d",&T);

  for (int tc=1; tc<=T; tc++) {
    mapa = new map<pair<node*,char*>, int>();
    //map.clear();
    scanf("%s",&buf);
    bound = strlen(buf);
    printf("Case #%d: %d\n",tc,run(root, buf, 0));
    //    delete mapa;
  }
}
