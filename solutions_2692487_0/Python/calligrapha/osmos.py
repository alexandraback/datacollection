def go(A, motes):
    if not motes:
        return 0
    if A > motes[0]:
        return go(A + motes[0], motes[1:])
    elif A == 1:
        return len(motes)
    else:
        count = 0
        while A <= motes[0]:
            count += 1
            A += (A - 1)
        return min(count + go(A + motes[0], motes[1:]), len(motes))

def solve(A, motes):
    motes.sort()
    return go(A, motes)

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    A, N = (int(x) for x in f.readline().strip().split())
    motes = [int(x) for x in f.readline().strip().split()]
    assert len(motes) == N
    result = solve(A, motes)
    out.write("Case #%s: %s\n" % (test, result))
out.close()