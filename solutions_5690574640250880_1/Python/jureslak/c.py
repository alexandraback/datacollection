from itertools import combinations as comb, product
from collections import deque

def check_one(polje, i, j):
    q = deque([(i,j)])
    while len(q) > 0:
        ci,cj = q.popleft()
        if polje[ci][cj] == '.': continue
        for di in [-1,0,1]:
            for dj in [-1,0,1]:
                if di == dj == 0: continue
                if 0 <= ci+di < len(polje) and 0 <= cj+dj < len(polje[0]) and \
                            str(polje[ci+di][cj+dj]) not in '.*' and polje[ci][cj] == 0:
                    q.append((ci+di, cj+dj))
        polje[ci][cj] = '.'
    return all(set(i) <= set(".*") for i in polje)

def count(polje, i, j):
    if polje[i][j] == '*':return'*'
    c = 0
    for di in [-1,0,1]:
        for dj in [-1,0,1]:
            if di == dj == 0: continue
            c += 0 <= i+di < len(polje) and 0 <= j+dj < len(polje[0]) and polje[i+di][j+dj] == '*'
    return c

def small(h,w,m):

    for c in comb(product(range(h),range(w)),m):
        polje = [['.' for i in range(w)] for j in range(h)]
        for i,j in c:
            polje[i][j] = '*'
        
        for i in range(h):
            for j in range(w):
                polje[i][j] = count(polje,i,j)

        first = True
        for i in range(h):
            for j in range(w):
                if polje[i][j] == 0 and first:
                    if check_one(polje, i, j):
                        polje[i][j] = 'c'
                        return polje
                    first = False

        if m == h*w-1:
            for i in range(h):
                for j in range(w):
                    if polje[i][j] != '*':
                        polje[i][j] = 'c'
            return polje


def large(h,w,m):
    if h <= 5 and w <= 5:
        return small(h,w,m)
    if w <= h:
        vs = m//w
        ost = m % w
        if h-vs < 5:
            vs -= 5 - h + vs
            ost += (h-vs)*w
        if vs == 0:
            return small(h,w,m)
        p = large(h-vs, w, ost)
        if p == None: return None
        p += [['*']*w for j in range(vs)]
        polje = p
    else:
        vs = m//h
        ost = m % h
        if w-vs < 5:
            vs -= 5 - w + vs
            ost += (w-vs)*h
        if vs == 0:
            return small(h,w,m)
        p = large(h, w-vs, ost)
        if p == None: return None
        polje = [p[i] + ['*']*vs for i in range(h)]
    return polje 

for tt in range(int(input())):
    h,w,m = map(int, input().split())
#      print (h,w,m)
    print ("Case #{}:".format(tt+1))
    polje = large(h,w,m) 
#      print(polje)
    if polje is not None:
        print('\n'.join(''.join(i) for i in polje))
    else:
        print("Impossible")
