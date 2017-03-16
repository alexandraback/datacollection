import sys

def attempt(instance, cut, best):
    clock = 0
    for p in instance:
        serves = p // cut
        if p % cut > 0:
            serves += 1
        serves -= 1

        if serves > 0:
            clock += serves
            if (clock+cut) >= best:
                return None

    return clock+cut

def solve(instance):
    ub = max(instance)
    best = ub
    for cut in range(ub, 0, -1):
        candidate = attempt(instance, cut, best)
        if candidate != None and candidate < best:
            best = candidate

    print(best)

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    IL = []
    for i in range(T):
        sys.stdin.readline()
        line = sys.stdin.readline().strip().split()
        line = [int(i) for i in line]

        IL.append(line)

    for i in range(T):
        print('Case #'+str(i+1)+': ', end='')
        solve(IL[i])

