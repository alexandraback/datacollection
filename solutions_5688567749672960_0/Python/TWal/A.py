import sys
from collections import deque

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print(''.join(map(str, args)))

def int_input():
    return list(map(int, input().split(' ')))

def solve(n):
    explored = set()
    if n == 1 :
        return 1
    ns = str(n)
    q = deque([("1", 1)])
    while True:
        elem, depth = q.popleft()
        if elem in explored:
            continue
        explored.add(elem)
        ielem = int(elem)
        relem = "".join(reversed(elem))
        if ielem + 1 == n:
            return depth + 1
        elif relem == ns:
            return depth + 1
        """
        if str(ielem+1) not in explored:
            explored.add(str(ielem+1))
            q.append((str(ielem+1), depth+1))
        if relem not in explored:
            explored.add((relem, depth+1))
        """
        q.extend([(str(ielem+1), depth+1), (relem, depth+1)])



def read_input():
    return int(input()),


if __name__ == '__main__':
    for i in range(int(input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
