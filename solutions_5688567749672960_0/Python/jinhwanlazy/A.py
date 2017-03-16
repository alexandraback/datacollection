def reverse(N):
    N = str(N)
    if N[-1] == '0':
        return None
    else:
        return int(str(N)[::-1])

r = [0]

def solve(N):
    global r

    if len(r) > N:
        return r[N]

    for i in range(len(r), N+1):
        a = i-1
        b = reverse(i)
        if b and 0 < b < i:
            r.append(min(r[a], r[b])+1)
        else:
            r.append(r[a]+1)

    return r[-1]


for case in range(int(input())):
    N = int(input())
    print("Case #%d: %s" % (case+1, solve(N)))

#for i, v in enumerate(r):
#    print(i, v)
#
