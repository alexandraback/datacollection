import sys, functools

def pk(s):
    index = s.find('+')
    sol = 0 if index == 0 else 1
    while index != -1 and index != len(s) - 1:
        if s[index:index + 2] == '+-':
            sol = sol + 2
        index = s.find('+', index + 1)
    return sol

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())

    for i in range(T):
        S = f.readline().strip('\n')
        print("Case #{0}: {1}".format(i + 1, pk(S)))