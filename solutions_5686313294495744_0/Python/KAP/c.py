#!/usr/bin/python3

def find(i):
    global gr, p2, was
    if i in was:
        return False
    was[i] = i
    for j in gr[i]:
        if (not(j in p2)) or find(p2[j]):
            p2[j] = i
            return True
    return False

tests = int(input())
for test in range(tests):
    m = int(input())
    gr = {}
    gr2 = {}
    for i in range(m):
        s = input().split()
        if not s[0] in gr:
            gr[s[0]] = []
        gr[s[0]].append(s[1])
        if not s[1] in gr2:
            gr2[s[1]] = []
        gr2[s[1]].append(s[0])
    n1 = len(gr.keys())
    n2 = len(gr2.keys())
    #print('n1,n2=',n1,' ',n2)
    p2 = {}
    size = 0
    for k in gr:
        was = {}
        if find(k):
            size += 1
    #print("size=", size)
    #for j in p2:
    #    print('par=',p2[j],' ',j);
    print("Case #%d: %d" % (test+1, m-(n1+n2-size)))
    