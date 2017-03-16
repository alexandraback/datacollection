import sys

def pairize(L):
    return [(L[i], L[i+1]) for i in range(0, len(L), 2)]
        
def max_boxed(listA, listB):
    if len(listA)*len(listB) == 0:
        return 0
    (a, A) = listA[0]
    (b, B) = listB[0]
    # print listA, listB
    if A == B:
        if a >= b:
            return b + max_boxed([(a-b, A)] + listA[1:], listB[1:])
        else:
            return a + max_boxed(listA[1:], [(b-a, B)] + listB[1:])
    else:
        for i in range(len(listB)):
            if listB[i][1] == A:
                until = i
                break
        else:
            until = len(listB)
        return max(max_boxed(listA, listB[until:]),
                   max_boxed(listA[1:], listB))

fi = open("C.in", "r")
fo = open("C.out", "w")

T = int(fi.readline())
for case in range(T):
    N, M = map(int, fi.readline().split())
    listA = pairize(map(int, fi.readline().split()))
    listB = pairize(map(int, fi.readline().split()))
    result = max_boxed(listA, listB)
    fo.write('Case #{0}: {1}\n'.format(case+1, result))

print "Done"
fo.flush()
