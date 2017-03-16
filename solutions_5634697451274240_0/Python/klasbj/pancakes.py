import sys

def solve(stack):
    stack = [1 if p == '-' else 0 for p in stack.strip()]
    nflips = 0
    for p in reversed(stack):
        if (nflips%2) != p:
            nflips += 1
    return nflips

if __name__ == '__main__':
    lines = sys.stdin.readlines()[1:]
    for t, n in enumerate(lines):
        print("Case #{}: {}".format(t+1, solve(n)))

