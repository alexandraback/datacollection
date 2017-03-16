import fileinput

def calc(cakes, target):
    ceil = lambda x, y: x / y + (0 if x % y == 0 else 1)
    all_parts = sum(map(lambda c: ceil(c, target) - 1, cakes))
    return all_parts + target

def solve(cakes):
    lower = max(cakes)
    guess = range(1, lower + 1)
    return min(min(map(lambda t: calc(cakes, t), guess)), lower)

def main():
    f = fileinput.input()
    count = int(f.readline())
    for i in xrange(1, count + 1):
        f.readline()
        cakes = map(lambda x: int(x), f.readline().split())
        print("Case #%d: %d" % (i, solve(cakes)))

if __name__ == '__main__':
    main()
