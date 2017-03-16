from collections import deque
import time
import cProfile

def reverse(n):
    return int(str(n)[::-1])

def solve_slow(n, show_path=False):
    frontier = deque([(1, 1, [1])])
    visited = set([1])
    best = n
    while True:
        try:
            current, depth, path = frontier.popleft()
        except:
            return best
        if current > n and reverse(current) > n:
            continue
        if depth + (n - current) < best and n - current > 0 and False:
            best = depth + n - current
            #print "New best", best, (current, depth)
        if current == n:
            if show_path:
                print path
            return depth
        visited.add(current)
        if current + 1 not in visited and depth + 1 < best:
            frontier.append((current + 1, depth + 1, path + [current + 1]))
        if reverse(current) not in visited and depth + 1 < best:
            frontier.append((reverse(current), depth + 1, path + [reverse(current)]))

def solve(n, log=False):
    steps = 1
    while n != 1:
        steps += 1
        if n % 10 == 1 and reverse(n) % 10 != 1:
            n = reverse(n)
        else:
            n -= 1
        if log:
            print n
    return steps

def check(n):
    if solve_slow(n) != solve(n):
        return False, (solve_slow(n), solve(n))
    return True, (solve(n), solve(n))

if __name__  == "__main__":
    case_count = int(raw_input())
    for case_num in xrange(1, case_count + 1):
        n = int(raw_input())
        print "Case #%s: %s" % (case_num, solve(n))
