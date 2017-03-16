import sys

sys.stdin = open("D-large.in")
sys.stdout = open("out.txt", "w")

def n_ary(k, lst):
    v = 0
    for i in lst:
        v = v * k + i
    return v

def group_list(lst, k, padding=None):
    if len(lst) <= k:
        return [lst + [padding]*(k - len(lst))]
    return [lst[:k]] + group_list(lst[k:], k, padding)

def fractile(k, c, s):
    if k > c * s:
        return 'IMPOSSIBLE'

    # [[0, 1, 2], [3, 4, 5], [6, 7, 8]]
    group = group_list(list(range(k)), c, 0)
    
    positions = list(str(n_ary(k, x) + 1) for x in group)
    return ' '.join(positions)

t = int(input())

for i in range(1, t+1):
    ss = input().split()
    k = int(ss[0])
    c = int(ss[1])
    s = int(ss[2])
    print('Case #{}: {}'.format(i, fractile(k, c, s)))

    #print("Case #%d: "%(i))
    
sys.stdout.close()
