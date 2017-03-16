import  sys

sys.setrecursionlimit(100000)
T = int(raw_input())

def solve(s):
    best = 0
    if (len(s) <= 1):
        return  s
    for i in range(len(s)):
        if ord(s[best]) <= ord(s[i]):
            best = i
    return s[best] + solve(s[:best]) + s[best+1:]

for t in range(1,T+1):
    S = raw_input()
    print "Case #"+str(t)+": "+solve(S)
