from collections import defaultdict

d = {
    0: 'ZERO',  # 1
    1: 'ONE',   # 9
    2: 'TWO',   # 2
    3: 'THREE', # 8
    4: 'FOUR',  # 7
    5: 'FIVE',  # 6
    6: 'SIX',   # 3
    7: 'SEVEN', # 5
    8: 'EIGHT', # 4
    9: 'NINE',  # 10
}
l = [0, 2, 6, 8, 7, 5, 4, 3, 1, 9]

T = input()
for t in range(T):
    S = raw_input()
    ans = []
    c = defaultdict(int)
    for s in S:
        c[s] += 1 
    for u in l:
        while 1:
            sirve = True
            for x in d[u]:
                c[x] -= 1
                if c[x] < 0:
                    sirve = False
            if not sirve:
                for x in d[u]:
                    c[x] += 1
                break
            else:
                ans.append(str(u))
    ans.sort()
    print "Case #%d: %s" % (t + 1, ''.join(ans))
    #check = list(''.join(d[int(x)] for x in ans)).sort()
    #print check == list(S).sort()
