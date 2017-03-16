import sys

infile = sys.stdin

def move(target, back, forward):
    if target < 0:
        target = -target
        back, forward = forward, back

    return (back + forward) * target
    

def solve(x, y):
    x_move = move(x, 'W', 'E')
    y_move = move(y, 'S', 'N')
    return y_move + x_move

if __name__ == "__main__":
    T = int(infile.readline())
    for i in range(T):
        x, y = [int(item) for item in infile.readline().split()]
        ret = solve(x, y)
        print "Case #%d: %s" % (i + 1, ret)
