from sys import stdin

def read_ints(): return map(int, stdin.readline().split())

def solve(A, i, motes, changes):
    if changes > len(motes): return len(motes)
    mote = motes[i]
    if i == len(motes) - 1:
        return 0 if A > mote else 1
    else:
        a = A
        j = 0
        while a <= mote:
            a += a - 1
            j += 1
        if j < 2:
            return changes + solve(a + mote, i + 1, motes, changes) + j
        else:
            return changes + min(solve(a + mote, i + 1, motes, changes) + j, solve(A, i + 1, motes, changes) + 1)

def main():
    cases = int(stdin.readline())
    for case in xrange(1, cases + 1):
        A, N = read_ints()
        motes = read_ints()
        
        motes.sort()
        
        if A == 1:
            ans = N
        else:
            ans = solve(A, 0, motes, 0)        

        print('Case #{}: {}'.format(case, ans))
        
main()