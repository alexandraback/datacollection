#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct Mote {
    int size;
    struct Mote *next;
} Mote;

Mote *new_mote(int size) {
    Mote *m = new Mote;

    m->size = size;
    m->next = NULL;

    return m;
}

void free_motes(Mote *first) {
    Mote *m_next;
    for (Mote *m = first; m; m = m_next) {
        m_next = m->next;
        free(m);
    }
}

int A, N;
int mote[1000];

/* return the minimum number of changes to mote_list to make it solvable */
int search(Mote *mote_list, int motesize) {
    Mote *m;
    for (m = mote_list; m && m->size < motesize; motesize += m->size, m = m->next);

    if (!m)
        return 0;

    /* consider deleting all remaining motes */
    int deletingall = 0;
    for (Mote *p = m; p; p = p->next, deletingall++);

    /* consider inserting a new mote before m that is edible, and recurse */
    if (motesize * 2 - 1 > motesize) {
        int inserting = 1 + search(m, motesize * 2 - 1);
        return inserting < deletingall ? inserting : deletingall;
    } else {
        return deletingall;
    }
}

int main() {
    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", mote + j);
        }

        /* sort motes by size */
        sort(mote, mote+N);

        Mote *first = new_mote(mote[0]);
        Mote *last = first;
        for (int j = 1; j < N; j++) {
            Mote *m = new_mote(mote[j]);
            last->next = m;
            last = m;
        }

        printf("Case #%d: %d\n", i+1, search(first, A));

        free_motes(first);
    }
}
