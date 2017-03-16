#! /usr/bin/python2.7

case = input()
ans = 0
cnt = [0] * 2000002

def minstr(s):
    s = str(s)
    n = len(s)
    mins = s
    for i in range(n):
        s = s[1:] + s[0]
        if s < mins:
            mins = s
    return mins

def pair(i):
    if cnt[i] == 0:
        return 0
    k = cnt[i]
    return k*(k-1)/2

for Case in range(1,case+1):
    cin = raw_input().split()
    n = int(cin[0])
    m = int(cin[1])
    ans = 0
    cnt = [0] * 2000002
    for i in range(n, m+1):
        cnt[int(minstr(i))] += 1
    for i in range(m+1):
        ans += pair(i)
    print "Case #" + str(Case) + ":", ans
    
