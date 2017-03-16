import fileinput

def solve(x, r, c):
    if x == 1:
        return True
    elif x == 2:
        return (r * c) % 2 == 0
    elif x == 3:
        return (r * c) % 3 == 0 and r * c > 3
    elif x == 4:
        return r * c == 12 or r * c == 16
    return False

def main():
    f = fileinput.input()
    count = int(f.readline())
    for i in xrange(1, count + 1):
        x, r, c = tuple(map(lambda x: int(x), f.readline().split()))
        print("Case #%d: %s" % (i, 'GABRIEL' if solve(x, r, c) else 'RICHARD'))

if __name__ == '__main__':
    main()
