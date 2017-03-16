#include <stdlib.h>
#include <stdio.h>

typedef struct list_head
{
    struct list_head *prev, *next;
} list_head;

static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
    next->prev = prev;
    prev->next = next;
}

static inline void list_del(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = NULL;
    entry->prev = NULL;
}

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}


#define container_of(pointer, type, member) \
    (type*)((char*)pointer - (char*)&((type*)0)->member)

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

typedef struct round_info
{
    int a;
    int b;
    int level; /* 0, 1, 2 */
    list_head q1;
    list_head q2;
} round_info;

int main()
{
    FILE *in, *out;
    int t;
    int n;
    round_info r[1000];
    int i, j, k;
    int stars;
    int times;
    int remain;
    list_head q1;
    list_head q2;
    list_head *entry;
    list_head *tmp;
    list_head *entry1;
    list_head *tmp1;
    round_info *r_info;
    round_info *r_info1;
    
    in = fopen("B-small-attempt1.in", "r");
    out = fopen("out.txt", "w");
    
    fscanf(in, "%d", &t);
    for (k = 0; k < t; k++)
    {
        fscanf(in, "%d", &n);
        stars = 0;
        times = 0;
        remain = n;
        INIT_LIST_HEAD(&q1);
        INIT_LIST_HEAD(&q2);
        
        for (i = 0; i < n; i++)
        {
            fscanf(in, "%d %d", &r[i].a, &r[i].b);
            r[i].level = 0;
            INIT_LIST_HEAD(&r[i].q1);
            INIT_LIST_HEAD(&r[i].q2);
            list_for_each_safe(entry, tmp, &q1)
            {
                r_info = container_of(entry, round_info, q1);
                if (r_info->a > r[i].a)
                {
                    break;
                }
            }
            list_add_tail(&r[i].q1, entry);
            list_for_each_safe(entry, tmp, &q2)
            {
                r_info = container_of(entry, round_info, q2);
                if (r_info->b > r[i].b)
                {
                    break;
                }
            }
            list_add_tail(&r[i].q2, entry);
        }

        retry:
        list_for_each_safe(entry, tmp, &q2)
        {
            r_info = container_of(entry, round_info, q2);
            if (stars >= r_info->b)
            {
                if (0 == r_info->level)
                {
                    stars += 2;
                    list_del(&r_info->q1);
                }
                else
                {
                    stars++;
                }
                r_info->level = 2;
                list_del(&r_info->q2);
                remain--;
                times++;
                continue;
            }
            list_for_each_safe(entry1, tmp1, &q1)
            {
                r_info1 = container_of(entry1, round_info, q1);
                if (stars >= r_info->b || stars < r_info1->a)
                {
                    break;
                }
                stars++;
                r_info1->level = 1;
                times++;
                list_del(&r_info1->q1);
            }
            if (stars < r_info->b)
            {
                break;
            }
            else
            {
                goto retry;
            }
        }
        if (remain)
        {
            fprintf(out, "Case #%d: Too Bad\n", k + 1);
        }
        else
        {
            fprintf(out, "Case #%d: %d\n", k + 1, times);
        }
    }

    fclose(in);
    fclose(out);
    
    return 0;
}
