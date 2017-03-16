import fileinput

def solve(x, r, c):
    if x == 1:
        return True
    if (r * c) % x != 0:
        return False
    if x == 2:
        return True
    if x == 3:
        return r * c > 3
    elif x == 4:
        return r * c >= 4 * 3
    elif x == 5:
        return r * c >= 5 * 4
    elif x == 6:
        return r * c >= 6 * 5
    return False

def main():
    f = fileinput.input()
    count = int(f.readline())
    for i in xrange(1, count + 1):
        x, r, c = tuple(map(lambda x: int(x), f.readline().split()))
        print("Case #%d: %s" % (i, 'GABRIEL' if solve(x, r, c) else 'RICHARD'))

if __name__ == '__main__':
    main()
