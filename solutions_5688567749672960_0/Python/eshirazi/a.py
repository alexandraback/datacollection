from Queue import PriorityQueue

def heuristic(a, b):
    return abs(b - a)


def a_star_search(start, goal):
    frontier = PriorityQueue()
    frontier.put(start, 0)
    came_from = {}
    cost_so_far = {}
    came_from[start] = None
    cost_so_far[start] = 0

    while not frontier.empty():
        current = frontier.get()

        if current == goal:
            break

        print current
        for next in [current + 1, int(str(current)[::-1])]:
            new_cost = cost_so_far[current] + 1
            if next not in cost_so_far or new_cost < cost_so_far[next]:
                cost_so_far[next] = new_cost
                priority = new_cost + heuristic(goal, next)
                frontier.put(next, priority)
                came_from[next] = current

    return came_from, cost_so_far


def memorize(f):
    d = {}

    def wrapper(k):
        if k in d:
            return d[k]
        d[k] = f(k)
        return d[k]

    return wrapper

@memorize
def solve(n):
    if n == 1:
        return 1

    rev = int(str(n)[::-1])

    if len(str(rev)) != len(str(n)) or rev > n or rev == n:
        return solve(n-1) + 1

    return min(solve(n-1), solve(rev)) + 1




if __name__ == "__main__":
    for i in xrange(1, 1000000 + 1):
        solve(i)

    tests = int(raw_input())
    for i in xrange(tests):
        n = int(raw_input())
        print "Case #{}: {}".format(i + 1, solve(n))
