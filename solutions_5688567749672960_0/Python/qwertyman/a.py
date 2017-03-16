import fileinput
import sys

def rev(x):
    return int(str(x)[::-1])

def reverse(x):
    if x % 10 == 0:
        return x
    return rev(x)

def solve_naive(n):
    queue = [(1, 1)]
    visited = set([1])
    while queue:
        now, depth = queue.pop(0)
        if now == n:
            return depth
        added = now + 1
        reved = rev(now)
        if not reved in visited:
            visited.add(reved)
            queue.append((reved, depth + 1))
        if not added in visited:
            visited.add(added)
            queue.append((added, depth + 1))
    return n

def solve(n):
    ans = 0
    while n > 0:
        last_n = n % 10
        if last_n > 1:
            n -= last_n - 1
            ans += last_n - 1
        rev_n = reverse(n)
        if rev_n < n:
            n = rev_n
        else:
            n -= 1
        ans += 1
    return ans

def main():
    f = fileinput.input()
    count = int(f.readline())
    for i in xrange(1, count + 1):
        sys.stderr.write(str(i) + '...')
        n = int(f.readline())
        print("Case #%d: %d" % (i, solve_naive(n)))
    sys.stderr.write('Done\n')

if __name__ == '__main__':
    main()
