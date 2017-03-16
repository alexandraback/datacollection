import sys

def main():
    with sys.stdin as f:
        for x in range(int(f.readline())):
            solve(f, x+1)

def solve(f, case):
    N = int(f.readline())
    ab = []
    for i in range(N):
        ab.append([int(x) for x in f.readline().split()])
    ab.sort(key=lambda x: x[1], reverse=True)
    stars = 0
    levels = 0
    while len(ab) > 0:
        do = -1
        for x in range(len(ab)):
            if ab[-(x+1)][1] <= stars:
                do = len(ab) - (x+1)
                break
        if do >= 0:
            if ab[do][0] == 3000:
                stars += 1
            else:
                stars += 2
            levels += 1
            ab.pop(do)
        else:
            for x in range(len(ab)):
                if ab[x][0] <= stars:
                    do = x
                    break
            if do >= 0:
                stars += 1
                levels += 1
                ab[do][0] = 3000
            else:
                print "Case #%d: Too Bad" % case
                return
    print "Case #%d: %d" % (case, levels)

if __name__ == '__main__':
    main()
