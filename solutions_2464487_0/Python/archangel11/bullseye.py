from math import sqrt

def solve(f):
    nm = f.readline().split()
    r = long(nm[0])
    t = long(nm[1])

    a = 2*r + 1
    d = 4
    output = (long(sqrt((2*a-d)**2 + 8*t*d) - (2*a-d)))/(2*d)

    return long(output)



if __name__ == "__main__":
    solve()