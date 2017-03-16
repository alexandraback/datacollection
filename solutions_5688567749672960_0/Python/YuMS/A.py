reversed = lambda x: x[::-1]

times = {}
def rev(num):
    return int(reversed(str(num)))

def reach(now, N):
    ans = 0
    length = len(N)
    if length == 1:
        return int(N) - 1
    if now[:length / 2] == N[:length / 2]:
        return int(N[length / 2:])
    if int(N[length / 2:]):
        head = N[:length / 2]
        ans += int(reversed(head))
        ans += int(N[length / 2:])
    else:
        ans += reach(now, str(int(N) - 1)) + 1
    return ans

def add_length(now):
    length = len(now)
    return reach(now, '9' * length)

def solve(N):
    ans = 1
    now = '1'
    while len(N) > len(now):
        ans += add_length(now)
        now += '0'
        ans += 1
    else:
        ans += reach(now, N)
    return ans

def main():
    T = input()
    for i in xrange(1, T + 1):
        N = str(input())
        print 'Case #{0}: {1}'.format(i, solve(N))

if __name__ == '__main__':
    main()
