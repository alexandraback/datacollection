

def solve(s):
    ret = []
    for c in s:
        if not ret or ord(c) >= ord(ret[0]):
            ret.insert(0, c)
        else:
            ret.append(c)
    return ''.join(ret)
N=int(input())
for caseid in range(1, N+1):
    S = input().strip()
    print("Case #%d: %s" % (caseid, solve(S)))