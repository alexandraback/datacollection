import sys
from fractions import Fraction

def dist(x, y):
    return (x*x + y*y)

def sgn(x): return abs(x) // x

def gcd(a, b):
    a = abs(a)
    b = abs(b)
    while b != 0:
        a, b = b, a % b
    return a

def slope(a, b):
    x = int(2*a)
    y = int(2*b)
    if y == 0:
        if x == 0:
            return (0, 0)
        return (sgn(x), 0)
    if x == 0:
        return (0, sgn(y))
    g = gcd(x, y)
    if g == 0:
        return (0, 0)
    s = sgn(y)
    return (x//g, y//g)

def attach(p, slopes, dists, dst, positions):
    if p[0] == 0 and p[1] == 0:
        return
    d = dist(p[0], p[1])
    a = slope(p[0], p[1])
    if a in slopes:
        i = slopes.index(a)
        if d < dists[i]:
            dists[i] = d
            positions[i] = p
    elif d <= dst*dst:
        slopes.append(a)
        dists.append(d)
        positions.append(p)

def slopes(p, l, w, dst):
    slopes = []
    dists = []
    corners = []
    positions = []
    step_x = 2*w
    step_y = 2*l
    a = int(2*p[0])
    b = int(2*p[1])
    x = -(dst // step_x)*step_x
    while min(abs(x), abs(x-a)) <= dst:
        y = -(dst // step_y)*step_y
        while min(abs(y), abs(y-b)) <= dst:
            corners.append((x, y))
            attach((x, y), slopes, dists, dst, positions)
            attach((x-a, y), slopes, dists, dst, positions)
            attach((x, y-b), slopes, dists, dst, positions)
            attach((x-a, y-b), slopes, dists, dst, positions)
            y += step_y
        x += step_x
    for c in corners:
        s = slope(c[0]+a, c[1]+b)
        if s[0] in [-1, 1] and s[1] in [-1, 1]:
            continue
        if s in slopes:
            d = dist(c[0]+a, c[1]+b)
            i = slopes.index(s)
            if d <= dists[i]:
                slopes = slopes[:i] + slopes[i+1:]
                dists = dists[:i] + dists[i+1:]
                positions = positions[:i] + positions[i+1:]
    return slopes

def hall_of_mirrors(args, dst):
    hall = [[0 if i == '.' else 1 for i in j] for j in args]
    for i in range(len(args)):
        for j in range(len(args[i])):
            if args[i][j] == 'X':
                pos = (j, i)
                break
    pos = (pos[0] - 0.5, pos[1] - 0.5)
    s = slopes(pos, len(args)-2, len(args[0])-2, dst)
    return str(len(s))

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    x = 0
    for i in range(1, int(Input[0]) + 1):
        a = Input[i+x].split(' ')
        n = int(a[0])
        m = int(a[1])
        dst = int(a[2])
        args = [Input[i+x+j] for j in range(1, n + 1)]
        x += n
        result = hall_of_mirrors(args, dst)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
