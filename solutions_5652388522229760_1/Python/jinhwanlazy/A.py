def solve(n):
    if n == 0:
        return 'INSOMNIA'
    seen = set(str(n))
    nn = n
    while len(seen) < 10:
        nn += n
        seen |= set(str(nn))
    return nn


for case in range(int(input())):
    N = int(input())
    print("Case #%d:" % (case+1), solve(N))
