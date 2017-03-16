import sys, functools

def sheep(N):
    if N == 0:
        return 'INSOMNIA'
    else:
        sleep = [False] * 10
        index = 1

        while 1:
            Nstr = str(N * index)
            for i in Nstr:
                sleep[int(i)] = True
            if functools.reduce( lambda x, y: x and y, sleep):
                return Nstr
            else:
                index = index + 1

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())

    for i in range(T):
        N = int(f.readline())
        print("Case #{0}: {1}".format(i + 1, sheep(N)))